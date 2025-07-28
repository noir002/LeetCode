class Solution(object):
    def countMaxOrSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        self.max_or = 0
        self.count = 0
        n = len(nums)
        
        def backtrack(index, curr_or):
            if index == n:
                if curr_or == self.max_or:
                    self.count += 1
                elif curr_or > self.max_or:
                    self.max_or = curr_or
                    self.count = 1
                return
            
            # Include nums[index]
            backtrack(index + 1, curr_or | nums[index])
            # Exclude nums[index]
            backtrack(index + 1, curr_or)
        
        backtrack(0, 0)
        return self.count
