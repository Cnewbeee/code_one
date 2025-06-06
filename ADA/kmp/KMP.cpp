#include<iostream>

using namespace std;

int ne[1000000];
int next_operations = 0;
int kmp_operations = 0;
int bf_operations = 0;

struct _timeb T;

int BF(string s, string t){
    bf_operations = 0; // 重置计数器
    for(int i = 0; i < s.length(); i++){
        bf_operations++; // 外层循环比较次数
        if(s[i] == t[0]){
            bool match = true;
            for(int j = 1; j < t.length(); j++){
                bf_operations += 2; // 内层循环比较 + 字符比较
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
    next_operations = 0; // 重置计数器
    ne[0] = -1;
    int j = -1;

    for(int i=1; i<p.length(); i++){
        next_operations++; // 外层循环入口判断
        while(j>=0) {
            next_operations++; // 进入while条件判断
            if(p[i] != p[j+1]){
                j = ne[j];
                next_operations++; // 字符比较操作
            } else {
                break;
            }
        }
        next_operations++; // 退出while后的字符比较
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
}



int kmp(string s, string t){
    int i = 0, j = 0;
    kmp_operations = 0; // 重置计数器
    while(i < s.length() && j < t.length()){
        kmp_operations++; // 进入循环的条件判断
        if(s[i] == t[j]){
            kmp_operations++; // 字符比较操作
            i++, j++;
        } else {
            kmp_operations++; // 字符比较操作
            j = ne[j];
            if(j == -1){
                i++, j = 0;
            }
        }
        if(j == t.length()){
            return i-j;
        }
    }
    return -1;
}


string generate_pattern(int n) {
    _ftime(&T);
    srand(T.millitm);

    string t = "a";
    for(int i = 0; i < n; i++){
        t += rand() % 26 + 'a'; // 随机生成小写字母
        if(i % 5 == 0) t += "a"; // 偶数位插入b
    }
    return t;
}

string generate_text(string t) {
    _ftime(&T);
    srand(T.millitm);

    string s;
    int m = t.length() * 10; // 文本串长度为模式串10倍
    for(int i = 0; i < m; i++){
        s += rand() % 26 + 'a'; // 随机生成小写字母
        if(i % 7 == 0){
            int len = rand() % (t.length() - 2);
            s += t.substr(0, len);
        }
    }
    s += t;
    return s;
}

int main() {
    
    for(int n = 10; n <= 200; n+=5) {
        string t = generate_pattern(n);
        string s = generate_text(t);
        
        // 重置计数器
        next_operations = 0;
        kmp_operations = 0;
        bf_operations = 0;
        
        // 执行核心逻辑
        getNext(t);
        kmp(s, t);
        BF(s, t);
        
        // 输出CSV格式数据
        cout << n << "\t" 
            << next_operations << "\t" 
            << kmp_operations << "\t"
            << bf_operations << endl;
    }
    return 0;
}
