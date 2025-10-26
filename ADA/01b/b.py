import matplotlib.pyplot as plt
import numpy as np
import heapq

# 图形显示配置
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

class OperationCounter:
    """操作计数器包装类"""
    def __init__(self):
        self.count = 0

# 算法实现（添加操作计数）
def greedy_knapsack(items, capacity, counter):
    """贪心算法操作计数版"""
    # 排序操作计数（假设比较次数为n logn）
    counter.count += len(items) * int(np.log2(len(items))) if len(items) > 0 else 0
    sorted_items = sorted(items, key=lambda x: x[1]/x[0], reverse=True)
    
    total_value = 0
    remaining = capacity
    for weight, value in sorted_items:
        counter.count += 1  # 每次物品检查
        if remaining >= weight:
            total_value += value
            remaining -= weight
            counter.count += 1  # 成功放入计数
    return total_value

def dp_knapsack(items, capacity, counter):
    """动态规划操作计数版"""
    dp = [0] * (capacity + 1)
    for weight, value in items:
        counter.count += 1  # 外层循环计数
        for w in range(capacity, weight - 1, -1):
            counter.count += 3  # 内层循环+两次数组访问+比较操作
            dp[w] = max(dp[w], dp[w - weight] + value)
    return dp[capacity]

class Node:
    """分支限界节点结构"""
    def __init__(self, level, value, weight, bound):
        self.level = level
        self.value = value
        self.weight = weight
        self.bound = bound

    def __lt__(self, other):
        return self.bound > other.bound

def branch_bound_knapsack(items, capacity, counter):
    """分支限界操作计数版"""
    items = sorted(items, key=lambda x: x[1]/x[0], reverse=True)
    n = len(items)
    max_value = 0
    
    # 初始化上界计算
    bound = 0
    remaining = capacity
    for i in range(n):
        counter.count += 3  # 比较+计算+赋值
        if remaining >= items[i][0]:
            bound += items[i][1]
            remaining -= items[i][0]
        else:
            bound += remaining * (items[i][1]/items[i][0])
            break
    
    queue = []
    heapq.heappush(queue, Node(0, 0, 0, bound))
    counter.count += 2  # 堆操作+节点创建
    
    while queue:
        counter.count += 2  # 循环计数+堆弹出
        current = heapq.heappop(queue)
        
        if current.bound <= max_value:
            counter.count += 1  # 剪枝判断
            continue
            
        if current.level == n:
            counter.count += 1  # 最大值更新
            max_value = max(max_value, current.value)
            continue
            
        # 处理左子节点
        next_level = current.level + 1
        if next_level <= n:
            new_weight = current.weight + items[current.level][0]
            new_value = current.value + items[current.level][1]
            
            counter.count += 2  # 重量判断
            if new_weight <= capacity and new_value > max_value:
                max_value = new_value
                
            new_bound = new_value
            new_remaining = capacity - new_weight
            for i in range(next_level, n):
                counter.count += 3  # 循环+计算+比较
                if new_remaining >= items[i][0]:
                    new_bound += items[i][1]
                    new_remaining -= items[i][0]
                else:
                    new_bound += new_remaining * (items[i][1]/items[i][0])
                    break
                    
            if new_bound > max_value:
                heapq.heappush(queue, Node(next_level, new_value, new_weight, new_bound))
                counter.count += 2  # 堆操作+节点创建
        
        # 处理右子节点
        new_bound = current.value
        new_remaining = capacity - current.weight
        for i in range(current.level + 1, n):
            counter.count += 3  # 循环+计算+比较
            if new_remaining >= items[i][0]:
                new_bound += items[i][1]
                new_remaining -= items[i][0]
            else:
                new_bound += new_remaining * (items[i][1]/items[i][0])
                break
                
        if new_bound > max_value:
            heapq.heappush(queue, Node(next_level, current.value, current.weight, new_bound))
            counter.count += 2  # 堆操作+节点创建
    
    return max_value

# 测试参数
n_values = np.arange(5, 201, 10)
W = 20

# 存储操作次数
greedy_counts = []
dp_counts = []
bb_counts = []

# 性能测试
for n in n_values:
    items = [(np.random.randint(1, 10), np.random.randint(10, 100)) for _ in range(n)]
    
    # 贪心法
    counter = OperationCounter()
    greedy_knapsack(items, W, counter)
    greedy_counts.append(counter.count)
    
    # 动态规划
    counter = OperationCounter()
    dp_knapsack(items, W, counter)
    dp_counts.append(counter.count)
    
    # 分支限界
    counter = OperationCounter()
    branch_bound_knapsack(items, W, counter)
    bb_counts.append(counter.count)

# 可视化结果
plt.figure(figsize=(12, 6))
plt.plot(n_values, greedy_counts, 'g-o', label='贪心法')
plt.plot(n_values, dp_counts, 'b-s', label='动态规划')
plt.plot(n_values, bb_counts, 'r-^', label='分支限界')
plt.yscale('log')  # 使用对数坐标轴
plt.xlabel('物品数量 (n)')
plt.ylabel('操作次数（对数尺度）')
plt.title('0-1背包问题算法操作次数对比 (W=20)')
plt.legend()
plt.grid(True)
plt.show()
