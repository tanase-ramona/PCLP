#include <stdio.h>

double putere(double x, int n)
{
    double i, put=1;
    for(i=1; i<=n; i++) 
    put=put*x;
    return put;
      
}

int factorial(int n)
{
    int i, fact=1;
    for(i=1; i<=n; i++)
    fact=fact*i;
    return fact;
}

double taylor(double x, int n)
{
    double i, sum_taylor=1;
    for(i=1; i<=n; i++)
    sum_taylor+=putere(x,i)/factorial(i);
    return sum_taylor;

}

int main()
{
    double X;
    int N;
    scanf("%lf%d", &X, &N);
    //printf("%lf", putere(X,N));
    //printf("%d", factorial(N));
    printf("%lf\n", taylor(X, N));


}
