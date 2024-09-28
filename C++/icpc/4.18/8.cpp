#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
char s[N][N];
char s1[N][N];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

int main(){
    cin >> n >> m;
    memset(s1, 'R', sizeof s1);
    memset(s, 'M', sizeof s);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 'M')s1[i][j] = 'M';
            else if(s[i][j] == 'H'){
                s1[i][j] = 'H';
                for(int k = 0; k < 8; k++){
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    s1[xx][yy] = s[xx][yy];
                }
            }
            else if(s[i][j] == 'L'){
                int ok = 1;
                for(int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(s[x][y] != 'L'){
                        ok = 0;
                        break;
                    }
                }
                if(ok) s1[i][j] = 'S';
                else s1[i][j] = 'L';
            }
            else if(s[i][j] == 'G'){
                int ok = 1;
                for(int k = 0; k < 8; k ++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(s[x][y] == 'L'){
                        ok = 2;
                    }
                    if(s[x][y] == 'H'){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 0) s1[i][j] = 'G';
                else if(ok == 1) s1[i][j] = 'B';
                else if(ok == 2) s1[i][j] = 'N';
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int  j = 1; j <= m; j++){
            cout << s1[i][j];
        }
        cout << endl;
    }
}