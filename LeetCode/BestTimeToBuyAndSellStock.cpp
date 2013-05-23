/**
 Say you have an array for which the ith element is the price of a given stock on day i.

 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() <= 0) return 0;
        
        int N = prices.size();
        
        vector<int> maximal(N, 0);
        maximal[N - 1] = prices[N - 1];
        for (int i = N - 2; i >= 0; i --) {
            maximal[i] = max(maximal[i + 1], prices[i]); 
        }
        
        int ans = 0;
        for (int i = 0; i < N; i ++) {
            ans = max(ans, maximal[i] - prices[i]);
        }
        
        return ans;
    }
};