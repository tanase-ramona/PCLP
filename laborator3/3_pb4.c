#include <stdio.h>

int sumcif(int n)
{
    int s=0;
    while(n)
    {
        s+=n%10;
        n/=10;
    }

    return s;
}

int main()
{
    int x, y, s;
    scanf("%d", &x);
    while(x!=0)
    {
        scanf("%d", &y);
        s=sumcif(x);
        if(y==x%s) printf("(%d, %d)\n", x, y);
        x=y;


    }
}