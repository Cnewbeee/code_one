#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, x, y;
    string a, b, c;
    cin >> n >> x >> y;
    cin >> a >> b >> c;

    int A0 = 0, A1 = 0, B0 = 0, B1 = 0;
    for (int i = 0; i < n; ++i) {
        int a_bit = a[i] - '0';
        int b_bit = b[i] - '0';
        int c_bit = c[i] - '0';
        int current_xor = a_bit ^ b_bit;
        if (current_xor != c_bit) {
            if (current_xor == 0) { // 类型A，需要变为1
                if (b_bit == 0) {
                    A0++;
                } else {
                    A1++;
                }
            } else { // 类型B，需要变为0
                if (b_bit == 0) {
                    B0++;
                } else {
                    B1++;
                }
            }
        }
    }

    // 处理内部对
    int a_pairs = min(A0, A1);
    int b_pairs = min(B0, B1);
    int rem_a = (A0 + A1) - 2 * a_pairs;
    int rem_b = (B0 + B1) - 2 * b_pairs;

    // 处理类型对
    int ab_pairs = min(rem_a, rem_b);
    int cost = (a_pairs + b_pairs) * y + ab_pairs * min(2 * x, y) + (rem_a + rem_b - 2 * ab_pairs) * x;

    // 全部翻转的成本
    int all_flip_cost = (A0 + A1 + B0 + B1) * x;

    cout << min(cost, all_flip_cost) << endl;

    return 0;
}