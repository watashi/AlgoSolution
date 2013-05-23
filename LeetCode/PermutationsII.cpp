class Solution {
public:

    vector<vector<int> > ans;
    
    void recursivePermute(vector<int> & curr, int pos, vector<int> &num) {
        if (curr.size() == num.size() || pos >= num.size()) {
            ans.push_back(curr);
            return;
        }
        
        map<int, bool> visited; // Flag the number if is visited in current pos
        
        for (int i = pos; i < num.size(); i ++) {
            if (visited.count(num[i]) > 0) continue;
            
            visited[num[i]] = true;
            
            swap(num[pos], num[i]);
            curr.push_back(num[pos]);
            recursivePermute(curr, pos + 1, num);
            curr.pop_back();
            swap(num[pos], num[i]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> curr;
        ans.clear();
        recursivePermute(curr, 0, num);
        return ans;
    }
};