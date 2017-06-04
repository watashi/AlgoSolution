class Solution {
public:
    bool cdata(const char*& p) {
        const char* prefix = "<![CDATA[";
        if (strncmp(p, prefix, strlen(prefix)) != 0) {
            return false;
        }
        const char* q = strstr(p, "]]>");
        if (q == nullptr) {
            return false;
        } else {
            p = q + 3;
            return true;
        }
    }
    
    bool tag(const char*& p) {
        const char* q = p;
        if (*q++ != '<') {
            return false;
        }
        string tag;
        while (*q != '\0' && isupper(*q)) {
            tag += *q;
            ++q;
        }
        if (tag.length() < 1 || tag.length() > 9) {
            return false;
        }
        if (*q++ != '>') {
            return false;
        }
        content(q);
        if (*q++ != '<') {
            return false;
        }
        if (*q++ != '/') {
            return false;
        }
        if (strncmp(q, tag.data(), tag.size()) != 0) {
            return false;
        } else {
            q += tag.size();
        }
        if (*q++ != '>') {
            return false;
        }
        p = q;
        return true;
    }
    
    void content(const char*& p) {
        while (*p != '\0') {
            if (*p != '<') {
                ++p;
            } else if (!cdata(p) && !tag(p)) {
                break;
            }
        }
    }

    bool isValid(string code) {
        const char* p = code.data();
        return tag(p) && *p == '\0';
    }
};
