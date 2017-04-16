class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        ret = str(nums[0])
        if len(nums) > 2:
            ret = ret + '/(' + '/'.join(map(str, nums[1:])) + ')'
        elif len(nums) > 1:
            ret = ret + '/' + str(nums[1])
        return ret
