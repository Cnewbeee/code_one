import networkx as nx
import matplotlib.pyplot as plt

# 添加中文字体配置
plt.rcParams['font.sans-serif'] = ['SimHei']  # Windows系统字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 创建产业网络
G = nx.Graph()
nodes = ["冰雪旅游", "装备制造", "物流", "电商", "培训"]
edges = [("冰雪旅游", "装备制造", 8),
        ("冰雪旅游", "物流", 5),
        ("装备制造", "物流", 3),
        ("物流", "电商", 2),
        ("电商", "培训", 1)]

G.add_nodes_from(nodes)
for u, v, w in edges:
    G.add_edge(u, v, weight=w)

# 可视化布局
pos = nx.spring_layout(G, seed=2023)
plt.figure(figsize=(10,8))

# 绘制节点
nx.draw_networkx_nodes(
    G, pos,
    node_size=3000,
    node_color=["#2B579A","#E81123","#FFB900","#00B294","#7FBA00"],
    edgecolors="black",  # 添加节点边框
    linewidths=2
)

# 绘制边（根据权重调整线宽）
edge_widths = [d['weight']*0.8 for (u,v,d) in G.edges(data=True)]
nx.draw_networkx_edges(
    G, pos,
    width=edge_widths,
    edge_color="gray",
    alpha=0.7
)

# 添加边权重标签
edge_labels = {(u, v): f"{d['weight']}" for u, v, d in G.edges(data=True)}
nx.draw_networkx_edge_labels(
    G, pos,
    edge_labels=edge_labels,
    font_size=10,
    font_color="#444444"
)

# 绘制节点标签
nx.draw_networkx_labels(
    G, pos,
    font_size=12,
    font_weight="bold"
)

plt.title("冰雪产业关联网络（线宽表示关联强度）", fontsize=14, pad=20)
plt.axis('off')
plt.savefig('network.png', dpi=300, bbox_inches='tight')
