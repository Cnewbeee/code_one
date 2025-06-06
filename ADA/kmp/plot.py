import pandas as pd
import matplotlib.pyplot as plt

# 读取数据，指定编码格式为UTF-16 LE（根据实际情况调整）
try:
    data = pd.read_csv(r'E:\VS Code\ADA\kmp\data.csv', header=None, sep='\t',
                      names=['n', 'kmp_pre', 'kmp_match', 'bf'],
                      encoding='utf-16-le')
except UnicodeDecodeError:
    data = pd.read_csv(r'E:\VS Code\ADA\kmp\data.csv', header=None, sep='\t',
                      names=['n', 'kmp_pre', 'kmp_match', 'bf'],
                      encoding='iso-8859-1')

# 计算KMP总操作次数
data['kmp_total'] = data['kmp_pre'] + data['kmp_match']

plt.figure(figsize=(12, 6))

# 绘制KMP曲线
plt.plot(data['n'], data['kmp_total'], 
        label='KMP Total Operations', 
        color='blue', 
        linestyle='-')

# 绘制BF曲线
plt.plot(data['n'], data['bf'], 
        label='BF Operations', 
        color='red', 
        linestyle='-')

# 设置图表属性
plt.yscale('linear')  # 默认设置，适合均匀分布数据
plt.title('Algorithm Complexity Comparison')
plt.xlabel('Pattern Length (n)')
plt.ylabel('Operations (log scale)')
plt.grid(True, which="both", ls="--")
plt.legend()

# 保存图像
plt.tight_layout()
plt.savefig('comparison.png', dpi=300)
plt.show()

