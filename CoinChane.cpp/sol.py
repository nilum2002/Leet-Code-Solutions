



def change(amount, coins):
    
    if all (amount < c for c in coins):
        return 0
    opts = []
    for c in coins:
        opts.append(change(amount-c, coins))
    return min(opts)+1



amount = 7
coins = [1, 3, 4 , 5]
print(change(amount, coins))
