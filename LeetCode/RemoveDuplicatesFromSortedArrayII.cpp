class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0) return 0; //Notice, the 0 case
        
        int cnt = 1, ans = 1, i = 1;
        while (i < n) {
            while (i < n && A[ans - 1] == A[i] && cnt < 2) {
                A[ans ++] = A[i ++];
                cnt ++;
            }
            
            //cnt = 0; //There is no need to set cnt 0 here
            while(i < n && A[ans - 1] == A[i]) i ++;
            
            if (i < n) {
                A[ans ++] = A[i ++];
                cnt = 1;
            }
        }
        
        return ans;
    }
};