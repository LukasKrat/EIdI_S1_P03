#include<stdio.h>
#include "myDateFunctions.h"

int main() {
    int input[12] = {2000,1,1,14,05,0};
    int input2[12] = {2001,1,1,14,05,0};
    // printf("%lld\n", toUnixtime(input));
    // long long ts = toUnixtime(input);
    // long long ts2 = toUnixtime(input2);
    // printf("%lld\n", toUnixtime(input));
    // printf("%lld\n", ts);
    // printf("%s\n", unixtimeToString(ts));
    printf("%d", compare(input, input2));
    return 0;
}