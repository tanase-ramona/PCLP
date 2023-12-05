#include <stdio.h>
#include <stdlib.h>

void init_vector(int *a, int nr) {
    int x;
    a = malloc(nr * sizeof(int));
    int i;
    for( i = 0; i < nr; i++) {
        scanf("%d", &x);
        a[i] = x;
    }
}

void adauga_vector(int *a, int *nr, int n) {
    *nr = *nr + 1;
    a = realloc( a, * nr * sizeof(int));
    a[ *nr - 1 ] = n;
}

void scrie_vector(int *a, int nr){
    int i;
    for( i = 0; i < nr; i++) {
        printf("%d ", a[ i ]);
    }
    printf("\n");
}

int main()
{
    int * v, cap, n;
    scanf("%d", &cap);
    init_vector(v, cap);
    scanf("%d", &n);
    // adauga_vector(v, &cap, n);
    scrie_vector(v, cap);


}