#pragma once
#include <iostream>
#include <cstdlib>

struct Node
{
	int value = 0;
	Node * left = nullptr;
	Node * right = nullptr;
};

void print_pre_order_tree(Node * n)
{
	if (n != nullptr)
	{
		print_pre_order_tree(n->left);
		print_pre_order_tree(n->right);
		std::cout << n->value << " - ";	
	}
}

void print_in_order_tree(Node * n)
{
	if (n != nullptr)
	{
		print_in_order_tree(n->left);
		std::cout << n->value << " - ";
		print_in_order_tree(n->right);
	}
}

void print_post_order_tree(Node * n)
{
	if (n != nullptr)
	{
		print_post_order_tree(n->right);
		print_post_order_tree(n->left);
		std::cout << n->value << " - ";
	}
}