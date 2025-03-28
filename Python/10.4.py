import plotly.graph_objects as go

# 模拟数据
label = ["冰雪旅游", "装备制造", "物流", "电商", "培训"]
source = [0, 0, 1, 2, 3]
target = [1, 2, 2, 3, 4]
value = [800, 500, 300, 200, 150]

fig = go.Figure(data=[go.Sankey(
    node=dict(
      pad=15,
      thickness=20,
      line=dict(color="black", width=0.5),
      label=label,
      color=["#2B579A", "#E81123", "#FFB900", "#00B294", "#7FBA00"]
    ),
    link=dict(
      source=source,
      target=target,
      value=value,
      color=["rgba(43,87,154,0.5)" for _ in value]
  ))])

fig.update_layout(
    title="冰雪产业就业流动分析",
    font=dict(size=14, family="SimHei"),
    plot_bgcolor='#F5F5F5'
)
fig.write_html("sankey.html")