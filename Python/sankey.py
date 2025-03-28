import seaborn as sns
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 指定微软雅黑字体[1][2]
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题[2]

data = [[85.5, 74.7],  # 北方认知度
        [60.0, 50.0]]   # 南方认知度

sns.heatmap(data, 
           annot=True, 
           fmt=".1f",
           xticklabels=["区域认知度","年龄认知度"],
           yticklabels=["北方","南方"],
           cmap="YlGnBu")
plt.savefig('heatmap.png', dpi=300)