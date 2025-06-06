import matplotlib.pyplot as plt
import random
import matplotlib

# --------------------- 关键修改：设置中文字体 ---------------------
# 方法1：使用系统字体（需确保系统中存在中文字体，如 SimHei、Microsoft YaHei 等）
plt.rcParams['font.sans-serif'] = ['SimHei']  # Windows 系统常用
# plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']  # macOS 系统常用
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 方法2：指定具体字体文件路径（适用于自定义字体）
# font_path = '/path/to/your/font.ttf'  # 例如 'C:/Windows/Fonts/simhei.ttf'
# font_prop = matplotlib.font_manager.FontProperties(fname=font_path)
# plt.rcParams['font.family'] = font_prop.get_name()
# -----------------------------------------------------------------

# 统计暴力算法的操作次数
def brute_force_operations(a, b):
    operations = 0
    a, b = abs(a), abs(b)
    if a == 0 or b == 0:
        return 0
    min_val = min(a, b)
    for i in range(min_val, 0, -1):
        operations += 1
        if a % i == 0 and b % i == 0:
            break
    return operations

# 统计欧几里得算法的操作次数
def euclid_operations(a, b):
    operations = 0
    a, b = abs(a), abs(b)
    while b != 0:
        operations += 1
        a, b = b, a % b
    return operations

# 生成测试数据（问题规模范围和对数间隔采样）
problem_sizes = [10, 50, 100, 500, 1000, 5000, 10000]
num_samples = 100  # 每个规模随机采样次数

# 存储平均操作次数
avg_brute_ops = []
avg_euclid_ops = []

for size in problem_sizes:
    brute_ops = 0
    euclid_ops = 0
    for _ in range(num_samples):
        a = random.randint(size//2, size)
        b = random.randint(size//2, size)
        brute_ops += brute_force_operations(a, b)
        euclid_ops += euclid_operations(a, b)
    avg_brute_ops.append(brute_ops / num_samples)
    avg_euclid_ops.append(euclid_ops / num_samples)

# 绘制对比图
plt.figure(figsize=(10, 6))
plt.plot(problem_sizes, avg_brute_ops, 'r-', label='暴力算法 (O(n))', marker='o')
plt.plot(problem_sizes, avg_euclid_ops, 'b--', label='欧几里得算法 (O(log n))', marker='s')

# 设置对数横轴
plt.xscale('log')
plt.yscale('log')

# 中文标签和标题
plt.xlabel('问题规模（a/b的最大值）', fontsize=12)
plt.ylabel('平均操作次数（对数刻度）', fontsize=12)
plt.title('时间复杂度对比：暴力算法 vs. 欧几里得算法', fontsize=14)
plt.legend()
plt.grid(True, which="both", linestyle='--')

# 保存图片
plt.savefig('gcd_complexity_comparison_zh.png', dpi=300, bbox_inches='tight')
plt.show()