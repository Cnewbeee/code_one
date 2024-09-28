#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string a;
        int n;
        cin >> n >> a;
        int sum = 0, ans = 0;

        for(int i = 0; i < n; i++){
            if(a[i] == 'd' && sum == 0)sum ++;
            if(a[i] == 'f' && sum == 1)sum ++;
            if(a[i] == 's' && sum == 2){
                sum = 0;
                ans++;
            }
        }
        cout  << ans << endl;
    }
    return 0;
}
