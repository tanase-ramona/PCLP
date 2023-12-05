#include <stdio.h>

struct multime {
    int a;
};

void init(struct multime *m) {
    (*m).a = 0;
}

void add(struct multime *m, int x) {
    (*m).a = (*m).a | (1 << x);
}

void del(struct multime *m, int x) {
    (*m).a = (*m).a & ~(1 << x);
}

void print(struct multime *m) {
    int nr=0;
    while(nr < 9) {
        if(((*m).a >> nr) & 1 == 1) {
            printf("%d ", nr);
        }
        nr++;
    }
    printf("\n");
}

int contains(struct multime *m, int x) {
    if(((*m).a >> x) & 1 == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct multime m;
    int i, x, y, n;
    scanf("%d", &n);
    init(&m);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        add(&m, x);
    }
    print(&m);
    scanf("%d", &y);
    //print(&m);
    del(&m, y);
    print(&m);
    int z;
    scanf("%d", &z);
    printf("%d\n", contains(&m, z));
}
