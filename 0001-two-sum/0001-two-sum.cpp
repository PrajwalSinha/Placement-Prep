class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force approach
        // int rem;
        // vector<int> res;
        // for(int i=0;i<nums.size();i++){
        //     rem = target - nums[i];
        //     for(int j=0;j<nums.size();i++){
        //         if(rem==nums[j]){
        //             res.push_back(i);
        //             res.push_back(j);
        //         }
        //     }
        // }
        // return res;
        
        //Better Approach
//         int rem;
//         int low;
//         int high;
//         vector<int> res;
//         vector<int> sorted=nums;
//         sort(sorted.begin(),sorted.end());
//         for(int i=0;i<sorted.size();i++){
//             rem = target - sorted[i];
//             low = i;
//             high = sorted.size()-1;
            
//             while(low<=high){
//                 int mid = (low+high)/2;
//                 if(sorted[mid]==rem){
//                     res.push_back(i);
//                     res.push_back(mid);
//                 } else if(sorted[mid]<target){
//                     low = mid+1;
//                 } else{
//                     high = mid-1;
//                 }
//             }
            
//         }
//         return res; 
        
        //optimal approach
        map<int,int> mpp;
        int rem;
        for(int i=0;i<nums.size();i++){
            rem = target - nums[i];
            if(mpp.find(rem)!=mpp.end()){
                return {mpp[rem],i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
  }
};