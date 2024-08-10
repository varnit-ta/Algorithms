# 5
# ?????
# xbx
# ab??e
# abcde
# ayy?x
# a
# ab??e
# dac
# paiu
# mom


num = int(input())

def check(str1, str2):
    for i in range(len(str1)):
        if str1[i] == str2[i] or str[2] == "?":
            continue
        else:
            return False
        
    return True

for _ in range(num):
    s = list(input())
    t = input()

    i = 0
    count = 0

    found = False

    while i < len(s) and not found:
        if check(''.join(s[i:i+len(t)]), t):
            found = True
        
        i += 1

        if found:
            print("YES")
            s[i:i+len(t)] = list(t)
            print("".join(s))
        
    if not found:
        print("NO")