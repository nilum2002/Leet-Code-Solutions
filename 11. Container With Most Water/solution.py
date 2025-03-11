def maxArea(height):
    """
    :type height: List[int]
    :rtype: int
    """
    left = 0
    right = len(height) - 1
    max_amount = 0

    while left < right:
        m = min(height[left], height[right])
        area = m * (right - left)
        max_amount = max(area, max_amount)

        if height[left] > height[right]:
            right -= 1
        else:
            left += 1

    return max_amount

arr= [1,8,6,2,5,4,8,3,7]
print(maxArea(arr))

            

        