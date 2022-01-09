/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

/* BinarySearchTree default constructor
 */
BinarySearchTree::BinarySearchTree()
{
        root = nullptr;
}

/* BinarySearchTree destructor (all Nodes are dynamically-allocated, need to 
 * delete with destructor)
 */
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}

/* post_order_delete method
 * Purpose: Delete every node in the BinarySearchTree
 * Parameters: Node pointer representing which node function currently on
 * Returns: void function - no return
 */
void BinarySearchTree::post_order_delete(Node *node)
{
        if (node == nullptr){
            return;
        }
        
        post_order_delete(node->right);
        post_order_delete(node->left);
        
        delete node;
        return;
}

/* BinarySearchTree copy constructor
 * Purpose: BinarySearchTree constructor, copies another BST
 * Parameters: BinarySearchTree to copy
 * Returns: Return nothing, instead creates a new BinarySearchTree
 */
// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

/* BinarySearchTree assignment operator overload
 * Purpose: BinarySearchTree assignment, overload the "=" operator
 * Parameters: BinarySearchTree to copy
 * Returns: Returns a new BinarySearchTree
 */
// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // If self-assignment, do nothing and return original node
        if (this == &source){
            return *this;
        }

        // Empty current BinarySearchTree
        post_order_delete(root);
        // Copy the BinarySearchtree to store adress to this->root
        this->root = pre_order_copy(source.root);

        return *this;
}

/* pre_order_copy method
 * Purpose: BinarySearchTree assignment, overload the "=" operator
 * Parameters: Node pointer for current node function is on
 * Returns: Returns a node pointer representing the start of the 
 * new BinarySearchTree that is the result of the copy
 */
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        Node* new_node;
        if (node != nullptr){
            new_node = new Node;
            new_node->data = node->data;
            new_node->count = node->count;
            new_node->left = pre_order_copy(node->left);
            new_node->right = pre_order_copy(node->right);
        } else {
            return nullptr;
        }
        return new_node;
}

/* find_min method (public)
 * Purpose: Call private recursive find_min method
 * Parameters: None
 * Returns: Returns an integer representing the smallest value in the 
 * BinarySearchTree
 */
int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}

/* find_min recursive method
 * Purpose: Recursively find the minimum value in the BinarySearchTree
 * Parameters: Node pointer representing the current node function is on
 * Returns: Node pointer with the minimum value
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
    if (node->left == nullptr){
        return node;
    } else {
        return find_min(node->left);
    }
}

/* find_max method (public)
 * Purpose: Call private recursive find_max method
 * Parameters: None
 * Returns: Returns an integer representing the largest value in the 
 * BinarySearchTree
 */
int BinarySearchTree::find_max() const
{
        if (root == nullptr){
            return numeric_limits<int>::min(); // INT_MIN
        } else {
            return find_max(root)->data;
        }
}

/* find_max recursive method
 * Purpose: Recursively find the maximum value in the BinarySearchTree
 * Parameters: Node pointer representing the current node function is on
 * Returns: Node pointer with the maximum value
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
    if (node->right == nullptr){
        return node;
    } else {
        return find_max(node->right);
    }
}

/* contains (public)
 * Purpose: call the private recursive contains method
 * Parameters: Integer representing value for Node to search for
 * Returns: boolean value representing whether that value is in the 
 * binarySearchTree 
 */
bool BinarySearchTree::contains(int value) const
{
    return contains(root, value);
}

/* contains
 * Purpose: recursively search for value in BinarySearchTree
 * Parameters: Integer representing value for Node to search for and a node 
 * pointer representing the current node the function is looking at.
 * Returns: boolean value representing whether that value is in the 
 * binarySearchTree 
 */
bool BinarySearchTree::contains(Node *node, int value) const
{
        if (node == nullptr){
            return false;
        } else if (node->data == value){
            return true;
        } else if (node->data > value){
            return contains(node->left, value);
        }else if (node->data < value){
            return contains(node->right, value);
        }
        
        return false;
}

/* insert (public)
 * Purpose: call the private recursive insert method
 * Parameters: Integer representing value for Node to insert
 * Returns: void function - no return
 */
void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}

/* insert
 * Purpose: recursively inserts a Node into the BinarySearchTree
 * Parameters: Two node pointers, one representing the current node and the 
 * other the parent node. Also integer parameter for the value of Node being
 * inserted.
 * Returns: void function - no return
 */
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        // If there isn't a node with the value trying to be added, create 
        // that Node
        if (node == nullptr){
            Node* new_node = new Node;
            new_node->right = nullptr;
            new_node->left = nullptr;
            new_node->data = value;
            new_node->count = 1;
            
            // Update the parent node pointer to new Node
            if (parent == nullptr){
                root = new_node;
            } else {
                if (parent->data < value){
                    parent->right = new_node;
                } else {
                    parent->left = new_node;
                }
            }
            return;
        }
        // Check if there is already a node with the value trying to be
        // inserted (increments count)
        else if (node->data == value){
            node->count++;
            return;
        }
        
        // Recursively call insert function on next Node in tree
        else if (node->data > value){
            insert(node->left, node, value);
            return;
        }
        else if (node->data < value){
            insert(node->right, node, value);
            return;
        } else {
            return;
        }
}

/* remove (public method)
 * Purpose: calls recursive remove method (private) with value passed as 
 * parameter.
 * Parameters: Value to look for 
 * Returns: Boolean representing whether value was in tree or not
 */
bool BinarySearchTree::remove(int value)
{
        return remove(root, nullptr, value);
}


/* remove (private method)
 * Purpose: recursive remove method (private) to remove (or decrement count) 
 * Node in BinarySearchTree, return true if value in tree, false otherwise.
 * Parameters: Value to look for, also two Node pointers representing current 
 * Node and the parent Node.
 * Returns: Boolean representing whether value was in tree or not
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
    // If there isn't a node with the value trying to be added, create 
    // that Node
    if (node == nullptr){
        return false;
    }
    // Check if there is already a node with the value trying to be
    // inserted (increments count)
    if (node->data == value){
        if (node->count > 1){
            node->count--;
            return true;
        } else {
            if (node->right == nullptr and node->left == nullptr){
                if (parent != nullptr) {
                    remove_leaf(node, parent);
                } 
                else { 
                    delete node;
                }
            } else if (node->left == nullptr) {
                if (parent != nullptr) {
                    remove_right_child(node, parent);
                } else {
                    root = node->right;
                    delete node;
                }
            } else if (node->right == nullptr) {
                if (parent != nullptr) {
                    remove_left_child(node, parent);
                } else {
                    root = node->left;
                    delete node;
                }
            } else {
                remove_both_child(node, parent);
            }
            return true;
        }
    // Call remove function recursively on next Node
    } else if (node->data > value){
        return remove(node->left, node, value);
    } else if (node->data < value){
        return remove(node->right, node, value);
    }
    // Should never get to this point, but return false just in case
    return false;
}

/* tree_Height (public)
 * Purpose: Call the private recursive height finding method
 * Parameters: None
 * Returns: integer representing the BinarySearchTree height
 */
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

/* tree_Height
 * Purpose: Recursively finds the "height" of the BinarySearchTree 
 * (private function)
 * Parameters: None
 * Returns: integer representing the BinarySearchTree height
 */
int BinarySearchTree::tree_height(Node *node) const
{
        // Base Case
        if (node == nullptr){
            return -1;
        } else {
        // Recursively find subtree heights
            int l_height = tree_height(node->left);
            int r_height = tree_height(node->right);
            if (l_height > r_height) {
                return l_height + 1;
            } else {
                return r_height + 1;
            }
        }
        
}

/* node_count (public)
 * Purpose: call the private recursive node_count method
 * Parameters: None
 * Returns: integer representing the current number of nodes hit.
 */
// returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

/* node_count
 * Purpose: recursively count the number of nodes in the binarySearchTree, 
 * not including duplicates
 * Parameter: Node pointer to the current node function is running on
 * Returns: integer representing the current number of nodes hit.
 */
int BinarySearchTree::node_count(Node *node) const
{
        if (node == nullptr){
            return 0;
        } else {
            return 1 + node_count(node->left) + node_count(node->right);
        }
}

/* count_total (public)
 * Purpose: call the private recursive count_total method
 * Parameters: None
 * Returns: integer representing the current number of nodes hit.
 */
// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

/* count_total
 * Purpose: recursively count the total number of nodes in a binarySearchTree, 
 * including duplicates
 * Parameter: Node pointer to the current node function is running on
 * Returns: integer representing the current number of nodes hit.
 */
int BinarySearchTree::count_total(Node *node) const
{
    if (node != nullptr){
        return count_total(node->left) + count_total(node->right) +\
 (node->data * node->count);
    } else {
        return 0;
    }
}

/* find_parent
 * Purpose: take two nodes and find the parent node
 * Parameter: Two nodes, one representing the "child" and the other changes
 * until it finds the parent.
 * Returns: A Node pointer representing the "parent" node
 */
BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

/* print_tree
 * Purpose: call the recursive function print the BinarySearchTree
 * Parameter: None
 * Returns: Void function - none
 */
// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

/* print_tree
 * Purpose: recursive function to print the BinarySearchTree
 * Parameter: Node pointer and three characters representing printing info
 * Returns: Void function - none
 */
// use the printPretty helper to make the tree look nice
// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}




/* remove_leaf (helper function for recursive remove method)
 * Purpose: function to remove leaf Node in BinarySearchTree class, private 
 * and called by remove() method (helpter function).
 * Parameter: Two Node pointers, one to keep track of the parent Node and the
 * current node trying to remove()
 * Returns: Void function - none
 */
void BinarySearchTree::remove_leaf(Node* node, Node* parent){
    if (parent->left->data == node->data) {
        parent->left = nullptr;
    } else {
        parent->right = nullptr;
    }
    delete node;
    return;
}

/* remove_right_child (helper function for recursive remove method)
 * Purpose: function to remove Node with one right child in BinarySearchTree 
 * class, private and called by remove() method (helpter function).
 * Parameter: Two Node pointers, one to keep track of the parent Node and the
 * current node trying to remove()
 * Returns: Void function - none
 */
void BinarySearchTree::remove_right_child(Node* node, Node* parent){
    if (parent->left->data == node->data) {
        parent->left = node->right;
    } else {
        parent->right = node->right;
    }
    delete node;
    return;
}

/* remove_left_child (helper function for recursive remove method)
 * Purpose: function to remove Node with one left child in BinarySearchTree 
 * class, private and called by remove() method (helpter function).
 * Parameter: Two Node pointers, one to keep track of the parent Node and the
 * current node trying to remove()
 * Returns: Void function - none
 */
void BinarySearchTree::remove_left_child(Node* node, Node* parent){
    if (parent->left->data == node->data) {
        parent->left = node->left;
    } else {
        parent->right = node->left;
    }
    delete node;
    return;
}

/* remove_both_child (helper function for recursive remove method)
 * Purpose: function to remove Node with two "child" Nodes in BinarySearchTree 
 * class, private and called by remove() method (helpter function).
 * Parameter: Two Node pointers, one to keep track of the parent Node and the
 * current node trying to remove()
 * Returns: Void function - none
 */
void BinarySearchTree::remove_both_child(Node* node, Node* parent){
    Node *replace = find_min(node->right);

    //change replace's parent's pointers
    Node *replace_parent = find_parent(root, replace);
    if (replace_parent->left != nullptr and replace_parent->left->data\
 == replace->data) {
            if (replace->left == nullptr){
                    replace_parent->left = nullptr;
            } else{
                    replace_parent->left = replace->left;
            }
            if(replace->right == nullptr){
                    replace_parent->left = nullptr; 
            } else{
                    replace_parent->left = replace->right;
            }
    }
    else if(replace_parent->right != nullptr and replace_parent->right->data\
 == replace->data){
            if (replace->right == nullptr) {
                    replace_parent->right = nullptr;
            } else {
                    replace_parent->right = replace->right;
            }
            if (replace->left == nullptr) {
                    replace_parent->right = nullptr;
            } else {
                    replace_parent->right = replace->left; 
            }
    }
    //deleted node's parent needs to now point to replace
    if (parent !=  nullptr) {
            if (parent->left->data == node->data) {
                    parent->left = replace;
            }
            else if (parent->right->data == node->data) {
                    parent->right = replace;
            }
    } else {
            root = replace; 
    }
    //replace to now point to was node was pointing to
    replace->right = node->right; 
    replace->left = node->left;
    delete node; 
}


