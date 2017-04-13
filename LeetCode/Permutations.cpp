/**
 Given a collection of numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
 
class Solution {
public:
    vector<vector<int> > ans;
    
    void recursivePermute(vector<int> & num, int pos) {
        if (pos >= num.size()) {
            ans.push_back(num);
            return;
        }
        
        for (int i = pos; i < num.size(); i ++) {
            swap(num[pos], num[i]);
            recursivePermute(num, pos + 1);
            swap(num[pos], num[i]);
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        recursivePermute(num, 0);
        return ans;
    }
};