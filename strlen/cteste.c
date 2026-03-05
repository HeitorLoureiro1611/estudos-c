#include <stdio.h>
#include <stdbool.h>

int main(void){

    char s[100];
    char *Ps = s;
    int len = 0;

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    while(*Ps != '\0'){
        *Ps++;
        len++;
    }

    printf("The string is %d characters long\n", len-1);
    return 0;
}
