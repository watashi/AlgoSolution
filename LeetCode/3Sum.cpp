/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 *
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 */
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() funct
        vector<vector<int> > ans;
        
        // special case, special deal
        if (num.size() <= 2) return ans;
        
        // sort the num array, this always be the first step to solve problem like this ;)
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size() - 2; i ++) {
            // avoid duplicated first number
            if (i > 0 && num[i] == num[i - 1]) continue;
    
            // in order to get a + b + c == 0, now we have fix a = num[i], so b + c should be -a
            int target = 0 - num[i];

            // the following code is typical pattern to find x + y = C in a sorted array
            int b = i + 1, e = num.size() - 1;
            while (b < e) {
                int tmp = num[b] + num[e];
                if (tmp < target) {
                    b ++;
                } else if (tmp > target) {
                    e --;
                } else {
                    vector<int> ret(3, 0 - target);
                    ret[1] = num[b ++];
                    ret[2] = num[e --];
                    ans.push_back(ret);
                    // Remove duplicated pairs...
                    while (b < num.size() && num[b] == num[b - 1]) b ++;
                    while (e > b && num[e] == num[e + 1]) e --;
                }
            }
        }
    }
};
