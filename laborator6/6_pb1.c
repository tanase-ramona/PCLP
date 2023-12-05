#include <stdio.h>

void f (int v[ ], int n)
{
    int ok=0;
    int i, j, aux;
    while(!ok)
    {
        ok=1;
        for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        if(v[i]>v[j])
        {
            aux=v[j];
            v[j]=v[i];
            v[i]=aux;
            ok=0;
        }
    }
}

int main()
{
    int n, v[10000], i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &v[i]);
    f(v, n);
    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\n");    

}