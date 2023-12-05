#include <stdio.h>

#include <stdlib.h>

#define const 1001

// functie care transforma un numar din baza 10
// in baza 2 si retine rezultatul intr-un vector
void binar(int x, int v[], int * nrcif) {
  int poz = -1, aux[const], j = -1, i;
  while (x > 0) {
    aux[++poz] = x % 2;
    x = x / 2;
  }
  for (i = 0; i <= poz; i++) {
    v[++j] = aux[i];
  }
  * nrcif = poz + 1;
}

// fucntie care aduna 2 numere binare dupa
// regula: 0 + 0 =0, 0 + 1 / 1 + 0 = 1,
// 1 + 1 = 0
void adunare(int nr1[], int nr2[]) {
  // variabila t retine transportul, in cazul in care
  // suma depaseste valoarea 1, ce va fi adaugat la urmatorul
  // pas
  int i, aux, t = 0;
  for (i = 3; i >= 0; i--) {
    aux = nr1[i] + nr2[i];
    if (aux + t < 2) {
      nr1[i] = aux + t;
      t = 0;
    } else if (aux + t == 2) {
      nr1[i] = 0;
      t = 1;
    } else if (aux + t > 2) {
      nr1[i] = 1;
      t = 1;
    }
  }
}

// functie ce interschimba valoarea a 2 variabile
void swap(int * a, int * b) {
  int aux = * a;
  * a = * b;
  * b = aux;
}

// functie ce interschimba bitul de pe pozița p1 cu bitul de
// pe poziția p2 pentru primul număr, unde p1 reprezintă primii
// 2 biți din al doilea număr, iar p2 reprezintă ultimii doi biți
// din al doilea număr
void interschimbare(int nr1[], int nr2[]) {
  int p1, p2;
  p1 = nr2[0] * 2 + nr2[1] * 1;
  p2 = nr2[2] * 2 + nr2[3] * 1;
  swap( & nr1[p1], & nr1[p2]);
}

// functie ce roteste fiecare bit din nr1 la stânga
// de nr2 ori
void rotatie_la_stanga(int nr1[], int nr2[]) {
  int nr, aux, i, j;
  nr = nr2[0] * 8 + nr2[1] * 4 +
    nr2[2] * 2 + nr2[3] * 1;
  for (i = 0; i < nr; i++) {
    aux = nr1[0];
    for (j = 0; j < 3; j++) {
      nr1[j] = nr1[j + 1];
    }
    nr1[3] = aux;
  }
}

// functie ce face sau exclusiv pe biti
void xor(int nr1[], int nr2[]) {
  int i;
  for (i = 0; i < 4; i++) {
    nr1[i] = nr1[i] ^ nr2[i];
  }
}

int main() {
  int N, M, Mbin[const], i, nrcif, nrop = 0;
  int k, poz, nr1[const], nr2[const], op[const];
  // vector de pointeri la functiile cu cele 4 operatii
  void( * o[4])(int * , int * ) = {
    adunare,
    interschimbare,
    rotatie_la_stanga,
    xor
  };
  scanf("%d%d", & N, & M);
  // in vectorul Mbin retinem valoarea lui M in binar
  binar(M, Mbin, & nrcif);
  // folosim primii N * 6 + 4 biti
  poz = N * 6 + 4;
  // extragem primul numar
  k = -1;
  for (i = 0; i < 4; i++) {
    nr1[++k] = Mbin[--poz];
    nrcif--;
  }
  while (nrop != N) {
    // extragem operatia 
    k = -1;
    for (i = 0; i <= 1; i++) {
      op[++k] = Mbin[--poz];
      nrcif--;
    }
    nrop++;
    // extragem al doilea numar
    k = -1;
    for (i = 0; i <= 3; i++) {
      nr2[++k] = Mbin[--poz];
      nrcif--;
    }
    // in functie de operatie apelam :
    // adunare
    if (op[0] == 0 && op[1] == 0) {
      ( * o[0])(nr1, nr2);
      // interschimbare
    } else if (op[0] == 0 && op[1] == 1) {
      ( * o[1])(nr1, nr2);
      // rotatie la stanga
    } else if (op[0] == 1 && op[1] == 0) {
      ( * o[2])(nr1, nr2);
      //xor
    } else if (op[0] == 1 && op[1] == 1) {
      ( * o[3])(nr1, nr2);
    }
  }
  // fiecare functie retine rezultatul partial in nr1
  // la final in nr1 vom avea rezultatul in binar si il
  // transformam in zecimal
  int nr = nr1[0] * 8 + nr1[1] * 4 +
    nr1[2] * 2 + nr1[3] * 1;
  printf("%d", nr);
}
