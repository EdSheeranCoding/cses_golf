char s[1000001];
int freq[26];
int main() {
    scanf("%s",s);
    int n=strlen(s);
    
    for (int i = 0; i < n; i++)
        freq[s[i] - 'A']++;
    
    // check at most one odd frequency
    int odd = -1, odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) {
            odd = i;
            odd_count++;
        }
    }
    
    if (odd_count > 1) {
        puts("NO SOLUTION");
        return 0;
    }
    
    // build palindrome from outside in
    int l = 0, r = n - 1;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < freq[i] / 2; j++)
            s[l++] = s[r--] = 'A' + i;
    
    // place odd character in the middle
    if (odd != -1)
        s[n / 2] = 'A' + odd;
    
    puts(s);
    return 0;
}