import string
s = input()
n = len (s)
pref = {} 
# prefl'a'][5] = occurrences of 'a' in s[0..4]
for char in "abc":
# create temporary array with 0s and 1s
    tmp = [0] * (n + 1)
    for i in range(n):
        if s[i] == char:
            tmp [i+1] = 1
    # run prefix sums
    for i in range(n):
        print(tmp);
        tmp[i+1] += tmp [i]
        print(tmp,char)

    pref[char] = tmp
