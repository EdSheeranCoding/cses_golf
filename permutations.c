#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1\n");
    } else if (n <= 3) {
        printf("NO SOLUTION\n");
    } else {
        for (int i = 2; i <= n; i += 2)
            printf("%d ", i);   // print even numbers
        for (int i = 1; i <= n; i += 2)
            printf("%d ", i);   // print odd numbers
    }
    return 0;
}
