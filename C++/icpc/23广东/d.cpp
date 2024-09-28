#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 5e5 + 10;

bool cmp(PII a, PII b){
    return a.second-a.first < b.second-b.first;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<PII> A, B;
    ll suma = 0, sumb = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a >= b)A.push_back({a, b}), suma += a;
        else B.push_back({a, b}), sumb += b;
    }
    int lenb = B.size(), lena = A.size();
    if(lenb == 0){
        //cout << 0 << endl;
        if(lena == 1)cout << A[0].second << endl;
        else cout << suma << endl;
        return ;
    }

    sort(B.begin(), B.end(), cmp);

    if(lena == 0){
        //cout << 1 << endl;
        if(lenb*2-1 > m){   
            for(PII i : B){
                sumb -= (i.second-i.first);
                lenb--;
                m--;
                if(lenb*2 <= m)break;
            }
        }
        cout << sumb << endl;
        return ;
    }

    if(lena == 1){
        //cout << 2 << endl;
        ll sum = sumb;
        m--;
        if(lenb*2 > m){
            sum += A[0].first;  
            for(PII i : B){
                sum -= (i.second-i.first);
                lenb--;
                m--;
                if(lenb*2 <= m)break;
            }   
        }else{
            sum = max(sumb+A[0].second, sumb-(B[0].second-B[0].first)+A[0].first);
        }
        cout << sum << endl;
        return ;
    }
    ll sum = suma + sumb;
    m -= lena;
    if(lenb*2 > m){
        for(PII i : B){
            sum -= (i.second-i.first);
            lenb--;
            m--;
            if(lenb*2 <= m)break;
        }
    }
    cout << sum << endl;
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
