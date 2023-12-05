#include <stdio.h>

int main()
{
    int H, M, S;
    if(scanf("%d%d%d", &H, &M, &S)==3)
     printf("%#02d:%#02d:%#02d\n", H, M, S);
     else printf("Date incorect introduse!\n");
}