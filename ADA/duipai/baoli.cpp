#include<bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("in.txt", "r", stdin);      
    freopen("baoli.txt", "w", stdout);
	
	int n, m;
	cin >> n >> m;

	for (int i = std::min(n, m); i >= 1; --i) {
        if (n % i == 0 && m % i == 0) {
            cout << i << endl;
            return 0;
        }
    }

	return 0;
}
