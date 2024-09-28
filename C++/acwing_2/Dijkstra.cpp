#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 510;

int n, m;
int g[N][N];
int dist[N];
int st[N];
int dijkstra(){
    memset(dist, 0x3f3f3f, sizeof dist);
    dist[1] = 0;
    
    for(int i = 0; i < n - 1; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){//找当前出发点
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        for(int j = 1; j <= n; j++){//找最近目标点
            dist[j] = min(dist[j], dist[t]+g[t][j]);
        }
        cout << endl;
        st[t] = true;
    }
    if(dist[n] == 0x3f3f3f)return -1;
    else return dist[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> m;
    memset(g, 0x3f, sizeof g);

    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);

    }

    cout << dijkstra() << endl;
	return 0;
}
