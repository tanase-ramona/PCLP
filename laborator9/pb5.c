#include <stdio.h>
#include <stdlib.h>

struct complex {
     float re, im;
};

void adunare_complex ( struct complex *a, struct complex *b) {
    *a.re = *a.re + *b.re;
    *a.im = *a.im + *b.im;
}

void scadere_complex ( struct complex *a, struct complex *b) {
    *a.re = *a.re - *b.re;
    *a.im = *a.im - *b.im;
}

void inmultire_complex ( struct complex *a, struct complex *b) {
    *a.re = *a.re * *b.re - a.im + *b.im ;
    *a.im = *a.re * *b.im + a.im * *b.re;
}

void putere_complex ( struct complex *a, int putere) {
    float real, imaginar;
    
}

int main() {
    complex x;

}   