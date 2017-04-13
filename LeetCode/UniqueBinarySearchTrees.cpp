class Solution {
public:
    int getNumberOfTrees(int left, int right) {
        if (left >= right) return 1;
        
        int ans = 0;
        for (int i = left; i <= right; i ++) {
            // It is easy to get confused to declare the same names of left and right in for loop...
            ans += getNumberOfTrees(left, i - 1) * getNumberOfTrees(i + 1, right);
        }
        
        return ans;
    }
    
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return getNumberOfTrees(1, n);
    }
};