class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int start = 0, end = n-1;
        while( start < end )
        {
            int h = min(height[start], height[end]);
            water = max(water, h*(end-start));
            while( height[start] <= h && start < end )
                start++;
            
            while( height[end] <= h && start < end )
                end--;
        }
        return water;
    }
};