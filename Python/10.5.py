import geopandas as gpd
import matplotlib.pyplot as plt
from pyproj import CRS
from shapely.geometry import Point
import os

# ====================
# 可视化配置参数
# ====================
CONFIG = {
    "map_style": {
        "base_color": "#F0F0F0",
        "border_color": "#999999",
        "border_width": 0.8,
        "figsize": (16, 12)
    },
    "employment_style": {
        "indirect": {
            "color": "#2B579A",  # 深蓝色系
            "alpha": 0.3,
            "size_factor": 1/280  # 间接就业规模系数
        },
        "direct": {
            "color": "#E81123",   # 品牌红色
            "alpha": 0.85,
            "size_factor": 1/145, # 直接就业规模系数
            "edge_color": "white",
            "edge_width": 0.8
        }
    },
    "annotation": {
        "text_offset": 0.08,      # 标注水平偏移量
        "fontsize": 9.5,
        "text_color": "#333333",
        "line_spacing": 1.2       # 行距倍数
    },
    "output": {
        "dpi": 600,
        "facecolor": "white"
    }
}

# ====================
# 初始化设置
# ====================
# 配置中文字体（适配多平台）
plt.rcParams.update({
    'font.sans-serif': ['SimHei', 'Microsoft YaHei', 'Heiti SC'],
    'axes.unicode_minus': False,
    'figure.autolayout': True  # 自动调整布局
})

# ====================
# 数据准备
# ====================
def load_geodata(url):
    """加载地理数据并转换坐标系"""
    try:
        gdf = gpd.read_file(url)
        return gdf.to_crs(CRS("EPSG:4326"))  # 确保WGS84坐标系
    except Exception as e:
        raise RuntimeError(f"地理数据加载失败: {str(e)}")

# 2024年冰雪经济就业数据（单位：人）
employment_data = {
    "城市": ["哈尔滨市", "齐齐哈尔市", "牡丹江市", "佳木斯市", "大庆市", "伊春市"],
    "直接就业": [21800, 6350, 4820, 3870, 2950, 1620],
    "间接就业": [39240, 11430, 8676, 6966, 5310, 2916],
    "经度": [126.53, 123.97, 129.62, 130.32, 125.03, 128.90],
    "纬度": [45.80, 47.34, 44.58, 46.80, 46.58, 47.73]
}

# ====================
# 可视化逻辑
# ====================
def create_base_map(gdf):
    """创建基础地图底图"""
    return gdf.plot(
        color=CONFIG["map_style"]["base_color"],
        edgecolor=CONFIG["map_style"]["border_color"],
        linewidth=CONFIG["map_style"]["border_width"],
        figsize=CONFIG["map_style"]["figsize"]
    )

# 修改后的关键部分（保持全中文变量名）

def add_employment_layer(ax, gdf, emp_type_zh):
    """统一使用中文参数配置"""
    style_config = {
        "直接": {
            "color": "#E81123",
            "size_factor": 1/150,  # 原代码的1/150会导致标记过大
            "alpha": 0.8,
            "edge": "white"
        },
        "间接": {
            "color": "#2B579A",
            "size_factor": 1/800,  # 调整为更合理的缩放比例
            "alpha": 0.4,
            "edge": "none"
        }
    }
    
    config = style_config[emp_type_zh]
    gdf.plot(
        ax=ax,
        markersize=gdf[f"{emp_type_zh}就业"] * config["size_factor"],
        color=config["color"],
        alpha=config["alpha"],
        edgecolor=config["edge"],
        linewidth=0.5,
        label=f'{emp_type_zh}就业'
    )



def add_annotations(ax, gdf):
    """添加城市标注"""
    for _, row in gdf.iterrows():
        ax.text(
            x=row.geometry.x + CONFIG["annotation"]["text_offset"],
            y=row.geometry.y,
            # 添加间接就业数据展示
            s=f"{row['城市']}\n直接：{row['直接就业']}人\n间接：{row['间接就业']}人",
            fontsize=CONFIG["annotation"]["fontsize"],
            color=CONFIG["annotation"]["text_color"],
            ha='left',
            va='center',
            linespacing=CONFIG["annotation"]["line_spacing"]
        )


# ====================
# 执行可视化流程
# ====================
try:
    # 加载地理数据
    heilongjiang = load_geodata('https://geo.datav.aliyun.com/areas_v3/bound/230000_full.json')
    
    # 创建地理数据框架
    gdf = gpd.GeoDataFrame(
        employment_data,
        geometry=[Point(xy) for xy in zip(employment_data["经度"], employment_data["纬度"])]
    )
    
    # 初始化画布
    base_map = create_base_map(heilongjiang)
    
    # 分层添加就业数据
    add_employment_layer(base_map, gdf, "间接")
    add_employment_layer(base_map, gdf, "直接")
    
    # 添加标注
    add_annotations(base_map, gdf)
    
    # 添加图例和标题
    plt.title('2024年黑龙江省冰雪经济就业分布热力图', 
             fontsize=16, pad=18, color='#2A2A2A')
    plt.legend(title='就业类型', 
              frameon=False, 
              labelspacing=1.5,
              handletextpad=2)
    
    # 保存结果
    output_path = "./黑龙江冰雪就业分布_2024.png"
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    plt.savefig(output_path, 
               dpi=CONFIG["output"]["dpi"], 
               bbox_inches='tight',
               facecolor=CONFIG["output"]["facecolor"])
    
    print(f"可视化结果已保存至：{output_path}")

except Exception as e:
    print(f"程序执行异常: {str(e)}")
    exit(1)
