#include <stdio.h>
#include <string.h>

int f(char v1[ ], char v2[ ])
{
    int i=0;
    while(v1[i] && v2[i])
    {
        if(v1[i]>v2[i]) return 1;
        else if(v1[i]<v2[i]) return -1;
        i++;

    }
    return 0;
}

int main()
{
    char v1[100], v2[100];
    scanf("%s", v1);
    scanf("%s", v2);
    int rez=f(v1, v2);
    printf("%d", rez);
    printf("\n");

}
