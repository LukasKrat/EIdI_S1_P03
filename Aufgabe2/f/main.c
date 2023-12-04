#include<stdio.h>
#include "myDateFunctions.h"

int main() {
    int input[12] = {2000,1,1,14,05,0};
    printf("%d\n", toUnixtime(input));
    long long ts = toUnixtime(input);
    printf("%d\n", toUnixtime(input));
    printf("%d\n", ts);
    printf("%s\n", unixtimeToString(ts));
    return 0;
}