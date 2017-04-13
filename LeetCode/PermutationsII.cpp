/**
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].
 */
 
class Solution {
public:

    vector<vector<int> > ans;
    
    void recursivePermute(vector<int> & num, int pos) {
        if (pos >= num.size()) {
            ans.push_back(num);
            return;
        }
        
        map<int, bool> visited; // Flag the number if is visited in current pos
        
        for (int i = pos; i < num.size(); i ++) {
            if (visited.count(num[i]) > 0) continue;
            
            visited[num[i]] = true;
            
            swap(num[pos], num[i]);
            recursivePermute(num, pos + 1);
            swap(num[pos], num[i]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        recursivePermute(num, 0);
        return ans;
    }
};