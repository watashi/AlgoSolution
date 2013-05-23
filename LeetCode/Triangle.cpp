/**
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

 For example, given the following triangle

 [
      [2],
     [3,4],
    [6,5,7],
   [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int N = triangle.size();
        for (int row = 1; row < N; row ++) {
            triangle[row][0] += triangle[row - 1][0];
            triangle[row][row] += triangle[row - 1][row - 1];
            
            for (int i = 1; i < row; i ++) {
                triangle[row][i] += min(triangle[row - 1][i - 1], triangle[row - 1][i]); 
            }
        }
        
        int ans = INT32_MAX;
        
        for (int i = 0; i < N; i ++) {
            ans = min(triangle[N - 1][i], ans);
        }
        
        return ans;
    }
};