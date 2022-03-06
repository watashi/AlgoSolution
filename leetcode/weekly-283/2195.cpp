class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back((int)nums.size() + k + 100);
        sort(nums.rbegin(), nums.rend());
        long long ans = 0;
        long long x = 1;
        while (k > 0) {
            while (nums.back() < x) {
                nums.pop_back();
            }
            long long y = min<long long>(x + k, nums.back());
            nums.pop_back();
            ans += (x + y - 1) * (y - x) / 2;
            k -= y - x;
            x = y + 1;
        }
        return ans;
    }
};
