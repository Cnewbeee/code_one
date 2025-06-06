#include <bits/stdc++.h>  // 包含所有标准库头文件
#define int long long      // 将int统一为long long防止溢出

using namespace std;

const int INF = 1e18;     // 定义极大值常量

// 二进制位反转函数
int fan(int num) {
    if (num == 0) return 0;  // 特判0的情况
    uint64_t num_unsigned = num;
    // 计算有效二进制位数（64位系统下）
    int w = 64 - __builtin_clzll(num_unsigned); 
    int res = 0;
    // 逐位镜像翻转（从最高位到最低位）
    for (int i = w-1; i >= 0; --i)
        if ((num >> i) & 1)  // 如果当前位是1
            res += 1LL << (w-1 - i);  // 在镜像位置设置1
    return res;
}

signed main() {
    // 输入输出优化（禁用同步，解除绑定）
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读取输入数据
    int n, m;
    cin >> n >> m;
    
    // 初始化原始数组并计算原始总和
    vector<int> a(n);
    int sum_orig = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_orig += a[i];
    }
    
    // 计算每个元素的翻转增益（翻转后值 - 原值）
    vector<int> d(n);
    for (int i = 0; i < n; ++i) 
        d[i] = fan(a[i]) - a[i];
    
    // 动态规划数组初始化（使用滚动数组优化空间）
    vector<int> dp(m+1, -INF);  // dp[j]: 选j段的最大增益
    vector<int> last(m+1, -INF); // last[j]: 最后一段以当前元素结尾的最大增益
    dp[0] = 0;  // 初始状态：选0段的增益为0
    
    // 核心动态规划过程（逆序更新防止状态覆盖）
    for (int num : d) {
        for (int j = m; j >= 1; --j) {
            // 两种状态转移选项：
            int option1 = last[j] != -INF ? last[j] + num : -INF; // 延续当前区间
            int option2 = dp[j-1] != -INF ? dp[j-1] + num : -INF; // 创建新区间
            last[j] = max(option1, option2);  // 更新当前段状态
            dp[j] = max(dp[j], last[j]);      // 更新全局最优解
        }
    }
    
    // 计算最大有效增益（非负值）
    int max_gain = 0;
    for (int j = 1; j <= m; ++j)
        if (dp[j] > max_gain)
            max_gain = dp[j];
    
    // 最终输出结果（原始总和 + 最大增益）
    cout << sum_orig + max(max_gain, 0LL) << endl;
}
