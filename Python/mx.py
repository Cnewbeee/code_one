from linearmodels import PanelOLS
import pandas as pd
import numpy as np
import statsmodels.api as sm
from mgwr.gwr import GWR
from mgwr.sel_bw import Sel_BW
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
import geopandas as gpd
import seaborn as sns 

y_var = '就业密度'
x_vars = ['基础设施指数', '政策强度', '游客增长率']
panel_vars = ['省份', '年份']

# 数据加载与预处理
def preprocess_data():
    """统一数据预处理"""
    data = pd.read_excel(r'E:\VS Code\Python\冰雪经济数据.xlsx', 
                    sheet_name='面板数据', 
                    engine='openpyxl')
    geo_data = gpd.read_file('省域行政边界.geojson')
    
    # 数据校验
    assert not data[panel_vars].duplicated().any(), "存在重复的面板数据"
    return data, geo_data


# 模块1：地理加权回归(GWR)
def spatial_gwr(data, geo_data):
    """优化后的空间异质性分析"""
    # 面板转横截面（示例取最新年份）
    cross_data = data[data.年份 == data.年份.max()].copy()
    
    # 空间坐标校验
    coords = list(zip(cross_data['经度'], cross_data['纬度']))
    assert len(coords) == len(geo_data), "地理数据不匹配"

    # 批量标准化
    scaler = StandardScaler()
    scaled = pd.DataFrame(scaler.fit_transform(cross_data[x_vars + [y_var]]),
                         columns=x_vars + [y_var])
    
    # 带宽优化（添加并行计算）
    bw_selector = Sel_BW(coords, scaled[y_var], scaled[x_vars],
                        kernel='gaussian', n_jobs=-1)
    bw = bw_selector.search(verbose=False)
    
    # 模型拟合
    model = GWR(coords, scaled[y_var], scaled[x_vars], bw=bw, kernel='gaussian')
    return model.fit()

#模块2：可视化模块
def plot_spatial_coef(results, geo_data, variables):
    """空间系数可视化"""
    fig, axes = plt.subplots(1, len(variables), figsize=(18,6))
    for ax, var in zip(axes, variables):
        geo_data[var+'_coef'] = results.params[:, x_vars.index(var)]  # 添加冒号分隔符
        geo_data.plot(column=var+'_coef', ax=ax, legend=True,
                     cmap='RdYlGn', legend_kwds={'shrink':0.5})
        ax.set_title(f'{var}空间变异系数')
    plt.tight_layout()
    return fig

# 模块3：面板回归模型
def panel_regression(data):
    """安全的面板回归"""
    # 使用数据副本
    panel_data = data.copy().set_index(panel_vars)
    
    # 添加时间趋势项
    panel_data['trend'] = panel_data.index.get_level_values('年份') - 
                        panel_data.index.get_level_values('年份').min()
    
    # 正确模型构建方式
    y = panel_data[y_var]
    X = sm.add_constant(panel_data[x_vars + ['trend']])
    
    model = PanelOLS(y, X, entity_effects=True, time_effects=True)
    return model.fit(cov_type='clustered', cluster_entity=True)

# 模块4：因子分析
def factor_analysis(data):
    """潜在变量提取"""
    from sklearn.decomposition import FactorAnalysis
    
    # 变量选择
    fa_vars = ['滑雪场密度', '酒店数量', '交通通达度', '政策文件数', '职业培训人次']
    
    # 因子数确定（移除不支持的rotation参数）
    fa = FactorAnalysis(n_components=3)
    factors = fa.fit_transform(data[fa_vars])
    
    # 因子载荷矩阵
    loadings = pd.DataFrame(fa.components_.T, 
                          columns=['资源禀赋', '产业协同', '人力资本'],
                          index=fa_vars)
    
    # 热力图展示
    plt.figure(figsize=(10,6))
    sns.heatmap(loadings, annot=True, cmap='coolwarm', center=0)
    plt.title('因子载荷矩阵')
    
    return factors

# 执行分析
if __name__ == '__main__':
    # 数据管道
    raw_data, geo_data = preprocess_data()
    
    # 空间分析
    gwr_model = spatial_gwr(raw_data, geo_data)
    plot_spatial_coef(gwr_model, geo_data.copy(), x_vars)
    
    # 面板分析
    print(panel_regression(raw_data).summary)
    
    # 因子分析
    factor_analysis(raw_data.copy())
