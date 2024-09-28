#include <bits/stdc++.h>
using namespace std;
string a = "5686916124919823647759503875815861830379270588570991944686338516346707827689565614010094809128502533";

string year = "2023";
int main()
{
  int i;
  int n = 100, m = 0;
  for(int k = 0; k < 4 && m < n; ++m){
    if(year[k] == a[m])k++;
  }
  int mo, mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int da;
  set<int> day;
  for(int i = m; i < n; i++){
    if(a[i] == '0'){
      for(int j = i+1; j < n; j++){
        if(a[j] != '0'){
          mo = a[j]-'0';
          //cout << mo << "<<<<<<<" << j << endl;
          for(int k = j+1; k < n; k++){
            if(a[k] <= '3'){
              for(int l = k+1; l < n; l++){
                da = (a[k] - '0')*10+(a[l]-'0');
                
                if(da <= mon[mo] && da > 0) day.insert(mo*100+da);
              }
            }
          }
        }
      }
    }
    else if(a[i] == '1'){
      for(int j = i+1; j < n; j++){
        if(a[j] <= '2'){
          mo = (a[j]-'0')+10;
          for(int k = j+1; k < n; k++){
            if(a[k] <= '3'){
              for(int l = k+1; l < n; l++){
                da = (a[k] - '0')*10+(a[l]-'0');
                if(da <= mon[mo] && da > 0) day.insert(mo*100+da);
              }
            }
          }
        }
      }
    }
  }
  cout << day.size() << endl;
  return 0;
}