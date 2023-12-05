#include <stdio.h>

#include <string.h>

#define const1 51

#define const2 501
// sorteaza caracterele din cheie dupa codul ascii
// dar fara a interschimba elementele: ordinea
// caracterelor ordonate e retinuta cu ajutorul
// indicilor in vectorul indici[ ]
void sortare(char cheie[const1], int indici[const1]) {
  int i, j, nr;
  char ch, aux[const1];
  strcpy(aux, cheie);
  for (i = 0; i < strlen(aux); i++)
    indici[i] = i;
  for (i = 0; i < strlen(aux) - 1; i++)
    for (j = i + 1; j < strlen(aux); j++) {
      if (aux[i] > aux[j]) {
        ch = aux[i];
        aux[i] = aux[j];
        aux[j] = ch;
        nr = indici[i];
        indici[i] = indici[j];
        indici[j] = nr;
      }
    }
}

void CodificareA(char s[const2], char cheie[const1]) {
  char m[const2][const2];
  int i, j, nc = strlen(cheie), nl, k = -1, indici[const1], poz = -1;
  // calculam numar linii
    if ((strlen(s)) % nc) {
    nl = (strlen(s)) / nc + 2;
  } else {
     nl = (strlen(s)) / nc + 1;
  }
  // initializam matricea cu spatii
  for (i = 0; i < nl; i++)
    for (j = 0; j < nc; j++)
      m[i][j] = ' ';
  // linia 0 din matrice este initializata
  // cu caracterele din cheie
  for (j = 0; j < nc; j++) {
    m[0][j] = cheie[j];
  }
  // adaugam sirul in magtrice
  for (i = 1; i < nl; i++)
    for (j = 0; j < nc && s[++k] != '\0'; j++) {
      m[i][j] = s[k];
    }
  sortare(cheie, indici);
  // citim coloanele din matricea in fucntie de ordinea
  // data de vectorul indici, unde le-am ordonat
  for (j = 0; j < nc; j++) {
    for (i = 1; i < nl; i++) {
      if (m[i][indici[j]] == '\n' || m[i][indici[j]] == '\0') m[i][indici[j]] = ' ';
      s[++poz] = m[i][indici[j]];
    }
  }
  s[++poz] = '\0';
  printf("%s\n", s);
}

void CodificareB(char s[], int n) {
  int i;
  char aux[const2], cps[const2];
  // facem o copie lui s
  strcpy(cps, s);
  // retinem in aux ultimele n caractere
  // ce urmeaza a fi modificate
  strcpy(aux, cps + strlen(cps) - n);
  // stergem ultimele n caractere din copie
  cps[strlen(cps) - n] = '\0';
  // modificam caracterele din aux
  for (i = 0; i < strlen(aux); i++) {
    if (aux[i] >= 'a' && aux[i] <= 'z') {
      if (aux[i] + n > 'z') {
        aux[i] = 'A' + (aux[i] + n - 'z' - 1);
      } else {
        aux[i] += n;
      }
    } else if (aux[i] >= 'A' && aux[i] <= 'Z') {
      if (aux[i] + n > 'Z') {
        aux[i] = 'a' + (aux[i] + n - 'Z' - 1);
      } else {
        aux[i] += n;
      }
    }
  }
  // lipim cele 2 siruri modificate
  strcat(aux, cps);
  strcpy(s, aux);
  printf("%s\n", s);
}

void DecodificareA(char s[], char cheie[]) {
  char m[const2][const2];
  int i, j, nc = strlen(cheie), nl, k = -1, indici[const1], poz = -1;
  // calculam numarul de linii
  if ((strlen(s)) % nc) {
    nl = strlen(s) / nc + 2;
  } else {
    nl = strlen(s) / nc + 1;
  }
  // initializam matricea cu spatii
  for (i = 0; i < nl; i++)
    for (j = 0; j < nc; j++)
      m[i][j] = ' ';
  // initializam prima linie din matrice
  // cu caracterele din cheie
  for (j = 0; j < nc; j++) {
    m[0][j] = cheie[j];
  }
  sortare(cheie, indici);
  // adaugam caracterele sirului in matrice pe coloane
  // in ordinea data de vectorul indici, unde le-am ordonat
  for (j = 0; j < nc; j++)
    for (i = 1; i < nl && s[++k] != '\0'; i++) {
      m[i][indici[j]] = s[k];
    }
  for (i = 1; i < nl; i++) {
    for (j = 0; j < nc; j++) {
      if (m[i][j] == '\n' || m[i][j] == '\0') m[i][j] = ' ';
      s[++poz] = m[i][j];
    }
  }
  s[++poz] = '\0';
  printf("%s\n", s);
}

void DecodificareB(char s[], int n) {
  int i;
  char aux[const2], aux2[const2], cps[const2];
  // facem copie sirului s
  strcpy(cps, s);
  // adaugam in aux primele n caractere din sir
  strncpy(aux, cps, n);
  aux[n] = '\0';
  // pastram in copie doar caracterele pe care
  // nu le am pus in aux
  strcpy(aux2, cps + n);
  strcpy(cps, aux2);
  // modificam aux
  for (i = 0; i < strlen(aux); i++)
    if (aux[i] >= 'a' && aux[i] <= 'z') {
      if (aux[i] - n < 'a') {
        aux[i] = 'Z' - ('a' - aux[i] + n) + 1;
      } else {
        aux[i] -= n;
      }
    } else if (aux[i] >= 'A' && aux[i] <= 'Z') {
    if (aux[i] - n < 'A') {
      aux[i] = 'z' - ('A' - aux[i] + n) + 1;
    } else {
      aux[i] -= n;
    }
  }
  strcat(cps, aux);
  strcpy(s, cps);
  printf("%s\n", s);
}

int main() {
  char s[const2], cheie[const1], comanda[const2], aux[const1];
  int n;
  fgets(s, const2, stdin);
  s[strlen(s) - 1] = '\0';
  scanf("%s", comanda);
  // in functie de comanda vom apela functia
  // corespunzatoare
  while (strcmp(comanda, "STOP")) {
    if (strcmp(comanda, "CodificareA") == 0) {
      fgets(cheie, const1, stdin);
      strcpy(aux, cheie + 1);
      strcpy(cheie, aux);
      cheie[strlen(cheie) - 1] = '\0';
      CodificareA(s, cheie);
    } else if (strcmp(comanda, "CodificareB") == 0) {
      scanf("%d", & n);
      CodificareB(s, n);
    } else if (strcmp(comanda, "DecodificareA") == 0) {
      fgets(cheie, const1, stdin);
      strcpy(aux, cheie + 1);
      strcpy(cheie, aux);
      cheie[strlen(cheie) - 1] = '\0';
      DecodificareA(s, cheie);
    } else if (strcmp(comanda, "DecodificareB") == 0) {
      scanf("%d", & n);
      DecodificareB(s, n);
    }
    scanf("%s", comanda);
  }
}
