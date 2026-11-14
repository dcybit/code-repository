void revs_char_add(char sum[], char a[], char b[]) { //a[], b[], sum[] 倒序存储数字，如a[] = "123", 实际a = 321
    short next = 0;                                  //即value = \sum_{i=1}^{n} a[i] * pow(10, i)
    int i = 0;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
       if (i == 0) {
        sum[i] = ((a[i]-'0') + (b[i]-'0')) % 10 + '0';
        next = ((a[i]-'0') + (b[i]-'0')) > 9;       
       } else {
        sum[i] = ((a[i]-'0') + (b[i]-'0') + next) % 10 + '0';
        next = ((a[i]-'0') + (b[i]-'0') + next) > 9;
       }
    }
    if (next && a[i] == '\0' && b[i] == '\0') {sum[i] += next + '0';}
    if (a[i] == '\0') {
        for (; b[i] != '\0'; i++) {
            sum[i] = b[i] + next;
            next = 0;
        }
    }
    if (b[i] == '\0') {
        for (; a[i] != '\0'; i++) {
            sum[i] = a[i] + next;
            next = 0;
        }
    }
}