#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int index;
    int degree;
    int color;
};

string road[13] = {"A->B", "A->C", "A->D", "B->A", "B->C", "B->D", "D->A", "D->B", "D->C", "E->A", "E->B", "E->C", "E->D"};

void sort(Node nodes[])
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 12; j > i; j--)
        {
            if (nodes[j].degree > nodes[j - 1].degree)
            {
                int degree = nodes[j - 1].degree;
                int index = nodes[j - 1].index;
                nodes[j - 1].degree = nodes[j].degree;
                nodes[j - 1].index = nodes[j].index;
                nodes[j].degree = degree;
                nodes[j].index = index;
            }
        }
    }
}

void output(Node nodes[])
{
    queue<int> q0, q1, q2, q3, q4, q5;
    queue<int> q[6];
    for (int i = 0; i < 13; i++)
        q[nodes[i].degree].push(nodes[i].index);
    for (int i = 5; i >= 0; i--)
    {
        cout << "度数为" << i << "的顶点：";
        if (q[i].empty())
            cout << "无";
        while (!q[i].empty())
        {
            int index = q[i].front();
            cout << road[index] << " ";
            q[i].pop();
        }
        cout << endl;
    }
}

bool ifOk(Node nodes[], int graph[][13], int color, int j)
{
    if (nodes[j].color != 0)
        return false;
    for (int i = 0; i < 13; i++)
        if (graph[nodes[j].index][i] == 1)
            for (int m = 0; m < 13; m++)
                if (nodes[m].index == i)
                    if (nodes[m].color == color)
                        return false;
    return true;
}

int main()
{
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

    Node nodes[13];
    for (int i = 0; i < 13; i++)
    {
        int degree = 0;
        for (int j = 0; j < 13; j++)
        {
            if (graph[i][j])
            {
                degree++;
                cout << road[i] << " 与 " << road[j] << " 冲突 " << endl;
            }
        }
        nodes[i].index = i;
        nodes[i].degree = degree;
        nodes[i].color = 0;
    }

    sort(nodes);

    cout << "按度数由大到小排序后的结果：";
    for (int i = 0; i < 13; i++)
    {
        cout << road[nodes[i].index] << " ";
        if (i == 12)
            cout << endl;
    }
    output(nodes);

    int k = 0;
    while (1)
    {
        k++;
        int i;
        for (i = 0; i < 13; i++)
            if (nodes[i].color == 0)
            {
                nodes[i].color = k;
                break;
            }

        if (i == 13)
            break;

        for (int j = 0; j < 13; j++)
            if (ifOk(nodes, graph, k, j))
                nodes[j].color = k;
    }

    cout << "所需要的最小颜色数目：" << k - 1 << endl;
    cout << "一种涂色方案为：" << endl;
    for (int i = 1; i < k; i++)
    {
        cout << i << ':';
        for (int j = 0; j < 13; j++)
            if (nodes[j].color == i)
                cout << road[nodes[j].index] << ' ';
        if (i < k - 1)
            cout << endl;
    }
}
