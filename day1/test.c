#include <stdio.h>

int main(void){

    FILE *in;
    in = fopen("test.txt", "r");

    int n;
    fscanf(in, "%d", &n);
    printf("%d\n", n);
    
    return 0;
}
