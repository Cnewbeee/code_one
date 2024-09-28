#include<bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m, s, d;
int a[N], dist[N];
int sum[N];
int cnt[N];
int g[N][N];
int pre[N];
bool st[N] = {false};
void djst(){
    memset(dist, 0x3f3f3f, sizeof dist);
    memset(pre, -1, sizeof pre);
    
    dist[s] = 0;
    sum[s] = a[s];
    cnt[s] = 1;

    for(int i = 0; i < n; i++){
        int t = -1;

        for(int j = 0; j < n; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        for(int j = 0; j < n; j++){
            if(dist[j] > dist[t] + g[t][j]){
                dist[j] = dist[t] + g[t][j];
                sum[j] = sum[t] + a[j];
                cnt[j] = cnt[t];
                pre[j] = t;
            }
            else if(dist[j] == dist[t] + g[t][j]){
                cnt[j] += cnt[t];
                if(sum[t] + a[j] > sum[j])
				{
					sum[j] = sum[t] + a[j];
					pre[j] = t;
				}
            }
        }
        st[t] = true;
    }
}
void solve()
{
	cout << cnt[d] << " " << sum[d] << endl;
	vector<int> vc;
	int x = d;
	do{
		vc.push_back(x);
		x = pre[x];
	}while(x != -1);
	for(int i = vc.size()-1; i >= 0; i--)
	{
		cout << vc[i];
		if(i != 0) cout << " ";
	}
}

int main(){
    
    cin >> n >> m >> s >> d;

    for(int i = 0; i < n; i++)cin >> a[i];

    memset(g, 0x3f, sizeof g);
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = g[y][x] = z;
    }

    djst();
    solve();
    return 0;
}