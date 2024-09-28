#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int T = 1;
string s[1441];
int p = 0;

void solve()
{
    int h, m;
    scanf("%d:%d", &h, &m);
    int r = 0;
    if(h >= 12) r = 1;
    if(h == 12)h += 12;
    if(h == 0)h += 12;
    //if(r == 0) printf("%02d:%02d AM", h, m);
    //else printf("%02d:%02d PM", h-12, m);
    //if(T != 0)printf("\n");
    if(r == 1)h -= 12;
    if(r == 0){
        string hh, mm;
        if(h < 10 && m < 10){
            s[p].push_back('0');
            s[p].push_back((h%10) +'0');
            s[p].push_back(':');
            s[p].push_back('0');
            s[p].push_back( m+'0');
            
            //hh[0] = '0', hh[1] = h+'0', mm[0] = '0', mm[1] = m+'0';
        }
        else if(h < 10)hh[0] == '0', hh[1] = (h%10) +'0', mm[0] = '0', mm[1] = m+'0';
        else if(m < 10)hh[0] = '1', hh[1] = (h%10)+'0', mm[0] = '0', mm[1] = (m%10)+'0';
        else hh[0] = '1', hh[1] = (h%10)+'0', mm[0] = m/10+'0', mm[1] = (m%10)+'0';
        cout << hh << ":" << mm << "<<<<<<<" <<endl;
        s[p++] = hh+mm+" "+"AM";
    } 
    else{
        string hh, mm;
        if(h < 10 && m < 10)hh[0] = '0', hh[1] = h+'0', mm[0] = '0', mm[1] = m+'0';
        else if(h < 10)hh[0] == '0', hh[1] = (h%10) +'0', mm[0] = '0', mm[1] = m+'0';
        else if(m < 10)hh[0] = '1', hh[1] = (h%10)+'0', mm[0] = '0', mm[1] = (m%10)+'0';
        else hh[0] = '1', hh[1] = (h%10)+'0', mm[0] = m/10+'0', mm[1] = (m%10)+'0';
        cout << hh << ":" << mm << "<<<<<<<" << endl;
        s[p++] = hh+mm+" "+"PM";
    }
    
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
    cin >> T;
    while (T -- ){
        solve();
        
    }
    for(int i = 0; i < p; i++){
        cout << s[i] << endl;
    }

	return 0;
}
