class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//        map<int,int> mpp;
//        int sum = 0;
//        int n = nums.size();
//        int maxSum = 0;
//        for(int i=0;i<n;i++){
//            sum+=nums[i];
//            int rem = sum - maxSum;
           
//            if(mpp.find(rem)!=mpp.end()){
//                int start = mpp[rem];
//                int end = i;
//                int res = 0;
//                for(int i=start;i<end;i++){
//                    res+=nums[i];
//                }
//                maxSum = max(maxSum,res);
//            }
//            mpp[sum] = i;
//        }
//         return maxSum+1;
        
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;
       int pre = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>maxSum){
                maxSum = sum;
            }
            if(sum<0){
                sum = 0;
            }
    
        }
        return maxSum;
    }
};