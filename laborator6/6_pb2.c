#include <stdio.h>
#include <math.h>

void f2 (double a, double b, double c, double *A, double *B, double *C)
{
    double unghi_1, unghi_2, unghi_3;
    unghi_1 = acos((b*b+c*c-a*a)/(2*b*c));
    unghi_2 = acos((c*c+a*a-b*b)/(2*a*c));
    unghi_3 = acos((b*b+a*a-c*c)/(2*b*a));

    *A = unghi_1;
    *B = unghi_2;
    *C = unghi_3;

}

void f1 (double l[3], double u[3])
{
    u[0]=acos((l[1]*l[1]+l[2]*l[2]-l[0]*l[0])/(2*l[1]*l[2]))*180/M_PI;
    u[1]=acos((l[0]*l[0]+l[2]*l[2]-l[1]*l[1])/(2*l[0]*l[2]))*180/M_PI;
    u[2]=acos((l[0]*l[0]+l[1]*l[1]-l[2]*l[2])/(2*l[1]*l[0]))*180/M_PI;
}

int main()
{
    double lat[10], ung[10], a, b, c, A, B, C;
    int i;
    for(i=0; i<3; i++)
     scanf("%lf", &lat[i]);
    f1(lat, ung);
    for(i=0; i<3; i++)
     printf("%lf ", ung[i]);
    printf("\n");

   
    a=lat[0];
    b=lat[1];
    c=lat[2];
    f2(a, b, c, &A, &B, &C);
    printf("%lf %lf %lf ", A, B, C); 
    printf("\n");
   


    
}