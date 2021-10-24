class Solution {
public:
    static int go(int p, const vector<vector<int>>& children, vector<int64_t>& score) {
        int n = (int)children.size();
        if (children[p].empty()) {
            score[p] = n - 1;
            return 1;
        } else {
            int s = 1;
            score[p] = 1;
            for (int i: children[p]) {
                int t = go(i, children, score);
                s += t;
                score[p] *= t;
            }
            if (s < n) {
                score[p] *= n - s;
            }
            return s;
        }
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = (int)parents.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parents[i]].push_back(i);
        }
        vector<int64_t> score(n);
        go(0, children, score);
        int64_t highest = *max_element(score.begin(), score.end());
        return (int)count(score.begin(), score.end(), highest);
    }
};
