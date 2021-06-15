class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mymap;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++)
        {
            map<int,int>::iterator it = mymap.find(target-nums[i]);
            if(mymap.end() != it){
                result.push_back(i);
                result.push_back(it->second);
                break;
            } else {
                mymap[nums[i]] = i;
            }
            
            

        }
        
        return result;

    }
};