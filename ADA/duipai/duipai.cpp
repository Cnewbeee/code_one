#include <bits/stdc++.h>
using namespace std;

int main() {
    while (1) {
        system("data.exe");
        system("baoli.exe");
        system("std.exe");
        
        if (system("cmd /c fc std.txt baoli.txt")) {
            cout << "error" << endl;
            char in[100];
            char baoli[100];
            char std_output[100]; 
            
            ifstream da("in.txt");
            ifstream bao("baoli.txt");
            ifstream biao("std.txt");
            
            if (da.is_open()) {
                da.getline(in, 100);
                bao.getline(baoli, 100);
                biao.getline(std_output, 100); 
                
                cout << "     in: " << in << endl;
                cout << "std out: " << std_output << endl; 
                cout << "    out: " << baoli << endl;
            }
            getchar();
        }
    }
    return 0;
}
