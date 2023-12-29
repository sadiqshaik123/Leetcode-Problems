from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        pre, cur, cnt, n = 0, 1, 1, len(nums)
        
        while cur < n:
            if nums[pre] == nums[cur] and cnt == 0:
                cur += 1
            else:
                if nums[pre] == nums[cur]:
                    cnt -= 1
                else:
                    cnt = 1
                pre += 1
                nums[pre] = nums[cur]
                cur += 1

        return 0 if not nums else pre + 1
