#include <stdio.h>

int prim(int n)
{
  int d;
  if (n == 0) return 0;
  if (n == 1 || n == 2) return 1;
  if (n%2 == 0) return 0; 
  for (d=2; d*d<=n; d++) 
  if (n%d == 0) return 0;
  return 1;

}

void Gb(int n)
{
  int i;
  for(i=1; i<=n/2; i++)
  {
    if( prim (i) && prim ( n-i ))
    printf("%d + %d\n", i, n-i);

  }

}

int main()
{
  int n;
  scanf("%d", &n);
  //printf("%d", prim(n));
  Gb (n);
   

}
