from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if k > n or k < 0:
            return []
        if k == 0:
            return [[]]

        res = self.combine(n - 1, k - 1)
        for a in res:
            a.append(n)

        for a in self.combine(n - 1, k):
            res.append(a)

        return res
