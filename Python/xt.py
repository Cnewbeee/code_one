import matplotlib.pyplot as plt

# 设置全局中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

# 数据准备...
# 后续代码保持不变


# 数据准备
factors = {
    '驱动力': [('政策支持',65), ('市场需求',75), ('技术创新',40)],
    '阻力': [('文创薄弱',25), ('装备依赖',33), ('培训问题',33), ('标准缺失',44), ('机制问题',35)]
}

# 创建力场图
fig, ax = plt.subplots(figsize=(12,6))

# 生成不同的Y轴坐标
y_drive = range(len(factors['驱动力']))      # [0,1,2]
y_resist = range(len(factors['阻力']))       # [0,1,2,3,4]

# 绘制驱动力（修改点1）
ax.barh(y_drive, 
        [x[1] for x in factors['驱动力']],
        color='#2B579A', 
        label='驱动力')
# 绘制驱动力条形图后
for i, (name, value) in enumerate(factors['驱动力']):
    ax.text(value + 2, i, 
            f'{name}\n{value}人', 
            va='center', ha='left',
            color='#2B579A', fontsize=10)

# 绘制阻力（修改点2）
ax.barh(y_resist,
        [-x[1] for x in factors['阻力']],
        color='#E81123',
        label='阻力')

# 绘制阻力条形图后         
for i, (name, value) in enumerate(factors['阻力']):
    ax.text(-value - 2, i, 
            f'{name}\n{value}人',
            va='center', ha='right',
            color='#E81123', fontsize=10)

# 标注策略关联（修改点3）
strategy_links = [
    (0, 'S1'), (1, 'S2'), (2, 'S3'), 
    (3, 'S4'), (4, 'S5')
]
for pos, strat in strategy_links:
    # 分别处理驱动力和阻力
    if pos < len(factors['驱动力']):
        ax.text(50, pos, 
                f'{strat}\n{factors["驱动力"][pos][0]}', 
                va='center', ha='center', color='white')
    if pos < len(factors['阻力']):
        ax.text(-50, pos, 
                f'{strat}\n{factors["阻力"][pos][0]}', 
                va='center', ha='center', color='white')

plt.legend()
plt.savefig('force_analysis.png', dpi=300)
