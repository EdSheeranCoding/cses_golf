#include <stdio.h>
#include <math.h>

#define NC2(N) (N * N) * (N * N - 1) >> 1
#define NC2_PRIME(N) (unsigned long long)(N) * (2 * (N) - 1) * ((N) - 1)

#define NATTACK(N) 4 * (N - 1) * (N - 2)
#define NATTACK_PRIME(N) 8 * (N) - 16

// starting values for n == 2
unsigned long long result = 6;
int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    printf("0\n6\n");

    for (int i = 3; i <= n; i++) {
        result += (unsigned long long)(NC2_PRIME(i)) - (NATTACK_PRIME(i));
        printf("%llu\n", result);
    }
}

/*@notes
Number of total positions is Choose(n^2, 2)
positions where they attack eachother is: (given n < 2)

Take a 2 x 3 'bounding box' --> bb
On a n * n board there are k = n^2 - (3n - 2) positions for bb
for every coordinate in k there are 3 variations (neutral, hotdog flip, hamburger flip).
    - note that you are not allowed to flip hotdog + hamburger as that is just the neutral
Then you can count the same thing for bb' which is 3 x 2.
so just * 2.
N_ATTACKS(n) = 6*k = 6 * n^2 - 18 * n + 12. = 6 * (n - 1) * (n - 2)
nc2(N) = (N >> 1) * (N - 1) --> WHERE N = n^2
nc2(n) = (n^2 >> 1) *(n^2 - 1)

find out how f changes as n changes
f(n + 1) - f(n) = 6 * (2 * n - 2)
                  ^    ^
                vars   added_squares


find out how nc2 changes as n changes
nc2(n+1) - nc2(n) = n
*/
