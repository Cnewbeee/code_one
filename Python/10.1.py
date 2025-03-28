import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

# 数据准备
categories = ['1-2次', '3-5次', '5+次']
values = [60, 35, 15]
spend = [500, 1400, 3000]

# 创建3D坐标系
fig = plt.figure(figsize=(10,8))
ax = fig.add_subplot(111, projection='3d')

# 气泡尺寸映射
size = [n**1.5 for n in values]  # 非线性放大

# 绘制散点
sc = ax.scatter(
    x=range(len(categories)), 
    y=spend, 
    z=np.zeros(len(categories)),
    s=size,
    c=spend, 
    cmap='viridis',
    depthshade=False,
    edgecolors='w',
    linewidths=1.5
)

# 坐标轴增强
ax.set_xticks(range(len(categories)))
ax.set_xticklabels(categories, rotation=45, ha='right')
ax.set_xlabel('参与频率', labelpad=15)
ax.set_ylabel('消费金额（元）', labelpad=15)
ax.set_zlabel(' ')

# 添加等高线投影
for i, (x, y, z) in enumerate(zip(range(len(categories)), spend, np.zeros(len(categories)))):
    ax.plot([x, x], [y, y], [z, -y/100], 'k--', alpha=0.3)
    ax.text(x, y, -y/100-500, f"{values[i]}人", ha='center')

# 颜色条设置
cbar = plt.colorbar(sc, pad=0.1)
cbar.set_label('消费梯度', rotation=270, labelpad=20)

# 视角调整
ax.view_init(elev=25, azim=-45)

plt.savefig('matplotlib_3d.png', dpi=300, bbox_inches='tight')