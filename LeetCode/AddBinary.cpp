class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (a.length() < b.length()) swap(a, b);
        int delta = 0;
        
        int j = a.length() - 1;
        for (int i = b.length() - 1; i >= 0; i --) {
            int tmp = a[j] - '0' + b[i] - '0' + delta;
            if (tmp > 1) {
                delta = 1;
                tmp -= 2;  //Here, tmp -= 2, tmp could be 2 or 3...
            } else delta = 0; //Don't forget else...
            
            a[j --] = tmp + '0';
        }
        
        while (delta > 0 && j >= 0) {
            int tmp = a[j] - '0' + delta;
            if (tmp > 1) {
                delta = 1;
                tmp -= 2;
            } else delta = 0; // Don't forget else...
            
            a[j --] = tmp + '0';
        }
        
        if (delta > 0) a = string(1, '1') + a;
        
        return a;
    }
};