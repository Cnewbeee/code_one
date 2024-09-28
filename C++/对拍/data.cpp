#include<bits/stdc++.h>
#define ll long long

ll Random(ll mod)
{
    ll ans = 2147483647;
    return ans = ans * rand() % mod + 0;
}

int main()
{
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);
    //freopen("in.txt", "w", stdout);
    ll t = 1;
    //printf("%ld\n", t);
    while(t--){
        ll n = Random(20);
        printf("%ld\n", n);
        while(n--){
            ll a = Random(100);
            printf("%ld ", a);
        }
        printf("\n");
    }
    return 0;
}
