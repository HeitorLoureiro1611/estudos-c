#include <stdio.h>

void troca(int *p1,int *p2){

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}

int main(void){

    int a = 23;
    int b = 98;
    int *pa = &a;
    int *pb = &b;

    printf("%d -> %p\n", a, &a);
    printf("%d -> %p\n", b, &b);

    troca(pa, pb);

    printf("%d -> %p\n", a, &a);
    printf("%d -> %p\n", b, &b);

    return 0;
}
