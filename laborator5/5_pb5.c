#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2)-(y1-y2)*(y1-y2));
}

int main()
{
    int n, x, y, i, coordonate[100][3]={0}, distanta, distanta+maxima=-1;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        scanf("%d%d", coordonate[i][0], coordonate[i][1]);
    for(i=1; i<n; i++)
        for(j=i+1; j<=n; j++)
    {
        distanta=dist(coordonate[i][0], coordonate[i][1], coordonate[j][0], coordonate[j][1]);
        if (distanta>distanta_maxima)
        distanta_maxima=distanta;
    }
        
    

}
