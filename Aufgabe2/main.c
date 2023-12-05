#include<stdio.h>
#include "myDateFunctions.h"

int main() {
    int input[12] = {2023,12,1,15,12,0};
    printf("%lld\n", toUnixtime(input));
    return 0;
}