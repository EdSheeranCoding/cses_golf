#include <stdio.h>
 
int main() {
    int max = 1, count = 0;
    char c, prev_char = '\0';
 
    while(~scanf("%c", &c)) {
        if (c == prev_char) {
            count++;
            if (count > max) {
                max = count;
            } 
        } else {
            prev_char = c;
            count = 1;
        }
    }
 
    printf("%d",max);
    return 0;
}