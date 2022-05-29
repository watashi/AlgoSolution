class Solution {
public:
    string discountPrices(string sentence, int discount) {
        double y = (100.0 - discount) / 100;
        const char* p = sentence.data();
        string ret;
        while (*p != '\0') {
            if (*p == ' ') {
                ret += *p++;
                continue;
            }
            if (*p == '$' && isdigit(p[1])) {
                char* q;
                auto x = strtoll(p + 1, &q, 10);
                if (*q == ' ' || *q == '\0') {
                    char buf[80];
                    sprintf(buf, "$%.2f", x * y);
                    ret += buf;
                    p = q;
                    continue;
                }
            }
            while (*p != ' ' && *p != '\0') {
                ret += *p++;
            }
        }
        return ret;
    }
};
