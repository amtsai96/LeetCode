// time: O(log(n)), space: O(1)
bool isPowerOfTwo(int n){
    if (n <= 0) return false;
    while (n % 2 == 0)
    {
        n /= 2;
    }

    return (n == 1);
}

// time: O(1), space: O(1)
bool isPowerOfTwo(int n){
    if (n <= 0) return false;
    return ((n & (n-1)) == 0);
}