class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int end = m + n - 1;
        int t1 = m - 1, t2 = n - 1;
        
        while (t1 >= 0 && t2 >= 0) {
            if (A[t1] >= B[t2]) {
                A[end --] = A[t1 --];
            } else {
                A[end --] = B[t2 --];
            }
        }
        
        while (t1 >= 0) A[end --] = A[t1 --];
        while (t2 >= 0) A[end --] = B[t2 --];
    }
    
};