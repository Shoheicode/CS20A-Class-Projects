#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<string>
#include<functional>
#include<iostream>
#include<assert.h>
#include<queue>
#include"bstnode.h"

template<typename Type>
class BinarySearchTree {

public:
	// Public Interface Functions: All of these are implemented
	BinarySearchTree();
	~BinarySearchTree();

	void	printInorder();
	void	printPostorder();
	void	printPreorder();
	void	insert(Type value);

	void	remove(Type value);

	Type	min() const;
	Type	max() const;
	int		height() const;
	bool	search(Type value) const;

	bool	empty() const;

	void	printTree() const;

	void	report() const;

private:

	// Member variable root
	Node<Type>* root;

	//Auxillary recursive bst functions
	//public interface functions call these
	//You will implement these functions.

	// Tree traversal, second parameter is a "function" with 
	// return type void and parameter Node*, i.e: 
	//					void process(Node* )
	void inorder(Node<Type>* node, std::function<void(Node<Type>*)> proc);
	void preorder(Node<Type>* node, std::function<void(Node<Type>*)> proc);
	void postorder(Node<Type>* node, std::function<void(Node<Type>*)> proc);

	Node<Type>* min(Node<Type> *node) const;
	Node<Type>* max(Node<Type> *node) const;
	int   height(Node<Type>* node) const;

	Node<Type>* insert(Node<Type> *node, Type value);
	bool  search(Node<Type> *node, Type value) const;

	Node<Type>* remove(Node<Type> *node, Type value);

	void  printTree(Node<Type> *node, int space) const;
};




//----------------------------------------------------------
//-------------- Binary Search Tree Function Implementations 
// 
//  Public Interface functions
// 		Completley Implemented, nothing to do.  These functions 
//      call the recursive helper functions you will implement
//		below.

// Constructor
template<typename Type>
BinarySearchTree<Type>::BinarySearchTree() :root(nullptr) {}

// Destructor
template<typename Type>
BinarySearchTree<Type>::~BinarySearchTree() {

	//Use the post order traversal to delete the nodes.
	//lambda function to delete a node n: 
	//				[](Node* n) {delete n; } 
	postorder(root, [](Node<Type>* n) {delete n; });
}
template<typename Type>
void BinarySearchTree<Type>::printInorder() {

	//Use inorder traversal to print items in a node in the tree.
	//lambda function to print the value in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->value() << std::endl; }"
	inorder(root, [](Node<Type>* n) {std::cout << n->value() << " "; });

	std::cout << std::endl;
}
template<typename Type>
void BinarySearchTree<Type>::printPreorder() {

	//Use pre order traversal to print items in a node in the tree.
	//lambda function to print the value in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->value() << std::endl; }"
	preorder(root, [](Node<Type>* n) {std::cout << n->value() << " "; });
	std::cout << std::endl;
}
template<typename Type>
void BinarySearchTree<Type>::printPostorder() {

	//Use post order traversal to print items in a node in the tree.
	//lambda function to print the value in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->value() << std::endl; }"
	postorder(root, [](Node<Type>* n) {std::cout << n->value() << " "; });
	std::cout << std::endl;
}
template<typename Type>
void BinarySearchTree<Type>::insert(Type value) {
	root = insert(root, value);
}
template<typename Type>
void BinarySearchTree<Type>::remove(Type value) {
	root = remove(root, value);
}
template<typename Type>
Type	BinarySearchTree<Type>::min() const {

	assert(root != nullptr);

	Node<Type>* node = min(root);
	return node->value();
}
template<typename Type>
Type	BinarySearchTree<Type>::max() const {

	assert(root != nullptr);

	Node<Type>* node = max(root);
	return node->value();
}
template<typename Type>
int	BinarySearchTree<Type>::height() const {

	return height(root);
}
template<typename Type>
bool BinarySearchTree<Type>::search(Type value) const {
	return search(root, value);
}
template<typename Type>
bool BinarySearchTree<Type>::empty() const {
	return (root == nullptr);
}
template<typename Type>
void BinarySearchTree<Type>::printTree() const {
	printTree(root, 0);
}

//----------------------------------------------------------
//
// Private Recursive Functions: You Implement These.
//

// Inorder Traversal: Implemented so you can see how passing a function into 
// another function works, other traversals remain for you to implement.  the second
// parameter, proc, is a function and we see that its return type is void and it 
// has a Node* as a parameter.  Any function of that form passed into inorder will be
// called as seen below.  
// If we assume that we use the printing lambda defined above you can imagine that proc 
// is defined as:
//		void proc(Node<Type> * n){std::cout << n->value << " "; }
template<typename Type>
void BinarySearchTree<Type>::inorder(Node<Type>* node, std::function<void(Node<Type>*)> proc) {
	if (node == nullptr)
		return;

	inorder(node->left(), proc);
	proc(node);
	inorder(node->right(), proc);

}

template<typename Type>
void BinarySearchTree<Type>::postorder(Node<Type>* node, std::function<void(Node<Type>*)> proc) {
	
	//********* TODO **********
	if (node == nullptr) {
		return;
	}
	postorder(node->left(), proc);
	postorder(node->right(), proc);
	proc(node);

}
template<typename Type>
void BinarySearchTree<Type>::preorder(Node<Type>* node, std::function<void(Node<Type>*)> proc) {

	//********* TODO **********
	if (node == nullptr) {
		return;
	}

	proc(node);
	preorder(node->left(), proc);
	preorder(node->right(), proc);

}

// BinarySearchTree::insert recursively inserts into the BST according 
// to the rules of the BST.  
template<typename Type>
Node<Type>* BinarySearchTree<Type>::insert(Node<Type>* node, Type value) {
	
	//********* TODO **********
	//std::cout << "AJLJFLKDJLJDFS" << std::endl;
	if (node == nullptr) {
		//std::cout << "I HAVE ADDED ROOT" << std::endl;
		return new Node<Type>(value, nullptr, nullptr);
	}
	else {
		if (node->value() == value) {
			return node;
		}
		if (node->value() > value) {
			if (node->left() == nullptr) {
				//std::cout << "Adding to left: " << value << std::endl;
				Node<Type>* a = new Node<Type>(value, nullptr, nullptr);
				node->left(a);
				return node;
			}
			else {
				insert(node->left(), value);
				return node;
			}
		}
		if (node->value() < value) {
			if (node->right() == nullptr) {
				//std::cout << "Add to right: " << value << std::endl;
				Node<Type>* a = new Node<Type>(value, nullptr, nullptr);
				node->right(a);
				return node;
			}
			else {
				insert(node->right(), value);
				return node;
			}
		}
	}

	return nullptr;

}

// BinarySearchTree<Type>::search recursively searches the tree for value.
template<typename Type>
bool BinarySearchTree<Type>::search(Node<Type>* node, Type value) const {
	if (node == nullptr) {
		return false;
	}
	//std::cout << "JLKAJDFLJSDLK" << std::endl;
	if (node->value() == value) {
		return true;
	}
	else {
		if (node->value() > value) {
			//std::cout << "left" << std::endl;
			return search(node->left(), value);
		}
		if (node->value() < value) {
			//std::cout << "right" << std::endl;
			return search(node->right(), value);
		}
	}

	//********* TODO **********
	return false;
}

// BinarySearchTree<Type>::height
// Height of a binary tree is the height of the largest subtree + 1
// An empty tree has height 0;
template<typename Type>
int	BinarySearchTree<Type>::height(Node<Type>* node) const {
	if (node == nullptr) {
		return 0;
	}

	int height = 0 ;
	std::queue<Node<Type>*> q;

	q.push(node);
	q.push(nullptr);

	while (!q.empty()) {
		std::cout << "Run baby run" << std::endl;
		Node<Type>* temp = q.front();
		if (temp != nullptr) {
			std::cout << "Value: " << temp->value() << std::endl;
		}
		q.pop();

		if (temp == nullptr) {
			std::cout << "HEIGHT IS INCREASING" << std::endl;
			height++;
		}

		if (temp != nullptr) {
			std::cout << "RANN RUNNING" << std::endl;
			if (temp->left() != nullptr ) {
				std::cout << "To the left" << std::endl;
				q.push(temp->left());
			}
			if (temp->right() != nullptr) {
				std::cout << "To the right" << std::endl;
				q.push(temp->right());
			}
		}

		else if (!q.empty()) {
			std::cout << "AM NULL" << std::endl;
			q.push(nullptr);
		}
	}


	//********* TODO **********
	return height;
}
// BinarySearchTree<Type>::min recursively obtain the node with the minimum value
template<typename Type>
Node<Type>* BinarySearchTree<Type>::min(Node<Type>* node) const {

	//********* TODO **********
	if (node == nullptr) {
		return nullptr;
	}
	
	if (node->left() != nullptr) {
		return min(node->left());
	}
	else {
		return node;
	}
	return nullptr;
}

// BinarySearchTree<Type>::max recursively obtain the node with the minimum value
template<typename Type>
Node<Type>* BinarySearchTree<Type>::max(Node<Type>* node) const {

	//********* TODO **********
	if (node == nullptr) {
		return nullptr;
	}

	if (node->right() != nullptr) {
		return min(node->right());
	}
	else {
		return node;
	}
	return nullptr;
}

// BinarySearchTree<Type>::printTree
// Prints the BST in a tree format rotated -90 degrees.  Uses space to 
// signify the space between levels of the tree. Uses the inorder 
// traversal but traverses right first, rather than left. Cannot use
// any of the other travel functions because of this.
//
// parameter space determines the number of spaces needed for each level.
// Example binary shows 5 spaces between levels. 
//
// i.e. traverse right 
//		print appropriate number of spaces 
//		print value 
//		traverse left
template<typename Type>
void BinarySearchTree<Type>::printTree(Node<Type>* node, int space) const {

	//********* TODO **********

	if (node == nullptr) {
		return;
	}

	space += 10;

	printTree(node->right(), space);

	std::cout << std::endl;
	for (int i = 10; i < space; i++) {
		std::cout << " ";
	}
	std::cout << node->value() << std::endl;

	printTree(node->left(), space);


}


//BinarySearchTree<Type>::remove
//
// Make sure you're comfortable with the iterative solution seen in the lecture slides
// before thinking about how to do it recursively.
//
// Recursively removes a node in the binary tree.  The recursive algorithm will 
// be different than the iterative algorithm.  The iterative algorithm conisted
// of first finding the node using two pointers so that we know how to rearrange
// the children of the deleted node. In recursion we are passing in the sub trees
// each recursive step, so by definition we already have a handle on each subtrees'
// parents (it is the node that is passed into the previous recursive step).
// After we search the node to remove (if it is in the tree) everything else is the same, we  
// handle the three cases: leaf, one child (which consist of two cases: left vs right),
// and two children.  With iterative algorithm there were subcases regardling if the 
// node was root or not, with recursion we get that for free.  
//
// In the iterative algorithm discussed in class, in dealing with a node with two children
// We swapped items from one of the nodes in either subtree.  For the recursive algorithm
// We just want to write the subtree node's value into the node to be deleted, not actually 
// swap. This way subtree remains a valid bst, so we can recurse on that subtree and 
// recursively call _deleteNode on that value (not the original) to remove that node.  
// 
// It takes a bit to wrap your head around this, use the 6 steps, draw lots of pictures.
// 
template<typename Type>
Node<Type>* BinarySearchTree<Type>::remove(Node<Type>* node, Type value) {

	//********* TODO **********
	if (node == nullptr) {
		return nullptr;
	}
	else {
		//std::cout << "I AM removing run" << std::endl;
		if (node != nullptr) {
			std::cout << node->value() << std::endl;
		}
		Node<Type>* nodeL = node->left();
		Node<Type>* nodeR = node->right();

		if (nodeL) {
			std::cout << "LEFT VALUE: " << nodeL->value() << std::endl;
			if (nodeL->value() == value) {
				std::cout << "I AM RUNNING Remove" << std::endl;
				if (nodeL->left() != nullptr) {
					std::cout << "I AM RUNNING Remove left" << std::endl;
					Node<Type>* temp = nodeL;
					Node<Type>* leftNode = nodeL->left();
					
					if (nodeL->right() == nullptr) {
						delete temp;
						node->left(leftNode);
						return node;
					}
					nodeL = nodeL->right();
					delete temp;
					
					Node<Type>* temp2 = nodeL;
					while (temp2->left() != nullptr) {
						temp2 = temp->left();
					}
					temp2->left(leftNode);
					node->left(nodeL);
					return node;
				}
				else if (nodeL->right() != nullptr) {
					std::cout << "I AM RUNNING Removing Right" << std::endl;
					Node<Type>* tem = nodeL;
					nodeL = nodeL->right();
					delete tem;
					node->left(nodeL);
					return node;
				}
			}
		}
		if (nodeR) {
			std::cout <<"Right: " << nodeR->value() << std::endl;
			if (nodeR->value() == value) {
				std::cout << "I AM RUNNING Remove" << std::endl;
				if (nodeR->left() != nullptr) {
					std::cout << "I AM RUNNING Remove left" << std::endl;
					Node<Type>* temp = nodeR;
					Node<Type>* leftNode = nodeR->left();

					if (nodeR->right() == nullptr) {
						delete temp;
						node->right(leftNode);
						return node;
					}
					nodeR = nodeR->right();
					delete temp;

					Node<Type>* temp2 = nodeR;
					while (temp2->left() != nullptr) {
						temp2 = temp->left();
					}
					temp2->left(leftNode);
					node->right(nodeR);
					return node;
				}
				else if (nodeR->right() != nullptr) {
					std::cout << "I AM RUNNING Removing Right" << std::endl;
					Node<Type>* tem = nodeR;
					nodeR = nodeR->right();
					delete tem;
					node->right(nodeR);
					return node;
				}
			}
		}
		
		if (node->value() > value) {
			remove(node->left(), value);
			return node;
		}
		else if (node->value() < value) {
			remove(node->right(), value);
			return node;
		}
		else {
			return nullptr;
		}
	}

	return nullptr;
}

// BinarySearchTree<Type>::report
template<typename Type>
void BinarySearchTree<Type>::report() const {

	//********* TODO **********
	std::string msg = "Analysis";
	std::cout << msg << std::endl;
}


































































// MMX


























































#endif//BINARYSEARCHTREE_H_MMX