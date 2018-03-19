import sys
import random

# language {a^n b^n : n \in IN}
def L(w):
    i = 0
    mid = False
    for a in w:
        if a not in ['a', 'b']:
            return False
        if a == 'a' and not mid:
            i += 1
        if a == 'a' and mid:
            return False
        if a == 'b' and mid:
            i -= 1
        if a == 'b' and not mid:
            r = i
            mid = True
            i -= 1
    if i != 0 or 2*r < n:
        return False
    return True

n = random.randint(1, 10)
print("Alice claims the language [[a^n b^n : n in IN]] is regular and there exists an automaton with {0} states.".format(n))
w = input("Choose a word in the language of length >= {0}: ".format(n))

if not L(w):
    sys.exit("Your word is not in the language or your word is too short, you lose!")

k = random.randint(0, n-1)
l = random.randint(k+1, n)

x = w[:k]
y = w[k:l]
z = w[l:]

print("Alice chooses the decomposition x = {0}, y = {1}, z = {2}.".format(x, y, z))
i = int(input("Choose a natural number i sucht that xy^iz is not in the language: "))

wp = x + (y*i) + z

if not L(wp):
    print("w' = xy^{0}z is not in the language, you win.".format(i))
else:
    sys.exit("w' = xy^{0}z is in the language, you lose.".format(i))
