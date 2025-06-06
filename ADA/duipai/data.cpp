#include <bits/stdc++.h>
#include<sys/timeb.h>
int main()
{
	struct _timeb T;
    _ftime(&T);
    srand(T.millitm); 
	
    freopen("in.txt", "w", stdout); 
    int a = (rand() % 1000 + 10), b = rand() % 1000 + 10;
    printf("%d %d\n", a, b);
}

