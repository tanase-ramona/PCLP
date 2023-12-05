#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x, y, delta;
    scanf("%f%f%f", &a, &b, &c);
    if(a==0 && b==0 && c==0) 
     printf("Infinit\n");
     else if(a==0) {
                     x=-c/b;
                     printf("%.2f\n", x);

                   }
     else {
            delta=b*b-4*a*c;
            if(delta==0)
             {
                x=-b/(2*a);
                printf("%.2f\n", x);

             }

             else if(delta>0)
             {
                x=(-b-sqrt(delta))/(2*a);
                y=(-b+sqrt(delta))/(2*a);
                printf("%.2f %.2f\n", x, y);


             }
             else printf("Nu exista solutii\n");

          }              
}