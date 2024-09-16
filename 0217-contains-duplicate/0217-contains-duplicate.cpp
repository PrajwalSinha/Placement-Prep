class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
//         map<int,int> mpp;
//         int n = nums.size();
        
//         for(int i=0;i<n;i++){
//             mpp[nums[i]]++;
//         }
        
//         for(int i=0;i<n;i++){
//             if(mpp[nums[i]]>=2){
//                 return true;
//             }
//         }
        
//         return false;
        
        //better approach
        
        map<int,int> mpp;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()){
                return true;
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};