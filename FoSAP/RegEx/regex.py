# parser for context-free grammar:
# S -> a | eps | empty | (S+S) | (S.S) | S*
def parse(text):
	i = [0]
	def build_tree():
		while i[0] < len(text):
			o = text[i[0]]
			if o in ['a', 'b']:
				return ['S', [o]]
			
			elif o in ['(']:
				i[0] += 1
				tree = build_tree()
				return ['(', [o, tree]]

			elif o in [')']:
				i[0] += 1
				tree = build_tree()
				return [
			
			elif o in ['+'] 
				i[0] += 1
				tree1 = build_tree()
				i[0] += 1
				tree2 = build_tree()
				return ['S', [o, tree1, tree2]]
	
	tree = build_tree()
	if i[0] == len(text)-1:
		return tree


def to_string(tree):
	if len(tree[1]) == 3:
		return '(' + tree[0] + ', (' + tree[1][0] + ', ' + to_string(tree[1][1]) + ', ' +  to_string(tree[1][2]) + '))'
	elif len(tree[1]) == 2:
		return '(' + tree[0] + ', (' + tree[1][0] + ', ' + to_string(tree[1][1]) + '))'
	elif len(tree[1]) == 1:
		return '(' + tree[0] + ', (' + tree[1][0] + '))'
