class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int b = -1, e = 0;
        
        while (e < n) {
            if (A[e] != elem) {
                A[++ b] = A[e];
            } 
            
            e ++;
        }
        
        return b + 1;
    }
};