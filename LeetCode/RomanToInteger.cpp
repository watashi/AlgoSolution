class Solution {
public:

    int romanToInt(const string& str)
    {
        int h[256];
        memset(h, 0, sizeof(h));
        h['I'] = 1;
        h['V'] = 5;
        h['X'] = 10;
        h['L'] = 50;
        h['C'] = 100;
        h['D'] = 500;
        h['M'] = 1000;
        
        int ans = 0;
        for (unsigned int i = 0; i < str.length(); ++i)
        {
            if ((str[i] == 'I' || str[i] == 'X' || str[i] == 'C') && i + 1 < str.length() && h[str[i]] < h[str[i + 1]]) 
                ans -= h[str[i]];
            else
                ans += h[str[i]];
        }
        return ans;
    }
    
    int romanToInt2(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000

        int h[256];
        memset(h, 0, sizeof(h));
        h['I'] = 1;
        h['V'] = 5;
        h['X'] = 10;
        h['L'] = 50;
        h['C'] = 100;
        h['D'] = 500;
        h['M'] = 1000;
        
        int ans = 0, tmp = 0, cnt = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (h[s[i]] == tmp) {
                cnt ++;
            } else if (h[s[i]] > tmp) {
                ans -= tmp * cnt;
                tmp = h[s[i]];
                cnt = 1;
            } else {
                ans += tmp * cnt;
                tmp = h[s[i]];
                cnt = 1;
            }
        }
        
        ans += tmp * cnt; //Here, add the last component...
        
        return ans;
    }
};