class Solution {
public:
    int getPosition(int b, int e, vector<int> &num, int target) {
        while (b <= e) {
            int mid = b + (e - b) / 2;
            if (num[mid] <= target) b = mid + 1;
            else e = mid - 1;
        }
        
        return b;
    }
    
    /**
     * Find the last index, so that from last to the end, the sequence is decreasing.
     * num[index - 1] < num[index], so that find the minimal number P that is greater than num[index - 1];
     * swap num[index - 1] with P, reverse the sequence from index to the end.
     */
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 1) return;
        
        for (int i = num.size() - 2; i >= 0; i --) {
            if (num[i + 1] > num[i]) {
                reverse(num.begin() + i + 1, num.end());
                
                int posi = getPosition(i + 1, num.size() - 1, num, num[i]);
                swap(num[i], num[posi]);
                
                return;
            }
        }
        
        reverse(num.begin(), num.end());
    }
};