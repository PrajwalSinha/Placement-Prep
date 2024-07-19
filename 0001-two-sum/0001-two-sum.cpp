class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> res;
    //     for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size(); j++) {
    //         if (nums[i] + nums[j] == target){
    //             res.push_back(i);
    //             res.push_back(j);
    //         }
    //     }
    // }
    // return res;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more)!=mpp.end()){
                return {mpp[more],i};
            }
            mpp[a] = i;
        }
        
        return {-1,-1};
  }
};