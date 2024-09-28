#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];

signed main(void)
{
    string a, b;
    cin >> a >> b;
    string sum;
    ll al = a.size(), bl = b.size();
    if(al < bl)
    {
        for(int i = 0; i < bl-al; i++)
            a = "0" + a;
    }
    else
    {
        for(int i = 0; i < al - bl; i++)
            b = "0" + b;
    }
    al = a.size();
    int temp = 0;
    int cf = 0;
    for(ll i = al-1; i >= 0; i --)
    {
        temp = a[i] - '0' + b[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        sum = char(temp + '0') + sum;
    }
    if(cf != 0)
        sum = char(cf + '0') + sum;

    cout << sum;
	return 0;
}
