#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    while (n--) {
        unsigned long long x, y;
        scanf("%llu %llu", &y, &x);

        unsigned long long m = x > y ? x : y;   // max
        unsigned long long k = x > y ? y : x;   // min
        int d = (x >= y) == (m % 2);  // 0 = ascending, 1 = negative
        unsigned long long val = d * (m * m - k + 1) + (1 - d) * ((m - 1) * (m - 1) + k);

        printf("%llu\n", val);
    }
    return 0;
}
