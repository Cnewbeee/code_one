#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Graph {
private:
    struct AdjNode {
        int vertex;
        AdjNode* next;
        AdjNode(int v) : vertex(v), next(nullptr) {}
    };

    struct Vertex {
        char name;
        AdjNode* first;
        Vertex(char n) : name(n), first(nullptr) {}
    };

    vector<Vertex> vertices;
    int numVertices;
    int numEdges;

public:
    Graph() : numVertices(0), numEdges(0) {}
    
    // 添加顶点
    void addVertex(char name) {
        vertices.push_back(Vertex(name));
        numVertices++;
    }
    
    // 添加边
    void addEdge(char a, char b) {
        int aIndex = findVertex(a);
        int bIndex = findVertex(b);
        
        if (aIndex == -1 || bIndex == -1) return;
        
        // 添加a->b
        AdjNode* newNode = new AdjNode(bIndex);
        newNode->next = vertices[aIndex].first;
        vertices[aIndex].first = newNode;
        
        // 添加b->a (无向图)
        newNode = new AdjNode(aIndex);
        newNode->next = vertices[bIndex].first;
        vertices[bIndex].first = newNode;
        
        numEdges++;
    }
    
    // 查找顶点索引
    int findVertex(char name) {
        for (int i = 0; i < numVertices; i++) {
            if (vertices[i].name == name) {
                return i;
            }
        }
        return -1;
    }
    
    // 图着色算法
    int graphColoring() {
        if (numVertices == 0) return 0;
        
        vector<int> result(numVertices, -1); // 存储每个顶点的颜色
        vector<bool> available(numVertices, false); // 可用颜色
        
        result[0] = 0; // 第一个顶点着第一种颜色
        
        // 为剩余的顶点着色
        for (int u = 1; u < numVertices; u++) {
            // 处理所有邻接顶点并标记它们的颜色为不可用
            AdjNode* p = vertices[u].first;
            while (p != nullptr) {
                if (result[p->vertex] != -1) {
                    available[result[p->vertex]] = true;
                }
                p = p->next;
            }
            
            // 找到第一个可用的颜色
            int cr;
            for (cr = 0; cr < numVertices; cr++) {
                if (available[cr] == false) {
                    break;
                }
            }
            
            result[u] = cr;
            
            // 重置可用颜色为false
            p = vertices[u].first;
            while (p != nullptr) {
                if (result[p->vertex] != -1) {
                    available[result[p->vertex]] = false;
                }
                p = p->next;
            }
        }
        
        // 返回使用的颜色数量
        return *max_element(result.begin(), result.end()) + 1;
    }
    
    void printGraph() {
        cout << "图结构:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << vertices[i].name << " -> ";
            AdjNode* p = vertices[i].first;
            while (p != nullptr) {
                cout << vertices[p->vertex].name << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
};

int main() {
    // 创建五叉路口图模型
    Graph crossroad;
    
    // 添加顶点(道路方向)
    // 假设道路A,B,D是双行线，有进和出两个方向
    // 道路C,E是单行线，只有一个方向
    crossroad.addVertex('A'); // A方向
    crossroad.addVertex('B'); // B方向 
    crossroad.addVertex('C'); // C方向(单行)
    crossroad.addVertex('D'); // D方向
    crossroad.addVertex('E'); // E方向(单行)
    
    // 添加冲突边(不能同时通行的方向)
    // 根据用户确认：
    // E是单向驶入路口，C是单向驶出路口
    // 冲突关系设置：
    // 1. 双行线之间的交叉冲突
    crossroad.addEdge('A', 'B'); // A-B交叉冲突
    crossroad.addEdge('A', 'D'); // A-D交叉冲突
    crossroad.addEdge('B', 'D'); // B-D交叉冲突
    
    // 2. 驶入方向(E)的冲突
    crossroad.addEdge('E', 'A'); // 驶入E与A方向冲突
    crossroad.addEdge('E', 'D'); // 驶入E与D方向冲突
    
    // 3. 驶出方向(C)的冲突
    crossroad.addEdge('C', 'A'); // 驶出C与A方向冲突
    
    crossroad.printGraph();
    
    int colors = crossroad.graphColoring();
    cout << "需要的最少交通灯颜色数量: " << colors << endl;

    return 0;
}