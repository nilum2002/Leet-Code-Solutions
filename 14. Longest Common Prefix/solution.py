def longestCommonPrefix(strs):
    #get the mnimum length word
    min_word = strs[0] # cir 
                           # car 
    for s in strs:
        if len(s) < len(min_word):
            min_word = s
    min_length = len(min_word)
    i = 0
    while (i < min_length):
        for s in strs:
            if s[i] != strs[0][i]:
                return s[:i]
        i += 1
    return strs[0][:i]


    ###############################################
    # this is a nice approach 
    

    # pre = strs[0]
    # pre_length = len(strs[0])
    # for s in strs[1:]:
    #     while pre != s[0:pre_length]:
    #         pre_length -= 1
    #         if (pre_length==0):
    #             return ""
    #         pre = pre[0: pre_length]
    # return pre[0:pre_length] 
        
strs = ["car", "cir"]
print(longestCommonPrefix(strs))