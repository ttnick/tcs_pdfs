#! /usr/bin/env python
import ete3

# parser for context-free grammar:
# S -> +SS | *SS | -S | 0 | 1 | x | y | z
def parse(text):
	i = [0]
	def build_tree():
		while i[0] < len(text):
			o = text[i[0]]
			if o in ['0', '1', 'x', 'y', 'z']:
				return ['S', [o]]
			
			elif o in ['-']:
				i[0] += 1
				tree = build_tree()
				return ['S', [o, tree]]
			
			elif o in ['+', '*']:
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


def to_ete(tree):
	if len(tree[1]) == 3:
		return '(' + tree[1][0] + ', ' + to_ete(tree[1][1]) + ', ' +  to_ete(tree[1][2]) + ')'
	elif len(tree[1]) == 2:
		return '(' + tree[1][0] + ', ' + to_ete(tree[1][1]) + ')'
	elif len(tree[1]) == 1:
		return '(' + tree[1][0] + ')'


def visualize(tree):
	tree = to_ete(tree) + ';'
	t = Tree(tree)
	print t
	
	ts = TreeStyle()
	ts.rotation = 270
	ts.orientation = 1
	ts.show_scale = False

	ns = NodeStyle()
	ns['hz_line_width'] = 1
	ns['vt_line_width'] = 1
	ns['size'] = 5
	for st in t.traverse():
		st.set_style(ns)

	t.render("tree.png", w=183, units="mm", tree_style=ts)
