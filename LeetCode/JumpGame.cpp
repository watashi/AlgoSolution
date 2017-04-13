class Solution {
public:
    bool canJumpRecursive(int A[], int pos, int n) {
        if (pos >= n) return false;
        if (pos == n - 1) return true;
        
        for (int i = A[pos]; i >= 1; i --) {
            if (canJumpRecursive(A, pos + i, n)) return true;
        }
        
        return false;
    }
    
    bool canJumpIteration(int A[], int n) {
        bool isOK[n];
        memset(isOK, false, sizeof(isOK));
        
        isOK[0] = true;
        for (int i = 0; i < n; i ++) {
            if (!isOK[i]) continue;
            for (int j = i + A[i]; j > i; j --) {
                if (j >= n) continue;  // Check if j is less than n...
                if (isOK[j]) break;
                isOK[j] = true;
            }
        }
        
        return isOK[n - 1];
    }
    
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return canJumpIteration(A, n);
        return canJumpRecursive(A, 0, n);
    }
};