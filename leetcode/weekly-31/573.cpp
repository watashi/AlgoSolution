class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0, diff = INT_MAX;
        for (int i = 0; i < (int)nuts.size(); ++i) {
            int tmp = abs(nuts[i][0] - tree[0]) + abs(nuts[i][1] - tree[1]);
            sum += tmp;
            diff = min(diff, abs(nuts[i][0] - squirrel[0]) + abs(nuts[i][1] - squirrel[1]) - tmp);
        }
        return sum * 2 + diff;
    }
};
