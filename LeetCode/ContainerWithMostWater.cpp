/*
 * For any container, its volume depends on the shortest board.
 * Two-pointer scan. And always move with shorter board index.
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int b = 0, e = height.size() - 1, ans;
        
        while ( b < e) {
            ans = max(ans, (e - b) * min(height[b], height[e]));
            
            if (height[b] <= height[e]) {
                b ++;
            } else {
                e --;
            }
        }
        
        return ans;
    }
};