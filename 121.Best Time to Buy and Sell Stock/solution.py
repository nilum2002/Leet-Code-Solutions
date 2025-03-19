def maxProfit(prices):
    m = 0
    stk = [prices[0]]
    for i in range(1,len(prices)):
        if stk[-1] > prices[i]:
            stk.pop()
            stk.append(prices[i])
        else:
            m = max(m, prices[i] - stk[-1])
    return m

print(maxProfit([7,1,5,3,6,4]))