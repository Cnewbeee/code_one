#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

unsigned long long count_2powers_upto(unsigned long long n) {
    if (n < 2) return 0;
    return 63 - __builtin_clzll(n);
}

bool isExcluded(unsigned long long n) {
    if (n < 2) return false;
    return (n & (n - 1)) == 0;
}

void solve(){

    int i;
    cin >> i;
    
    unsigned long long low = 1, high = 2 * i;
    while (low < high) {
        unsigned long long mid = low + (high - low) / 2;
        unsigned long long c = count_2powers_upto(mid);
        if (mid - c < i) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    // 调整n是否为被排除的2的幂
    if (isExcluded(low)) {
        --low;
    }
    cout << 2 * low << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
