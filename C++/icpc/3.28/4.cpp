#include <iostream>

using namespace std;

const int N = 100010;

int m, n;
int e[N], l[N], r[N], idx;

// 在节点a的右边插入一个数x
void insert(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++ ;
}

// 删除节点a
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

int main()
{
    cin >> n;

    // 0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
    insert(0, 1);

    for(int i = 2; i <= n; i++)
    {
        int x, c;
        cin >> x >> c;

        if(c == 0){
            insert(l[x+1], i);
        }
        else{
            insert(x+1, i);
        }
    }
    cin >> m;

    while(m--){
        int t;
        cin >> t;
        for(int i = r[0]; i != 1; i = r[i]){
            if(e[i] == t){
                remove(i);
                break;
            }
        }

    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';

    return 0;
}