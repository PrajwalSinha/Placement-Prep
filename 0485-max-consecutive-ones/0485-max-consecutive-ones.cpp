class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++; 
            }
            else{
                res.push_back(count);
                count=0;
            }
         res.push_back(count);
        }
        int max = INT_MIN;
        for(int i=0;i<res.size();i++){
            if(res[i]>max){
                max=res[i];
            }
        }
        return max;
    }
};