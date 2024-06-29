#pragma once
#include <iostream>
template <class T>
class tree {
	T value;
	T children[];
public:
	tree() : value(0), children[0](0);
	tree(T v, int fii) : value(v), children[fii]{
	for (int i = 0; i < fii; i++)
		children[i] = 0;
	}
	~tree() : delete children, delete value;
	T add_node(tree parent, T val) {
		if (parent == nullptr)
		{
			a = new tree(0, 0);
			return a;
		}
		else
		{
			int i = 0;
			while (parent->children[i] != 0)
			{
				i++;
			}
			parent->children[i] = new tree(val, 0);
		}
		return children[i];
	}
	T get_node(tree* parent) {
		if (*parent == nullptr)
			
		else
			return parent;
	}
	T delete_node(tree node) {
		delete node;
	}
	T find() {

	}
};