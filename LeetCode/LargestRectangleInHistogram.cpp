struct Node{
  int index, height;
  Node();
  Node(int i, int h) {
    index = i, height = h;
  }
  
  bool operator < (const Node & a) const {
    return this->height < a.height;
  }
};

class Solution {
public:
  int maxContinuousArea;
  map<int, int> hash;
  
  void insert(int index) {
    int ret = 1, low = index, high = index;
    
    if (hash.find(index + 1) != hash.end()) {
      high = hash[index + 1];
      hash.erase(index + 1);
    } 
    
    if (hash.find(index - 1) != hash.end()) {
      low = hash[index - 1];
      hash.erase(index - 1);
    }
    
    hash[high] = low;
    hash[low] = high;
    
    maxContinuousArea = max(maxContinuousArea, high - low + 1);
  }
  
  int largestRectangleArea(vector<int> &height) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<Node> h;
    for (int i = 0; i < height.size(); i ++) {
      h.push_back(Node(i, height[i]));
    }
    
    sort(h.begin(), h.end());
    
    maxContinuousArea = 1;
    hash.clear();
    
    int ans = 0;
    
    for (int i = h.size() - 1; i >= 0; i --) {
      insert(h[i].index);
      ans = max(ans, h[i].height * maxContinuousArea);    
    }
    
    return ans;
  }
};