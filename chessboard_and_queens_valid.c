/*#include <stdio.h>

int board[8][8];
int cols[8];
int count = 0;

int is_safe(int row, int col) {
    for (int r = 0; r < row; r++) {
        if (cols[r] == col) return 0;
        if (abs(cols[r] - col) == abs(r - row)) return 0;
    }
    return 1;
}

void solve(int row) {
    if (row == 8) {
        for (int r = 0; r < 8; r++)
            if (board[r][cols[r]]) return;
        count++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (is_safe(row, col)) {
            cols[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    char line[10];
    for (int r = 0; r < 8; r++) {
        scanf("%s", line);
        for (int c = 0; c < 8; c++)
            board[r][c] = (line[c] == '*');
    }
    solve(0);
    printf("%d\n", count);
    return 0;
}*/

#include <stdio.h>

int cols[8];

int is_safe(int row, int col) {
    for (int r = 0; r < row; r++) {
        if (cols[r] == col) return 0;
        if (abs(cols[r] - col) == abs(r - row)) return 0;
    }
    return 1;
}

void solve(int row) {
    if (row == 8) {
        printf("{");
        for (int r = 0; r < 8; r++)
            printf("%d%s", cols[r], r < 7 ? "," : "");
        printf("},\n");
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (is_safe(row, col)) {
            cols[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    solve(0);
    return 0;
}