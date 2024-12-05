// time: O(n), space: O(1)
bool canChange(char* s, char* t) {
    int n = strlen(s);
    for(int i = 0, j = 0; i < n || j < n; i++, j++)
    {
        while(i<n && s[i]=='_') i++;
        while(j<n && t[j]=='_') j++;
        if(s[i] != t[j]) return false; // not the same alphabet
        if(s[i] == 'L' && i < j) return false; // L but move to right
        if(s[i] == 'R' && i > j) return false; // R but move to left
    }
    return true;
}