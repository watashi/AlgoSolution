class Solution {
public:
    int countPoints(string rings) {
        static string rgb = "RGB";
        vector<int> c(10, 0);
        for (int i = 0; i < (int)rings.length(); i += 2) {
            int x = rgb.find(rings[i]);
            int y = rings[i + 1] - '0';
            c[y] |= 1 << x;
        }
        return (int)count(c.begin(), c.end(), 7);
    }
};
