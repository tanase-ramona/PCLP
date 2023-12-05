#include <stdio.h>

int main()
{
    float x, y;
    scanf("%f%f", &x, &y);
    if(x>=0 && y>=0) printf("1");
     else if(x<=0 && y>=0) printf("2");
      else if(x<=0 && y<=0) printf("3");
       else if(x>=0 && y<=0) printf("4");
       printf("\n");


}