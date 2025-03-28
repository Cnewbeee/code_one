#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1e5 + 10;

struct Node {
    int l, r, cnt;
} hjt[N * 20];
int cnt, root[N];

int p[N];
int n, m;

void build(int &now, int l, int r) {
    now = ++cnt;
    hjt[now].cnt = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(hjt[now].l, l, mid);
    build(hjt[now].r, mid+1, r);
}

void insert(int pre, int &now, int l, int r, int x) {
    hjt[now = ++cnt] = hjt[pre];
    hjt[now].cnt++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid) insert(hjt[pre].l, hjt[now].l, l, mid, x);
    else insert(hjt[pre].r, hjt[now].r, mid+1, r, x);
}

int query(int u, int v, int l, int r, int x) {
    if (l >= x) return 0;
    if (r < x) return hjt[u].cnt - hjt[v].cnt;
    int mid = (l + r) >> 1;
    return query(hjt[u].l, hjt[v].l, l, mid, x) + query(hjt[u].r, hjt[v].r, mid+1, r, x);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    // 初始化主席树
    cnt = 0;
    build(root[0], 1, n);
    for (int i = 1; i <= n; ++i) {
        insert(root[i-1], root[i], 1, n, p[i]);
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        if (c < l || c > r) {
            cout << c << endl;
            continue;
        }
        int x = p[c];
        int k = query(root[r], root[l-1], 1, n, x);
        cout << l + k << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}