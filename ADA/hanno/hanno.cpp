#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

// 递归计数器
long long recursive_counter = 0;

// 非递归计数器
long long iterative_counter = 0;

// 递归实现
void hanoi_recursive(int n, char from, char to, char aux, ofstream& out) {
    if (n == 1) {
        recursive_counter++;
        return;
    }
    hanoi_recursive(n-1, from, aux, to, out);
    hanoi_recursive(n-1, aux, to, from, out);
}

// 非递归实现
void hanoi_iterative(int n, ofstream& out) {
    struct Task {
        int n;
        char from, to, aux;
        bool expanded;
    };
    
    stack<Task> tasks;
    tasks.push({n, 'A', 'C', 'B', false});

    while (!tasks.empty()) {
        Task task = tasks.top();
        tasks.pop();

        if (task.n == 1) {
            iterative_counter++;
        } else {
            if (!task.expanded) {
                // 分解任务的顺序要与递归顺序一致
                tasks.push({task.n-1, task.aux, task.to, task.from, false});
                tasks.push({1, task.from, task.to, task.aux, true});  // 本次移动
                tasks.push({task.n-1, task.from, task.aux, task.to, false});
                task.expanded = true;
            } else {
                // 当任务被标记为已展开时，执行实际移动操作
                iterative_counter++;
            }
        }
    }
}


int main() {
    ofstream out("hanoi_data.csv");
    out << "n,iterative\n";

    for (int n = 1; n <= 20; ++n) {  // 测试n=1到10的情况
        recursive_counter = 0;
        iterative_counter = 0;
        
        // 运行两种算法
        hanoi_recursive(n, 'A', 'C', 'B', out);
        hanoi_iterative(n, out);
        
        // 记录结果
        out << n << "," << recursive_counter;
        out << "," << iterative_counter << endl;
    }
    out.close();
    return 0;
}
