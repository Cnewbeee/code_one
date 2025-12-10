#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // 优化输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    string s;
    cin >> s;

    // 收集非 'N' 的学生才艺类型
    // students[i] 存储的是重新编号后第 i+1 个学生的才艺
    vector<char> students; 
    for (char c : s) {
        if (c != 'N') {
            students.push_back(c);
        }
    }

    int k = students.size();
    
    // 如果没有学生参加，直接输出 NO (根据题意推断，或者不输出)
    // 题目说 n>=2，但没说剔除后 k>=1。假设 k=0 为 NO。
    if (k == 0) {
        cout << "NO" << endl;
        return 0;
    }

    // 初始化排列数组: 1, 2, ..., k
    vector<int> p(k);
    iota(p.begin(), p.end(), 1);

    vector<vector<int>> valid_permutations;

    // 生成全排列并检查
    do {
        bool ok = true;
        for (int i = 0; i < k - 1; ++i) {
            // p[i] 是当前排列中第 i 个位置的学生编号 (1-based)
            // p[i+1] 是下一个位置的学生编号
            // 对应的才艺类型在 students 数组中下标为 p[i]-1 和 p[i+1]-1
            if (students[p[i] - 1] == students[p[i+1] - 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            valid_permutations.push_back(p);
        }
    } while (next_permutation(p.begin(), p.end()));

    if (valid_permutations.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (const auto& perm : valid_permutations) {
            for (int i = 0; i < k; ++i) {
                cout << perm[i];
            }
            cout << endl;
        }
    }

    return 0;
}
