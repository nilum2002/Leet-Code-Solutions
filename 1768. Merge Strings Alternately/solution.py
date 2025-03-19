def mergeAlternately( word1: str, word2: str):
    res = ""
    if (len(word1)<= len(word2)):
        for i in range(len(word1)):
            res += word1[i] + word2[i]
        res += word2[len(word1):]
    else:
        for i in range(len(word2)):
            res += word1[i] + word2[i]
        res += word1[len(word2):]

    return res


word1 ="abcd"
word2 = "pq"


print(mergeAlternately(word1,word2))