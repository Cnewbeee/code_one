#include<bits/stdc++.h>

using namespace std;

const int N = 10001;

int n, m;
int heap[N], len;
int d[N], q[N];
void PushUp(int i){
    if (i == 1) return;
    while (i != 1){
        if (heap[i] < heap[i / 2]) swap(heap[i], heap[i / 2]), i /= 2;
        else break;
    }
}
int bfs(int x){
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = 1;
    d[1] = 0;

    while(hh <= tt){
        int t = q[hh++];

        for(int i = t*2; i != t*2+2; i++){
            int p = heap[i];
            if(d[p] == -1){
                d[p] = d[t] + 1;
                q[++tt] = p;
            }
        }
    }
    return d[x];
}
int Stoi(string t){
    int res = 0;
    for(int i = 0; i < t.size(); i++){
        res = res * 10 + t[i]-'0';
    }
    return res;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> heap[i];
        PushUp(i);
    }
    len = n;
    string s;
    int ss = 0;
    //getline(cin, s);
    getline(cin, s);
    while(m--){
        getline(cin, s);
        //cout << m << " << " << s << endl;
        int x = 0, y;
        vector<int> ko;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')ko.push_back(i);
            //cout << i << endl;
        }
        string t = s.substr(0, ko[0]);
        x = Stoi(t);
        //cout << x << " << " << endl;
        if(ko.size() == 3){
            if(x == heap[1]){
                cout << "T" << endl;
            }
            else {
                cout << "F" << endl;
            }
        }
        else if(ko.size() == 4){
            //cout << s[ko[0]+1] << endl;
            t = s.substr(ko[1]+1, ko[2]-ko[1]-1);
            //cout << "t = " << t << endl;
            y = Stoi(t);
            //cout << "y = " << y << endl;
            int xx, yy;
            for(int i = 1; i <= n; i++){
                if(x == heap[i])xx = i;
                if(y == heap[i])yy = i;
            }
            if(bfs(xx) == bfs(yy)){
                cout << "T" << endl;
            }
            else {
                cout << "F" << endl;
            }
        }
        else if(s[ko[1]+1] == 't'){
            t = s.substr(ko.back()+1);
            //cout << "t = " << t << endl;
            y = Stoi(t);
            //cout << "y = " << y << endl;
            int xx, yy;
            for(int i = 1; i <= n; i++){
                if(x == heap[i])xx = i;
                if(y == heap[i])yy = i;
            }
            if(yy/2 == xx || yy/2+1 == xx){
                cout << "T" << endl;
            }
            else {
                cout << "F" << endl;
            }
        }
        else{
            //cout << s[ko[0]+1] << endl;
            t = s.substr(ko.back()+1);
            //cout << "t = " << t << endl;
            y = Stoi(t);
            //cout << "y = " << y << endl;
            int xx, yy;
            for(int i = 1; i <= n; i++){
                if(x == heap[i])xx = i;
                if(y == heap[i])yy = i;
            }
            if(yy*2 == xx || yy*2+1 == xx){
                cout << "T" << endl;
            }
            else {
                cout << "F" << endl;
            }
        }
    }
}