
#include <stdio.h>

long half, idx1, idx2;
int main(n)
{
    scanf("%d",&n);
    long tri = ((long)n * n + n) >> 1;
    if(tri & 1) {
        printf("NO\n");
    } else {
    printf("YES\n");

    long half = tri / 2;
    int set1[n], set2[n];
    int idx1 = 0, idx2 = 0;

    for(int i = n; i >= 1; i--) {
        if(i <= half) {
            set1[idx1++] = i;
            half -= i;
        } else {
            set2[idx2++] = i;
        }
    }

    printf("%d\n", idx1);
    for(int i = 0; i < idx1; i++)
        printf("%d ", set1[i]);
    printf("\n%d\n", idx2);
    for(int i = 0; i < idx2; i++)
        printf("%d ", set2[i]);
    printf("\n");
    }
}