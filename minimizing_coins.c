#include <stdlib.h>
#include <stdio.h>

int *coins;
int *memos;

int main(int argc, char **argv)
{
    int num_coins, sum;
    scanf("%d %d", &num_coins, &sum);
    coins = (int *)calloc(num_coins, sizeof(int));
    memos = (int *)calloc(sum + 1, sizeof(int));

    
    for (int i = 0; i < num_coins; i++) {
        scanf("%d", coins + i);
    }

    for (int i = 1; i <= sum; i++) {
        memos[i] = sum + 1; // safe "inf"
    }

    // Build the table bottom up
    for (int i = 1; i <= sum; i++) {
        for (int k = 0; k < num_coins; k++) {
            if (coins[k] <= i && memos[i - coins[k]] + 1 < memos[i]) {
                memos[i] = memos[i - coins[k]] + 1;
            }
        }
    }

    printf("%d\n", memos[sum] > sum ? -1 : memos[sum]);

    free(coins);
    free(memos);
    return 0;
}
