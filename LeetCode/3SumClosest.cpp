class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 2) return 0;
        
        sort(num.begin(), num.end());
        
        int ans = num[0] + num[1] + num[2]; // Be careful, the initialize...
        
        for (int i = 0; i < num.size() - 2; i ++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            
            int t = target - num[i];
            int b = i + 1, e = num.size() - 1;
            while (b < e) {
                int tmp = num[b] + num[e];
                
                if (abs(t - tmp) < abs(ans - target)) {
                    ans = tmp + num[i];
                }
                
                if (ans == target) return ans;
                
                if (tmp < t) {
                    b ++;
                } else if (tmp > t) {
                    e --;
                }
            }
        }
        
        return ans;
    }
};