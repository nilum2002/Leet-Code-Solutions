def uniqueOccurrences(arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        map_nums = {}
        for num in set(arr):
            map_nums[num] = arr.count(num)
        set_count = set()
        for val in map_nums.values():
            if val in set_count:
                return False
            else:
                set_count.add(val)
        return True
arr = [1,2,2,1,1,3]
print(uniqueOccurrences(arr))