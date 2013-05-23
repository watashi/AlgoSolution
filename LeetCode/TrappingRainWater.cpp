/**
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

 For example, 
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.



 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */
 
class Solution {
public:
    int getRainDropFromLeftToRight(int A[], int n, bool including) {
        if (n < 3) return 0;
        
        vector<int> sequence;
        sequence.push_back(0);
        int curr = A[0];
        
        for (int i = 1; i < n; i ++) {
            if (including && curr <= A[i]) {
                curr = A[i];
                sequence.push_back(i);
            } else if (!including && curr < A[i]) {
                curr = A[i];
                sequence.push_back(i);
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < sequence.size() - 1; i ++) {
            int rainDrop = 0;
            for (int j = sequence[i] + 1; j < sequence[i + 1]; j ++) {
                rainDrop += A[sequence[i]] - A[j];
            }
            
            ans += rainDrop;
        }
        
        return ans;
    }
    
    void reverse(int A[], int n) {
        int b = 0, e = n - 1;
        while (b < e) swap(A[b ++], A[e --]);
    }
    
    int trap2(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int ans = getRainDropFromLeftToRight(A, n, true);
        reverse(A, n);
        ans += getRainDropFromLeftToRight(A, n, false);
        
        return ans;
    }
    
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> leftBar(n, 0), rightBar(n, 0);
        for (int i = 1; i < n; i ++) 
            leftBar[i] = max(leftBar[i - 1], A[i - 1]);
        for (int i = n - 2; i >= 0; i --) 
            rightBar[i] = max(rightBar[i + 1], A[i + 1]);
            
        int ret = 0;
        for (int i = 0; i < n; i ++) 
            ret += max(0, min(leftBar[i], rightBar[i]) - A[i]);
        
        return ret;
    }
};