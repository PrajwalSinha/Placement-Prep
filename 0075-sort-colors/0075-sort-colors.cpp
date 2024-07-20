class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < mp[0]; ++i) {
            nums[index++] = 0;
        }
        for (int i = 0; i < mp[1]; ++i) {
            nums[index++] = 1;
        }
        for (int i = 0; i < mp[2]; ++i) {
            nums[index++] = 2;
        }
    }
};