class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0) return 0;
        
        sort(A, A + n);
        
        int b = 0, e = 1;
        
        while (e < n) {
            while (e < n && A[b] == A[e]) e ++;
            
            if (e < n)
              A[++ b] = A[e];
        }
    
        return b + 1;
    }
};