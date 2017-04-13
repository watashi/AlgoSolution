class Solution {
public:
  
  int findKthInSortedArrays(int A[], int m, int B[], int n, int k) {
    if (m == 0) return B[k - 1];
    if (n == 0) return A[k - 1];
    
    int b = 0, e = m - 1;
    
    while (b <= e) {
      int mid = (b + e) >> 1;
      int index = k - mid - 2;
      if (index >= n) {
        if (mid == k - n - 1 && B[n - 1] <= A[mid]) return A[mid];
        b = mid + 1;
      } else if (index < 0) {
        if (mid == k - 1 && B[0] >= A[mid]) return A[mid];
        e = mid - 1;
      } else if (B[index] <= A[mid]) {
        if (index == n - 1 || B[index + 1] >= A[mid]) return A[mid];
        else e = mid - 1;
      } else {
        b = mid + 1;
      }
    }
    
    return findKthInSortedArrays(B, n, A, m, k);
  }
  
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    if ((n + m) % 2 == 1) return findKthInSortedArrays(A, m, B, n, (n + m + 1) / 2);
    
    double sum = findKthInSortedArrays(A, m, B, n, (n + m) / 2);
    sum += findKthInSortedArrays(A, m, B, n, (n + m) / 2 + 1);
    
    return sum / 2;
  }
};