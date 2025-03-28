import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # Windows系统
# plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']  # Mac系统
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 载荷矩阵
loadings = np.array([
    [0.87, 0.15, 0.03],  # 滑雪场密度
    [0.12, 0.93, 0.11],  # 配套企业
    [0.05, 0.08, 0.89]   # 职业资格
])

plt.figure(figsize=(10,6))
ax = sns.heatmap(loadings, 
                annot=True, 
                cmap="YlGnBu",
                yticklabels=["资源禀赋","产业协同","人力资本"],
                xticklabels=["滑雪场密度","配套企业数","持证率"])

# 添加方差贡献
# 调整后的方差贡献标注
ax.text(3.1, 1.5, "方差贡献率", 
        rotation=90, 
        verticalalignment='center',
        fontsize=12,
        fontfamily='SimHei')

# 调整百分比标注位置 (x坐标统一为3.5，y对应各因子中心位置)
ax.text(3.5, 0.5, "32%", ha='center', va='center')  # 第一行中心
ax.text(3.5, 1.5, "25%", ha='center', va='center')  # 第二行中心
ax.text(3.5, 2.5, "18%", ha='center', va='center')  # 第三行中心


# 调整布局并保存
plt.tight_layout()
plt.savefig('因子分析热力图', dpi=300, bbox_inches='tight')  # 保存为高清图片
plt.show()
