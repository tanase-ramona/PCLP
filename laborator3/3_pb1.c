#include <stdio.h>

int main()
{
    int ch, n=0;
    for(ch=31; ch<=127; ch++)
    {
        n++;
        if(n==10) {
                    printf("\n");
                    n=0;
                  }
        printf("%c = c%d ", ch, ch);
    }

}