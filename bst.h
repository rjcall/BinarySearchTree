#pragma once
#include<iostream>
using namespace std;


struct node {
	node* left = nullptr;
	node* right = nullptr;
	int data;
	node(int n);
	bool is_leaf();

};


class bst {
public:

	bst();
	~bst();

	int size();

	void print();
	void pre();
	void in();
	void post();

	void insert(int num);
	void erase(int num);

	node*& find(int num);
	void clear();
private:
	// traversals

	void in(node* n);
	void pre(node* n);
	void post(node* n);
	void print(node* n, int depth);

	// other helper functions

	void insert(int n, node* parent);
	void remove(node*& n);
	bool erase(node*& n, int num);
	node*& find(node*& n, int num);
	int n_max(node* n);
	int size(node* bn);
	// root data member

	node* root;

};
