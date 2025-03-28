import folium
import numpy as np  # 添加的缺失库
from folium.plugins import HeatMapWithTime

# 生成哈尔滨时空数据
harbin_coords = [45.8, 126.53]
time_index = [f"2023-12-{d:02d}" for d in range(1,32)]  # 12月数据

# 模拟每日就业热点
data = [
    [[45.8 + np.random.uniform(-0.1,0.1), 
      126.53 + np.random.uniform(-0.1,0.1)] 
     for _ in range(200 + d*10)]  # 就业密度日增长
    for d in range(31)
]

# 创建动态地图
m = folium.Map(location=harbin_coords, zoom_start=11)
HeatMapWithTime(
    data,
    index=time_index,
    auto_play=True,
    radius=20,
    gradient={0.2: 'blue', 0.4: 'lime', 0.6: 'yellow', 0.8: 'red'}
).add_to(m)

m.save("heatmap_time.html")
