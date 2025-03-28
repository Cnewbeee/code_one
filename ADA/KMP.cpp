#include<iostream>

using namespace std;

int ne[1000000];
int next_operations = 0;
int kmp_operations = 0;
int bf_operations = 0;

int BF(string s, string t){

    bf_operations = 0; // 重置计数器
    for(int i = 0; i < s.length(); i++){
        bf_operations++; // 外层循环比较
        if(s[i] == t[0]){
            bool match = true;
            for(int j = 1; j < t.length(); j++){
                bf_operations++; // 内层循环比较
                if(i+j >= s.length() || s[i+j] != t[j]){
                    match = false;
                    break;
                }
            }
            if(match) return i;
        }
    }
    return -1;
}

// 标准KMP预处理实现 O(n)
void getNext(string p){
    ne[0] = -1;
    int j = -1;
    for(int i=1; i<p.length(); i++){
        while(j>=0 && p[i]!=p[j+1])
            j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
}


int kmp(string s, string t){
    int i = 0, j = 0;
    while(i < s.length() && j < t.length()){
        kmp_operations++;
        if(s[i] == t[j])i++, j++;
        else{
            j = ne[j];
            if(j == -1)i++, j = 0;
        }

        if(j == t.length()){
            return i-j;
        }
    }
    return -1;
}

string generate_pattern(int n) {
    return string(n, 'a'); // 生成全a测试模式串
}

string generate_text(string t) {
    int m = t.length() * 10; // 文本串长度为模式串10倍
    string s(m, 'b');        // 用b填充文本串
    s.insert(m/2, t);        // 在中间插入模式串确保匹配
    return s;
}

int main() {
    // 测试不同规模：模式串长度从1到100
    for(int n = 1; n <= 100; n++) {
        string t = generate_pattern(n);
        string s = generate_text(t);
        
        // 重置计数器
        next_operations = 0;
        kmp_operations = 0;
        
        // 执行核心逻辑
        getNext(t);
        kmp(s, t);
        BF(s, t);
        
        // 输出CSV格式数据
        cout << n << "," 
            << next_operations << "," 
            << kmp_operations << ","
            << bf_operations << endl;
    }
    return 0;
}
