class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int iter = 1;
        string ret = "1";
        
        while (iter < n) {
            stringstream output;
            
            char last = ret[0];
            int cnt = 1;
            for (int i = 1; i < ret.length(); i ++) {
                if (ret[i] == last) {
                    cnt ++;
                } else {
                    output << cnt << last;
                    last = ret[i];
                    cnt = 1;
                }
            }
            
            // output the last count and say
            output << cnt << last;
            
            ret = output.str();
            
            iter ++;
        }
        
        return ret;
    }
};