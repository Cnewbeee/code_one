#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5+10;

vector<int> rd(N);
int n;
int ans = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    n--;int t;
    cin >> t;
    rd[++ans] = t;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(rd[ans] < t) rd[++ans] = t;
        else if(rd[0] > t) rd[0] = t;
        else {
            int l = 1, r = ans, mid;
            while(l <= r){
                mid = l + r >> 1;
                if(t > rd[mid-1] && t <= rd[mid]) break;
                if(rd[mid] < t) l = mid+1;
                else r = mid;
            }
            rd[mid] = t;
        }
    }
    cout << ans << endl;
    return 0;
}