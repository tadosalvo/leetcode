# Hashmap solution
# returns the max key with the highest count
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = collections.Counter(nums)
        return max(count.key(), key=count.get)
    
    
# Boyer-Moore Voting algorithm
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = None
        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1) #adds 1 if current cand is repeated -1 if otherwise
        return candidate