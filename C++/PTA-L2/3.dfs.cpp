#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<double,double>


const int mod = 1e9 + 7;
const int N = 1001;
double d;
int n;
double sum = 0;
bool cmp(PII x, PII y){
    return x.first > y.first;
}
signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> d;
    vector<PII> v(n);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v[i].second = t;
    }
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].first /= v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = n-1; i >= 0; i--){
        if(d >= v[i].second){
            d -= v[i].second;
            sum += v[i].first * v[i].second;
        }
        else{
            sum += v[i].first * d;
            break;
        }
        
    }

	return 0;
}
