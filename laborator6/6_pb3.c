#include <stdio.h>

void f(int a[ ], int b[ ], int c[ ], int n, int m)
{
    int i, j, dim=-1;
    for(i=0; i<n; i++)
     for(j=0; j<m; j++)
      if(a[i]==b[j])
       {
        c[++dim]=a[i];
        break;
       }

    printf("%d", dim+1);
    printf("\n");
    for(i=0; i<=dim; i++)
     printf("%d ", c[i]);
    printf("\n"); 


}

int main()
{
    int n, i, m, a[1001], b[1001], c[1001];
    scanf("%d", &n);
    for(i=0; i<n; i++)
     scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i=0; i<m; i++)
     scanf("%d", &b[i]);
    f(a, b, c, n, m);

     

}