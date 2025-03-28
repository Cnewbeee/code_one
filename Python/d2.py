import pandas as pd
import plotly.express as px
df = pd.DataFrame({
    '频率': ['低频','中频','高频'],
    '人数': [60,35,15],
    '消费': [800, 2000, 2000],
    '装备级别': ['基础','中级','高级']
})
fig = px.scatter_matrix(df, dimensions=['人数','消费','装备级别'],
                       color='频率', symbol='频率',
                       title="参与行为三维散点矩阵")
fig.write_html('3d_scatter.html')  # 生成交互式图表