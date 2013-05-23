/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

    void merge(vector<Interval> &intervals, Interval newInterval, vector<Interval> &ret) {
        if (intervals.size() <= 0) {
            ret.push_back(newInterval);
            return;
        }
        
        if (newInterval.start <= intervals[0].start) {
            ret.push_back(newInterval);
        } 
        
        ret.push_back(intervals[0]);
        
        
        for (int i = 1; i < intervals.size(); i ++) {
            if (newInterval.start > intervals[i - 1].start && newInterval.start <= intervals[i].start) {
                ret.push_back(newInterval);
            }
            
            ret.push_back(intervals[i]);
        }
        
        // Don't forget if newInterval.start is the biggest one
        if (newInterval.start > intervals.back().start) ret.push_back(newInterval);
    }
    
    
    
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        
        merge(intervals, newInterval, ret);
        
        int b = 0, e = 1, maxTail = ret[b].end;
        while (b < e && e < ret.size()) {
            if (maxTail < ret[e].start) {
                b ++, e ++; 
                maxTail = ret[b].end;
                continue;
            }
            
            while (e < ret.size() && maxTail >= ret[e].start) {
                maxTail = max(maxTail, ret[e ++].end);
            }
            
            ret[b ++].end = maxTail;
            
            while (e < ret.size()) ret[b ++] = ret[e ++]; 
            
            // Remember to pop_back all the remaining Interval
            // I made a mistake here: I wrote while(b ++ <= ret.size()) ...
            // When I pop_back(), the ret.size() is decreased by 1, so... LOL
            while (ret.size() > b) ret.pop_back();
        }
        
        return ret;
        
    }
};