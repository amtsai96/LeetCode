class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2) return 0;
        if(height.size() == 2) return min(height[0], height[1]);
        
        int max_area = 0;
        int left = 0, right = height.size()-1;
        while(left < right){
            max_area = max(max_area, (right-left)*min(height[left], height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
    }
};