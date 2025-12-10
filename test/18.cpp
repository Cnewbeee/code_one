#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x <= 150) v.push_back(x);
    }
    int m = (int)v.size();
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int up = 1, down = 1;
    for (int i = 1; i < m; ++i) {
        if (v[i] > v[i-1]) up = down + 1;
        else if (v[i] < v[i-1]) down = up + 1;
    }
    cout << max(up, down) << '\n';
    return 0;
}
