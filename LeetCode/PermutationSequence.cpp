class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int permu = 1;
        
        string ans = "";
        for (int i = 1; i <= n; i ++) {
            ans += string(1, i + '0');
            permu *= i;
        }
        
        k --;
        k %= permu;
        permu /= n;
        
        // calculate the 0 position of the remain subsequence each time
        for (int i = 0; i < n - 1; i ++) {
            int delta = k / permu; 
            k = k % permu;
            permu /= (n - i - 1);
            
            // Insert the delta + i number at i
            int tmp = ans[delta + i];
            
            for (int j = delta; j > 0; j --) {
                ans[i + j] = ans[i + j - 1];
            }
            
            ans[i] = tmp;
        }
        
        return ans;
    }
};