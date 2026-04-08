#include <stdio.h>

long long fact(int n) {
    long long r = 1;
    for (int i = 2; i <= n; i++) r *= i;
    return r;
}

int main(void) {
    char s[9];
    int n = 0, c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (n < 8) s[n++] = c;
    }

    for (int i = 1; i < n; i++) {
        char key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j] > key) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }

    long long total = fact(n);
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && s[j] == s[i]) j++;
        total /= fact(j - i);
        i = j;
    }

    printf("%lld\n", total);

    while (1) {
        for (int i = 0; i < n; i++) putchar(s[i]);
        putchar('\n');

        int i = n - 2;
        while (i >= 0 && s[i] >= s[i + 1]) i--;
        if (i < 0) break;

        int j = n - 1;
        while (s[j] <= s[i]) j--;

        char t = s[i];
        s[i] = s[j];
        s[j] = t;

        int l = i + 1, r = n - 1;
        while (l < r) {
            char tmp = s[l];
            s[l++] = s[r];
            s[r--] = tmp;
        }
    }

    return 0;
}