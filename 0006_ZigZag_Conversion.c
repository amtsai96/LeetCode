char * convert(char * s, int numRows){
    int len = strlen(s);
    if(numRows <= 1 || numRows >= len)
    {
        return s;
    }
    char *s2 = (char*)malloc(sizeof(char)*(len+1));
    char *s1 = s2;
    int i;
    int zigzag_num = numRows*2-2;
    for (i=0;i<numRows;i++)
    {
        int base = i;
        while(base < len)
        {
            *(s1++) = *(s+base);
            if (i != 0 && i != numRows-1)
            {
                int idx = base+zigzag_num-2*i;
                if (idx < len)
                {
                    *(s1++) = *(s+idx);
                }
            }
            base += zigzag_num;
        }
    }
    *(s1++) = '\0';
    return s2;
}