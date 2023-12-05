#include <stdio.h>

int main()
{
    float x;
    double y, sx=0, sy=0;
    double i, n, pas=0;
    scanf("%lf%f%lf", &n, &x, &y);
    for(i=0; i<n; i++)
    {
        pas++;
        sx+=x;
        sy+=y;
        if(pas==n/10)
        {
            pas=0;
            printf("%f %e ", sx, sx);
            printf("%f %e\n", sy, sy);

        }
        
    }

}