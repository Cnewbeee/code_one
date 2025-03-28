# 环境配置（如需）
# !pip install pandas seaborn matplotlib numpy

import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib import font_manager

# 中文显示配置（Windows系统示例）
plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置中文字体
plt.rcParams['axes.unicode_minus'] = False    # 解决负号显示问题

# 生成模拟数据（替换为真实数据）
np.random.seed(2023)

# 构建数据框结构
age_groups = ['18-25岁', '26-35岁', '36-45岁', '46-55岁', '56岁以上']
positions = ['专业技术岗', '景区服务岗', '装备制造岗']

# 按比例生成各岗位人数（专业技术35%，景区服务45%，装备制造20%）
data = []
for age in age_groups:
    data.extend([
        [age, positions[0], int(7000 * np.random.uniform(0.8, 1.2))],  # 专业技术岗
        [age, positions[1], int(9000 * np.random.uniform(0.85, 1.15))], # 景区服务岗
        [age, positions[2], int(4000 * np.random.uniform(0.75, 1.25))]  # 装备制造岗
    ])

df = pd.DataFrame(data, columns=['年龄组', '岗位类型', '人数'])

# 数据透视处理
pivot_df = pd.pivot_table(df, 
                         values='人数',
                         index='年龄组',
                         columns='岗位类型',
                         aggfunc=np.sum)

# 蜂窝聚类热力图
plt.figure(figsize=(12, 8))

# 生成聚类热图对象
cluster_grid = sns.clustermap(
    pivot_df, 
    cmap="YlGnBu",          # 颜色映射
    dendrogram_ratio=0.2,   # 树状图宽度占比
    figsize=(10, 6),        # 画布尺寸
    linewidths=0.5,         # 单元格边线宽度
    annot=True,             # 显示数值
    fmt="d",               # 整数格式
    annot_kws={'size':10}, # 标注字体设置
    cbar_pos=(0.1, 0.32, 0.03, 0.2)  # 颜色条位置调整
)

# 标题和标签设置
plt.suptitle('冰雪经济就业年龄-岗位聚类分析', 
             y=1.02, 
             fontsize=14,
             fontweight='bold')

# 调整树状图样式
cluster_grid.ax_row_dendrogram.set_facecolor('#F5F5F5')  # 行聚类树背景色
cluster_grid.ax_col_dendrogram.set_facecolor('#F5F5F5') # 列聚类树背景色

# 旋转X轴标签
cluster_grid.ax_heatmap.set_xticklabels(
    cluster_grid.ax_heatmap.get_xmajorticklabels(), 
    rotation=45,
    ha='right'
)

# 保存高清图像
output_path = "./冰雪就业聚类热图.png"
cluster_grid.savefig(output_path, 
                    dpi=300, 
                    bbox_inches='tight')

print(f"可视化结果已保存至：{output_path}")