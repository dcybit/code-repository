void add(char a[], char b[], char value[]) { //a[], b[], value[] 倒序存储数字，如a[] = "123", 实际a = 321
    short next = 0;                                  //即value = \sum_{i=1}^{n} a[i] * pow(10, i)
    int i = 0;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        value[i] = ((a[i]-'0') + (b[i]-'0') + next) % 10 + '0';
        next = ((a[i]-'0') + (b[i]-'0') + next) > 9;
    }
    if (next && a[i] == '\0' && b[i] == '\0') {value[i++] = next + '0';}
    if (a[i] == '\0' && b[i] != '\0') {
        for (; b[i] != '\0'; i++) {
            value[i] = ((b[i]-'0') + next) % 10 + '0';
            next = ((b[i]-'0') + next) > 9;
        }
        if (next) {value[i++] = next + '0';}
    }
    if (b[i] == '\0' && a[i] != '\0') {
        for (; a[i] != '\0'; i++) {
            value[i] = ((a[i]-'0') + next) % 10 + '0';
            next = ((a[i]-'0') + next) > 9;
        }
        if (next) {value[i++] = next + '0';}
    }
    value[i] = '\0';
}
