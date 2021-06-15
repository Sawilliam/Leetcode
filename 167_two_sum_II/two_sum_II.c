class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> sumArray;
        map<int, int>::iterator iter;
        vector<int> ans;
        for(int i = 0;i<numbers.size();i++)
        {
            iter = sumArray.find(target-numbers[i]);
            if(iter != sumArray.end()){
                if(iter->second == i)
                    continue;
                ans.push_back((iter->second)+1);
                ans.push_back(i+1);
                break;
            }
            sumArray[numbers[i]] = i;
        }
         return ans;
    }
};