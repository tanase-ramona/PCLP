#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char s[101], s2[101], aux[101];
    char *p;
    scanf("%d", &n); //citire nr de cuv
    gets();  
    fgets(s, 101, stdin);            //citire sir
    p=strtok(s, " ");
    strcpy(s2, p);
    strcpy(aux, p);
    p=strtok(NULL, " ");
    while(p)
    {
        
        if((p[0]==aux[strlen(aux)-2] || p[0]==aux[strlen(aux)-2]-32 || p[0]==aux[strlen(aux)-2]+32) && (p[1]==aux[strlen(aux)-1] || p[1]==aux[strlen(aux)-1]-32 || p[1]==aux[strlen(aux)-1]+32 ))
          {
            strcat(s2,"-");
            strcat(s2, p);
            strcpy(aux, p);

          }
        p=strtok(NULL, " ");

    }
    printf("%s\n", s2);


}