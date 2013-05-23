class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        
        if (num.size() < 4) return ans;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size(); i ++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            
            for (int j = num.size() - 1; j > i + 2; j --) {
                if (j < num.size() - 1 && num[j] == num[j + 1]) continue;
                
                int tmpTarget = target - num[i] - num[j];
                
                int b = i + 1, e = j - 1;
                while (b < e) {
                    int sum = num[b] + num[e];
                    if (sum > tmpTarget) {
                        e --;
                    } else if (sum < tmpTarget) {
                        b ++;
                    } else {
                        vector<int> n;
                        n.push_back(num[i]);
                        n.push_back(num[b]);
                        n.push_back(num[e]);
                        n.push_back(num[j]);
                        ans.push_back(n);
                        
                        b ++, e --;
                        
                        while (b < j && num[b] == num[b - 1]) b ++;
                    }
                    
                }
            }
        }
        
        return ans;
    }
};