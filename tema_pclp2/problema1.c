#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define const 101

#define const2 110

// functie care primeste ca argument textul in care cautam
// cuvinte de subliniat, o cheie si un vector aux in care
// retinem sublinierea
void subliniere(char s[], char cuv[], char aux[]) {
  int k = 0, i, j, start, nrspatii;
  // daca in cheie exista spatiu il eliminam, de ex
  // first of -> forstof
  for (i = 0; i < strlen(cuv); i++) {
    if (cuv[i] == ' ') {
      for (j = i; j < strlen(cuv); j++) {
        cuv[j] = cuv[j + 1];
      }
    }
  }
  // parcurgem sirul si il comparam caracter cu caracter
  // cu cheia 
  i = 0;
  while (i < strlen(s)) {
    // verificam daca ne aflam la inceput de cuvant
    if (s[i] >= 'a' && s[i] <= 'z' && (s[i - 1] == ' ' || i == 0)) {
      if (s[i] == cuv[k]) {
        // in variabila start retinem pozitia la care
        // textul corescpunde cu cheia
        start = i;
        while (s[i] == cuv[k] && cuv[k] != '\0') {
          // in variabila nrspatii retinem peste cate spatii
          // am trecut in text, la compararea cu cheia, la
          // fiecare caracter
          nrspatii = 0;
          // k reprezinta pozitia carcterului din cheie
          // pe care il comparam
          k++;
          // i reprezinta pozitia carcterului din text
          // pe care il comparam
          i++;
          // trecem peste spatii in text, pentru a
          // compara doar literele
          while (s[i] == ' ') {
            i++;
            nrspatii++;
          }
        }
        k--;
        // daca am parcurs toata cheia si aceasta corescpunde
        // cu un intreg cuvant din text, il subliniem
        if (k == strlen(cuv) - 1 && (s[i - 1] == ' ' || i == strlen(s))) {
          for (j = start; j < i - nrspatii; j++) {
            aux[j] = '_';
          }
        }
        k = 0;
      } else {
        i++;
      }
    } else {
      i++;
    }
  }
}

int main() {
  char ** text, aux[const2];
  int N, i, j, l, nrcol = -1;
  scanf("%d", & N);
  // alocarea dinamica si citirea matricei de caractere
  // (vector de c uvinte) "text", in care retinem textul 
  text = malloc((N + 1) * sizeof(char * ));
  for (i = 0; i <= N; i++) {
    fgets(aux, const2, stdin);
    l = strlen(aux);
    aux[l - 1] = '\0';
    if (l > nrcol) {
      nrcol = l;
    }
    text[i] = malloc((strlen(aux) + 1) * sizeof(char));
    strcpy(text[i], aux);
  }
  // cream vectorul de cuvinte in care retinem cheile
  char cheie[101][101];
  strcpy(cheie[0], "first of");
  strcpy(cheie[1], "for");
  strcpy(cheie[2], "for each");
  strcpy(cheie[3], "from");
  strcpy(cheie[4], "in");
  strcpy(cheie[5], "is");
  strcpy(cheie[6], "is a");
  strcpy(cheie[7], "list of");
  strcpy(cheie[8], "unit");
  strcpy(cheie[9], "or");
  strcpy(cheie[10], "while");
  strcpy(cheie[11], "int");
  strcpy(cheie[12], "float");
  strcpy(cheie[13], "double");
  strcpy(cheie[14], "string");
  // pentru fiecare linie de text cautam cuvinte de
  // subliniat (cuvinte care corespund cheilor) si
  // afisam atat textul, cat si sublinierea aferenta
  int k;
  for (i = 1; i <= N; i++) {
    // vectorul aux va retine sublinierile,
    // in rest il initializam cu ' '(spatiu)
    for (k = 0; k < strlen(text[i]); k++) {
      aux[k] = ' ';
    }
    aux[strlen(text[i])] = '\0';
    for (j = 0; j < 15; j++) {
      subliniere(text[i], cheie[j], aux);
    }
    printf("%s\n%s\n", text[i], aux);
  }
  free(text);
}
