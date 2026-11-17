void convert(int n, char s[]) {
    for (int i = 0; n > 0; i++) {
        s[i] = n % 10 + '0';
        n /= 10;
    }
}