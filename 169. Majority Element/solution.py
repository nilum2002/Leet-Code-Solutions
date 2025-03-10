
def majorityElement(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    # time complexity is O(N) 
    # there is an optimal way to solve this with the time complexity of O(1)
    n = len(nums)
    for num in list(set(nums)):
        if (nums.count(num) > n//2 ):
            return num
        
nums = [3, 2, 2]
print(majorityElement(nums))

####################################################################################################
# The Optimal Way 
####################################################################################################

def majorityElement(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    # time complexity is O(N) 
    # there is an optimal way to solve this with the time complexity of O(1)
    n = len(nums)
    majority = nums[len(nums)//2]
    return majority
        
nums = [3 , 2, 2]
print(majorityElement(nums))