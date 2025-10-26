import numpy as np
import timeit
import matplotlib.pyplot as plt
import random

# 图形显示配置
plt.rcParams['font.sans-serif'] = ['SimHei']  # 中文显示支持
plt.rcParams['axes.unicode_minus'] = False    # 负号显示修正

def 暴力法求解最大子数组(数组):
    """
    时间复杂度 O(n²) 的暴力解法
    参数：包含整数的列表
    返回：最大子数组和
    """
    数组长度 = len(数组)
    最大和 = float('-inf')  # 初始化为负无穷
    
    for 起始位置 in range(数组长度):
        当前子数组和 = 0
        for 结束位置 in range(起始位置, 数组长度):
            当前子数组和 += 数组[结束位置]
            if 当前子数组和 > 最大和:
                最大和 = 当前子数组和
    return 最大和

def 动态规划法求解最大子数组(数组):
    """
    时间复杂度 O(n) 的动态规划解法(Kadane算法)
    参数：包含整数的列表
    返回：最大子数组和
    """
    if not 数组:
        return 0
    
    当前连续和 = 最大和 = 数组[0]
    for 数字 in 数组[1:]:
        当前连续和 = max(数字, 当前连续和 + 数字)  # 关键递推关系
        最大和 = max(最大和, 当前连续和)
    return 最大和

if __name__ == "__main__":
    # 实验参数配置
    随机种子 = 42
    测试规模范围 = np.arange(10, 1001, 50)  # 从10到1000，步长50
    重复测试次数 = 10      # 暴力法测试次数（因其计算较慢）
    高效算法测试次数 = 1000  # 动态规划法测试次数
    
    random.seed(随机种子)
    暴力法耗时记录 = []
    动态规划法耗时记录 = []

    # 执行耗时测试
    for 当前规模 in 测试规模范围:
        测试数组 = [random.randint(-100, 100) for _ in range(当前规模)]
        
        # 暴力法计时（减少测试次数以保证合理耗时）
        暴力法耗时 = timeit.timeit(
            lambda: 暴力法求解最大子数组(测试数组), 
            number=重复测试次数
        )
        暴力法耗时记录.append(暴力法耗时)
        
        # 动态规划法计时（增加测试次数以提高准确性）
        动态规划耗时 = timeit.timeit(
            lambda: 动态规划法求解最大子数组(测试数组),
            number=高效算法测试次数
        )
        动态规划法耗时记录.append(动态规划耗时)

    # 可视化结果配置
    图表尺寸 = (12, 6)
    图表分辨率 = 100
    曲线样式配置 = {
        'linewidth': 2,
        'markersize': 6,
        'markerfacecolor': 'white'
    }

    plt.figure(figsize=图表尺寸, dpi=图表分辨率)
    
    # 绘制耗时曲线
    plt.plot(
        测试规模范围, 暴力法耗时记录, 
        'r-o', 
        label='暴力解法 (O(n^2))', 
        **曲线样式配置
    )
    plt.plot(
        测试规模范围, 动态规划法耗时记录, 
        'b-s', 
        label='动态规划 (O(n))', 
        **曲线样式配置
    )

    

    # 图表装饰元素
    plt.grid(
    True, 
    linestyle='--', 
    linewidth=0.4,  # 调整线宽
    alpha=0.5,       # 降低透明度
    color='gray'     # 统一颜色
)
    plt.title('最大子数组和算法性能对比', fontsize=14)
    plt.xlabel('输入数据规模（元素个数）', fontsize=12)
    plt.ylabel('平均执行耗时（秒）', fontsize=12)
    plt.legend(loc='upper left')
    plt.tight_layout()
    
    # 显示可视化结果
    plt.show()
