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
    char g[4][4];
    int cnt = 0;
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            cin >> g[i][j];
            if(g[i][j] == 'G'){
                cnt++;
            }
        }
    }
    if(cnt >= 5){
        cout << "Yes" << endl;
        return;
    }
    int falg = 0;
    for(int i = 1; i < 4; i++){
        int x = 0, y = 0;
        for(int j = 1; j < 4; j++){
            if(g[i][j] == 'O'){
                y++;
                break;
            }else if(g[i][j] == 'X'){
                x++;
            }
        }
        if(x > 0 && y == 0){
            falg = 1;
            break;
        }
    }
    if(falg){
        cout << "Yes" << endl;
        return;
    }
    for(int i = 1; i < 4; i++){
        int x = 0, y = 0;
        for(int j = 1; j < 4; j++){
            if(g[j][i] == 'O'){
                y++;
                break;
            }else if(g[j][i] == 'X'){
                x++;
            }
        }
        if(x > 0 && y == 0){
            falg = 1;
            break;
        }
    }
    if(falg){
        cout << "Yes" << endl;
        return;
    }
    int x = 0, y = 0;
    for(int i = 1; i < 4; i++){
        if(g[i][i] == 'O'){
            y++;
            break;
        }else if(g[i][i] == 'X'){
            x++;
        }
    }
    if(x > 0 && y == 0){
        cout << "Yes" << endl;
        return;
    }

    for(int i = 1; i < 4; i++){
        if(g[i][4-i] == 'O'){
            y++;
            break;
        }else if(g[i][4-i] == 'X'){
            x++;
        }
    }
    if(x > 0 && y == 0){
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
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
