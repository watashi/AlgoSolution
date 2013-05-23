class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; i ++) A[i] --;
        
        int i = 0;
                
        while (i < n) {
            if (A[i] != i && A[i] >= 0 && A[i] < n && A[A[i]] != A[i]) {
                swap(A[A[i]], A[i]);
            } else i ++;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (ans == A[i]) ans ++;
        }
        
        return ans + 1;
    }
};