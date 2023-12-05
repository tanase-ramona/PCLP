#include <stdio.h>
#include <string.h>

int main() {
  char filename[100];
  scanf("%s", filename);
  // creare fisier din care citim codificarea
  FILE *in;
  in = fopen(filename, "rt");
  if (!in) {
    fprintf(stderr, "Cannot open %s\n", filename);
    return -1;
  }

  char filename1[100];
  scanf("%s", filename1);
  // creare fisier din care citim textul de modificat
  FILE *in1;
  in = fopen(filename1, "rt");
  if (!in1) {
    fprintf(stderr, "Cannot open %s\n", filename);
    return -1;
  }

  char filename2[100];
  scanf("%s", filename2);
  // creare fisier in care afisam textul modificat
  FILE *out = fopen(filename2, "wt");
  if (!out) {
    fprintf(stderr, "Cannot open %s\n", filename);
    return -1;
  }

  char s[100], cod[3][1000], c;
  int i;
  // initiem matricea cu caracterul NULL
  for(i=0; i<=1000; i++)
  cod[0][i]=NULL;
  // matricea cod va contine pe linia 0 pe coloana 
  // data de codul ascii al literelor ce trebuie codate, 
  // litera corespunzatoare de dupa codare
  while ( fgets(s, 100, in1) != NULL ) {
    cod[0][(int)s[0]]=s[2];

  }
  while ( fgets(s, 100, in) != NULL ) {
    // parcurgem sirurile de pe fiecare linie
    // caracter cu caracter si codificam literele 
    for(i=0; i<strlen(s); i++) {
        if(cod[0][(int)s[i]] != NULL)
        s[i]=cod[0][(int)s[i]];
    }
    fprintf(out, "%s\n", s);
  
  }
  fclose(in1);
  fclose(in);
  fclose(out);
  return 0;
}
