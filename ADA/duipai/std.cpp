#include <bits/stdc++.h>
using namespace std;
int main(){
    
	freopen("in.txt", "r", stdin);      
    freopen("std.txt", "w", stdout);
    int n, m;
    cin >> n >> m;

    int c = 1;
	for(int i = 2; i <= min(n, m); i++){
		while(m % i == 0 && n % i == 0){
			c *= i;
			m /= i;
			n /= i;
		}
	}
	cout << c << endl;

    return 0;
}

