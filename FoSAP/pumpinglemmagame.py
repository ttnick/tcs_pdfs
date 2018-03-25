import sys
import random

# configuration
lang = "{a^n b^n : n in IN}"	# language
maxn = 10						# maximal number of states

# checks if a word w is in the language L
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
			mid = True
			i -= 1
	return (i == 0)

# choose a number of states
def choose_n(minn=1, maxn=maxn):
	return random.randint(minn, maxn)

# checks if a word is long enough
def length(w, m):
	return (len(w) >= m)

# decomposition strategy
def decompose(n, w):
	k = random.randint(0, n-1)
	l = random.randint(k+1, n)
	return k, l

# play
# 1. Alice chooses number of states n
n = choose_n()
print("Alice claims the language {0} is regular and there exists an automaton with {1} states.".format(lang, n))

# 2. Bob chooses word w
w = input("Choose a word in the language of length >= {0}: ".format(n))
if not L(w):
	sys.exit("Your word is not in the language. You lose.")
elif not length(w, n):
	sys.exit("Your word is too short. You loose.")

# 3. Alice chooses decomposition xyz
k, l = decompose(n, w)
x = w[:k]
y = w[k:l]
z = w[l:]
print("Alice chooses the decomposition x = {0}, y = {1}, z = {2}.".format(x, y, z))

# 4. Bob chooses pumping number i
i = int(input("Choose a natural number i sucht that w' = xy^iz is not in the language: "))
wp = x + y*i + z
if not L(wp):
	print("w' = xy^{0}z is not in the language. You win.".format(i))
else:
	sys.exit("w' = xy^{0}z is in the language. You lose.".format(i))
