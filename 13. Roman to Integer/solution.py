def romanToInt(self, s):
    roman_val = {"I":1, "V":5, "X": 10, "L": 50, "C":100, "D": 500, "M": 1000}
    val = 0
    for i in range(len(s)-1):
        if roman_val[s[i]] < roman_val[s[i+1]]:
            val-= roman_val[s[i]]
        else:
            val+= roman_val[s[i]]

    return val+ roman_val[s[-1]]
