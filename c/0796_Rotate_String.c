// time:O(m*n), space: O(1)
bool rotateString(char* s, char* goal) {
    int sLen = strlen(s);
    int i;
    if(sLen != strlen(goal)) return false;

    for(i = 0; i<sLen*2; i++)
    {
        int j = 0;
        for(; j<sLen; j++)
        {
            if(s[(i+j) % sLen] != goal[j]) break;
        }
        if(j == sLen) return true;
    }
    return false;
}