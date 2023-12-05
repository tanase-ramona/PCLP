#include <stdio.h>

#include <string.h>

#define ascii 48

// functie care aduna 2 numere a si b
void adunare(char a[], char b[], int n) {
  int i, j, aux = 0;
  // adunarea partii reale
  // a si b sunt simultan negative
  // (-a-b=-(a+b)) sau simultan pozitive (a+b)
  if ((a[0] == '0' && b[0] == '0') || (a[0] == '1' && b[0] == '1')) {
    aux = 0;
    for (i = (n - 1) / 2 - 1; i >= 1; i--) {
      aux = a[i] - ascii + b[i] - ascii + aux;
      a[i] = aux % 10 + ascii;
      aux = aux / 10;
    }
  } else {
    // a este pozitiv si b negativ (a+(-b)=a-b)
    if (a[0] == '0' && b[0] == '1') {
    // comparam numerele a si b
    i = 1;
    while (a[i] == b[i] && i < (n - 1) / 2 - 1) {
      i++;
    }
    // a>=b care devine a-b
    if (a[i] >= b[i]) {
      a[0] = '0';
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (a[i] >= b[i]) {
          a[i] = a[i] - b[i] + ascii;
        } else {
          j = i - 1;
          while (a[j] == '0') {
            a[j] = '9';
            j--;
          }
          a[j]--;
          a[i] = 10 + a[i] - b[i] + ascii;
        }
      }
    } else {
      // a<b care devine -(b-a)
      a[0] = '1';
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (b[i] >= a[i]) {
          a[i] = b[i] - a[i] + ascii;
        } else {
          j = i - 1;
          while (b[j] == '0') {
            b[j] = '9';
            j--;
          }
          b[j]--;
          a[i] = 10 + b[i] - a[i] + ascii;
        }
      }
    }
  } else {
    // a este negativ si b pozitiv (-a+b)
    // comparam numere a si b
    i = 1;
    while (a[i] == b[i] && i < (n - 1) / 2 - 1) {
      i++;
    }
    // a>=b care devine -(a-b)
    if (a[i] >= b[i]) {
      a[0] = '1';
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (a[i] >= b[i]) {
          a[i] = a[i] - b[i] + ascii;
        } else {
          j = i - 1;
          while (a[j] == '0') {
            a[j] = '9';
            j--;
          }
          a[j]--;
          a[i] = 10 + a[i] - b[i] + ascii;
        }
      }
    } else {
      // a<b care devine b-a
      a[0] = '0';
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (b[i] >= a[i]) {
          a[i] = b[i] - a[i] + ascii;
        } else {
          j = i - 1;
          while (b[j] == '0') {
            b[j] = '9';
            j--;
          }
          b[j]--;
          a[i] = 10 + b[i] - a[i] + ascii;
        }
      }
    }
  }
  }
  // adunarea partii imaginare
  // a si b sunt simultan negativa sau
  // simultan pozitive
  if ((a[(n - 1) / 2] == '0' && b[(n - 1) / 2] == '0') || (a[(n - 1) / 2] == '1' && b[(n - 1) / 2] == '1')) {
    aux = 0;
    for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
      aux = a[i] - ascii + b[i] - ascii + aux;
      a[i] = aux % 10 + ascii;
      aux = aux / 10;
    }
  } else {
    // a este pozitiv si b negativ (a-b)
    if (a[(n - 1) / 2] == '0' && b[(n - 1) / 2] == '1') {
    // comparam cele 2 numere
    i = (n - 1) / 2 + 1;
    while (a[i] == b[i] && i < n - 2) {
      i++;
    }
    // a>=b care devine a-b
    if (a[i] >= b[i]) {
      a[(n - 1) / 2] = '0';
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (a[i] >= b[i]) {
          a[i] = a[i] - b[i] + ascii;
        } else {
          j = i - 1;
          while (a[j] == '0') {
            a[j] = '9';
            j--;
          }
          a[j]--;
          a[i] = 10 + a[i] - b[i] + ascii;
        }
      }
    } else {
      // a<b care devine -(b-a)
      a[(n - 1) / 2] = '1';
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (b[i] >= a[i]) {
          a[i] = b[i] - a[i] + ascii;
        } else {
          j = i - 1;
          while (b[j] == '0') {
            b[j] = '9';
            j--;
          }
          b[j]--;
          a[i] = 10 + b[i] - a[i] + ascii;
        }
      }
    }
  } else {
    if (a[(n - 1) / 2] == '1' && b[(n - 1) / 2] == '0') {
    // a este negativ si b pozitiv (-a+b)
    // comparam cele 2 numere
    i = (n - 1) / 2 + 1;
    while (a[i] == b[i] && i < n - 2) {
      i++;
    }
    // a>=b care devine -(a-b)
    if (a[i] >= b[i]) {
      a[(n - 1) / 2] = '1';
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (a[i] >= b[i]) {
          a[i] = a[i] - b[i] + ascii;
        } else {
          j = i - 1;
          while (a[j] == '0') {
            a[j] = '9';
            j--;
          }
          a[j]--;
          a[i] = 10 + a[i] - b[i] + ascii;
        }
      }
    } else {
      // a<b care devine b-a
      a[(n - 1) / 2] = '0';
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (b[i] >= a[i]) {
          a[i] = b[i] - a[i] + ascii;
        } else {
          j = i - 1;
          while (b[j] == '0') {
            b[j] = '9';
            j--;
          }
          b[j]--;
          a[i] = 10 + b[i] - a[i] + ascii;
        }
      }
    }
  }
  }
  }
}

// functie care scade 2 numere a si b
void scadere(char a[], char b[], int n) {
  int i, j, aux = 0;
  // scaderea partii reale
  // a este negativ si b pozitiv (-a-(+b)=-(a+b))
  // sau a este pozitiv si b negativ (a-(-b)=a+b)
  if ((a[0] == '0' && b[0] == '1') || (a[0] == '1' && b[0] == '0')) {
    aux = 0;
    for (i = (n - 1) / 2 - 1; i >= 1; i--) {
      aux = a[i] - ascii + b[i] - ascii + aux;
      a[i] = aux % 10 + ascii;
      aux = aux / 10;
    }
  } else if (a[0] == '0' && b[0] == '0') {
    // a e pozitiv si b negativ (a-b)
    // comparam cele 2 numere
    i = 1;
    while (a[i] == b[i] && i < (n - 1) / 2 - 1) {
      i++;
    }
    // a>b care devine a-b
    if (a[i] >= b[i]) {
      a[0] = '0';
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (a[i] >= b[i]) {
          a[i] = a[i] - b[i] + ascii;
        } else {
          j = i - 1;
          while (a[j] == '0') {
            a[j] = '9';
            j--;
          }
          a[j]--;
          a[i] = 10 + a[i] - b[i] + ascii;
        }
      }
    } else {
      // a<b care devine -(b-a)
      a[0] = '1';
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (b[i] >= a[i]) {
          a[i] = b[i] - a[i] + ascii;
        } else {
          j = i - 1;
          while (b[j] == '0') {
            b[j] = '9';
            j--;
          }
          b[j]--;
          a[i] = 10 + b[i] - a[i] + ascii;
        }
      }
    }
  } else {
    // a si b sunt negative (-a-(-b)=-a+b)
    // comparam cele 2 numere
    i = 1;
    while (a[i] == b[i] && i < (n - 1) / 2 - 1) {
      i++;
    }
    // a>b care devine -(a-b)
    if (a[i] >= b[i]) {
      a[0] = '1';
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (a[i] >= b[i]) {
          a[i] = a[i] - b[i] + ascii;
        } else {
          j = i - 1;
          while (a[j] == '0') {
            a[j] = '9';
            j--;
          }
          a[j]--;
          a[i] = 10 + a[i] - b[i] + ascii;
        }
      }
    } else {
      // a<b care devine b-a
      a[0] = '0';
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (b[i] >= a[i]) {
          a[i] = b[i] - a[i] + ascii;
        } else {
          j = i - 1;
          while (b[j] == '0') {
            b[j] = '9';
            j--;
          }
          b[j]--;
          a[i] = 10 + b[i] - a[i] + ascii;
        }
      }
    }
  }
  // scaderea partii imaginare
  // a este negativ si b pozitiv (-a-(+b)=-(a+b))
  // sau a este pozitiv si b negativ (a-(-b)=a+b)
  if ((a[(n - 1) / 2] == '0' && b[(n - 1) / 2] == '1') || (a[(n - 1) / 2] == '1' && b[(n - 1) / 2] == '0')) {
    aux = 0;
    for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
      aux = a[i] - ascii + b[i] - ascii + aux;
      a[i] = aux % 10 + ascii;
      aux = aux / 10;
    }
  } else if (a[(n - 1) / 2] == '0' && b[(n - 1) / 2] == '0') {
    // a este pozitiv si b negativ (a-b)
    // comparam cele 2 numere
    i = (n - 1) / 2 + 1;
    while (a[i] == b[i] && i < n - 2) {
      i++;
    }
    // a>b care devine a-b
    if (a[i] >= b[i]) {
      a[(n - 1) / 2] = '0';
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (a[i] >= b[i]) {
          a[i] = a[i] - b[i] + ascii;
        } else {
          j = i - 1;
          while (a[j] == '0') {
            a[j] = '9';
            j--;
          }
          a[j]--;
          a[i] = 10 + a[i] - b[i] + ascii;
        }
      }
    } else {
      // a<b care devine -(b-a)
      a[(n - 1) / 2] = '1';
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (b[i] >= a[i]) {
          a[i] = b[i] - a[i] + ascii;
        } else {
          j = i - 1;
          while (b[j] == '0') {
            b[j] = '9';
            j--;
          }
          b[j]--;
          a[i] = 10 + b[i] - a[i] + ascii;
        }
      }
    }
  } else {
    // a este negativ si b pozitiv (-a+b)
    // comparam cele 2 numere
    i = (n - 1) / 2 + 1;
    while (a[i] == b[i] && i < n - 2) {
      i++;
    }
    // a>b care devine -(a-b)
    if (a[i] >= b[i]) {
      a[(n - 1) / 2] = '1';
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (a[i] >= b[i]) {
          a[i] = a[i] - b[i] + ascii;
        } else {
          j = i - 1;
          while (a[j] == '0') {
            a[j] = '9';
            j--;
          }
          a[j]--;
          a[i] = 10 + a[i] - b[i] + ascii;
        }
      }
    } else {
      // a<b care devine (b-a)
      a[(n - 1) / 2] = '0';
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (b[i] >= a[i]) {
          a[i] = b[i] - a[i] + ascii;
        } else {
          j = i - 1;
          while (b[j] == '0') {
            b[j] = '9';
            j--;
          }
          b[j]--;
          a[i] = 10 + b[i] - a[i] + ascii;
        }
      }
    }
  }
}

#define const 1001

int main() {
  int N;
  char a[const], b[const], op;
  scanf("%d", & N);
  scanf("%s", a);
  scanf(" %c", & op);
  while (op != '0') {
    scanf(" %s", b);
    if (op == '-') {
      scadere(a, b, N);
      printf("%s\n", a);
    } else {
      adunare(a, b, N);
      printf("%s\n", a);
    }
    scanf(" %c", & op);
  }
}
