import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

# 初始化seaborn主题
sns.set_theme(style="whitegrid", font_scale=1.1)

# 数据读取配置
data = pd.read_csv(r'E:\VS Code\ADA\hanno\hanoi_data.csv',
                  header=0,
                  names=['n', 'recursive', 'iterative'],
                  dtype={'n': 'int16', 'recursive': 'int64', 'iterative': 'int64'},
                  encoding='utf-8')

# 创建单一对比图表
plt.figure(figsize=(12, 7))

# 绘制双算法曲线
plt.plot(data['n'], data['recursive'],
        label='Recursive Method',
        marker='D',  # 菱形标记
        markersize=8,
        color='#4B72B0',
        linewidth=2.5,
        alpha=0.9)

plt.plot(data['n'], data['iterative'],
        label='Iterative Method',
        marker='s',  # 方形标记
        markersize=7,
        color='#59A14F', 
        linewidth=2.5,
        alpha=0.9)

# 增强可视化配置
plt.title('Hanoi Tower Algorithm Comparison (n=1-20)', 
         fontsize=16,
         pad=20,
         fontweight='semibold')

plt.xlabel('Number of Disks (n)', 
          fontsize=13,
          labelpad=10)
plt.ylabel('Move Operations', 
          fontsize=13,
          labelpad=10)

# 配置网格和刻度
plt.grid(True, 
        alpha=0.25,
        linestyle='--')
plt.xticks(np.arange(0, 21, 2))
plt.yticks(np.arange(0, 1.1e6, 200000))

# 优化图例样式
legend = plt.legend(loc='upper left',
                   frameon=True,
                   shadow=True,
                   fancybox=True,
                   borderpad=1,
                   fontsize=12)
legend.get_frame().set_facecolor('#F5F5F5')

# 添加数据标注
for n in range(1, 21, 5):
    y_rec = data.loc[data['n'] == n, 'recursive'].values[0]
    y_iter = data.loc[data['n'] == n, 'iterative'].values[0]
    
    plt.text(n-0.8, y_rec*1.05, f'{y_rec:,}',
            fontsize=9,
            color='#4B72B0',
            rotation=25)
    
    plt.text(n+0.5, y_iter*0.95, f'{y_iter:,}',
            fontsize=9,
            color='#59A14F',
            rotation=-25)

# 保存优化配置
plt.savefig('hanoi_comparison.png',
           dpi=300,
           bbox_inches='tight',
           facecolor='white')

plt.show()
