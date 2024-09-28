#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int B, t1, a, t, b;
    cin >> B >> t1 >> a >> t >> b;
    t -= t1;

    double ansa = 0, ansb = 0;
    if(t == 0){
        if(a > b){
            ansb += (double)(b*2)/(double)B;
            ansa += ansb;
            ansa += double(a-b)/B;
        }else{
            ansb += (double)(a*2)/(double)B;
            ansa += ansb;
            ansb += double(b-a)/B;
        }
    }else{
        if((double)a/B <= t){
            ansa = (double)a/B;
            ansb = (double)b/B;
        }else{
            ansa = t;
            a -= t*B;
            if(a > b){
                ansb += (double)(b*2)/(double)B;
                ansa += ansb;
                ansa += double(a-b)/B;
            }else{
                ansb += (double)(a*2)/(double)B;
                ansa += ansb;
                ansb += double(b-a)/B;
            }
        }
    }
    //cout << ansa << " " << ansb << endl;
    printf("%.9lf %.9lf\n", ansa, ansb);
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
