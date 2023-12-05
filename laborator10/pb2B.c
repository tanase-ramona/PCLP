#include <stdio.h>
#include <stdlib.h>

#define CONST 100

struct set {
    unsigned int n; // maximum number of elements
    unsigned char *a;
};

// Initialize the set m with the empty set
void init(struct set *m, int dim) {
    m->n = dim;
    m->a = (unsigned char*) calloc((dim+7)/8, sizeof(unsigned char));
}

// Add x to the set m
void add(struct set *m, int x) {
    if (x < m->n)
        m->a[x/8] |= 1 << (x%8);
}

// Delete x from the set m
void del(struct set *m, int x) {
    if (x < m->n)
        m->a[x/8] &= ~(1 << (x%8));
}

// Display the set m
void print(struct set *m) {
    for (int i = 0; i < m->n; i++) {
        if (m->a[i/8] & (1 << (i%8))) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Return 1 if x is in the set m and 0 otherwise
int contains(struct set *m, int x) {
    return (x < m->n) && (m->a[x/8] & (1 << (x%8)));
}

int main() {
    struct set m;
    /*init(&m);
    add(&m, 4);
    add(&m, 7);
    add(&m, 11);
    print(&m);
    del(&m, 7);
    print(&m);
    if (contains(&m, 11)) printf("YES\n");
    else printf("NO\n");
    return 0; */
    char op;
    int nr, n, i;
    scanf("%d", &n);
    init(&m, n);
    for(i = 0; i < n; i++) {
        scanf("%c", &op);
        if(op == 'A') {
            scanf("%d", &nr);
            add(&m, nr);           
        } else if(op == 'D') {
            scanf("%d", &nr);
            del(&m, nr);
        } else if(op == 'C') {
            scanf("%d", &nr);
            if (contains(&m, nr)) {
                printf("DA\n");
            } else {
                printf("NU\n");
            }
        } else if(op == 'P') {
                print(&m);
        }
    }
}