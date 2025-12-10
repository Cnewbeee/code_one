#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

// Disjoint Set Union (DSU) structure to manage connected components
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        // Initialize each node as its own parent
        iota(parent.begin(), parent.end(), 0);
    }
    // Find the representative of the set containing x with path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    // Unite the sets containing x and y
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) parent[rootX] = rootY;
    }
};

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, q;
    if (!(cin >> k >> q)) return 0;

    vector<int> p(k + 1);
    vector<int> id_start(k + 2, 0);
    
    // Read the number of segments for each layer
    for (int i = 1; i <= k; ++i) {
        cin >> p[i];
        // Calculate the starting ID for each layer to map (layer, segment) to a unique ID
        id_start[i+1] = id_start[i] + p[i];
    }

    int total_nodes = id_start[k+1];
    DSU dsu(total_nodes);

    // Build connections between adjacent layers i and i+1
    for (int i = 1; i < k; ++i) {
        int pa = p[i];
        int pb = p[i+1];
        int offset_a = id_start[i];
        int offset_b = id_start[i+1];

        // Use long long to prevent overflow during cross-multiplication
        long long PA = pa;
        long long PB = pb;
        
        int v = 1;
        // Iterate through each segment u in layer i
        for (int u = 1; u <= pa; ++u) {
            // We want to find all segments v in layer i+1 that overlap with segment u in layer i.
            // Segment u covers angle range [(u-1)/PA, u/PA)
            // Segment v covers angle range [(v-1)/PB, v/PB)
            // They overlap if the intersection of these intervals has non-zero length.
            // Condition: max((u-1)/PA, (v-1)/PB) < min(u/PA, v/PB)
            
            // 1. Advance v to the first segment that could potentially overlap.
            // We skip v if it ends before or exactly when u starts.
            // v ends at v/PB. u starts at (u-1)/PA.
            // Skip if v/PB <= (u-1)/PA  <=>  v*PA <= (u-1)*PB
            while (v <= pb && (long long)v * PA <= (long long)(u - 1) * PB) {
                v++;
            }
            
            // 2. Iterate through valid v's starting from the current v.
            // A segment v overlaps with u if v starts before u ends.
            // v starts at (v-1)/PB. u ends at u/PA.
            // Overlap if (v-1)/PB < u/PA  <=>  (v-1)*PA < u*PB
            
            int temp_v = v;
            while (temp_v <= pb && (long long)(temp_v - 1) * PA < (long long)u * PB) {
                dsu.unite(offset_a + u, offset_b + temp_v);
                temp_v++;
            }
            // Note: We do not update v to temp_v because the next u (u+1) starts later,
            // but it might still overlap with some of the v's we just processed.
            // However, since u increases, the start point of u increases, so the first valid v
            // can only move forward or stay the same. Thus, maintaining 'v' is correct.
        }
    }

    string res = "";
    // Process queries
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // Convert (layer, segment) coordinates to unique IDs
        int id1 = id_start[r1] + c1;
        int id2 = id_start[r2] + c2;
        
        // Check if they belong to the same connected component
        if (dsu.find(id1) == dsu.find(id2)) {
            res += '1';
        } else {
            res += '0';
        }
    }
    cout << res << endl;

    return 0;
}
