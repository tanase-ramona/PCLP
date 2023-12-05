#include <stdio.h>
#include <string.h>

char *strdel(char *p, int n)
{
    strcpy(p, p+n);

}

char *strins(char *p, char *s)
{
    strcat(s, p);
    strcpy(p, s);
}

int main()
{
    char sir_initial[3000], sir_de_inlocuit[200], sir_cu_care_se_inlocuieste[200], aux[3000], rez[3000];
    int n, lg;
    gets(sir_initial);
    gets(sir_de_inlocuit);
    gets(sir_cu_care_se_inlocuieste);
    n=strlen(sir_de_inlocuit);
    char *p=strtok(sir_initial, " ");
    while(p)
    {
        lg=strlen(p);
        if(strstr(p, sir_de_inlocuit))
        {
          
          if(strstr(p, sir_de_inlocuit)==p)
           {

            if(lg==n)
            {
                strcat(rez, sir_cu_care_se_inlocuieste);
                strcat(rez, " ");
            }
            else
            {
                strdel(p, n);
                strcpy(aux, sir_cu_care_se_inlocuieste);
                strins(p, aux);
                strcat(rez, aux);
                strcat(rez, " ");
            }
           }
          else if(strstr(p, sir_de_inlocuit)+n==NULL)
          { 
             //strcpy(p+(strstr(aux, sir_de_inlocuit)-p), sir_cu_care_se_inlocuieste);
            //strcat(rez, p);
             //strcat(rez, " ");
             p[strstr(p, sir_de_inlocuit)-p]=NULL;
             strcat(rez, p);
             strcat(rez, sir_cu_care_se_inlocuieste);
             strcat(rez, " ");    


          }
          else
          {
            strcpy(aux, strstr(aux, sir_de_inlocuit)+n);
            p[strstr(p, sir_de_inlocuit)-p]=NULL;
            strins(sir_cu_care_se_inlocuieste, p);
            strins(aux, p);
            strcat(rez, p);
            strcat(rez, " ");

          }
        }

        p=strtok(NULL, " ");   
    }

    strcat(rez, "\0");
    strcpy(sir_initial, rez);
    printf("%s\n", rez);



    /*
    strdel(s, n);     // sterge n caractere din pozitia p->fct 1
    printf("%s\n", s);

    strins(p,s);      // insereaza la p, sirul s->fct 2
    printf("%s", p);
    */
   
}