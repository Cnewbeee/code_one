#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 110;
int g[N][N];
int n, m;
int d[N][N];
PII p[N*N];

/*int bfs(){
    int hh = 0, tt = 0;
    p[0] = {0, 0};

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    while(hh <= tt){
        auto t = p[hh++];

        for(int i = 0 ; i < 4; i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0){
                d[x][y] = d[t.first][t.second] + 1;
                p[++tt] = {x, y};
            }
        }
    }
    return d[n-1][m-1];
}*/
queue<PII> q;
int bfs(){
    q.push({0, 0});
    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    while(!q.empty()){
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x < n && x >= 0 && y < m && y >= 0 && d[x][y] == -1 && g[x][y] == 0){
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    return d[n-1][m-1];
}

signed main(void)
{
	cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    
    cout << bfs() << endl;

	return 0;
}
