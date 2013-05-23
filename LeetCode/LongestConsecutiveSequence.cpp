/**
  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

  For example,
  Given [100, 4, 200, 1, 3, 2],
  The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

  Your algorithm should run in O(n) complexity.

  
  */
  
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> visited;
        unordered_map<int, int> segment;
        
        for (int i = 0; i < num.size(); i ++) {
            if (visited.find(num[i]) != visited.end()) continue;
            
            visited.insert(num[i]);
            int high = num[i], low = num[i]; // Always remember to initialize
            
            if (segment.find(num[i] + 1) != segment.end()) 
                high = max(high, segment[num[i] + 1]);
            if (segment.find(num[i] - 1) != segment.end())
                low = min(low, segment[num[i] - 1]);
        
            segment.erase(num[i] - 1);
            segment.erase(num[i] + 1);
            
            segment[high] = low;
            segment[low] = high;
        }
        
        int ans = 1;
        for (unordered_map<int, int>::iterator it = segment.begin(); it != segment.end(); it ++) {
            ans = max(ans, abs(it->first - it->second) + 1);
        } 
        
        return ans;
    }
};