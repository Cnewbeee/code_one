#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    int k; cin >> k;
    vector<int> b = a;
    if (k > 0) {
        for (int i = 0; i + k <= N; i += k) {
            int last = a[i + k - 1];
            for (int j = k - 1; j >= 1; --j) b[i + j] = a[i + j - 1];
            b[i] = last;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << b[i];
    }
    cout << '\n';
    return 0;
}
