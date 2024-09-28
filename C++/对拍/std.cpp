#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=2e5+10;
ll sum,ans;
int n,a[N];
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        sum+=a[i];
    }
    if(sum%n==0)ptlle(sum/n);
    else{  
        per(i,30,0){
            ll v=1<<i;
            if(sum/v>=n){
                ans+=v;
                sum-=n*v;
            }
            else{
                ll x=v-1;
                if(sum<=1ll*n*x)continue;
                ll cnt=min(1ll*n,sum/v);
                ans+=v;
                sum-=cnt*v;
            }
        }
        ptlle(ans);
    }
    return 0;
}