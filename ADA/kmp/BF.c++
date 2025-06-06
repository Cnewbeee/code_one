#include<iostream>

using namespace std;

int BF(string s, string t){

    for(int i = 0; i < s.length(); i++){
        if(s[i] == t[0]){
            for(int j = 1; j < t.length(); j++){
                if(s[i+j]!= t[j]){
                    break;
                }
                if(j == t.length()-1){
                    return i;
                }
            }
        }
    }
    return -1;
}

int main(){
    string s = "abcdaacavafgacaf";
    string t = "acaf";

    int ans = BF(s, t);

    if(ans == -1){
        cout << "Not found" << endl;
    }else{
        cout << "Found at index " << ans << endl;
    }

    return 0;
}