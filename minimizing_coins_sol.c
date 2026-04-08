#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
 
typedef uint32_t u32;
typedef uint64_t u64;
static char* buf;
static char* buf_end;
static char* cur;
 
void init_io() {
    struct stat st;
    int fd = STDIN_FILENO;
    if (fstat(fd, &st) == 0 && st.st_size > 0) {
        buf = (char*)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (buf != MAP_FAILED) {
            buf_end = buf + st.st_size;
            cur = buf;
            return;
        }
    }
    static char temp[1 << 24];
    size_t r = fread(temp, 1, sizeof(temp), stdin);
    buf = temp;
    buf_end = temp + r;
    cur = buf;
}
 
static inline u32 read_u32() {
    u32 x = 0;
    while (cur < buf_end && *cur <= ' ') cur++;
    while (cur < buf_end && *cur >= '0') {
        x = x * 10 + (*cur++ - '0');
    }
    return x;
}
 
int cmp_asc(const void* a, const void* b) {
    u32 ua = *(const u32*)a;
    u32 ub = *(const u32*)b;
    return (ua > ub) - (ua < ub);
}
 
void solve_algo_1(u32 n, u32 x, u32* input_coins) {
    u32* coins = (u32*)malloc(n * sizeof(u32));
    u32 valid_n = 0;
    qsort(input_coins, n, sizeof(u32), cmp_asc);
 
    for (u32 i = 0; i < n; i++) {
        if (input_coins[i] == x) {
            printf("1\n");
            free(coins);
            return;
        }
        if (input_coins[i] < x) {
            coins[valid_n++] = input_coins[i];
        } else {
            break;
        }
    }
    n = valid_n;
 
    if (n == 0) {
        printf("-1\n");
        free(coins);
        return;
    }
    u32* divs = (u32*)malloc(n * sizeof(u32));
    u32 min_num = x + 1;
    for (u32 i = 0; i < n; i++) {
        divs[i] = x / coins[i];
        if (x % coins[i] == 0) {
            if (divs[i] < min_num) min_num = divs[i];
        }
    }
 
    u32* stack = (u32*)malloc(((size_t)x + 1) * sizeof(u32));
    if (!stack) {
        free(coins);
        free(divs);
        return;
    }
 
    u32 top = 0;
    stack[top++] = n - 1;
 
    u64 coin_sum = 0;
    int down = 0;
 
    while (top > 0) {
        u32 idx = stack[top - 1];
        u32 coin = coins[idx];
 
        if (!down) {
            coin_sum += coin;
            if (coin_sum == x) {
                if (top < min_num) min_num = top;
                stack[top - 1] = 0;
            } else if (coin_sum < x) {
                if (top + 1 < min_num && divs[idx] < min_num) {
                    stack[top++] = idx;
                    continue;
                }
            }
        }
        coin_sum -= coin;
        down = (stack[top - 1] == 0);
        if (down) {
            top--;
        } else {
            stack[top - 1]--;
        }
    }
 
    if (min_num > x) {
        printf("-1\n");
    } else {
        printf("%d\n", (int32_t)min_num);
    }
 
    free(coins);
    free(divs);
    free(stack);
}
 
static u32* a2_coins;
static int a2_n = 0;
static u64 a2_min_coins;
 
int cmp_desc(const void* a, const void* b) {
    u32 x = *(const u32*)a;
    u32 y = *(const u32*)b;
    return (x > y) ? -1 : (x < y);
}
 
void a2_solve_rec(int idx, u32 rem, u64 count) {
    if (count >= a2_min_coins) return;
    if (rem == 0) {
        a2_min_coins = count;
        return;
    }
    if (idx == a2_n) return;
 
    u32 c = a2_coins[idx];
    if (count + ((u64)rem + c - 1) / c >= a2_min_coins) return;
 
    if (rem % c == 0) {
        u64 final_cnt = count + rem / c;
        if (final_cnt < a2_min_coins) a2_min_coins = final_cnt;
        return;
    }
 
    u32 max_k = rem / c;
    u32 next_c = (idx + 1 < a2_n) ? a2_coins[idx + 1] : 0;
 
    for (int k = max_k; k >= 0; k--) {
        u64 next_count = count + k;
        if (next_count >= a2_min_coins) continue;
 
        u32 next_rem = rem - k * c;
        if (next_c > 0) {
            if (next_count + ((u64)next_rem + next_c - 1) / next_c >=
                a2_min_coins)
                continue;
        } else if (next_rem > 0) {
            continue;
        }
 
        a2_solve_rec(idx + 1, next_rem, next_count);
    }
}

void solve_algo_2(u32 n_in, u32 x, u32* input_coins) {
    u32* temp_coins = (u32*)malloc(n_in * sizeof(u32));
    int temp_n = 0;
    for (u32 i = 0; i < n_in; i++) {
        if (input_coins[i] <= x && input_coins[i] > 0) {
            temp_coins[temp_n++] = input_coins[i];
        }
    }
 
    if (temp_n == 0) {
        printf("-1\n");
        free(temp_coins);
        return;
    }
 
    qsort(temp_coins, temp_n, sizeof(u32), cmp_desc);
    a2_coins = (u32*)malloc(temp_n * sizeof(u32));
    a2_n = 0;
    a2_coins[a2_n++] = temp_coins[0];
    for (int i = 1; i < temp_n; i++) {
        if (temp_coins[i] != a2_coins[a2_n - 1]) {
            a2_coins[a2_n++] = temp_coins[i];
        }
    }
    free(temp_coins);
 
    a2_min_coins = (u64)x + 1;
    for (int i = 0; i < a2_n; i++) {
        if (a2_coins[i] == x) {
            printf("1\n");
            free(a2_coins);
            return;
        }
    }
    {
        u32 rem = x;
        u64 cnt = 0;
        for (int i = 0; i < a2_n; i++) {
            cnt += rem / a2_coins[i];
            rem %= a2_coins[i];
        }
        if (rem == 0 && cnt < a2_min_coins) {
            a2_min_coins = cnt;
        }
    }
    for (int i = 0; i < a2_n; i++) {
        if (x % a2_coins[i] == 0) {
            u64 cnt = x / a2_coins[i];
            if (cnt < a2_min_coins) a2_min_coins = cnt;
        }
    }
 
    a2_solve_rec(0, x, 0);
 
    if (a2_min_coins > x) {
        printf("-1\n");
    } else {
        printf("%llu\n", (unsigned long long)a2_min_coins);
    }
 
    free(a2_coins);
}
 
int main() {
    init_io();
    if (cur >= buf_end) return 0;
 
    u32 n = read_u32();
    u32 x = read_u32();
 
    if (n == 0) {
        printf("-1\n");
        return 0;
    }
    u32* raw_coins = (u32*)malloc(n * sizeof(u32));
    for (u32 i = 0; i < n; i++) {
        raw_coins[i] = read_u32();
    }
    if (x > 150000) {
        solve_algo_1(n, x, raw_coins);
    } else {
        solve_algo_2(n, x, raw_coins);
    }
 
    free(raw_coins);
    return 0;
}