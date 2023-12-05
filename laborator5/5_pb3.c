#include <stdio.h>

int cmmmc(int a, int b)
{ 
    int copie_a=a, copie_b=b, rest;
    while(copie_b)
    {
        rest=copie_a%copie_b;
        copie_a=copie_b;
        copie_b=rest;
    }
    return (a*b)/copie_a;


}
int main()
{
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
   // printf("\n%d\n", cmmmc(y1, y2));
    int numitor_comun=cmmmc(y1, y2);   //numitor comun
    printf("%d %d\n%d %d", x1*(numitor_comun/y1), numitor_comun, x2*(numitor_comun/y2), numitor_comun);
    
    


}
