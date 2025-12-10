#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000005;
const int LOGN = 21;

vector<int> adj[MAXN];
int depth[MAXN];
int first[MAXN];
int euler[MAXN * 2];
int st[MAXN * 2][LOGN];
int logs[MAXN * 2];
int idx = 0;
int n, q;

// DFS for Euler Tour and Depth
void dfs(int u, int p, int d) {
    depth[u] = d;
    euler[++idx] = u;
    first[u] = idx;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            euler[++idx] = u;
        }
    }
}

// Build Sparse Table for RMQ
void build_st() {
    logs[1] = 0;
    for (int i = 2; i <= idx; i++)
        logs[i] = logs[i/2] + 1;

    for (int i = 1; i <= idx; i++) {
        st[i][0] = euler[i];
    }
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i + (1 << j) - 1 <= idx; i++) {
            int u = st[i][j - 1];
            int v = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = (depth[u] < depth[v]) ? u : v;
        }
    }
}

// O(1) LCA Query
int get_lca(int u, int v) {
    int L = first[u];
    int R = first[v];
    if (L > R) swap(L, R);
    int j = logs[R - L + 1];
    int x = st[L][j];
    int y = st[R - (1 << j) + 1][j];
    return (depth[x] < depth[y]) ? x : y;
}

int get_dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
}

// Check if w is on path u-v
bool on_path(int u, int v, int w) {
    return get_dist(u, v) == get_dist(u, w) + get_dist(w, v);
}

struct Node {
    int u, v;
    bool ok;
    bool empty;
};

Node merge(const Node& l, const Node& r) {
    if (l.empty) return r;
    if (r.empty) return l;
    if (!l.ok || !r.ok) return {0, 0, false, false};

    // Candidates for endpoints
    int p[4] = {l.u, l.v, r.u, r.v};
    
    // Try all pairs as new endpoints
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int u = p[i], v = p[j];
            bool possible = true;
            // Check if all 4 points are on path u-v
            // Optimization: We only need to check the points that are NOT u or v
            for (int k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                if (!on_path(u, v, p[k])) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                return {u, v, true, false};
            }
        }
    }
    
    return {0, 0, false, false};
}

Node tree[MAXN * 4];

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = {val, val, true, false};
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(node * 2, start, mid, idx, val);
    else update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return {0, 0, true, true};
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return merge(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);
    build_st();

    int head = 1;
    int tail = 0;
    
    // The segment tree will store the elements added to the queue.
    // Since q operations can add at most q elements, size q is enough.
    // However, the problem says q operations, some are type 2 or 3.
    // So at most q elements are added.
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            tail++;
            update(1, 1, q, tail, x);
        } else if (type == 2) {
            if (head <= tail) {
                head++;
            }
        } else if (type == 3) {
            if (head > tail) {
                cout << "1";
            } else {
                Node res = query(1, 1, q, head, tail);
                cout << (res.ok ? "1" : "0");
            }
        }
    }
    cout << endl;

    return 0;
}
