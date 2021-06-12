
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
    char* p;
    char* end = s + strlen(s) - 1;
    for(p = s; p+k-1 <= end;p += 2*k){
        reverse(p, k);
    }
    reverse(p, (end - p) + 1);
    return s;
}

