import plotly.graph_objects as go
import pandas as pd
import numpy as np

# 扩展数据集
locations = [
    {"city":"哈尔滨", "lat":45.8, "lon":126.53, "density":1.2, "direct":21800, "gdp_ratio":0.18},
    {"city":"齐齐哈尔", "lat":47.34, "lon":123.97, "density":0.8, "direct":6350, "gdp_ratio":0.12},
    {"city":"牡丹江", "lat":44.58, "lon":129.62, "density":0.6, "direct":4820, "gdp_ratio":0.09},
    {"city":"崇礼", "lat":40.97, "lon":115.28, "density":1.1, "direct":9200, "gdp_ratio":0.21},
    {"city":"安吉", "lat":30.68, "lon":119.68, "density":0.3, "direct":3200, "gdp_ratio":0.05},
    {"city":"成都", "lat":30.57, "lon":104.07, "density":0.4, "direct":4500, "gdp_ratio":0.07},
    {"city":"广州", "lat":23.13, "lon":113.26, "density":0.2, "direct":2800, "gdp_ratio":0.03},
    {"city":"三亚", "lat":18.25, "lon":109.50, "density":0.1, "direct":1500, "gdp_ratio":0.02}
]

df = pd.DataFrame(locations)

# 动态参数计算
size = np.power(df['direct'], 0.6) * 0.8  # 非线性缩放
color_range = [df['gdp_ratio'].min(), df['gdp_ratio'].max()]  # 动态色阶范围

# 创建可视化对象
fig = go.Figure()

# 主散点图
fig.add_trace(go.Scatter3d(
    x=df['lon'],
    y=df['lat'],
    z=df['density'],
    mode='markers+text',
    text=df['city'],
    textposition='top center',
    textfont=dict(size=14, color='darkblue'),
    
    marker=dict(
        size=size,
        color=df['gdp_ratio'],
        colorscale='Viridis',  # 高对比度色阶
        cmin=color_range[0],
        cmax=color_range[1],
        colorbar=dict(
            title=dict(text="GDP占比", font=dict(size=16)),
            x=0.82,
            len=0.6
        ),
        opacity=0.9,
        sizemode='diameter',
        sizeref=np.max(size)/50,
        line=dict(color='gray', width=1)
    )
))

# 坐标轴增强配置
axis_config = dict(
    showbackground=True,
    backgroundcolor="rgba(240,240,240,0.9)",
    gridcolor="white",
    zerolinecolor="gray",
    title_font=dict(size=14, color='black'),
    tickfont=dict(size=12, color='darkgray')
)

# 布局优化
lon_buffer = (df['lon'].max() - df['lon'].min()) * 0.15
lat_buffer = (df['lat'].max() - df['lat'].min()) * 0.15

fig.update_layout(
    scene=dict(
        xaxis=dict(axis_config, title='经度', range=[df['lon'].min()-lon_buffer, df['lon'].max()+lon_buffer]),
        yaxis=dict(axis_config, title='纬度', range=[df['lat'].min()-lat_buffer, df['lat'].max()+lat_buffer]),
        zaxis=dict(axis_config, title='就业密度 (人/km²)', range=[0,1.5]),
        camera=dict(
            eye=dict(x=1.2, y=-1.5, z=0.6),
            up=dict(x=0, y=0, z=1)
        )
    ),
    scene_aspectmode='manual',
    scene_aspectratio=dict(x=1.5, y=2, z=0.8),
    
    title=dict(
        text='<b>冰雪经济就业地理分布三维可视化</b>',
        x=0.5,
        y=0.95,
        font=dict(size=24, family="SimHei", color='#2A2A2A')
    ),
    margin=dict(l=0, r=0, b=0, t=100),
    paper_bgcolor='white'
)

# 添加坐标参考线
for axis in ['x','y','z']:
    fig.update_layout(scene={f'{axis}axis': dict(showspikes=True, spikecolor="gray", spikethickness=1)})

# 保存为HTML文件
fig.write_html("3d_visualization.html")

fig.show()