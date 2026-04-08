#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

unsigned *memo;

unsigned recurse(int n)
{
    if (n == 0)
        return 1;
    if (memo[n] != 0)
        return memo[n];

    unsigned count = 0;
    for (int i = 1; i <= 6 && n - i >= 0; i++) {
        count = (count + recurse(n - i)) % MOD;
    }

    memo[n] = count;
    return count;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    memo = calloc(n + 1, sizeof(unsigned));
    printf("%u\n", recurse(n));
    free(memo);
    return EXIT_SUCCESS;
}
