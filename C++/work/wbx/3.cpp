#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 优化输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        // 题目要求忽略能量超过 600 (含) 的节点
        // 根据样例 1 说明，忽略意味着将其从序列中剔除，剩余元素组成新的连续序列
        if (val < 600) {
            a.push_back(val);
        }
    }

    int m = a.size();
    int max_len = 0;

    // 数据范围 N <= 100，可以使用 O(N^2) 的暴力枚举
    // 枚举所有可能的子区间 [i, j]
    for (int i = 0; i < m; ++i) {
        int current_min = a[i];
        int current_max = a[i];
        // 题目要求区间至少包含两个节点，所以 j 从 i + 1 开始
        for (int j = i + 1; j < m; ++j) {
            current_min = min(current_min, a[j]);
            current_max = max(current_max, a[j]);

            // 检查极差是否满足阈值 K
            if (current_max - current_min <= k) {
                max_len = max(max_len, j - i + 1);
            } else {
                // 剪枝优化：
                // 如果当前区间 [i, j] 的极差已经超过 k，
                // 那么继续向右扩展 [i, j+1...] 只会让极差变大或不变（min更小或max更大），
                // 不可能再满足条件，所以可以直接跳出内层循环
                break; 
            }
        }
    }

    if (max_len >= 2) {
        cout << "YES" << endl;
        cout << max_len << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
