#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 2

struct materia {
    char name[10];
    int course_hours;
    char exam_type;
};

void citire_MAT(struct materia *mat) {
    int i;
    char aux[15], ch;
    fgets(aux, 20, stdin);
    aux[strlen(aux)-1] = '\0';
    for (i = 0; i < strlen(aux); i++) {
        if (!isalpha(aux[i]) && aux[i] != ' ') {
            printf("Nume invalid\n");
        }
    }
    strcpy(mat->name, aux);
    fflush(stdin);
    //gets();
    scanf("%d", &mat->course_hours);
    if (mat->course_hours <= 0) {
        printf("Ore invalide\n");
    }
    //fflush(stdin);
    ch = getchar();
    //gets();
    scanf("%c", &mat->exam_type);
    if (mat->exam_type != 'C' && mat->exam_type != 'S' && mat->exam_type != 'A') {
        printf("Tip invalid\n");
    }
    //fflush(stdin);
    ch = getchar();
    //gets();
}

void citire_programa( struct materia p[ ]) {
    int i, n = MAX;
    for(i = 0; i < n; i++) {
        citire_MAT(&(p[i]));
    }
}

void afisare_programa(char exam_type, int course_hours, struct materia p[]) {
    int i, n = MAX;
    for (i = 0; i < n; i++) {
        if (p[i].exam_type == exam_type && p[i].course_hours == course_hours) {
            printf("%s\n", p[i].name);
            printf("%d\n", p[i].course_hours);
            printf("%c\n", p[i].exam_type);
        }
    }
}
void afisare(struct materia p[]) {
    int i, n = MAX;
    for (i = 0; i < n; i++) {
        printf("%s\n", p[i].name);
        printf("%d\n", p[i].course_hours);
        printf("%c\n", p[i].exam_type);
        
    }
}

int main() {
    struct materia m;
    /*citire_MAT(&m);
    printf("%s\n", m.name);
    printf("%d\n", m.course_hours);
    printf("%c\n", m.exam_type);
    */
    struct materia p[MAX]; 
    citire_programa(p);
    char exam_type;
    int course_hours;
    scanf("%c%d", &exam_type, &course_hours);
    afisare_programa(exam_type, course_hours, p);
    //afisare(p);
}
