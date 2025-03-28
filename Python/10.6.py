import plotly.express as px
import pandas as pd

# 创建数据帧 & 配置可视化参数
df = pd.DataFrame({
    "dimension": ["基础设施", "政策力度", "参与度", "数字化", "培训投入"],
    "impact_factor": [0.42, 0.35, 0.28, 0.19, 0.24]
})

# 可视化配置参数
VISUAL_CONFIG = {
    "color_sequence": ['#2B579A'],        # 主色系
    "fill_opacity": 0.25,                # 填充透明度
    "line_width": 2.5,                   # 轮廓线宽
    "grid_color": "#E0E0E0",             # 网格线颜色
    "angularaxis_rotation": 90,          # 起始角度（12点方向）
    "radialaxis_range": [0, 0.5],         # 径向轴范围
    "radialaxis_tickformat": ".0%",      # 显示百分比格式
}

# 创建雷达图
fig = px.line_polar(
    df,
    r='impact_factor',
    theta='dimension',
    line_close=True,
    color_discrete_sequence=VISUAL_CONFIG["color_sequence"],
    template="plotly_white"
)

# 图形样式调整
fig.update_traces(
    fill='toself',
    line=dict(width=VISUAL_CONFIG["line_width"]),
    fillcolor=VISUAL_CONFIG["color_sequence"][0] + hex(int(255*VISUAL_CONFIG["fill_opacity"]))[2:].zfill(2)
)

# 布局配置
fig.update_layout(
    polar=dict(
        radialaxis=dict(
            gridcolor=VISUAL_CONFIG["grid_color"],
            range=VISUAL_CONFIG["radialaxis_range"],
            tickformat=VISUAL_CONFIG["radialaxis_tickformat"]
        ),
        angularaxis=dict(
            rotation=VISUAL_CONFIG["angularaxis_rotation"],
            direction="counterclockwise"
        )
    ),
    font=dict(
        family="SimHei",
        size=12
    ),
    title=dict(
        text="政策影响因子分析雷达图",
        x=0.5,
        font=dict(size=18, color="#333")
    ),
    margin=dict(t=60, b=30),
    showlegend=False
)

fig.show()
