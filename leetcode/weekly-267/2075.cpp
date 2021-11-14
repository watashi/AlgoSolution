class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = (int)encodedText.size() / rows;
        string ret = "";
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows && (i + j) < cols; ++j) {
                ret += encodedText[j * cols + i + j];
            }
        }
        while (ret.length() > 0 && ret.back() == ' ') {
            ret.pop_back();
        }
        return ret;
    }
};
