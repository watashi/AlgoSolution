/**
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  For example,
  "A man, a plan, a canal: Panama" is a palindrome.
  "race a car" is not a palindrome.

  Note:
  Have you consider that the string might be empty? This is a good question to ask during an interview.

  For the purpose of this problem, we define empty string as valid palindrome.
  */

class Solution {
public:

    bool isCharacter(char &a)
    {
        if (a >= 'a' && a <= 'z') {
            a = a - 'a' + 'A';
            return true;
        }
        
        return (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9');
    }
    
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int b = 0, e = s.length() - 1;
        
        while (b < e) {
            // It is easy to forget b < s.length() && e >= 0
            while (b < s.length() && !isCharacter(s[b])) b ++;
            while (e >= 0 && !isCharacter(s[e])) e --;
            
            if (b < e && s[b ++] != s[e --]) return false;
        }
        
        return true;
    }
};