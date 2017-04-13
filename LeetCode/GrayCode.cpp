class Solution {
public:
    
    vector<int> grayCodeAnotherSolution(int n)   
    {   
        vector<int> ret;   
        int size = 1 << n;   
        for(int i = 0; i < size; ++i)   
            ret.push_back( (i >> 1) ^ i );   
        
        return ret;   
    }

    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(1, 0);
        
        for (int i = 0; i < n; i ++) {
            int delta = 1 << i;
            
            for (int i = ret.size() - 1; i >= 0; i --) {
                ret.push_back(ret[i] + delta);
            }
        }
        
        return ret;
    }
  
};