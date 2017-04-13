class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int b = 0, e = n - 1;
        
        while (b <= e) {
            int mid = (b + e) >> 1;
            
            if (A[mid] == target) return mid;
            
            if (A[mid] >= A[b]) { // Why should be ">=" here, while not ">"
                // Because A[mid] == A[b] could be true because mid = (b + e) / 2
                // If e == mid, b == mid is always true, while when b == mid, e could be mid + 1
                if (A[b] > target) b = mid + 1;
                else if (A[mid] > target) e = mid - 1;
                else b = mid + 1;
            } else {
                if (A[e] < target) e = mid - 1;  
                // Why should be A[e] < target, while not A[b] < target here
                // Because, if A[b] < target, could not make sure if A[mid] < target, 
                // if A[mid] < target is true, b = mid + 1, so e = mid - 1 here should be wrong.
                
                else if (A[mid] > target) e = mid - 1;
                else b = mid + 1;
            }
        }
        
        return -1;
    }
};