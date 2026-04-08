#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main(void)
{
    int n;
    scanf("%d", &n);

    unsigned *dp = calloc(n + 1, sizeof(unsigned));
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && i - j >= 0; j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    printf("%u\n", dp[n]);
    free(dp);
    return 0;
}
