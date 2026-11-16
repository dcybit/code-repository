extern void add(char a[], char b[], char value[]);
void multiply(int MAXSIZE, char a[], char b[], char value[]) {
    int next = 0;
    char m[MAXSIZE*MAXSIZE];
    char n[MAXSIZE*MAXSIZE];
    char ans[MAXSIZE*MAXSIZE];
    for (int i = 0; i < MAXSIZE*MAXSIZE; i++) {
        m[i] = n[i] = ans[i] = '\0';
    }
    n[0] = '0';
    for (int i = 0; a[i] != '\0'; i++) {
        for (int n = 0; n < i; n++) {
            m[n]= '0';                                  
        }
        int k = 0;
        for (int j = 0; b[j] != '\0'; j++, k++) {
            ans[k] = ((a[i]-'0') * (b[j]-'0') + next) % 10 + '0';
            next = ((a[i]-'0') * (b[j]-'0') + next) / 10;
            m[i + k] = ans[k];              
        }
        if (next != 0) {
            ans[k] = next + '0';
            m[i + k] = ans[k];
            next = 0;
        }
        add(m, n, value);
        int r = 0;
        for (r = 0; value[r] != '\0'; r++) {
            n[r] = value[r];
        }
        n[r] = '\0';
    }
}