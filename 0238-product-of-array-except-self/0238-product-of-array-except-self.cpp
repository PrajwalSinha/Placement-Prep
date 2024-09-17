class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
    int n = nums.size();
    int prePro[n];
    int postPro[n];
        
    prePro[0] = 1;
    postPro[n-1] = 1;
        
       //calculating the preProduct in the
       for(int i=1;i<n;i++){
           prePro[i] = prePro[i-1]*nums[i-1];
       }
       //calculating the postproduct 
        
        for(int i=n-2;i>=0;i--){
            postPro[i] = postPro[i+1]*nums[i+1];
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = prePro[i]*postPro[i];
        }
        return ans;
    }
};