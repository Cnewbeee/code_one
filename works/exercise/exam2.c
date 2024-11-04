#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    char w[100][100];
    

    while(fgets(str, 100, stdin)!= NULL){
        memset(w, '\0', sizeof(w));
        int p = 0, r = 0;
        int i = 0, j = 0;
        for(i = 0; str[i] != ' '; i++){
            w[p][i] = str[i];
        }
        p++;
        for(; str[i] != '('; i++);
        for(i++; str[i] != ')'; i++){
            if(r == 0 && str[i] != ' '){
                w[p][j] = str[i];
                j++;
            }else if(r == 0 && str[i] == ' ' && j!= 0){
                p++;
                r = 1;
                j = 0;
            }else if(r == 1 && str[i] == ','){
                r = 0;
            }
        }
        for(int k = 0; k < p; k++){
            for(int l = 0; w[k][l] != '\0'; l++){
                printf("%c", w[k][l]);
            }
            printf(" ");
        }
        printf("\n");
    }
}