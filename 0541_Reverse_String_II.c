
void reverse(char* s, int sSize){
    char *p = s, *q = s + sSize - 1;
    while (p < q) {
        *p = *p ^ *q;
        *q = *p ^ *q;
        *p = *p ^ *q;
        p++;
        q--;
    }
}

char * reverseStr(char * s, int k){
    char* p = s;
    char* end = s + strlen(s) - 1;
    while (p + k - 1 <= end) {
        reverse(p, k);
        p += 2 * k;
    }
    reverse(p, (end - p) + 1);
    return s;
}

