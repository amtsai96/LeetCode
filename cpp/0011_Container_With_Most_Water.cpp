// time: O(n), space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        if (height.size() < 2) return 0;
        if (height.size() == 2) return min(height[left], height[right]);

        while (left < right)
        {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max_area;
    }
};