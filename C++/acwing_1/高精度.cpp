#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool cmp(vector<int> a, vector<int> b){
    if(a.size() != b.size()) return a.size() > b.size();
    else{
        for(int i = a.size() - 1; i >= 0; i--){
            if(a[i] != b[i]) return a[i] > b[i];
        }
        return true;
    }
}

vector<int> add(vector<int> a, vector<int> b){
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size() || i < b.size(); i ++){
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t%10);
        t /= 10;
    }
    if(t) c.push_back(t);
    return c;
}
vector<int> sub(vector<int> a, vector<int> b){
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size() || i < b.size(); i ++){
        t = a[i] - t;
        if(i < b.size()) t -= b[i];
        c.push_back((t+10)%10);
        if(t < 0) t = 1;
        else t = 0;
    }

    while(c.size() > 1 && c.back() == 0) c.pop_back();

    return c;
}
vector<int> mul(vector<int> a, int b){
    vector<int> c;
    if(b == 0){
        c.push_back(0);
        return c;
    }
    int t = 0;
    
    for(int i = 0; i < a.size() || t; i++){
        if(a.size() > i) t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
vector<int> div(vector<int> a, int b, int &r){
    vector<int> c;

    r = 0;
    for(int i = a.size()-1; i >= 0; i--){
        r = r * 10 + a[i];
        c.push_back(r/b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back() == 0)c.pop_back();
    return c;
}

int main(){
    //string a, b;
    //vector<int> A, B;
    vector<int> c;

    string a;
    vector<int> A;
    int b;

    std::cin >> a >> b;

    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');

    //for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

    /*c = add(A, B);

    for(int i = c.size()-1; i >= 0; i --) cout << c[i];
    cout << endl;*/

    /*if(cmp(A, B)){
        c = sub(A, B);
    }
    else{
        cout << "-";
        c = sub(B, A);
    }
    for(int i = c.size()-1; i >= 0; i --) cout << c[i];
    c = mul(A, b);*/
    int r = 0;
    c = div(A, b, r);
    for(int i = c.size()-1; i >= 0; i --) cout << c[i];
    cout << endl << r;
    cout << endl;
}