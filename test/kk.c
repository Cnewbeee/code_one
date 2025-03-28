#include <stdio.h>
main()
{
    int a = 6, b = 7, m = 1;
    switch (a % 2)
    {
    case 0:
        m++;
        break;
    case 1:
        m++;
        switch (b % 2)
        {
        defaut:
            m++;
        case0:
            m++;
            break;
        }
    }
    printf("%d\n", m);
}