/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool compare(const Interval & a, const Interval & b) {
    return a.start < b.start;
 }
    
class Solution {
public:

    // Much simpler version:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret(intervals.begin(), intervals.end());
        
        if (ret.size() <= 1) return ret;
        
        sort(ret.begin(), ret.end(), compare);
        
        int b = 0, e = 0;
        for (int i = 1; i < ret.size(); i ++) {
            if (ret[e].end < ret[i].start) {
                ret[b ++] = ret[e];
                e = i;
            } else {
                ret[e].end = max(ret[e].end, ret[i].end);
            }
        }
        
        ret[b ++] = ret[e];
        
        ret.resize(b);
        
        return ret;
    }
    
    vector<Interval> merge2(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret(intervals.begin(), intervals.end());
        
        if (ret.size() <= 1) return ret;
        
        sort(ret.begin(), ret.end(), compare);
        
        int b = 0, e = 1, maxTail = ret[b].end;
        while (b < e && e < ret.size()) {
            if (maxTail < ret[e].start) {
                if (e - b > 1) ret[b + 1] = ret[e];
                b ++, e ++;
                maxTail = ret[b].end;
                continue;
            }
            
            while (e < ret.size() && maxTail >= ret[e].start) {
                maxTail = max(maxTail, ret[e ++].end);
            }
            
            // The following block is very important...
            ret[b].end = maxTail;
            if (e < ret.size()) {
                ret[++ b] = ret[e ++]; // Move b and e, to the next one...
                maxTail = ret[b].end;
            }
        }
        
        ret.resize(b + 1);
        
        return ret;
    }
};