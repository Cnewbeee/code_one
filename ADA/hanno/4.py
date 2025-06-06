import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

n_values = np.arange(1, 11)  # n=2^1到2^10

operations = n_values ** 2    # O(n²)

plt.figure(figsize=(8, 5))
plt.plot(n_values, operations, 'o-', color='red')
plt.title('棋盘覆盖算法时间复杂度趋势 (O(n^2))', fontsize=14)
plt.xlabel('棋盘边长 n (2^k)', fontsize=12)
plt.ylabel('操作次数', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.show()
