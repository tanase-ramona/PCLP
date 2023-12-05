#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a==b && a==c)
     printf("echilateral");
     else if(a==b || a==c || b==c)
      printf("isoscel");
      else if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b)
       printf("dreptunghic");
        else printf("oarecare");
    printf("\n");   
}