class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!str) return 0;
        int len = strlen(str);
        if (len == 0) return 0;
        
        while (str[0] == ' ') {str ++; len --;}
        
        bool isNegative = false;
        if (str[0] == '-') {isNegative = true; str ++; len --;}
        else if (str[0] == '+') {str ++; len --;}
        
        long long ans = 0;
        for (int i = 0; i < len; i ++) {
            if (str[i] < '0' || str[i] > '9') break;
            ans = ans * 10 + str[i] - '0';
        }
        
        // should be careful here, if the ans is overflow int, do special case...
        if (isNegative) {
            ans = 0 - ans;
            if (ans < INT_MIN) ans = INT_MIN;
        } else if (ans > INT_MAX) ans = INT_MAX;
        
        return ans;
    }
};