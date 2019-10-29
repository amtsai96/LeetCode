class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2) return 0;
        if(height.size() == 2) return min(height[0], height[1]);
        
        int max_area = 0;
        for(int i=0;i<height.size()-1;i++){
            for(int j=height.size()-1;j>i; j--){
                int area = (j-i)*min(height[i], height[j]);
                if(area > max_area) max_area = area;
            }
        }
        return max_area;
    }
};