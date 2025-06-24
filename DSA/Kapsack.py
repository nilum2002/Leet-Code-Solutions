



def Knapsack(W, V, W_max, n):
    if (n==0 or W_max==0):
        return 0
    pick = 0
    if (W[n-1]>= W_max):
        pick +=  V[n-1] + Knapsack(W, V, W_max-W[n-1], n-1)


    # not pick 

    not_pick = Knapsack(W, V, W_max, n-1)


    return max(not_pick,pick )






W = [4, 5, 1]
V = [1, 2, 3]
W_max = 4
n = len(W)


print(Knapsack(W, V, W_max, n))