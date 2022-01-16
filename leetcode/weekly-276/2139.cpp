class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int d = sizeof(target) * 8 - __builtin_clz(target) - 1;
        if (d <= maxDoubles) {
            return d + __builtin_popcount(target) - 1;
        } else {
            return (target >> maxDoubles) - 1 + maxDoubles + __builtin_popcount(target & ((1 << maxDoubles) - 1));
        }
    }
};
