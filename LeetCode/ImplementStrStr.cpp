/**
  *
  * Implement strStr().

  * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
  *
  */

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int haystackLength = strlen(haystack);
        int needleLength = strlen(needle);
        
        if (needleLength == 0) return haystack;
        if (haystackLength < needleLength) return NULL;
        
        int p[needleLength];
        p[0] = -1;
        int j = -1;
        for (int i = 1; i < needleLength; i ++) {
            while (j >= 0 && needle[j + 1] != needle[i]) j = p[j];
            if (needle[j + 1] == needle[i]) j ++;
            p[i] = j;
        }
        
        j = -1;
        for (int i = 0; i < haystackLength; i ++) {
            while (j >= 0 && needle[j + 1] != haystack[i]) j = p[j];
            if (needle[j + 1] == haystack[i]) j ++;
            if (j == needleLength - 1) {
                return haystack + i - j;
            }
        }
        
        return NULL;
    }
};