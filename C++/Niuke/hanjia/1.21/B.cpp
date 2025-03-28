#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 2) {
        int u, v;
        cin >> u >> v;
        cout << u << " " << v << endl;
        return 0;
    }
    
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    
    vector<int> leaves;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            leaves.push_back(i);
        }
    }
    
    if (leaves.size() > 2) {
        cout << -1 << endl;
    } else {
        if (leaves.size() == 2) {
            cout << leaves[0] << " " << leaves[1] << endl;
        } else {
            cout << -1 << endl; 
        }
    }
    
    return 0;
}
