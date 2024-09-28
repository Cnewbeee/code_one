#include<bits/stdc++.h>

using namespace std;
int n, m;
const double PI = 3.141592;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int r1, r2;
    cin >> r1 >> r2;
    double area = PI * (r2 * r2 - r1 * r1);
    printf("%.6lf\n", area);
    return 0;

}