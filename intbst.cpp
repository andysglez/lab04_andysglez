// intbst.cpp
// Implements class IntBST
// Andy Gonzalez, May 4, 2020

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if (n == NULL) {
        return;
    }
    else {
        printInOrder(n->left);
        cout << n->info << " ";
        printInOrder(n->right);
    }
    
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if (n == NULL) {
        return;
    }
    else {
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->info << " ";
    }
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    int total(0);
    if (n == NULL) {
        return total;
    }
    else {
        total += n->info + sum(n->right) + sum(n->left);
    }
    return total;
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    int c = 0;
    if (n == NULL) {
        return 0;
    }
    else {
        c++;
    }
    if (n->left != NULL) {
        c += count(n->left);
    }
    if (n->right != NULL) {
        c += count(n->right);
    }
    return c;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (n == NULL) {
        return NULL;
    }
    else if (value < n->info) {
        return getNodeFor(value, n->left);
    }
    else if (value > n->info) {
        return getNodeFor(value, n->right);
    }
    else if(value == n->info) {
        return n;
    }
    return NULL;
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if (getNodeFor(value, root) == NULL) {
        return false;
    }
    else {
        return true;
    }
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* valueNode = getNodeFor(value, root);
    if (valueNode->left == NULL) { //for nodes with no left substree
        if (valueNode->parent == NULL) { //check for root with no predecessor
            return NULL;
        }
        else {
            while(valueNode->parent!= NULL) {
                valueNode = valueNode->parent;
                if (valueNode->info < value) {
                    return valueNode;
                }
            }
            if (value < valueNode->info) { //checks if parent is not predecessor
                return NULL;
            }
            else { //predecessor found
                return valueNode;
            }
            
        }
    }    
    valueNode = valueNode->left; //for nodes with left subtree
    while (valueNode->right != NULL) {
        valueNode = valueNode->right;
    }
    return valueNode;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    if (getPredecessorNode(value)==NULL) {
        return 0;
    }
    else {
        return getPredecessorNode(value)->info;
    }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* SuccNode = getNodeFor(value, root);
    if (SuccNode->right == NULL) { //for nodes with no right substree
        if (SuccNode->parent == NULL) { //check for root with no predecessor
            return NULL;
        }
        while (SuccNode->parent != NULL) {
            SuccNode = SuccNode->parent;
            if (SuccNode->info > value) {
                return SuccNode;
            }
        }
        if (value > SuccNode->info) {
            return NULL;
        }
    }    
    SuccNode = SuccNode->right; //for nodes with right subtree
    while (SuccNode->left != NULL) {
        SuccNode = SuccNode->left;
    }
    if (SuccNode->info > value) { //last check
        return SuccNode;
    }
    return NULL;
}
// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    if (getSuccessorNode(value)==NULL) {
        return 0;
    }
    else {
        return getSuccessorNode(value)->info;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* Rnode = getNodeFor(value, root);
    if (!Rnode) return false;
    //Case 1
    if (!(Rnode->left) && !(Rnode->right)) {

        if (Rnode->parent) {
            if (Rnode == Rnode->parent->left) {
                Rnode->parent->left = nullptr;
            }
            else if (Rnode == Rnode->parent->right) {
                Rnode->parent->right = nullptr;
            }
        }
        delete Rnode; 
    }
    else if (!(Rnode->left) && Rnode->right) {
            Rnode->parent->right = Rnode->right;
            Rnode->right->parent = Rnode->parent;
            delete Rnode;
        }
    else if (!(Rnode->right) && Rnode->left) {
            Rnode->parent->left = Rnode->left;
            Rnode->left->parent = Rnode->parent;
            delete Rnode;
        }
    else {
        int SuccValue = getSuccessor(value); //retains Successor Value
        remove(SuccValue); //removes Succesor Node
        Rnode->info = SuccValue; //Updates Rnode value with Successor Value
    }
    
    if (!contains(value)) {
        return false;
    }
    else {
        return true;
    }
}
