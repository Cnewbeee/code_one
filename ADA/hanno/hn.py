import matplotlib.pyplot as plt
import numpy as np

# 配置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定默认字体为黑体
plt.rcParams['axes.unicode_minus'] = False    # 解决保存图像时负号'-'显示为方块的问题

def hanoi_moves(n):
    """计算汉诺塔问题移动n个圆盘所需的最少次数（公式法）"""
    return (2 ** n) - 1  # 根据递推公式T(n)=2^n - 1

def main():
    # 生成数据：圆盘数量范围（1到15）
    n_values = np.arange(1, 16)  # n=1到15
    moves = [hanoi_moves(n) for n in n_values]
    
    # 理论时间复杂度曲线（2^n）
    theoretical = 2 ** n_values
    
    # 配置可视化图表
    plt.figure(figsize=(10, 6))
    plt.plot(n_values, moves, 'o-', color='blue', label='实际移动次数 (2^n - 1)')
    plt.plot(n_values, theoretical, '--', color='red', label='理论时间复杂度 (2^n)')
    
    # 设置图表属性
    plt.title('汉诺塔问题：圆盘数量与时间复杂度关系', fontsize=14)
    plt.xlabel('圆盘数量 (n)', fontsize=12)
    plt.ylabel('移动次数', fontsize=12)
    plt.xticks(n_values)  # 显示所有整数n值
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.legend()
    
    # 添加对数坐标对比（右侧Y轴）
    ax = plt.gca()
    ax2 = ax.twinx()
    ax2.plot(n_values, np.log2(moves), 's-', color='green', label='log2(移动次数)')
    ax2.set_ylabel('log2(移动次数)', fontsize=12, color='green')
    ax2.tick_params(axis='y', colors='green')
    ax2.legend(loc='upper right')
    
    # 显示图表
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    main()
    