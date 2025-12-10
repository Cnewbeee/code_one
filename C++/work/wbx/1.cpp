#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    // 优化输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    if (!(cin >> n >> s)) return 0;

    // dp[j] 表示获得至少 j 点声望所需的最小花费
    // 因为目标是至少 S，所以超过 S 的部分都归约为 S
    vector<long long> dp(s + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        int cost, base_val, bonus;
        cin >> cost >> base_val >> bonus;

        // 价格超过 5000 (含) 为假货，不能购买
        if (cost >= 5000) continue;

        int w1 = base_val + bonus; // 第一次购买获得的声望
        int w2 = base_val;         // 后续购买获得的声望

        // 阶段 1: 第一次购买 (0/1 背包)
        // 必须倒序遍历，防止在同一次购买机会中多次使用
        for (int j = s; j >= 0; --j) {
            if (dp[j] == INF) continue;
            int next_rep = min(s, j + w1);
            dp[next_rep] = min(dp[next_rep], dp[j] + cost);
        }

        // 阶段 2: 后续购买 (完全背包)
        // 正序遍历，允许购买多次
        // 只有当基础声望 > 0 时才有意义，否则只会增加花费不增加声望
        if (w2 > 0) {
            for (int j = 0; j <= s; ++j) {
                if (dp[j] == INF) continue;
                int next_rep = min(s, j + w2);
                dp[next_rep] = min(dp[next_rep], dp[j] + cost);
            }
        }
    }

    if (dp[s] == INF) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dp[s] << endl;
    }

    return 0;
}
