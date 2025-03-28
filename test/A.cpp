#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], n, ma = 0, ans[3], an[3];
bool st[N];

int S(){
  int aa = ans[0], bb = ans[1], cc = ans[2];
  int A = a[aa], B = a[bb], C = a[cc];

  int lcmAB = lcm(A, B), lcmBC = lcm(B, C), lcmAC = lcm(A, C);
  int lcmABC = lcm(lcmAB, C);
  int res = A*B*C*lcmABC/(lcmAB*lcmBC*lcmAC);
  return res;
}

void dfs(int u){
  if(u == 3){
    int kt = S();
    if(kt > ma){
      an[0] = a[ans[0]], an[1] = a[ans[1]], an[2] = a[ans[2]];
      ma = kt;
    }
    return ;
  }
  for(int i = 0; i < n; i++){
    if(st[i])continue;
    st[i] = 1;
    ans[u] = i;
    dfs(u+1);
    st[i] = 0;
  }
}

int main()
{
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  dfs(0);

  for(int i = 0; i < 3; i++)cout << an[i] << ' ';
  
  return 0;
}