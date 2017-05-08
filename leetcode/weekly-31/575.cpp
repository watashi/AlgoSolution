class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> s;
        for (int i: candies) {
            s.emplace(i);
        }
        return (int)min(s.size(), candies.size() / 2);
    }
};
