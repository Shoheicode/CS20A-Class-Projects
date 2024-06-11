#ifndef BST_NODE_DEF
#define BST_NODE_DEF

// Node implementation: Implemented
template<typename Type>
class Node {
public:
	Node(Type v, Node* l, Node* r) :val(v), l(l), r(r) {}
	Node() :Node(0, nullptr, nullptr) {}

	Node* left() { return l; }
	Node* right() { return r; }

	void left(Node * lft) { l = lft; }
	void right(Node * rht){r = rht;}

	Type value() { return val; }
	void value(Type v) { val = v; }

private:
	Type val;
	Node *l, *r;
};


#endif