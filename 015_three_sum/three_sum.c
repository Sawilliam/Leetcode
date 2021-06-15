class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size; i++)
        {
            int target = 0 - nums[i];
            int left = i+1;
            int right = size-1;
            while( left < right )
            {
                if(nums[left]+nums[right] == target){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);

                    result.push_back(tmp);
             
                    while( left < right && (nums[left] == nums[++left]));
                   
                    while( left < right && nums[right] == nums[--right]);

                    
                } else if (nums[left]+nums[right] < target){
                    left++;
                } else 
                    right--;
            }
            while(  i < size-2 && nums[i] == nums[i+1])
                i++;
        }
        return result;
        

    }
};