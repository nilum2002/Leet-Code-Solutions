def minimumBoxes(apple, capacity):
    total_size = sum(apple)
    count = 0
    sorted_capscity = sorted(capacity, reverse = True )
    for c in sorted_capscity:
        if total_size > 0:
            count += 1
            total_size-= c
        else:
            break
    return count 

apple =[1,3,2]
capacity = [4, 3,1,5,2]
print(minimumBoxes(apple, capacity))