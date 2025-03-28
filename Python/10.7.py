import pandas as pd
import plotly.express as px
import numpy as np  # 添加缺失的numpy导入

# 生成时间序列数据
date_rng = pd.date_range(start='2023-12-01', end='2024-03-01', freq='D')
data = {
    "日期": date_rng,
    "就业量": np.sin(np.linspace(0, 4*np.pi, len(date_rng)))*500 + 2000
}
df = pd.DataFrame(data)

# 创建动画图表
fig = px.line(
    df, 
    x="日期", 
    y="就业量", 
    title="冰雪就业季节波动",
    template="ggplot2",
    markers=True
)

fig.update_layout(
    xaxis=dict(rangeslider=dict(visible=True)),
    hovermode="x unified",
    font=dict(family="SimHei")
)

# 修正参数传递方式，添加参数名
fig.update_traces(line=dict(width=3, color="#E81123"))
fig.write_html("seasonal_animation.html")
