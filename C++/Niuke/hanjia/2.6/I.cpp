#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + (s[i - 1] == 'u');
        }
        const string target = "uwawauwa";
        const int target_len = target.size();
        long long ans = 0;
        for (int j = 0; j + target_len <= n; ++j) {
            bool match = true;
            for (int k = 0; k < target_len; ++k) {
                if (s[j + k] != target[k]) {
                    match = false;
                    break;
                }
            }
            if (match && j >= 1) {
                ans += prefix[j - 1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}