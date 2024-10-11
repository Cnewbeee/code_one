#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itos(int num, char *head){
    char res[4];
    char a[9];
    memset(res, '\0', 4);
    memset(a, '\0', 9);
    while(num > 0){
        char t[10];
        a[0] = num % 10 + '0';
        num /= 10;
        strcpy(t, a);
        strcat(t, res);
        strcpy(res, t);
    }
    strcat(res, ":");
    strcpy(head, res);
}

void substr(char *str, int start, int end, char *sub){
    int len = end - start + 1;
    for(int i = 0; i < len; i++){
        sub[i] = str[start+i];
    }
    sub[len] = '\0';
}

int main() {
    char str[100];
    char in[9999], in1[9999];
    int line = 0, op = 0;
    FILE *fp = fopen("string.in", "rt");
    FILE *fp2 = fopen("string.out", "wt");

    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
        if(str[i] == '*'){
            op = 1;
        }
        if(str[i] == '['){
            op = 2;
        }
        if(str[i] == '^'){
            op = 3;
        }
    }
    //printf("test_1 str: %s\n", str);

    while(1){
        line++;
        char out[999], head[4];
        int cnt = 0;
        itos(line, head);
        if(feof(fp)){
            break;
        }
        strcpy(out, head);
        memset(in, '\0', 999);
        memset(in1, '\0', 999);
        
        fgets(in1, 999, fp);
        
        for(int i = 0; in1[i] != '\0'; i++){
            if(in1[i] >= 'A' && in1[i] <= 'Z'){
                in[i] = in1[i] + 32;
            }else{
                in[i] = in1[i];
            }
        }
        //printf("test_2 getline: %s\n", in1);

        for(int i = 0; in[i] != '\0'; i++){
            if(in[i] == str[0] || str[0] == '*' || str[0] == '['){
                //printf("test_3\n");
                int k = i;
                int j = 0;
                if(op == 0){
                    while(in[k] != '\0' && str[j] != '\0' && in[k] == str[j])k++,j++;
                    if(str[j] == '\0'){
                        cnt++;
                        char temp[100];
                        substr(in1, i, k-1, temp);
                        ////printf("test_4 temp: %s\n", temp);
                        if(cnt != 1){
                            strcat(out, ",");
                        }
                        strcat(out, temp);
                    }
                }else if(op == 1){
                    while(in[k] != '\0' && str[j] != '\0' && in[k] == str[j])k++,j++;
                    if(str[j] == '*'){
                        while(str[j+1] != in[k] && in[k] != '\0')k++;
                        if(in[k] == str[j+1]){
                            j++;
                            //printf("test_8 in: %c str: %c\n", in[k], str[j]);
                            while(in[k] != '\0' && str[j] != '\0' && in[k] == str[j])k++,j++;
                            //printf("test_9 in: %c str: %c\n", in[k], str[j]);
                            if(str[j] == '\0'){
                                cnt++;
                                char temp[100];
                                substr(in1, i, k-1, temp);
                                if(cnt != 1){
                                    strcat(out, ",");
                                }
                                strcat(out, temp);
                            }
                        }
                    }
                }else if(op == 2){
                    while(in[k] != '\0' && str[j] != '\0' && in[k] == str[j])k++,j++;
                    if(str[j] == '['){
                        int j1 = j;
                        char cs[25];
                        while(str[j1] != ']' && str[j1] != '\0')
                            j1++;
                        if(str[j1] == ']'){
                            substr(str, j+1, j1-1, cs);
                            ////printf("test_3 cs: %s\n", cs);
                            j = j1+1;
                        }
                        for(int k1 = 0; k1 < strlen(cs); k1++){
                            if(in[k] == cs[k1]){
                                k++;
                                while(in[k] != '\0' && str[j] != '\0' && in[k] == str[j])k++,j++;
                                if(str[j] == '\0'){
                                    cnt++;
                                    char temp[100];
                                    substr(in1, i, k-1, temp);
                                    if(cnt != 1){
                                        strcat(out, ",");
                                    }
                                    strcat(out, temp);
                                }
                            }
                        }
                    }
                }else if(op == 3){
                    while(in[k] != '\0' && str[j] != '\0' && in[k] == str[j])k++,j++;
                    if(str[j] == '['){
                        int j1 = j;
                        int r = 0;
                        char cs[25];
                        while(str[j1] != ']' && str[j1] != '\0')
                            j1++;
                        if(str[j1] == ']'){
                            substr(str, j+2, j1-1, cs);
                            ////printf("test_3 cs: %s\n", cs);
                            j = j1+1;
                        }
                        for(int k1 = 0; cs[k1] != '\0'; k1++){
                            if(in[k] == cs[k1]){
                                r++;
                                break;
                            }
                        }
                        if(!r){
                            k++;
                            while(in[k] != '\0' && str[j] != '\0' && in[k] == str[j])k++,j++;
                            if(str[j] == '\0'){
                                cnt++;
                                char temp[100];
                                substr(in1, i, k-1, temp);
                                if(cnt != 1){
                                    strcat(out, ",");
                                }
                                strcat(out, temp);
                            }
                        }
                    }
                }
            }
        }
        if(cnt != 0){
            fprintf(fp2, "%s\n", out);
            //printf("%s\n", out);
        }
    }
    fclose(fp); fclose(fp2);    
    return 0;
}