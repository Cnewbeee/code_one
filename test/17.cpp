#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> coords;
    coords.reserve(n);
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        if (x < 1500) coords.push_back(x);
    }
    int m = (int)coords.size();
    if (m == 0 || m <= k) {
        cout << 0 << '\n';
        return 0;
    }
    long long total = coords.back() - coords.front();
    vector<long long> gaps;
    gaps.reserve(m - 1);
    for (int i = 0; i + 1 < m; ++i) gaps.push_back(coords[i+1] - coords[i]);
    sort(gaps.begin(), gaps.end());
    long long sub = 0;
    for (int i = 0; i < k - 1; ++i) sub += gaps[i];
    cout << (total - sub) << '\n';
    return 0;
}
