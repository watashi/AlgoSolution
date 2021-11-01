class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        static constexpr int MAXN = 1000;
        vector<int> dist(MAXN + 1, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while (!q.empty()) {
            start = q.front();
            q.pop();
            for (int i: nums) {
                int to[3] = {start + i, start - i, start ^ i};
                for (int j: to) {
                    if (j == goal) {
                        return dist[start] + 1;
                    } else if (0 <= j && j <= MAXN && dist[j] == -1) {
                        dist[j] = dist[start] + 1;
                        q.push(j);
                    }
                }
            }
        }
        return -1;
    }
};
