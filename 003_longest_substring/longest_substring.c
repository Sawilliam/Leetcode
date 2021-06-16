class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> record(256, -1);
        int n = s.size();
        int max_length = 0;
        int start = -1;
        
        for(int i = 0; i < n; i++)
        {
            start = max(start, record[s[i]]);
            max_length = max(max_length, i-start);
            record[s[i]] = i;
        }
     
        return max_length;
        
    }
};