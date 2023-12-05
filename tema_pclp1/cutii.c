#include <stdio.h>

#define const 501
// Functie care verifica da prizonierul
// al nr-lea a gasit cutia cu numarul sau.
// Rezultatul este returnat prin variabila ok
int gasit(int v[], int n, int nr) {
  int i, ok = 0, poz = nr - 1;
  for (i = 0; i < n / 2; i++) {
    if (v[poz] == nr) {
      ok = 1;
    } else {
      poz = v[poz] - 1;
    }
  }
  return ok;
}

// functie care afiseaza ciclurile
void cicluri(int v[], int n) {
  int i = 0, primul;
  // Variabila care retine numarul de elemente
  // care deja fac parte dintr-un ciclu la un
  // moment dat
  int nrgasit = 0;
  int curent;
  // Vectorul indica daca un element face parte
  // dintr-un ciclu
  int gasit[const] = {0};
  while (nrgasit != n && i < n) {
    curent = i;
    primul = v[i];
    while (gasit[curent] == 0) {
      gasit[curent] = 1;
      if (v[v[curent] - 1] == primul) {
        printf("%d", curent + 1);
      } else {
        printf("%d ", curent + 1);
      }
      curent = v[curent] - 1;
      nrgasit++;
    }
    nrgasit--;
    i++;
    if (gasit[i] == 0) {
      printf("\n");
    }
  }
}

int main() {
  int P, cutie[const], i, evadare = 1;
  scanf("%d", & P);
  // citire cutii
  for (i = 0; i < P; i++) {
    scanf("%d", & cutie[i]);
  }
  // verifica daca prizonierul P a
  // evadat sau nu
  for (i = 1; i <= P; i++) {
    if (!gasit(cutie, P, i)) {
      evadare = 0;
    }
  }
  if (evadare) {
    printf("Da\n");
  } else {
    printf("Nu\n");
  }
  cicluri(cutie, P);
}
