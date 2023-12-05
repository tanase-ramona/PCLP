#include <stdio.h>

char* substr(char *src, int n, char *dest)
{
    int i, p=-1;
    for(i=0; i<n; i++)
     dest[++p]=src[i];
    dest[n+1]='\0'; 
}


int main()
{
    char sir[100], sir_extras[100];
    int poz, n;
    fgets(sir, 100, stdin);
    scanf("%d%d", &poz, &n);
    substr(sir+poz, n, sir_extras);
    printf("%s", sir_extras);
}