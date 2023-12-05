#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define const 101

#define const3 100

#define const2 21

struct masini {
  char * brand, * numar, * combustibil;
  double consum;
  int km;
};

// functie care calculeaza numarul de masini de fiecare tip
// in fucntie de combustibil
void tip(struct masini * v, int n, int * nr_benzina, int * nr_motorina, int * nr_hibrid, int * nr_electric) {
  int i;
  for (i = 0; i < n; i++) {
    if (strcmp(v[i].combustibil, "benzina") == 0) {
      * nr_benzina = * nr_benzina + 1;
    } else if (strcmp(v[i].combustibil, "motorina") == 0) {
      * nr_motorina = * nr_motorina + 1;
    } else if (strcmp(v[i].combustibil, "hibrid") == 0) {
      * nr_hibrid = * nr_hibrid + 1;
    } else if (strcmp(v[i].combustibil, "electric") == 0) {
      * nr_electric = * nr_electric + 1;
    }
  }
}

// functie care calculeaza numarul de litri consumati de
// fiecare tip de masini, in fucntie de brand
void consum(struct masini * v, int n, double nr_litri[], int gasit[]) {
  // retine pentru fiecare masina daca i-a fost calculat consumul
  int gas[const] = {0};
  int i, j;
  for (i = 0; i < n ; i++) {
    if (gas[i] == 0) {
      gas[i] = 1;
      nr_litri[i] = (double)((v[i].consum * (double)v[i].km) / (double)const3);
      gasit[i]=1;
      for (j = i + 1; j < n; j++) {
        if (strcmp(v[j].brand, v[i].brand) == 0) {
          if (gas[j] == 0) {
            gas[j] = 1;
            nr_litri[i] = nr_litri[i] + (double)((v[j].consum * (double)v[j].km) / (double)const3);
          }
        }
      }
    }
  }
}

// functie care verifica daca numarul masinii este valid
void numar(struct masini * v, int n, int valid[]) {
  int i, j, nrlit = 0, nrcf, ok, nrlit2, k;
  for (i = 0; i < n; i++) {
    nrlit = 0;
    nrlit2 = 0;
    nrcf = 0;
    ok = 0;
    j = 0;
    // calculeaza numarul de litere de la inceputul numerului
    while (v[i].numar[j] >= 'A' && v[i].numar[j] <= 'Z') {
      nrlit++;
      j++;
      ok = 1;
    }
    // calculeaza numarul de cifre din numar
    while (v[i].numar[j] >= '0' && v[i].numar[j] <= '9' && ok) {
      nrcf++;
      j++;
    }
    // calculeaza numarul de litere de la finalul nuamrului
    for (k = j; k < strlen(v[i].numar); k++) {
      if (v[i].numar[k] >= 'A' && v[i].numar[k] <= 'Z')
        nrlit2++;
    }
    // verifica conditiile 
    if (nrlit == 1 || nrlit == 2) {
      if (nrcf == 3 || nrcf == 2) {
        if (nrlit2 == 3) {
          valid[i] = 1;
        } else {
            valid[i] = 0;
        }
      } else {
        valid[i] = 0;
      }
    } else {
        valid[i] = 0;
    }
  }
}

int main() {
  int N, i, nr_benzina, nr_motorina, nr_electric, nr_hibrid, valid[const], ok = 1;
  // vector care retine pe ce pozitie s-a calculat consumul
  // pentru masina de un anumit brand
  int gasit[const]={0};
  double nr_litri[const] = {-1}, pret;
  nr_benzina = 0;
  nr_motorina = 0;
  nr_electric = 0;
  nr_hibrid = 0;
  char aux[const2], op;
  struct masini * v;
  scanf("%d", & N);
  // alocam dinamic memorie pentru vectorul de masini v
  v = malloc(N * sizeof(struct masini));
  // citim fiecare camp al strucutrii
  for (i = 0; i < N; i++) {
    scanf("%s", aux);
    v[i].brand = malloc((strlen(aux) + 1) * sizeof(char));
    strcpy(v[i].brand, aux);
    scanf("%s", aux);
    v[i].numar = malloc((strlen(aux) + 1) * sizeof(char));
    strcpy(v[i].numar, aux);
    scanf("%s", aux);
    v[i].combustibil = malloc((strlen(aux) + 1) * sizeof(char));
    strcpy(v[i].combustibil, aux);
    scanf("%lf", & (v[i].consum));
    scanf("%d", & (v[i].km));
  }
  scanf(" %c", & op);
  // in functie de operatia citita apelam functia necesara
  if (op == 'a') {
    tip(v, N, & nr_benzina, & nr_motorina, & nr_hibrid, & nr_electric);
    printf("benzina - %d\n", nr_benzina);
    printf("motorina - %d\n", nr_motorina);
    printf("hibrid - %d\n", nr_hibrid);
    printf("electric - %d\n", nr_electric);
  } else if (op == 'b') {
    consum(v, N, nr_litri, gasit);
    for (i = 0; i < N; i++) {
      if (nr_litri[i]!=-1 && gasit[i]!=0) {
        if (strcmp(v[i].combustibil, "benzina") == 0) pret = 8.02;
        else if (strcmp(v[i].combustibil, "motorina") == 0) pret = 9.29;
        else if (strcmp(v[i].combustibil, "hibrid") == 0) pret = 8.02;
        else if (strcmp(v[i].combustibil, "electric") == 0) pret = 0.0;
        printf("%s a consumat %.2lf - %.2lf lei\n", v[i].brand, nr_litri[i], nr_litri[i] * pret);
      }
    }
  } else if (op == 'c') {
    numar(v, N, valid);
    for (i = 0; i < N; i++)
      if (valid[i] == 0) {
        printf("%s cu numarul %s: numar invalid\n", v[i].brand, v[i].numar);
        ok = 0;
      }
    if (ok == 1) {
      printf("Numere corecte!\n");
    }
  }
   for (i = 0; i < N; i++) {
    free(v[i].brand);
    free(v[i].numar);
    free(v[i].combustibil); 
  }
  free(v);
}
