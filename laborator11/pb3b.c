#include <stdio.h>
#include <string.h>

int main() {
  char filename[100], ch;
  // citire caracter ce da comanda specifica
  scanf("%c", ch);
  scanf("%s", filename);
  // create fisier
  FILE *in;
  in = fopen(filename, "rt");
  if (!in) {
    fprintf(stderr, "Cannot open %s\n", filename);
    return -1;
  }
  int x, ok=0;
  char s[100], cuv[100], cps[100], *p;
  int nrlinie=0, linafis=0;
  // citire cuvant de cautat
  scanf("%s", cuv);
  // citire sir de caractere de pe fiecare linie
  while ( fgets(s, 100, in) != NULL ) {
    ok=0;
    // contorizeaza nr liniei curente
    nrlinie++;
    strcpy(cps, s);
    // impartim sirul pe cuvinte si le comparam 
    // cu cuv
    p=strtok(cps, " ");
    while(p) {
        if(strcmp(p, cuv)==0)
        ok=1;
        p=strtok(NULL, " ");
    }
    if(ok) {
        linafis++;
        // afisam nr liniei care contine cuv
        // in cazul in care caracterul a fost 'n'
        if(ch=='n') printf("[%d] ", nrlinie);
        printf("%s\n", s);

    }
  }
    // afisam nr liniilor care contine cuv
    // in cazul in care caracterul a fost 'c'
  if(ch=='c') {
    printf("Numarul total de linii:\n");
    printf("%d", linafis);
  }
  fclose(in);
  return 0;
}
