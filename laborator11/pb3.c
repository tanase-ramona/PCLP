#include <stdio.h>
#include <string.h>

int main() {
  char filename[100];
  // citire nume fisier
  scanf("%s", filename);
  FILE *in;
  in = fopen(filename, "rt");
  if (!in) {
    fprintf(stderr, "Cannot open %s\n", filename);
    return -1;
  }
  int x, ok=0;
  char s[100], cuv[100], cps[100], *p;
  // citire cuvant de cautat
  scanf("%s", cuv);
  // citire linii din fisier
  while ( fgets(s, 100, in) != NULL ) {
    ok=0;
    // facem copie sirului de pe fiecare linie
    strcpy(cps, s);
    // despartim sirul pe cuvinte si le comparam 
    // cu cuv
    p=strtok(cps, " ");
    while(p) {
        if(strcmp(p, cuv)==0)
        ok=1;
        p=strtok(NULL, " ");
    }
    if(ok) printf("%s\n", s);
  }
  fclose(in);
  return 0;
}
