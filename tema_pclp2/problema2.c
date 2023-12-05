#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define const 100

// definirea structurii pentru cuvintele din dictionar
struct dictionary_entry {
  char * word;
  int priority;
};

// functie care adauga un cuvant nou in dictionar
void adaugare(char cuv[], struct dictionary_entry ** d, int * N) {
  // marim dimensiunea dictionarului cu un loc pentru
  // noul cuvant
  * N = * N + 1;
  // realocam memorie pentru noua dimensiune si introducem 
  // cuvantul cu prioritate 1
  * d = realloc( * d, * N * sizeof(struct dictionary_entry));
  ( * d)[ * N - 1].word = malloc((strlen(cuv) + 1) * sizeof(char));
  strcpy(( * d)[ * N - 1].word, cuv);
  ( * d)[ * N - 1].priority = 1;
}

// functie care afiseaza cuvantul completat sau nu in functie
// de caz
void afis(char cuv[], struct dictionary_entry ** d, int * N) {
  char cuvdeafis[const];
  int i, ok = 0, nrap, poz;
  // cuvant cu '*', care trebuie afisat in forma sa initiala
  if (cuv[strlen(cuv) - 1] == '*') {
    ok = 0;
    // eliminam '*' de la final
    cuv[strlen(cuv) - 1] = '\0';
    // cautam cuvantul in dictionar si daca il gasim ii
    // marim prioritatea
    for (i = 0; i < * N; i++) {
      if (strcmp(( * d)[i].word, cuv) == 0) {
        ok = 1;
        ( * d)[i].priority = ( * d)[i].priority + 1;
      }
    }
    printf("%s ", cuv);
    // daca cuvantul nu apare in dictionar il adaugam
    if (ok == 0) {
      adaugare(cuv, d, N);
    }
  } else {
    //cuvant ce trebuie completat din dictionar
    nrap = -1;
    ok = 0;
    // parcurgem cuvintele din dictionar
    for (i = 0; i < * N; i++) {
      // daca gasim in dictionar termen cu prefixul
      // cuvantul cautat
      if (strstr(( * d)[i].word, cuv) - ( * d)[i].word == 0) {
        // retinem in 'cuvdeafis' termenul din
        // dictionar cu prioritatea cea mai mare
        ok = 1;
        if (( * d)[i].priority > nrap) {
          nrap = ( * d)[i].priority;
          poz = i;
          strcpy(cuvdeafis, ( * d)[i].word);

        } else if (( * d)[i].priority == nrap) {
          // daca 2 termeni au aceeasi prioritate
          // retinem in 'cuvdeafis' termenul mai
          // mic din punct de vedere lexicografic
          if (strcmp(( * d)[poz].word, ( * d)[i].word) > 0) {
            strcpy(cuvdeafis, ( * d)[i].word);
            poz = i;
          }
        }

      }
    }
    // daca nu am gasit cuvnatul in dictionar(ok == 0), il afisam
    // in forma in care este dat si il introducem in dictionar
    if (ok == 0) {
      printf("%s ", cuv);
      adaugare(cuv, d, N);
    } else {
      // daca am gasit cuvantul in dictionar il afisam
      // in forma completata
      printf("%s ", ( * d)[poz].word);
      ( * d)[poz].priority = ( * d)[poz].priority + 1;
    }
  }
}

int main() {
  int N, M, i;
  struct dictionary_entry * d;
  char cuv[const], aux[const];
  scanf("%d", & N);
  // alocam dinamic memorie pentru N cuvinte
  d = malloc(N * sizeof(struct dictionary_entry));
  for (i = 0; i < N; i++) {
    scanf("%s", aux);
    // alocam dinamic memorie pentru catacterele
    // necesare cuvantului ce urmeaza a fi retinut
    d[i].word = malloc((strlen(aux) + 1) * sizeof(char));
    strcpy(d[i].word, aux);
    d[i].priority = 0;
  }
  scanf("%d", & M);
  // citim cuvintele si le cautam pe rand in dictionar
  for (i = 0; i < M; i++) {
    scanf("%s", cuv);
    afis(cuv, & d, & N);
  }
  free( d );
}
