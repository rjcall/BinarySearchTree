#include"bst.h"

// Parameterized constructor for node

node::node(int n) {
	data = n;
	left = nullptr;
	right = nullptr;

}

// function returns true if node has no children and false if it does

bool node::is_leaf(){

	if ((left == nullptr) && (right == nullptr)) {
		return true;
	}
	else {
		return false;
	}
}



// erase deletes node if its data is the same as num

void bst::erase(int num) {

	// save address of node to be erased

	node* temp = find(num);

	// make sure temp isnt null

	if (temp != nullptr) {

		// try catch block so if the number doesnt exist the program wont break

		try {

			// call helper erase function

			erase(find(num), num);
		}
		catch (int e) {
			cout << "error:" << e << ". Number not in bst.\n";

		}
	}

	// if temp is null then the tree is empty

	else {
		cout<<"Error empty tree\n";
	}
}


// erase helper function

bool bst::erase(node*& n, int num) {

	// first case: if node has left and right children pass to n_max to return the largest nodes data from the left subtree

	if (n->left != nullptr && n->right != nullptr) {
		n->data = n_max(n);
	}


	// second case: if has left child set n to be its left, if has right child set n to be right

	else if (n->is_leaf() == false) {
		if (n->right == nullptr) {
			node* temp = n->left;
			delete n;
			n = nullptr;
			n = temp;
			return true;
		}
		if (n->left == nullptr) {
			node* temp = n->right;
			delete n;
			n = nullptr;
			n = temp;
			return true;
		}


	}

	// if n doesnt have any children just delete node

	else if (n->is_leaf()) {
		delete n;
		n = nullptr;
	}

	else {
		return false;
	}

}


// find the largest node in the left subtree

int bst::n_max(node* n){

	// temp is node to return to erase function

	node* temp;

	// if tree is empty cannot delete node

	if (n != nullptr) {

		// if there is no children n is largest
		if (n->is_leaf()) {
			temp = n;
		}
		else {

			// if furthest right then recursion is done
			if (n->right == nullptr) {
				temp = n;
			}

			// if more to the right call function with the next right child

			else {
				return n_max(n->right);
			}

		}

		// remove node because it is to be returned

		delete n;

		// set to null

		n = nullptr;

		// return the data of furthest right

		return temp->data;
	}
}


// default constructor


bst::bst() {

	// init root node
	root = nullptr;
}


// call post order remove function to delete all nodes in tree

bst::~bst() {
	remove(root);
}

// Test function for debugging

void bst::clear() {
	remove(root);
}

// post order remove function which deletes all nodes from the deepest child to the root

void bst::remove(node*& n) {

	// cannot delete nullptr

	if (n != nullptr) {

		// if left or right child call function with child

		if (n->left != nullptr) {
			remove(n->left);
		}

		if (n->right != nullptr) {
			remove(n->right);
		}

		// preform deletion after recursive call to ensure no leaks

		delete n;
		n = nullptr;
	}
}



// create new node and insert it into correct place in tree

void bst::insert(int n) {

	// if tree is empty create new node for root
	// if tree has children call helper function

	if (root != nullptr) {
		insert(n, root);
	}
	else {
		root = new node(n);
	}
}

// insert helper function
// insert node into correct place


void bst::insert(int n, node* bn) {

	// if number is less than parent and its left child isn't nullptr call function with left child

	if (n < bn->data) {
		if (bn->left != nullptr) {
			insert(n, bn->left);
		}
		else {
			bn->left = new node(n);
		}
	}

	// number is larger then parent insert right

	else if (n > bn->data) {
		if (bn->right != nullptr) {
			insert(n, bn->right);
		}
		else {
			bn->right = new node(n);
		}
	}
}

// size function returns the number of nodes in tree
int bst::size() {

	int tSize;

	// if parent has no children

	if (root == nullptr) {
		tSize = 0;
	}

	// if parent has children call helper

	else {
		tSize = size(root);
	}

	return tSize;
}

// size helper function

int bst::size(node* n) {

	// if node is not null return 1 + the num returned by size(left & right)

	if (n != nullptr) {
		return 1 + size(n->left)+size(n->right);
	}

	// if node is null there are no children

	else {
		return 0;
	}

}


// indented print

void bst::print() {

	// call print helper function

	print(root, 1);

}

// print helper function

void bst::print(node* n, int depth) {
	if (depth != 1) {

		// out lines for subtrees

		for (int i = 0; i < depth * depth; i++) {
			cout << "-";
		}
	}

	// if no child out empty

	if (n == nullptr) {
		cout << " [EMPTY]" << endl;
	}

	// if is leaf next to number out leaf

	else if (n->left == nullptr && n->right == nullptr) {
		cout << n->data;
		cout << " [leaf]" << endl;
	}

	// out the number and call print with subtrees with 1 + parents depth

	else {
		cout << n->data << endl;
		print(n->left, depth + 1);
		print(n->right, depth + 1);
	}
}

// find checks tree to see if num exists and returns its address if it does

node*& bst::find(int num) {
	return find(root, num);
}

// find helper function compares the number with the parent

node*& bst::find(node*& n, int num) {
	if (n != nullptr) {

		// if node is the number return that node

		if (n->data == num) {
			return n;
		}

		// if node is less then number check right

		else if (n->data < num) {
			find(n->right, num);
		}

		// if node is bigger then number check left

		else if (n->data > num) {
			find(n->left, num);
		}
	}
	// if node doesnt exist return n as nullptr
	else {
		return n;
	}

}

// preorder print traversal

void bst::pre() {
	if (root != nullptr) {
		pre(root);
	}
}


// pre helper function outputs the node and then calls with child

void bst::pre(node* n) {
	if (n != nullptr) {
		cout << n->data << " ";
		pre(n->left);
		pre(n->right);
	}
}


// post order print traversal

void bst::post() {
	if (root != nullptr) {
		post(root);
	}
}

// post helper function calls with children first then outs the nodes

void bst::post(node* n) {
	if (n != nullptr) {
		post(n->left);
		post(n->right);
		cout << n->data << " ";
	}
}

// in order print traversal

void bst::in() {
	if (root != nullptr) {
		in(root);
	}
}

// in helper function will call with the left child first then will out the node and last will call with the right child
void bst::in(node* n) {
	if (n != nullptr) {
		in(n->left);
		cout << n->data << " ";
		in(n->right);
	}
}
