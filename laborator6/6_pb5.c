#include <stdio.h>
#include <string.h>

void transform (int v[ ], int n, int x)
{
    int mici[101], mari[101], dim1=-1, dim2=-1, i;
    for(int i=0; i<n; i++)
     if(v[i]<x) mici[++dim1]=v[i];
     else  if(v[i]>=x) mari[++dim2]=v[i];
     int k=-1;
    for(i=0; i<=dim1; i++)
     v[++k]=mici[i];
    for(i=0; i<=dim2; i++)
     v[++k]=mari[i];
}

int main()
{
   int v[101], x, n, i;
   scanf("%d%d", &n, &x);
   for(i=0; i<n; i++)
    scanf("%d", &v[i]);
   transform(v, n, x);
   for(i=0; i<n; i++)
    printf("%d ", v[i]);
    printf("\n");


}
