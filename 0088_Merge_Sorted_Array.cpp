class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0 && n==0) return;
        int index=0;
        for(int i=0;i<n;i++){
            index = 0;
            if(m!=0){
                if(nums2[i] <= nums1[0]) index = 0;
                else{
                    for(int j=0;j<m-1;j++){
                        if(nums2[i] >= nums1[j] && nums2[i] < nums1[j+1]){
                            index = j+1;
                            break;
                        }
                    }
                    if(index == 0) index = m;
                }
                //insert at index
                for(int k=nums1.size()-2;k >= index;k--){
                    nums1[k+1] = nums1[k];  
                }
            }
            nums1[index] = nums2[i];
            m ++;
        }
    }
};
