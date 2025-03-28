import matplotlib.pyplot as plt
import numpy as np

# 数据准备
stages = ["认知(110)", "兴趣(66)", "意愿(46)", "参与(37)"]
values = [110, 66, 46, 37]
loss_reasons = ["信息不全面(44)", "时间/预算限制(32)", "流程/交通问题(7)", ""]

# 创建画布
fig, ax = plt.subplots(figsize=(10,6))

# 绘制漏斗主体
bar_width = 0.6
positions = np.arange(len(stages))
colors = ['#2B579A', '#E81123', '#FFB900', '#00B294']

bars = ax.barh(positions, values, height=bar_width, color=colors, edgecolor='white')

# 添加流失标注
for i in range(len(stages)-1):
    loss = values[i] - values[i+1]
    ax.text(values[i+1]+5, i+0.3, 
            f"↓ 流失 {loss}人\n{loss_reasons[i]}", 
            va='top', fontsize=9,
            bbox=dict(facecolor='white', alpha=0.8), fontproperties='Microsoft YaHei')

# 坐标轴优化
ax.set_yticks(positions)
ax.set_yticklabels(stages, fontproperties='Microsoft YaHei')
ax.invert_yaxis()  # 倒置显示顺序
ax.xaxis.set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['bottom'].set_visible(False)

# 添加数据标签
for rect in bars:
    width = rect.get_width()
    ax.text(width/2, rect.get_y()+rect.get_height()/2,
            f'{width}人\n({width/110:.1%})', 
            ha='center', va='center', 
            color='white', fontsize=10, fontproperties='Microsoft YaHei')

plt.tight_layout()
plt.savefig('funnel_matplotlib.png', dpi=300, bbox_inches='tight')