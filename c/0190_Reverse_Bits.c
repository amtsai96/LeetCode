uint32_t reverseBits(uint32_t n) {
    if(n==0) return 0;
    uint32_t res = 0;
    int i=0;
    for(i=0; i<32; i++){
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}