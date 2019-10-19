class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int beg = 0, end = x;
        while(beg <= end){
            int mid = beg+(end-beg)/2;
            if(x/mid == mid)
                return mid;
            else if(x/mid < mid)
                end = mid-1;
            else
                beg = mid+1;
            
        }
        return end;
    }
};
