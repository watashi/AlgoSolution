class Solution {
public:
    int readNextDire(int start, string &dir, const string &path) {
        dir = "";
        
        for (int i = start + 1; i < path.length(); i ++) {
            if (path[i] == '/') break;
            dir += string(1, path[i]);
        }
        
        if (dir == ".") return 0;
        if (dir == "..") return 2;
        if (dir.length() > 0) return 1;
        
        return 0;
    }
    
    void removeLastDire(string &path) {
        for (int i = path.length() - 1; i >= 0; i --) {
            if (path[i] == '/') {
                path = path.substr(0, i);
                return;
            }
        }
    }
    
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
        string dir = "";
        for (int i = 0; i < path.length(); i ++) {
            if (path[i] != '/') continue;
            
            int op = readNextDire(i, dir, path);
            if (op == 1) {
                ret += "/";
                ret += dir;
            } else if (op == 2) {
                removeLastDire(ret);
            }
        }
        
        if (ret.length() <= 0) return "/";
        return ret;
    }
};