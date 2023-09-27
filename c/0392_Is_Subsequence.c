bool isSubsequence(char * s, char * t){
    if (strlen(s) > strlen(t)) return false;
    
    int idx = 0;
    bool flag;

    for (int i = 0; i < strlen(s); i++)
    {
        flag = false;
        for (int j = idx; j < strlen(t); j++)
        {
            if (s[i] == t[j])
            {
                idx = j+1;
                flag = true;
                break;
            }
        }

        if (flag == false) return false;
    }

    return flag;
}

// optimized ans
bool isSubsequence(char * s, char * t){
    while (*s && *t) if (*s == *t++) s++;

    return !(*s);
}