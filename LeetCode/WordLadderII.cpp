/**
  Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

  Only one letter can be changed at a time
  Each intermediate word must exist in the dictionary
  For example,

  Given:
  start = "hit"
  end = "cog"
  dict = ["hot","dot","dog","lot","log"]

  Return

    [
      ["hit","hot","dot","dog","cog"],
      ["hit","hot","lot","log","cog"]
    ]
  Note:

  All words have the same length.
  All words contain only lowercase alphabetic characters.
  */
  
typedef unordered_set<string> curset;


class Solution {
public:
  
  map<string, vector<string> > p;
  vector<vector<string> > ans;
  
  vector<string> getNeighbors(string start, curset &dict) {
    vector<string> ret;
    
    string tmp = start;
    for (int i = 0; i < start.length(); i ++) {
      for (char j = 'a'; j <= 'z'; j ++) {
        if (start[i] == j) continue;
        
        tmp[i] = j;
        if (dict.find(tmp) != dict.end()) ret.push_back(tmp);
      }
      tmp[i] = start[i];
    }
    
    return ret;
  }
  
  void search(int offset, string cur, string end, vector<string> &path) {
    path[offset] = cur;
    
    if (offset == 0) {
      ans.push_back(path);
    } else {
      for (string pre : p[cur]) {
        search(offset - 1, pre, end, path);
      }
    }
  }
  
  vector<vector<string> > findLadders(string start, string end, curset &dict) {
    ans.clear();
    p.clear();
    
    map<string, int> minDis;
    set<string> visited;
    queue<string> q;
    
    q.push(start);
    visited.insert(start);
    minDis[start] = 0;
    
    while(!q.empty()) {
      string node = q.front();
      q.pop();
      
      if (node == end) break;
      
      vector<string> nbs = getNeighbors(node, dict);
      for (string nb : nbs) {        
        if (visited.find(nb) == visited.end()) {
          q.push(nb);
          visited.insert(nb);
          
          minDis[nb] = minDis[node] + 1;
        }
        
        if (minDis[node] + 1 == minDis[nb]) p[nb].push_back(node);
      }
    }
    
    if (minDis.find(end) == minDis.end()) return ans;
    
    vector<string> path(minDis[end] + 1);
    search(minDis[end], end, start, path);
    
    return ans;

  }
};

//----------------------------------------
//Version 2:
//----------------------------------------
typedef unordered_set<string> curset;

class Solution {
public:
  int minimalLevel;
  map<string, int> wordsMap;
  vector<vector<int> > ansPath;
  vector<vector<int> > previous;
  vector<int> path;
  vector<vector<int> > linkedList;
  vector<vector<string> > ans;
  
  void dfs(int offset, int cur, int end) {
    path[offset] = cur;
    
    if (offset == 0) {
      ansPath.push_back(path);
      return;
    } else {
      for (int i = 0; i < previous[cur].size(); i ++) {
        dfs(offset - 1, previous[cur][i], end);
      }
    }
  }
  
  int bfs(int start, int end) {
    vector<int> minDis(linkedList.size(), INT32_MAX);
    vector<bool> visited(linkedList.size(), false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    minDis[start] = 0;
    
    while(!q.empty()) {
      int node = q.front();
      q.pop();
      
      for (int i = 0 ; i < linkedList[node].size(); i ++) {
        int nb = linkedList[node][i];
        
        if (!visited[nb]) {
          q.push(nb);
          visited[nb] = true;
          minDis[nb] = minDis[node] + 1;
        }
        // This line is important: if minDid[nb] < minDis[node] + 1, it would be wrong to push node back
        if (minDis[node] + 1 == minDis[nb]) previous[nb].push_back(node);
      }
    }
    
    return minDis[end];
  }
  
  void init(curset &dict)
  {
    ans.clear();
    ansPath.clear();
    path.clear();
    wordsMap.clear();
    previous.assign(dict.size(), vector<int>());
    linkedList.assign(dict.size(), vector<int>());
  }
  
  vector<vector<string> > findLadders(string start, string end, curset &dict) {
    init(dict);
    
    vector<string> words(dict.begin(), dict.end());
    for (unsigned int i = 0; i < words.size(); i ++) wordsMap[words[i]] = i;
    
    for (int i = 0; i < words.size(); i ++) {
      string currWord = words[i];
      for (int j = 0; j < words[i].length(); j ++) {
        for (char k = 'a'; k <= 'z'; k ++) {
          if (words[i][j] == k) continue;
          
          currWord[j] = k;
          if (dict.find(currWord) != dict.end()) linkedList[i].push_back(wordsMap[currWord]);
        }
        currWord[j] = words[i][j];
      }
    }
    
    int offset = bfs(wordsMap[start], wordsMap[end]);
    if (offset == INT32_MAX) return ans;
    
    path.resize(offset + 1);
    dfs(offset, wordsMap[end], wordsMap[start]);
    
    for (int i = 0; i < ansPath.size(); i ++) {
      vector<string> p;
      for (int j = 0; j < ansPath[i].size(); j ++) {
        p.push_back(words[ansPath[i][j]]);
      }
      ans.push_back(p);
    }
    
    return ans;
  }
};

/*
// Time limited version...
class Solution {
public:
  int minimalLevel;
  
  vector<string> getNeighbors(string key, unordered_set<string> &dict) {
    vector<string> ret;
    string tmp = key;
    
    for (int i = 0; i < key.length(); i ++) {
      for (int c = 'a'; c <= 'z'; c ++) {
        if (key[i] == c) continue;
        
        tmp[i] = c;
        if (dict.find(tmp) != dict.end()) ret.push_back(tmp);
        tmp[i] = key[i];
      }
    }
    
    return ret;
  }
  
  void dfs(map<string, set<string> > &previous, vector<vector<string> > &ans, vector<string> &path, int level, string start, string end) {
    path.push_back(start);
    
    if (start == end) {
      ans.push_back(path);
    } else {
      if (level >= minimalLevel) {
          path.pop_back();
          return;
      }
      
      for (set<string>::iterator it = previous[start].begin(); it != previous[start].end(); it ++) {    
        dfs(previous, ans, path, level + 1, *it, end);
      }
    }
    
    path.pop_back();
  }
    
  vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    vector<vector<string> > ans;
    map<string, set<string> > previous;
    
    set<string> visited;
    visited.insert(start);
    
    queue<string> q;
    q.push(start);
    bool isPathFound = false;
    minimalLevel = 0;
    
    while(!q.empty() && !isPathFound) {
      string backNode = q.back();
      minimalLevel ++;
      
      while (!q.empty()) {
        string node = q.front();
        q.pop();
        
        for (string nb : getNeighbors(node, dict)) {
          if (nb == end) isPathFound = true;
          
          if (visited.find(nb) == visited.end()) {
            q.push(nb);
            visited.insert(nb);
          }
          
          previous[nb].insert(node);
        }
        
        if (node == backNode) break;
      }
    }
    
    if (!isPathFound) return ans;
    
    vector<string> path;
    visited.clear();
    dfs(previous, ans, path, 0, end, start);
    
    for (int i = 0; i < ans.size(); i ++) {
      int b = 0, e = ans[i].size() - 1;
      while (b < e) {
        swap(ans[i][b ++], ans[i][e --]);
      }
    }
    
    return ans;
  }
};
*/

