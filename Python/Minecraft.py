from __future__ import division  # 把下一个新版本的特性导入到当前版本

import sys
import math
import random
import time

from collections import deque
from pyglet import image
from pyglet.gl import *  # OpenGL,GLU接口
from pyglet.graphics import TextureGroup
from pyglet.window import key, mouse  # 键盘常量，事件

TICKS_PER_SEC = 60  # 每秒刷新60次

# 用于减轻块负荷的扇区的大小。
SECTOR_SIZE = 16

WALKING_SPEED = 5  # 移动速度
FLYING_SPEED = 15  # 飞行速度

GRAVITY = 20.0
MAX_JUMP_HEIGHT = 1.0  # 一个块的高度
# 跳跃速度公式
JUMP_SPEED = math.sqrt(2 * GRAVITY * MAX_JUMP_HEIGHT)
TERMINAL_VELOCITY = 50  # 自由下落终端速度

PLAYER_HEIGHT = 2  # 玩家高度

if sys.version_info[0] >= 3:
    xrange = range


# 返回以x,y,z为中心，边长为2n的正方体六个面的顶点坐标
def cube_vertices(x, y, z, n):
    return [
        x - n, y + n, z - n, x - n, y + n, z + n, x + n, y + n, z + n, x + n, y + n, z - n,  # top
        x - n, y - n, z - n, x + n, y - n, z - n, x + n, y - n, z + n, x - n, y - n, z + n,  # bottom
        x - n, y - n, z - n, x - n, y - n, z + n, x - n, y + n, z + n, x - n, y + n, z - n,  # left
        x + n, y - n, z + n, x + n, y - n, z - n, x + n, y + n, z - n, x + n, y + n, z + n,  # right
        x - n, y - n, z + n, x + n, y - n, z + n, x + n, y + n, z + n, x - n, y + n, z + n,  # front
        x + n, y - n, z - n, x - n, y - n, z - n, x - n, y + n, z - n, x + n, y + n, z - n,  # back
    ]


# 纹理坐标
# 给出纹理图左下角坐标，返回一个正方形纹理的四个顶点坐标
# 由于纹理图可看成4*4的纹理patch，所以n=4(图中实际有6个patch,其它空白)
# 比如，欲返回左下角的那个正方形纹理patch，
# 输入是左下角的整数坐标(0,0)
# 输出是0,0, 1/4,0, 1/4,1/4, 0,1/4
def tex_coord(x, y, n=4):
    m = 1.0 / n
    dx = x * m
    dy = y * m
    return dx, dy, dx + m, dy, dx + m, dy + m, dx, dy + m


# 计算一个正方体6个面的纹理贴图坐标
# top,bottom和4个侧面(side)共6个
# 将结果放入一个list中
def tex_coords(top, bottom, side):
    top = tex_coord(*top)  # 将元组(x, y)分为x, y作为函数参数
    bottom = tex_coord(*bottom)
    side = tex_coord(*side)
    result = []
    result.extend(top)  # extend用来连接两个list
    result.extend(bottom)
    result.extend(side * 4)
    return result


# 使用的纹理图片
TEXTURE_PATH = 'img.png'

# 计算草块，沙块，砖块，石块6个面的纹理贴图坐标(用一个list保存)
# 可以看出除了草块，其他的正方体六个而的贴图都一样
GRASS = tex_coords((1, 0), (0, 1), (0, 0))
SAND = tex_coords((1, 1), (1, 1), (1, 1))
BRICK = tex_coords((2, 0), (2, 0), (2, 0))
STONE = tex_coords((2, 1), (2, 1), (2, 1))

# 当前位置向6个方向移动1个单位要用到的增量坐标
FACES = [
    (0, 1, 0),
    (0, -1, 0),
    (-1, 0, 0),
    (1, 0, 0),
    (0, 0, 1),
    (0, 0, -1),
]


# 对位置x,y,z取整
def normalize(position):
    x, y, z = position
    x, y, z = (int(round(x)), int(round(y)), int(round(z)))
    return (x, y, z)


# 先将位置坐标x,y,z取整，然后各除以SECTOR_SIZE,返回x,0,z
# 会将许多不同的position映射到同一个(x,0,z)
# 一个(x,0,z)对应一个x*z*y=16*16*y的区域内的所有立方体中心position
def sectorize(position):
    x, y, z = normalize(position)
    x, y, z = x // SECTOR_SIZE, y // SECTOR_SIZE, z // SECTOR_SIZE
    return (x, 0, z)  # 得到的是整数坐标


class Model(object):

    def __init__(self):

        # 批处理一个集批量渲染顶点列表
        self.batch = pyglet.graphics.Batch()
        # 载入纹理贴图
        self.group = TextureGroup(image.load(TEXTURE_PATH).get_texture())
        # 字典：position:texture的键值对，存在于地图中所有立方体的信息
        self.world = {}
        # 字典：position:texture的键值对，显示出来的立方体
        self.shown = {}
        # 字典：postion:VertexList键值对，VertexList被批量渲染
        self._shown = {}

        # 字典：(x,0,z):[position1,position2...]键值对
        self.sectors = {}

        # 用于存储事件的队列
        self.queue = deque()
        # 画出游戏地图
        self._initialize()

    # 画地图，大小80*80
    def _initialize(self):
        n = 80  # 地图大小
        s = 1  # 步长
        y = 0  # initial y height
        for x in xrange(-n, n + 1, s):
            for z in xrange(-n, n + 1, s):
                # 在地下画一层石头，上面是一层草地
                # 地面从y=-2开始
                self.add_block((x, y - 2, z), GRASS, immediate=False)
                self.add_block((x, y - 3, z), STONE, immediate=False)
                # 地图的四周用墙围起来
                if x in (-n, n) or z in (-n, n):
                    # 创建外墙 .
                    for dy in xrange(-2, 3):
                        self.add_block((x, y + dy, z), STONE, immediate=False)

        # #为了避免建到墙上，o取n-10
        o = n - 10
        # 在地面上随机建造一些草块，沙块，砖块
        for _ in xrange(120):  # 只想迭代120次，不需要迭代变量i，直接用 _
            a = random.randint(-o, o)  # 在[-o,o]内随机取一个整数
            b = random.randint(-o, o)  # hill的z位置
            c = -1  # hill的底部
            h = random.randint(1, 6)  # hill的高度
            s = random.randint(4, 8)  # 2 * s是hill的边长
            d = 1  # 如何迅速地从hill上逐渐消失
            t = random.choice([GRASS, SAND, BRICK])
            for y in xrange(c, c + h):
                for x in xrange(a - s, a + s + 1):
                    for z in xrange(b - s, b + s + 1):
                        if (x - a) ** 2 + (z - b) ** 2 > (s + 1) ** 2:
                            continue
                        if (x - 0) ** 2 + (z - 0) ** 2 < 5 ** 2:
                            continue
                        self.add_block((x, y, z), t, immediate=False)
                s -= d  # 递减边的长度，hills逐渐减少

    # 检测鼠标是否能对一个立方体进行操作。
    # 返回key,previous：key是鼠标可操作的块(中心坐标)，根据人所在位置和方向向量求出，
    # previous是与key处立方体相邻的空位置的中心坐标。
    # 如果返回非空，点击鼠标左键删除key处立方体，
    # 点击鼠标右键在previous处添加砖块。
    def hit_test(self, position, vector, max_distance=8):
        m = 8
        x, y, z = position
        dx, dy, dz = vector
        previous = None
        for _ in xrange(max_distance * m):  # 迭代8*8=64次
            key = normalize((x, y, z))
            if key != previous and key in self.world:
                return key, previous
            previous = key
            x, y, z = x + dx / m, y + dy / m, z + dz / m
        return None, None

    # 只要position周围6个面有一个没有立方体(exposed了)，返回真值，表示要绘制position处的立方体
    # 如果6个面都被立方体包围(没有exposed)，position处的立方体就可以不绘制
    # 因为绘制了也看不到
    def exposed(self, position):
        x, y, z = position
        for dx, dy, dz in FACES:
            if (x + dx, y + dy, z + dz) not in self.world:
                return True
        return False

    # 添加立方体
    def add_block(self, position, texture, immediate=True):
        if position in self.world:  # 如果position已经存在于world中，要先移除它
            self.remove_block(position, immediate)
        self.world[position] = texture  # 添加相应的位置和纹理
        # 以区域为一组添加立方体的position到字典中，
        # 16*16*y区域内的立方体都映射到一个键值,这些立方体position以tuble形式存在于一个列表中
        self.sectors.setdefault(sectorize(position), []).append(position)
        if immediate:  # 初始时该变量为false，不会同步绘制
            if self.exposed(position):  # 如果同步绘制，且该位置是显露在外的
                self.show_block(position)  # 绘制该立方体
            self.check_neighbors(position)

    # 删除立方体
    def remove_block(self, position, immediate=True):
        del self.world[position]  # 把world中的position,texture对删除
        self.sectors[sectorize(position)].remove(position)  # 把区域中相应的position删除
        if immediate:  # 如果同步
            if position in self.shown:  # 如果position在显示列表中
                self.hide_block(position)  # 立即删除它
            self.check_neighbors(position)

    # 删除一个立方体后，要检查它周围6个邻接的位置
    # 是否有因此暴露出来的立方体，有的话要把它绘制出来
    def check_neighbors(self, position):

        x, y, z = position
        for dx, dy, dz in FACES:  # 检查周围6个位置
            key = (x + dx, y + dy, z + dz)
            if key not in self.world:  # 如果该处没有立方体则跳过
                continue
            if self.exposed(key):  # 如果该处有立方体且暴露在外
                if key not in self.shown:  # 且没有在显示列表中
                    self.show_block(key)  # 则立即绘制出来
            else:  # 如果没有暴露在外，而又在显示列表中，则立即隐藏(删除)它
                if key in self.shown:
                    self.hide_block(key)

    # 将world中还没显示且显露在外的立方体绘制出来
    def show_block(self, position, immediate=True):
        texture = self.world[position]  # 取出纹理(其实是6个面的纹理坐标信息)
        self.shown[position] = texture  # 存入shown字典中
        if immediate:  # 立即绘制
            self._show_block(position, texture)
        else:  # 不立即绘制，进入事件队列
            self._enqueue(self._show_block, position, texture)

    # 添加顶点列表(VertexList)到渲染对象，(on_draw会指渲染它)
    # 并将position:VertexList对存入_shown
    def _show_block(self, position, texture):

        x, y, z = position
        # 中心为x,y,z的1*1*1正方体
        # 顶点坐标数据和纹理坐标数据
        vertex_data = cube_vertices(x, y, z, 0.5)
        texture_data = list(texture)
        # 创建vertex 列表
        # FIXME Maybe `add_indexed()` should be used instead
        # 添加顶点列表(VertexList)到批渲染对象中
        # 顶点数目count=24(6个面，一个面4个点)
        self._shown[position] = self.batch.add(24, GL_QUADS, self.group,
                                               ('v3f/static', vertex_data),
                                               ('t2f/static', texture_data))

    # 隐藏立方体
    def hide_block(self, position, immediate=True):
        self.shown.pop(position)  # 将要隐藏的立方体中心坐标从显示列表中移除
        if immediate:  # 立即移除，从图上消失
            self._hide_block(position)
        else:  # 不立即移除，进行事件队列等待处理
            self._enqueue(self._hide_block, position)

    # 立即移除立方体
    # 将position位置的顶点列表弹出并删除，相应的立方体立即被移除(其实是在update之后)
    def _hide_block(self, position):
        self._shown.pop(position).delete()

    # 绘制一个区域内的立方体
    # 如果区域内的立方体位置没在显示列表，且位置是显露在外的，则显示立方
    def show_sector(self, sector):
        for position in self.sectors.get(sector, []):
            if position not in self.shown and self.exposed(position):
                self.show_block(position, False)

    # 隐藏区域
    # 如果一个立方体是在显示列表中的，则隐藏它，
    def hide_sector(self, sector):
        for position in self.sectors.get(sector, []):
            if position in self.shown:
                self.hide_block(position, False)  # 放入事件队列，不会立即隐藏

    # 移动立方体，移动区域是是一个连续的x、y子区域
    def change_sectors(self, before, after):
        before_set = set()
        after_set = set()
        pad = 4
        for dx in xrange(-pad, pad + 1):
            for dy in [0]:  # xrange(-pad, pad + 1):
                for dz in xrange(-pad, pad + 1):
                    if dx ** 2 + dy ** 2 + dz ** 2 > (pad + 1) ** 2:
                        continue
                    if before:
                        x, y, z = before
                        before_set.add((x + dx, y + dy, z + dz))
                    if after:
                        x, y, z = after
                        after_set.add((x + dx, y + dy, z + dz))
        show = after_set - before_set
        hide = before_set - after_set
        for sector in show:
            self.show_sector(sector)
        for sector in hide:
            self.hide_sector(sector)

    # 添加事件到队列queue
    def _enqueue(self, func, *args):
        self.queue.append((func, args))

    # 处理队头事件
    def _dequeue(self):
        func, args = self.queue.popleft()
        func(*args)

    # 用1/60秒的时间来处理队列中的事件
    # 不一定要处理完
    def process_queue(self):
        start = time.perf_counter()
        while self.queue and time.perf_counter() - start < 1.0 / TICKS_PER_SEC:
            self._dequeue()

    # 处理事件队列中的所有事件
    def process_entire_queue(self):
        while self.queue:
            self._dequeue()


class Window(pyglet.window.Window):

    def __init__(self, *args, **kwargs):
        # *args,化序列为位置参数：(1,2) -> func(1,2)
        # **kwargs,化字典为关键字参数：{'a':1,'b':2} -> func(a=1,b=2)
        super(Window, self).__init__(*args, **kwargs)

        # 初始时，鼠标事件没有绑定到游戏窗口
        self.exclusive = False

        # 当飞行重力没有效果时，速度增加
        self.flying = False

        # [z, x]，z表示前后运动，x表示左右运动
        self.strafe = [0, 0]

        # 开始位置在地图中间
        self.position = (0, 0, 0)
        # rotation(水平角x，俯仰角y)
        # 水平角是方向射线xoz上的投影与z轴负半轴的夹角
        # 俯仰角是方向射线与xoz平面的夹角
        self.rotation = (0, 0)

        # Which sector the player is currently in.
        self.sector = None

        # reticle表示游戏窗口中间的那个十字
        # 四个点，绘制成两条直线
        self.reticle = None

        # Velocity in the y (upward) direction.
        self.dy = 0

        # # 可以建造的类型
        self.inventory = [BRICK, GRASS, SAND]

        # # 初始时右键建造的是砖块
        self.block = self.inventory[0]

        # # 数字键响应，用于建造类型的切换
        self.num_keys = [
            key._1, key._2, key._3, key._4, key._5,
            key._6, key._7, key._8, key._9, key._0]

        # 处理地图的模型实例
        self.model = Model()

        # 游戏窗口左上角的label参数设置.
        self.label = pyglet.text.Label('', font_name='Arial', font_size=18,
                                       x=10, y=self.height - 10, anchor_x='left', anchor_y='top',
                                       color=(0, 0, 0, 255))

        pyglet.clock.schedule_interval(self.update, 1.0 / TICKS_PER_SEC)  # 每秒刷新60次

    # 设置鼠标事件是否绑定到游戏窗口
    def set_exclusive_mouse(self, exclusive):
        super(Window, self).set_exclusive_mouse(exclusive)
        self.exclusive = exclusive

    # 根据前进方向rotation来决定移动1单位距离时，各轴分量移动多少
    def get_sight_vector(self):
        x, y = self.rotation
        # y ranges from -90 to 90, or -pi/2 to pi/2, so m ranges from 0 to 1 and
        # is 1 when looking ahead parallel to the ground and 0 when looking
        # straight up or down.
        m = math.cos(math.radians(y))
        # dy ranges from -1 to 1 and is -1 when looking straight down and 1 when
        # looking straight up.
        dy = math.sin(math.radians(y))
        dx = math.cos(math.radians(x - 90)) * m
        dz = math.sin(math.radians(x - 90)) * m
        return (dx, dy, dz)

    # 运动时计算三个轴的位移增量
    def get_motion_vector(self):
        if any(self.strafe):
            x, y = self.rotation
            strafe = math.degrees(math.atan2(*self.strafe))  # arctan(z/x)，再转换成角度
            y_angle = math.radians(y)
            x_angle = math.radians(x + strafe)
            if self.flying:  # 如果允许飞，那么运动时会考虑垂直方向即y轴方向的运动
                m = math.cos(y_angle)
                dy = math.sin(y_angle)
                if self.strafe[1]:  # 如果x不为0
                    # 左移或右移
                    dy = 0.0
                    m = 1
                if self.strafe[0] > 0:  # 如果z大于0
                    # 向后移动
                    dy *= -1
                # 当你向上或向下飞行时，左、右运动都比较少
                dx = math.cos(x_angle) * m
                dz = math.sin(x_angle) * m
            else:
                dy = 0.0
                dx = math.cos(x_angle)
                dz = math.sin(x_angle)
        else:
            dy = 0.0
            dx = 0.0
            dz = 0.0
        return (dx, dy, dz)

    # 每1/60秒调用一次进行更新
    def update(self, dt):
        self.model.process_queue()  # 用1/60的时间来处理队列中的事件，不一定要处理完
        sector = sectorize(self.position)
        if sector != self.sector:  # 如果position的sector与当前sector不一样
            self.model.change_sectors(self.sector, sector)
            if self.sector is None:  # 如果sector为空
                self.model.process_entire_queue()  # 处理队列中的所有事件
            self.sector = sector  # 更新sector
        m = 8
        dt = min(dt, 0.2)
        for _ in xrange(m):
            self._update(dt / m)

    # 更新self.dy和self.position
    def _update(self, dt):

        speed = FLYING_SPEED if self.flying else WALKING_SPEED  # 如果能飞，速度15；否则为5
        d = dt * speed  # distance covered this tick.
        dx, dy, dz = self.get_motion_vector()
        # 新的空间地位，在重力面前。
        dx, dy, dz = dx * d, dy * d, dz * d
        # # 如果不能飞，则使其在y方向上符合重力规律
        if not self.flying:
            self.dy -= dt * GRAVITY
            self.dy = max(self.dy, -TERMINAL_VELOCITY)
            dy += self.dy * dt
        x, y, z = self.position
        # 碰撞检测后应该移动到的位置
        x, y, z = self.collide((x + dx, y + dy, z + dz), PLAYER_HEIGHT)
        self.position = (x, y, z)  # 更新位置

    # 碰撞检测
    # 返回的p是碰撞检测后应该移动到的位置
    # 如果没有遇到障碍物，p仍然是position；
    # 否则，p是新的值(会使其沿着墙走，或不支)
    def collide(self, position, height):
        pad = 0.25
        p = list(position)  # 将元组变为list
        np = normalize(position)  # 取整
        for face in FACES:  # 检查周围6个面的立方体
            for i in xrange(3):  # (x,y,z)中每一维单独检测
                if not face[i]:  # 如果为0，则过
                    continue
                # 这个维度有多少重叠
                d = (p[i] - np[i]) * face[i]
                if d < pad:
                    continue
                for dy in xrange(height):  # 检测每个高度
                    op = list(np)
                    op[1] -= dy
                    op[i] += face[i]
                    if tuple(op) not in self.model.world:
                        continue
                    p[i] -= (d - pad) * face[i]
                    if face == (0, -1, 0) or face == (0, 1, 0):
                        # 你与地面或顶部相撞，所以停止下降/上升
                        self.dy = 0
                    break
        return tuple(p)

    # 鼠标按下事件
    def on_mouse_press(self, x, y, button, modifiers):

        if self.exclusive:  # 当鼠标事件已经绑定了此窗口
            vector = self.get_sight_vector()
            block, previous = self.model.hit_test(self.position, vector)
            # 如果按下左键且该处有block
            if (button == mouse.RIGHT) or \
                    ((button == mouse.LEFT) and (modifiers & key.MOD_CTRL)):
                if previous:
                    self.model.add_block(previous, self.block)
            elif button == pyglet.window.mouse.LEFT and block:  # 如果按下右键，且有previous位置，则在previous处增加方块
                texture = self.model.world[block]
                if texture != STONE:  # 如果block不是石块，就移除它
                    self.model.remove_block(block)
        else:  # 否则隐藏鼠标，并绑定鼠标事件到该窗口
            self.set_exclusive_mouse(True)

    # 鼠标移动事件，处理视角的变化
    # dx,dy表示鼠标从上一位置移动到当前位置x，y轴上的位移
    # 该函数将这个位移转换成了水平角x和俯仰角y的变化
    # 变化幅度由参数m控制
    def on_mouse_motion(self, x, y, dx, dy):
        if self.exclusive:  # 在鼠标绑定在该窗口时
            m = 0.15
            x, y = self.rotation
            x, y = x + dx * m, y + dy * m
            y = max(-90, min(90, y))  # 限制仰视和俯视角y只能在-90度和90度之间
            self.rotation = (x, y)

    # 按下键盘事件，长按W，S，A，D键将不断改变坐标
    def on_key_press(self, symbol, modifiers):
        if symbol == key.W:  # opengl坐标系：z轴垂直平面向外，x轴向右，y轴向上
            self.strafe[0] -= 1  # 向前：z坐标-1
        elif symbol == key.S:
            self.strafe[0] += 1
        elif symbol == key.A:  # 向左：x坐标-1
            self.strafe[1] -= 1
        elif symbol == key.D:
            self.strafe[1] += 1
        elif symbol == key.SPACE:
            if self.dy == 0:
                self.dy = JUMP_SPEED
        elif symbol == key.ESCAPE:  # 鼠标退出当前窗口
            self.set_exclusive_mouse(False)
        elif symbol == key.TAB:  # 切换是否能飞，即是否可以在垂直方向y上运动
            self.flying = not self.flying
        elif symbol in self.num_keys:
            index = (symbol - self.num_keys[0]) % len(self.inventory)
            self.block = self.inventory[index]  # 取得相应的方块类型

    # 释放按键事件
    def on_key_release(self, symbol, modifiers):

        if symbol == key.W:  # 按键释放时，各方向退回一个单位
            self.strafe[0] += 1
        elif symbol == key.S:
            self.strafe[0] -= 1
        elif symbol == key.A:
            self.strafe[1] += 1
        elif symbol == key.D:
            self.strafe[1] -= 1

    # 窗口大小变化响应事件
    def on_resize(self, width, height):
        # label的纵坐标
        self.label.y = height - 10
        # reticle更新，包含四个点，绘制成两条直线
        if self.reticle:
            self.reticle.delete()
        x, y = self.width // 2, self.height // 2
        n = 10
        self.reticle = pyglet.graphics.vertex_list(4,
                                                   ('v2i', (x - n, y, x + n, y, x, y - n, x, y + n))
                                                   )

    def set_2d(self):
        """  配置在opengl绘制三维图形..
        """
        width, height = self.get_size()
        glDisable(GL_DEPTH_TEST)
        glViewport(0, 0, width, height)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        glOrtho(0, width, 0, height, -1, 1)
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()

    def set_3d(self):
        """ 配置在opengl绘制三维图形.
        """
        width, height = self.get_size()
        glEnable(GL_DEPTH_TEST)
        glViewport(0, 0, width, height)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        gluPerspective(65.0, width / float(height), 0.1, 60.0)
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
        x, y = self.rotation
        glRotatef(x, 0, 1, 0)
        glRotatef(-y, math.cos(math.radians(x)), 0, math.sin(math.radians(x)))
        x, y, z = self.position
        glTranslatef(-x, -y, -z)

    # 重写Window的on_draw函数
    # 当窗口需要被重绘时，事件循环(EventLoop)就会调度该事件
    def on_draw(self):
        self.clear()
        self.set_3d()  # 进入3d模式
        glColor3d(1, 1, 1)
        self.model.batch.draw()  # 将batch中保存的顶点列表绘制出来
        self.draw_focused_block()  # 绘制鼠标focus的立方体的线框
        self.set_2d()  # 进入2d模式
        self.draw_label()  # 绘制label
        self.draw_reticle()  # 绘制窗口中间的十字

    # 画出鼠标focus的立方体，在它的外层画个立方体线框
    def draw_focused_block(self):
        vector = self.get_sight_vector()
        block = self.model.hit_test(self.position, vector)[0]
        if block:
            x, y, z = block
            vertex_data = cube_vertices(x, y, z, 0.51)
            glColor3d(0, 0, 0)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE)
            pyglet.graphics.draw(24, GL_QUADS, ('v3f/static', vertex_data))
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)

    # 显示帧率，当前位置坐标，显示的方块数及总共的方块数
    def draw_label(self):
        x, y, z = self.position
        self.label.text = '%02d (%.2f, %.2f, %.2f) %d / %d' % (
            pyglet.clock.get_fps(), x, y, z,
            len(self.model._shown), len(self.model.world))
        self.label.draw()  # 绘制label的text

    # 绘制游戏窗口中间的十字，一条横线加一条竖线
    def draw_reticle(self):
        glColor3d(0, 0, 0)
        self.reticle.draw(GL_LINES)


# 设置雾效果
def setup_fog():
    glEnable(GL_FOG)
    # Set the fog color.
    glFogfv(GL_FOG_COLOR, (GLfloat * 4)(0.5, 0.69, 1.0, 1))
    # Say we have no preference between rendering speed and quality.
    glHint(GL_FOG_HINT, GL_DONT_CARE)
    # Specify the equation used to compute the blending factor.
    glFogi(GL_FOG_MODE, GL_LINEAR)
    # How close and far away fog starts and ends. The closer the start and end,
    # the denser the fog in the fog range.
    glFogf(GL_FOG_START, 20.0)
    glFogf(GL_FOG_END, 60.0)


# 设置雾效果
def setup():
    """ 基本opengl配置
    """
    # 颜色设置“Clear ”，亮度。.
    glClearColor(0.5, 0.69, 1.0, 1)
    # 启用向后面片的剔除（不是绘制）——对您不可见的刻面
    glEnable(GL_CULL_FACE)
    # 设置纹理缩小/放大功能gl_nearest（曼哈顿距离最近的）到指定纹理坐标。
    # gl_nearest”一般的速度比gl_linear快，
    # 但它能产生纹理图像边缘更加清晰的纹理元素因为之间的过渡是不顺利。”
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
    setup_fog()  # 设置雾效果


def main():
    # 设置游戏的音乐
    sound = pyglet.media.load('阳光开朗大男孩 (女版).ogg', streaming=False)  # 加载音乐（可换）
    sound.play()  # 播放

    window = Window(width=800, height=600, caption='Minecraft', resizable=True)  # 创建游戏窗口
    # 获取屏幕的宽度和高度
    screen_width = window.screen.width
    screen_height = window.screen.height

    # 计算窗口左上角的位置
    x = (screen_width - window.width) // 2
    y = (screen_height - window.height) // 2

    # 设置窗口位置
    window.set_location(x, y)

    # 隐藏鼠标光标，将所有的鼠标事件都绑定到此窗口
    window.set_exclusive_mouse(True)
    setup()  # 设置
    pyglet.app.run()  # 运行，开始监听并处理事件


if __name__ == '__main__':
    main()
