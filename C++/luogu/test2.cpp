#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1010;
int n, m;

bool check(int x, int y){
    return x < n && x >= 0 && y < n && y >= 0;
}

signed main(void)
{
    string a, b;
	cin >> a >> b;
    int x, y, bx, by;
    string d[8] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

    x = a[0]-'a';
    y = a[1]-'0';
    bx = b[0]-'a';
    by = b[1]-'0';
    
    int an = max(abs(x-bx), abs(y-by));
    cout << an << endl;

    while(x != bx || y != by){
        int dx = abs(x - bx), dy = abs(y - by);
        if(dx == dy){
            if(x < bx && y > by){
                cout << d[7] << endl;
                x++, y--;
            }else if(x < bx && y < by){
                cout << d[6] << endl;
                x++, y++;
            }
            else if(x > bx && y > by){
                cout << d[5] << endl;
                x--, y--;
            }
            else{
                cout << d[4] << endl;
                x--, y++;
            }
        }
        else if(dx > dy && dx){
            if(x > bx){
                cout << d[0] << endl;
                x--;
            }
            else{
                cout << d[1] << endl;
                x++;
            }
        }
        else if(dy > dx && dy){
            if(y > by){
                cout << d[3] << endl;
                y--;
            }
            else {
                cout << d[2] << endl;
                y++;
            }
        }
    }
	return 0;
}
