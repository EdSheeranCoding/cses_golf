main() {
    int n;
    scanf("%d", &n);

    int c, sum = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", &c);
        sum ^= c;
    }
    for (int i = 1; i < n + 1; i++) {
        sum ^= i;
    }
    printf("%d\n", sum);
}