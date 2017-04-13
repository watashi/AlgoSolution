struct BigInteger
{
    vector<int> num;
    
    BigInteger(const string& s)
    {
        for (int i = s.length()  - 1; i >= 0; --i)
            num.push_back(s[i] - '0');
    }
    
    BigInteger()
    {
        num.clear();
        num.push_back(0);
    }
    
    string ToString()
    {
        string ret = "";
        for (int i = num.size() - 1; i >= 0; --i) 
            ret += num[i] + '0';
        return ret;
    }
};

BigInteger operator + (const BigInteger& a, const BigInteger& b)
{
    BigInteger result;
    int maxLen = max(a.num.size(), b.num.size());
    result.num.assign(maxLen + 1, 0);
    
    int jiewei = 0;
    for (int i = 0; i <= maxLen; ++i)
    {
        result.num[i] = jiewei; 
        if (i < a.num.size()) result.num[i] += a.num[i];
        if (i < b.num.size()) result.num[i] += b.num[i];
        jiewei = result.num[i] / 10;
        result.num[i] %= 10;
    }
    
    while (result.num.back() == 0 && result.num.size() > 1) result.num.pop_back();
    return result;
}

BigInteger operator * (const BigInteger& a, int n) 
{
    BigInteger result, tmp;
    tmp.num = a.num;
    
    int delta = 1;
    for (int i = 0; i < tmp.num.size(); i ++) {
        tmp.num[i] *= n;
    }
    
    result = result + tmp;
    
    return result;
}

BigInteger operator * (const BigInteger& a, const BigInteger& b) 
{
    BigInteger result, tmpB;
    tmpB.num = b.num;
    
    for (int i = 0; i < a.num.size(); i ++) {
        BigInteger tmp = tmpB * a.num[i];
        result = result + tmp;
        tmpB = tmpB * 10;
    }
    
    return result;
}

class Solution {
public:

    
    void mutiplySingleNum(const string &num, int n, vector<int> &result) {
        if (n == 0) return;
        
        for (int i = 0; i < num.length(); i ++) {
            result[i] += (num[i] - '0') * n;
        }
    }
    
    string getAnswerString(vector<int> &result) {
        int delta = 0;
        
        for (int i = 0; i < result.size(); i ++) {
            result[i] += delta;
            delta = result[i] / 10;
            result[i] %= 10;
        }
        
        while (delta > 0) {
            result.push_back(delta % 10);
            delta /= 10;
        }
        
        while (result.back() == 0) result.pop_back();
        
        string ret = "";
        for (int i = result.size() - 1; i >= 0; i --) {
            ret += string(1, result[i] + '0');
        }
        
        // Remember, the 0 case...
        if (ret.length() == 0) ret = "0";
        
        return ret;
    }
    
    string multiply2(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(num1.length() + num2.length(), 0);
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for (int i = 0; i < num2.length(); i ++) {
            mutiplySingleNum(num1, num2[i] - '0', result);
            
            // Multiply num1 by 10
            num1 = string(1, '0') + num1;
        }
        
        return getAnswerString(result);
    }
    
    string multiply(string num1, string num2)
    {
        BigInteger n1(num1);
        BigInteger n2(num2);
        BigInteger ans = n1 * n2;
        return ans.ToString();
    }
};