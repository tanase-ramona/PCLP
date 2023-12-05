#include <stdio.h>

int main()
{
    int n, i, poz=0, m, nrlin=0;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
    {
        
        if(poz==m) {
                    printf("\n");
                    poz=0;
                    nrlin++;
                    if(nrlin==25){
                                    printf("\n");
                                    nrlin=0;
                           
                                }
                   }
        printf("%d ", i);
        poz++;
    }              
}