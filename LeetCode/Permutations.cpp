class Solution {
public:
    vector<vector<int> > ans;
    
    void recursivePermute(vector<int> & curr, int pos, vector<int> &num) {
        if (curr.size() == num.size() || pos >= num.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = pos; i < num.size(); i ++) {
            swap(num[pos], num[i]);
            curr.push_back(num[pos]);
            recursivePermute(curr, pos + 1, num);
            curr.pop_back();
            swap(num[pos], num[i]);
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> curr;
        ans.clear();
        recursivePermute(curr, 0, num);
        return ans;
    }
};