class Solution {
public:
    void sortColors2(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return;
        
        // mid, is the count number of 1.
        int b = 0, e = n - 1, mid = 0;  
        
        while (b + mid <= e) {
            if (A[b] == 0) {
                b ++;
                if (b + mid <= e) swap(A[b], A[b + mid]);
            } else if (A[b] == 2) {
                swap(A[b], A[e --]);
            } else {
                mid ++;
                if (b + mid <= e) swap(A[b], A[b + mid]);
            }
        }
    }
    
    void sortColors(int A[], int n) {
        if (n <= 1) return;
        int b = 0, e = n - 1, i = 0;
        while (i < n && i <= e) {
            if (A[i] == 0) {
                swap(A[b ++], A[i ++]);
            } else if (A[i] == 2) {
                swap(A[i], A[e --]);
            } else i ++; 
        }
    }
};