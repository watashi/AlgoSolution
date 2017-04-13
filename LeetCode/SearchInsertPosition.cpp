class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int b = 0, e = n - 1;
        while (b <= e) {
            int mid = b + (e - b) / 2;
            if (A[mid] < target) {
                b = mid + 1;
            } else if (A[mid] > target) {
                e = mid - 1;
            } else {
                return mid;
            }
        }
        
        return b;
    }
};