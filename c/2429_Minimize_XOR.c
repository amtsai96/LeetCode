// time: O(log(n), space: O(1)
int countBit(int x)
{
    int bit = 0;
    while(x)
    {
        bit += (x & 1);
        x >>= 1;
    }
    return bit;
}

int getValueByBitNum(int bit1, int bit2, int num)
{
    int x;
    if(bit1 > bit2)
    {
        x = bit1 - bit2; // bit num to remove
        while(x)
        {
            num &= (num - 1);
            x--;
        }
    }
    else // bit2 > bit1
    {
        int bitPos = 0;
        x = bit2 - bit1; // bit num to add
        while(x)
        {
            while((num >> bitPos) & 1)
            {
                bitPos++;
            }
            num |= (1 << bitPos);
            x--;
        }
    }
    return num;
}

int minimizeXor(int num1, int num2) {
    int bit1 = countBit(num1);
    int bit2 = countBit(num2);
    if(bit1 == bit2) return num1;
    return getValueByBitNum(bit1, bit2, num1);
}