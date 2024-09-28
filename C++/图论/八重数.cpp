#include<bits/stdc++.h>

using namespace std;

int bfs(string start){
    queue<string> q;
    q.push(start);
    unordered_map<string, int> d;
    d[start] = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    string end = "12345678x";
    while(!q.empty()){
        string t = q.front();
        q.pop();
        int dist = d[t];
        if(t == end) return dist;
        int k = t.find('x');
        int x = k / 3;
        int y = k % 3;
        for(int i = 0; i < 4; i ++){
            int a = x + dx[i];
            int b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3){
                swap(t[k], t[a * 3 + b]);
                if(!d.count(t)){
                    d[t] = dist + 1;
                    q.push(t);
                }
                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    return -1;
}

int main(){
    string start;
    
    for(int i = 0; i < 9; i++){
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
    return 0;
}