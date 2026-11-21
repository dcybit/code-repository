void convert(int n, char s[]) {     //将整数n转化为倒序的字符数组存储
    for (int i = 0; n > 0; i++) {
        s[i] = n % 10 + '0';
        n /= 10;
    }
}