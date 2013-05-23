class Solution {
public:
    int leftBound(int A[], int n, int target) {
        int b = 0, e = n - 1;
        while (b <= e) {
            int mid = b + (e - b) / 2;
            if (A[mid] < target) b = mid + 1;
            else e = mid - 1;
        }
        
        if (A[b] != target) return -1;
        return b;
    }
    
    int rightBound(int A[], int n, int target) {
        int b = 0, e = n - 1;
        while (b <= e) {
            int mid = b + (e - b) / 2;
            if (A[mid] <= target) b = mid + 1;
            else e = mid - 1;
        }
        
        if (b == 0 || A[b - 1] != target) return -1;
        return b - 1;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans(2, -1);
        
        ans[0] = leftBound(A, n, target);
        
        if (ans[0] == -1) return ans;
        
        ans[1] = rightBound(A, n, target);
        
        return ans;
    }
};