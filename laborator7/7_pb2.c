#include <stdio.h>

void count(int n, int *v, int *zero, int *poz, int *neg)
{
  int i;
  for(i=0; i<n; i++)
   if(v[i]==0) *zero=*zero+1;
   else if(v[i]>0) *poz=*poz+1;
   else *neg=*neg+1;
}

int main()
{
    int n, v[100], i, poz=0, neg=0, zero=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
     scanf("%d", &v[i]);
    count(n, v, &zero, &poz, &neg);
    printf("%d %d %d\n", zero, poz, neg);

}