/**
  Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

  Only one letter can be changed at a time
  Each intermediate word must exist in the dictionary
  For example,

  Given:
  start = "hit"
  end = "cog"
  dict = ["hot","dot","dog","lot","log"]

  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
  return its length 5.

  Note:

  Return 0 if there is no such transformation sequence.
  All words have the same length.
  All words contain only lowercase alphabetic characters.
  
  */

class Solution {
public:
    int bfs(string start, string end, unordered_set<string> &dict)
    {
        map<string, bool> visited;
        visited[start] = true;
        
        queue<pair<string, int> >q;
        q.push(make_pair(start, 1));
        
        while (!q.empty()) {
            pair<string, int> node = q.front();
            q.pop();
            string tmp = node.first;
            
            if (node.first == end) return node.second;
            
            for (int i = 0; i < start.length(); i ++) {
                for (int j = 'a'; j <= 'z'; j ++) {
                    if (j != node.first[i]) {
                        tmp[i] = j;
                        
                        if (dict.find(tmp) != dict.end() && !visited[tmp]) {
                            visited[tmp] = true;
                            q.push(make_pair(tmp, node.second + 1));
                        }
                        
                        tmp[i] = node.first[i];
                    }
                }
            }
        }
        
        return 0;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start.length() != end.length()) return 0;
        
        return bfs(start, end, dict);
    }
};