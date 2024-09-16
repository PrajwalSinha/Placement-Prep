class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force approach
//         int n = prices.size();
//         int profit = 0;
//         int maxi = INT_MIN;
//         int mini = INT_MAX;
//         for(int i=0;i<n;i++){
//             if(prices[i]>maxi){
//                 maxi = prices[i];
//             }
//             if(prices[i]<mini){
//                 mini = prices[i];
//             }
//         }
//         int maxProfit = maxi - mini;
//         for(int i=0;i<n;i++){
            
//             for(int j=i+1;j<n;j++){
//                 int val = prices[j] - prices[i];
//                 profit = max(profit,val);
//                 if(profit==maxProfit){
//                     return profit;
//                 }
//             }
//         }
   
// return profit;
        //initializing the values
        int n = prices.size();
        int buy = prices[0];
        int sell = 0;
        int profit = 0;
        int fin = 0;
        //iterating over the entire array 
        for(int i=1;i<n;i++){
            sell = prices[i];
            profit = sell - buy;
            fin = max(fin,profit);
            if(buy>prices[i]){
                buy = prices[i];
            }
        }
        return fin;
        
    }
};