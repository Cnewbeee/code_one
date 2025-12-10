#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    if (n == 0) { cout << -1 << '\n'; return 0; }
    int wl = (int)words[0].size();
    int totalLen = wl * n;
    int L = (int)s.size();
    if (L < totalLen) { cout << -1 << '\n'; return 0; }

    unordered_map<string,int> need;
    need.reserve(n*2);
    for (auto &w: words) need[w]++;

    vector<int> ans;
    for (int offset = 0; offset < wl; ++offset) {
        int left = offset;
        unordered_map<string,int> window;
        window.reserve(need.size()*2);
        for (int j = offset; j + wl <= L; j += wl) {
            string cur = s.substr(j, wl);
            auto it = need.find(cur);
            if (it == need.end()) {
                window.clear();
                left = j + wl;
            } else {
                window[cur]++;
                while (window[cur] > it->second) {
                    string leftWord = s.substr(left, wl);
                    window[leftWord]--;
                    left += wl;
                }
                if (j + wl - left == totalLen) {
                    ans.push_back(left);
                    // move left by one word to look for next
                    string leftWord = s.substr(left, wl);
                    window[leftWord]--;
                    left += wl;
                }
            }
        }
    }
    if (ans.empty()) {
        cout << -1 << '\n';
    } else {
        sort(ans.begin(), ans.end());
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
