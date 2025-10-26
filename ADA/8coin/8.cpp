#include <iostream>
#include <vector>
using namespace std;

vector<int> coins(8, 10); // 初始化8枚真币（重量10）

// 天平比较函数
int compare(const vector<int>& left, const vector<int>& right) {
    int lsum = 0, rsum = 0;
    for (int num : left) lsum += coins[num];
    for (int num : right) rsum += coins[num];
    
    if (lsum < rsum)       return -1;
    else if (lsum > rsum)  return 1;
    else                   return 0;
}

// 打印比较结果
void printCompare(const vector<int>& left, const vector<int>& right, int result) {
    cout << "称量 [";
    for (int num : left) cout << num << " ";
    cout << "] vs [";
    for (int num : right) cout << num << " ";
    cout << "] => ";
    
    if (result == -1) cout << "左轻右重" << endl;
    else if (result == 1) cout << "左重右轻" << endl;
    else cout << "平衡" << endl;
}

// 核心检测算法
void detectFakeCoin() {
    // 第一次称量：分组比较
    vector<int> group1 = {0,1,2};
    vector<int> group2 = {3,4,5};
    int result1 = compare(group1, group2);
    printCompare(group1, group2, result1);

    if (result1 == 0) { // 情况1：假币在G3
        vector<int> group3 = {6};
        int result2 = compare(group3, {0});
        printCompare(group3, {0}, result2);
        
        if (result2 == 0) {
            int result3 = compare({7}, {0});
            printCompare({7}, {0}, result3);
            cout << "假币：7号（" << (result3 == -1 ? "轻" : "重") << "）" << endl;
        } else {
            cout << "假币：6号（" << (result2 == -1 ? "轻" : "重") << "）" << endl;
        }
    } else { // 情况2：假币在G1/G2
        bool isLight = (result1 == -1);
        vector<int> left = {0,1}, right = {2,3};
        int result2 = compare(left, right);
        printCompare(left, right, result2);

        if (result2 == 0) { // 假币在B2/B3
            int result3 = compare({4}, {0});
            printCompare({4}, {0}, result3);
            
            if (result3 == 0) {
                cout << "假币：5号（" << (isLight ? "重" : "轻") << "）" << endl;
            } else {
                cout << "假币：4号（" << (isLight ? "重" : "轻") << "）" << endl;
            }
        } else if (result2 == (isLight ? -1 : 1)) { // 假币在A1/A2
            int result3 = compare({0}, {1});
            printCompare({0}, {1}, result3);
            
            if (result3 != 0) {
                cout << "假币：" << (result3 == -1 ? 0 : 1) << "号（" 
                     << (isLight ? "轻" : "重") << "）" << endl;
            }
        } else { // 假币在A3/B1
            int result3 = compare({2}, {0});
            printCompare({2}, {0}, result3);
            
            if (result3 != 0) {
                cout << "假币：2号（" << (isLight ? "轻" : "重") << "）" << endl;
            } else {
                cout << "假币：3号（" << (!isLight ? "轻" : "重") << "）" << endl;
            }
        }
    }
}

int main() {
    // 设置假币（示例：5号硬币较重）
    coins[5] = 11;
    
    cout << "---- 假币检测开始 ----" << endl;
    detectFakeCoin();
    cout << "---- 检测完成 ----" << endl;
    return 0;
}
