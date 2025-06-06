#include <iostream>
#include <fstream>

using namespace std;

// 全局定义邻接矩阵和解向量
string road[13] = {"A->B", "A->C", "A->D", 
                   "B->A", "B->C", "B->D", 
                   "D->A", "D->B", "D->C", 
                   "E->A", "E->B", "E->C", "E->D"};
int graph[13][13] = {
    0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
    1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0,
    1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0,
    0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int x[13];
int n = 13;    // 顶点数
int m;         // 可用颜色数
int sum;       // 方案总数

streambuf* coutBuf = cout.rdbuf();
ofstream of("out.txt");
streambuf* fileBuf = of.rdbuf();
        

// 判断顶点node是否可以涂色
bool ifOk(int node) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && x[node] == x[i]) {
            return false;
        }
    }
    return true;
}

// 深度优先遍历
void dfs(int node) {

    if (node >= n) {
        sum++;
        // 输出当前着色方案
        
        for (int i = 0; i < n; i++) 
            cout << x[i] << " ";
        cout << endl;
        of.flush();
        
        return;
    }
    
    for (int i = 1; i <= m; i++) {
        x[node] = i;
        if (ifOk(node)) {
            dfs(node + 1);
        }
        x[node] = 0;  // 回溯
    }
}

int main() {

    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 13; j++){
            if (graph[i][j]){
                cout << road[i] << " 与 " << road[j] << " 冲突 " << endl;
            }
        }
    }

    while (1) {
        m++;
        sum = 0;
        cout.rdbuf(fileBuf);
        dfs(0);
        cout.rdbuf(coutBuf);
        
        if (sum > 0) {
            break;
        }
    }
    cout << "最小颜色数为：" << m << endl;
    cout << "可行的涂色方案数为：" << sum;

    return 0;
}
