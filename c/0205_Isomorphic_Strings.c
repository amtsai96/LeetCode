bool isIsomorphic(char * s, char * t){
    const int ascii_max = 256;
    int arrS[ascii_max];
    int arrT[ascii_max];
    int len = strlen(s);

    for (int i = 0; i < ascii_max; i++)
    {
        arrS[i] = arrT[i] = -1;
    }

    for (int i = 0; i < len; i++)
    {
        if (arrS[s[i]] != arrT[t[i]])
            return false;
        arrS[s[i]] = arrT[t[i]] = i; 
    }

    return true;
}