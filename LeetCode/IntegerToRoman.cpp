class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<pair<int, char> > h;
        h.push_back(make_pair(1000, 'M'));
        h.push_back(make_pair(500, 'D'));
        h.push_back(make_pair(100, 'C'));
        h.push_back(make_pair(50, 'L'));
        h.push_back(make_pair(10, 'X'));
        h.push_back(make_pair(5, 'V'));
        h.push_back(make_pair(1, 'I'));
        
        string ret = "";
        
        for (int i = 0; i < h.size(); i ++) {
            if (num >= h[i].first) {
                int cnt = num / h[i].first;
                
                if (cnt > 3 && i % 2 == 0 && i > 0) {
                    ret += string(5 - cnt, h[i].second);
                    ret += string(1, h[i - 1].second);
                    num %= (5 - cnt) * h[i].first;
                } else if (i % 2 && (h[i - 1].first - num) <= h[i + 1].first) { // Notice.
                    ret += string(1, h[i + 1].second);
                    ret += string(1, h[i - 1].second);
                    num -= h[i - 1].first;  // Don't mix first and second..
                    num += h[i + 1].first;
                } else {
                    ret += string (cnt, h[i].second);
                    num %= h[i].first;
                }
            }
        }
        
        return ret;
    }
};