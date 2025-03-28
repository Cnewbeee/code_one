import seaborn as sns
import matplotlib.pyplot as plt

# 设置全局中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 使用微软雅黑
plt.rcParams['axes.unicode_minus'] = False  # 修复负号显示

# ... [原有数据准备代码] ...
industries = ['餐饮', '住宿', '交通', '文创', '装备制造', '培训']
scores = [
    [8.2, 7.9, 7.5, 3.8, 6.0, 5.5],  # 冰雪旅游
    [6.5, 6.8, 6.2, 4.5, 7.2, 6.9]   # 冰雪运动
]
# 创建热力图
fig, ax = plt.subplots(figsize=(10,6))
sns.heatmap(scores, 
            annot=True,
            fmt=".1f",
            cmap="YlGnBu",
            linewidths=.5,
            xticklabels=industries,
            yticklabels=['冰雪旅游', '冰雪运动'])

# 增强标注（不再需要单独设置fontproperties）
ax.text(2.5, 0.2, '高协同区', ha='center', va='center', fontsize=12, color='white')
ax.text(3.5, 0.2, '低协同区', ha='center', va='center', fontsize=12, color='black')

plt.title("产业协同度评估矩阵", pad=20)
plt.savefig('heatmap.png', dpi=300, bbox_inches='tight')
