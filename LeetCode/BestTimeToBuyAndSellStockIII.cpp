/**
 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most two transactions.

 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */


class Solution {
public:
    
    // Vector maximal saves the maximal point from index i to prices.end()
    int maxProfitFromStartPoint(vector<int> &prices, vector<int> &maximal) {
        if (prices.size() <= 0) return 0;
        
        int N = prices.size();
        
        maximal[N - 1] = prices[N - 1];
        for (int i = N - 2; i >= 0; i --) {
            maximal[i] = max(maximal[i + 1], prices[i]); 
        }
        
        int ans = 0;
        for (int i = N - 1; i >= 0; i --) {
            ans = max(ans, maximal[i] - prices[i]);
            maximal[i] = ans;
        }
        
        return ans;
    }
    
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() <= 1) return 0;
        
        int N = prices.size();
        
        vector<int> left(N, 0);
        vector<int> right(N, 0);
        
        // Only one transactions...
        int ans = maxProfitFromStartPoint(prices, right);
        
        left[0] = prices[0];
        for (int i = 1; i < N; i ++) {
            left[i] = min(left[i - 1], prices[i]); 
        }
        
        int leftMaxProfit = 0;
        for (int i = 0; i < N; i ++) {
            leftMaxProfit = max(leftMaxProfit, prices[i] - left[i]);
            ans = max(ans, leftMaxProfit + right[i]);
        }
        
        return ans;
    }
};