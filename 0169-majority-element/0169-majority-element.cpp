class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi = INT_MIN;
        for (auto pair : mp) {
            if(pair.second>maxi){
                maxi = pair.second;
            }
       }
        for (auto it : mp) {
            if (it.second == maxi) {
            return it.first;
            }
        }
        return -1;
    }
};