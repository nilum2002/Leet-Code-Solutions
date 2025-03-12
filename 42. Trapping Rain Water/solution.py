def trap(height):
    """
    :type height: List[int]
    :rtype: int
    """
    left_wall = 0
    right_wall = 0
    max_left = [0]*len(height)
    max_right = [0]*len(height)

    for i in range(len(height)):
        # get the right indexes 
        j = -i-1
        max_right[j] = right_wall
        max_left[i] = left_wall
        left_wall = max(left_wall,height[i] )
        right_wall = max(right_wall, height[j])
    print("left_array : ", max_left)
    print("Right array :", max_right)

    res_arr = [0]*len(height)
    for i in range(len(height)):
        p = min(max_left[i], max_right[i])
        res_arr[i] =  max(0, p - height[i])
    print(res_arr)
    return "The tptal volume : " + str(sum(res_arr))

arr = [0,1,0,2,1,0,1,3,2,1,2,1]
print(len(arr))
print(trap(arr))


# when I go with this problem It was very hard to understand how to solve this. Then I realized this method. Good Luck with this.