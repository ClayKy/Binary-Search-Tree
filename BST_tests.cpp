/* 
 * BST_tests.cpp
 * 
 * COMP 15 homework 3
 * by Clay Kynor, March 2021
 * 
 * Uses the multiple functions to test the functionality of the 
 * BinarySearchTree class created by Clay Kynor in BinarySearchTree.h. 
 * Each function explicitly tests one method of the class, however multiple 
 * methods may be called in each function (i.e. print_tree function is called
 * multiple times ).
 */
 
#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

// Function Declarations
void BST_default_constructor();
void BST_insert();
void BST_assignment_operator_overload();
void BST_count_nodes();
void BST_tree_height();
void BST_min_and_max();
void BST_contains_test();
void BST_copy_constructor_tests();
void BST_remove_tests();

void make_template_tree(BinarySearchTree& tree);

// Main function to call all method test functions
int main(){
    cout << endl;
    BST_default_constructor();
    BST_insert();
    BST_assignment_operator_overload();
    BST_count_nodes();
    BST_tree_height();
    BST_min_and_max();
    BST_contains_test();
    BST_copy_constructor_tests();
    BST_remove_tests();

    return 0;
}


 
 /* Binary Search  default constructor test
  * Run the BST default constructor to make sure there are no runtime
  * errors or memory leaks. Default constructor should simply initialize 
  * class' members to default values.
  */
void BST_default_constructor(){
    //Initialize a BinarySearchTree
    BinarySearchTree BST_1;
    cout << "BST default constructor test passed!" << endl << endl;
    // Printing an empty tree shouldn't output anything, but good to check that
    // BST isn't initialized while containing nodes (because it should be 
    // empty)
    BST_1.print_tree();
    return;
}

/* Binary Search insert method test
 * Run the BST insert method to add Nodes to multiple different-typed 
 * BinarySearchTrees and used print and assert to make sure the 
 * BinarySearchTrees are created correctly.
 */
void BST_insert(){
   //Initialize a BinarySearchTree
   BinarySearchTree BST_2;
   
   cout << "Insert method test #1: Following should print tree with ";
   cout << "single Node containing integer 3" << endl;
   // Use insert method to add a Node containing integer 3 to BST
   BST_2.insert(3);
   // Print the BinarySearchTree to make sure the node was correctly added.
   BST_2.print_tree();
   cout << endl;
   
   // Insert the another Node with the same value, should keep track that there
   // are two instances of integer 3 (because BST is supposed to be multiset)
   cout << "Insert method test #2: Following should print tree with ";
   cout << "two instances of the Node containing integer 3." << endl;
   BST_2.insert(3);
   BST_2.print_tree();
   cout << endl;
   
   // Insert method test with multiple Nodes containing different information
   // uses print_tree method to make sure tree is correctly created
   BinarySearchTree BST_3;
   BST_3.insert(1);
   BST_3.insert(0);
   BST_3.insert(2);
   cout << "Insert method test #4: Should print BST with Nodes containing ";
   cout << "0,1 and 2" << endl;
   BST_3.print_tree();
   
   
   BinarySearchTree BST_4;
   for (int i = 0; i < 10; i++){
       BST_4.insert(i);
       BST_4.insert(i+i%10);
   }
   BST_4.print_tree();
   cout << endl;
   return;
}

/* Binary Search assignment operator overload test
 * Run the BST insert method to add Nodes to multiple different-typed 
 * BinarySearchTrees and used print and assert to make sure the 
 * BinarySearchTrees are created correctly.
 */
void BST_assignment_operator_overload(){
   //Initialize a BinarySearchTree
   BinarySearchTree binary_tree1;
      

   /* Section 1: Testing self-assignment
    * Create BST and self-assign using "=" operator, make sure BST doesn't
    * change
    */
   cout << "Assignment Operator Overload test #1: Testing self-assignment";
   cout << "original and new tree should be the same" << endl;
   binary_tree1.insert(2);
   binary_tree1.insert(1);
   binary_tree1.insert(1);
   binary_tree1.insert(8);
   cout << "Original tree: " << endl;
   binary_tree1.print_tree();
   cout << endl;
   binary_tree1 = binary_tree1;
   cout << "New tree (should be the same as original): " << endl;
   binary_tree1.print_tree();
   cout << endl;
   
   /* Section 1: Testing assignment operator working properly
    * Create BST and copy to another using "=" operator, make sure when 
    * altering one BinarySearchTree, the other isn't changed as well
    */
   
   BinarySearchTree bst_1;
   bst_1.insert(0);
   bst_1.insert(1);
   bst_1.insert(-1);
   cout << "Original tree: " << endl;
   bst_1.print_tree();
   cout << endl;
   // Use "=" operator to copy contents of bst_1 to bst_2
   BinarySearchTree bst_2 = bst_1;
   cout << "New tree (should be the same as original): " << endl;
   bst_2.print_tree();
   cout << endl;
   
   // Test making sure the copy is not linked to the original node in any way
   cout << "Changing copy, should affect copy and not original" << endl;
   bst_2.insert(3);
   cout << "Original tree (shouldn't change): " << endl;
   bst_1.print_tree();
   cout << endl;
   cout << "Original tree (should have additional '3' node): " << endl;
   bst_2.print_tree();
   cout << endl;
   
   /*
   
   
   NOT FINISHED!
   
   */
   return;
}


/* Count nodes method tests
 * Tests BOTH node_count and count_total methods. Make sure both return the 
 * correct amount of nodes (count_total taking into account repition whereas
 * node_count method doesn't)
 */
void BST_count_nodes(){
   //Initialize a BinarySearchTree
   BinarySearchTree tree1;
      
   cout << endl << "COUNT_NODE TESTS:" << endl << endl;
   
   /* Section 1: count methods testing
    * Create small BinarySearchTree with 0 and 1 element, assess if methods
    * return accurate counts
    */
   cout << "node_count on empty tree (0) - " << tree1.node_count() << endl;
   cout << "count_total on empty tree (0) - " << tree1.count_total() << endl;
   cout << endl;
   
   tree1.insert(234);
   cout << "node_count on tree w/ one node (1) - " << tree1.node_count()\
    << endl;
   cout << "count_total on tree w/ one node (1) - " << tree1.count_total()\
    << endl;
   cout << endl;
   
   tree1.insert(234);
   cout << "node_count on tree w/ one node repeated (1) - " << tree1.\
   node_count() << endl;
   cout << "count_total on tree w/ one node repeated (2) - " <<\
    tree1.count_total() << endl;
   cout << endl;
   
   /* Section 2: count methods testing
    * Create large BinarySearchTree with many duplicates, assess if methods
    * return accurate counts
    */
   BinarySearchTree tree2;
   
   for (int i = 0; i < 100; i++){
       tree2.insert(i);
       if (i%3 == 0){
           tree2.insert(i-(i/3));
           tree2.insert(i);
       }
   }

   cout << "node_count on complicated tree (100) - " << tree2.\
   node_count() << endl;
   cout << "count_total on complicated tree (168) - " << tree2.count_total()\
    << endl << endl;
   return;
}




/* tree height method tests
 * Tests tree_height. Make sure both return the correct tree height on 
 * multiple different BinarySearchTrees
 */
void BST_tree_height(){
   //Initialize a BinarySearchTree
   BinarySearchTree tree3;
      
   cout << endl << "TREE_HEIGHT TESTS:" << endl << endl;
   
   /* Section 1: tree height
    * Create small BinarySearchTree with 0 and 1 element, assess if methods
    * return accurate counts
    */
   cout << "tree_height on empty tree (0) - " << tree3.tree_height() << endl;
   
   tree3.insert(0);
   cout << "tree_height on tree w/ one node (1) - " << tree3.tree_height()\
    << endl;
   
   // Add another instance of the same value, tree height shouldn't change
   tree3.insert(0);
   cout << "tree_height on tree w/ one node repeated (1) - " << tree3.\
   tree_height() << endl;
   cout << endl;

   /* Section 2: tree height
    * Create large BinarySearchTree with multiple elements, assess if 
    * tree_height method returns accurate counts
    */
    BinarySearchTree tree4;
    
    for (int i = 0; i < 100; i++){
        tree4.insert(i);
    }
    cout << "tree_height on tree w/ one-hundred nodes, ascending (100) - " <<\
     tree4.tree_height() << endl;
     return;
}


/* find_min and find_max method test
 * Tests BOTH find_min() and find_max() methods. Make sure both return the 
 * correct value for multiple different BinarySearchTrees
 */
void BST_min_and_max(){
   //Initialize a BinarySearchTree
   BinarySearchTree tree5;
      
   cout << endl << "MIN_AND_MAX TESTS:" << endl << endl;
   
   /* Section 1: find_min and find_max methods
    * Create small BinarySearchTree with 0 and 1 elements, assess if methods
    * return accurate counts
    */
   cout << "find_min on empty tree (smallest integer) - " <<\
     tree5.find_min() << endl;
   cout << "find_max on empty tree (largest integer) - " <<\
     tree5.find_max() << endl << endl;
   
   tree5.insert(4);
   cout << "find_min on tree with one Node (4) - " <<\
     tree5.find_min() << endl;
   cout << "find_max on tree with one Node (4) - " <<\
     tree5.find_max() << endl;
   
   tree5.insert(4);
   tree5.insert(4);
   cout << "find_min on tree with one Node w/ duplicates (4) - " <<\
     tree5.find_min() << endl;
   cout << "find_max on tree with one Node w/ duplicates (4) - " <<\
     tree5.find_max() << endl;
   
     
   /* Section 2: find_min and find_max methods
    * Create larger BinarySearchTree, assess if methods return accurate counts
    */
   
   BinarySearchTree tree6;
   for (int i = 0; i < 100; i++){
       tree6.insert(i);
   }
   cout << "find_min on tree with multiple Nodes (0) - " <<\
     tree6.find_min() << endl;
   cout << "find_max on tree with multiple Nodes (99) - " <<\
     tree6.find_max() << endl << endl;
   return;
}



/* contains method test
 * Tests contain() method. Make sure both return the correct boolean value 
 * for multiple different BinarySearchTrees
 */
void BST_contains_test(){
    BinarySearchTree tree7;
    cout << endl << "CONTAINS TESTS" << endl << endl;
    
    /* Section 1: contains methods
     * Create small BinarySearchTree with 0 and 1 elements, assess if contain
     * method returns accurate counts
     */
     
     cout << "contain method on empty tree (0) - " << tree7.contains(4) << endl;
     
     tree7.insert(4);
     cout << "contain method on tree w/ one node, number IN tree (1) - " <<\
      tree7.contains(4) << endl;
     cout << "contain method on tree w/ one node, number OUT of tree (0) - "\
      << tree7.contains(1) << endl << endl;
     
    
    /* Section 2: contains methods
     * Create large BinarySearchTree with duplicate elements, make sure 
     * contains() method returns the correct boolean value
     */
    
    BinarySearchTree tree8;
    for (int i = 10; i > 0; i--){
        tree8.insert(i+2);
        tree8.insert(i-1);
        tree8.insert(i);
    }
    
    cout << "contain method on complicated tree, number IN tree (not dupli\
cated) (1) - " << tree8.contains(11) << endl;
    cout << "contain method on complicated tree, number IN tree (dupli\
cated) (1) - " << tree8.contains(3) << endl;
    cout << "contain method on complicated tree, number OUT of tree (0) - "\
     << tree8.contains(-3242) << endl << endl;
    return;
}


/* BinarySearchTree class copy constructor tests
 * Tests copy constructor for the BinarySearchTree. Then uses print_tree and 
 * other public methods of the class to make sure copy constructor is working 
 * correctly.
 */
void BST_copy_constructor_tests(){
    BinarySearchTree tree9;
    
    /* Section 1: copy constructor tests
     * Create empty and small BinarySearchTrees and use copy constructor to 
     * create new copy instance of the class
     */
    
    BinarySearchTree tree10(tree9);
    cout << "copy constructor on empty tree - Original Tree (node count 0) - "\
     << tree9.node_count() << endl;
    cout << "copy constructor on empty tree - Copy Version (node count 0) - "\
     << tree10.node_count() << endl;
    
    tree9.insert(0);
    BinarySearchTree tree11(tree9);
    cout << "copy constructor on one-element tree - Original Tree (node coun\
t 1) - " << tree9.node_count() << endl;
    cout << "copy constructor on one-element tree - Copy Version (node count 1\
) - " << tree11.node_count() << endl << endl;
    

    /* Section 2: copy constructor tests
     * Create larger BinarySearchTrees and use copy constructor to 
     * create new copy instances of the class.
     */
     
     BinarySearchTree tree12;
     for (int i = 0; i < 10; i++){
         for (int j = 0; j < i; j++){
             tree12.insert(j);
         }
     }
     
     BinarySearchTree tree13(tree12);
    cout << "copy constructor on multi-element tree - Original Tree (total n\
ode count 120) - " << tree12.count_total() << endl;
    cout << "copy constructor on multi-element tree - Copy Version (total n\
ode count 120) - " << tree13.count_total() << endl;

    // Next, testing that there are no links between the trees (changing one 
    // tree shouldn't affect the other).
    
    tree13.insert(89);
    tree13.insert(-892);
    for (int i = 1; i < 31; i++){
        tree12.insert(23%i);
    }
    cout << "copy constructor on multi-element tree - Original Tree (total n\
ode count 13) - " << tree12.node_count() << endl;
    cout << "copy constructor on multi-element tree - Copy Version (total n\
ode count 11) - " << tree13.node_count() << endl << endl;

    return;
}


/* BinarySearchTree class remove method tests
 * Tests remove method for the BinarySearchTree. Then uses print_tree and 
 * other public methods of the class to make sure the complexities of the 
 * BinarySearchTree remove method are correctly implemented.
 */
void BST_remove_tests(){
    BinarySearchTree tree_1;
    cout << endl << "REMOVE TESTS" << endl << endl;
    
    /* Section 1: remove method
     * Create small BinarySearchTree with 0 and 1 elements, assess if remove
     * method returns accurate boolean value and edits BinaryTree correctly
     */
    cout << "remove method empty tree (should return False) 0 - " << tre\
e_1.remove(0) << endl;
    tree_1.insert(3);
    tree_1.insert(3);
    tree_1.insert(2);
    cout << "remove method on duplicate (count_total before removal should re\
turn) 8 - " << tree_1.count_total() << endl;
    cout << "remove method on duplicate (should return True) 1 - " << tree_1\
.remove(3) << endl;
    cout << "remove method on duplicate (count_total after removal should r\
eturn) 5 - " << tree_1.count_total() << endl << endl;
    
    cout << "remove method on non-duplicate (count_total before removal s\
hould return) 5 - " << tree_1.count_total() << endl;
    cout << "remove method on non-duplicate (should return True) 1 - " << t\
ree_1.remove(3) << endl;
    cout << "remove method on non-duplicate (count_total after removal shou\
ld return) 2 - " << tree_1.count_total() << endl << endl << endl;
    
    
    /* Section 2: remove method
     * Create template 10 Node BinarySearchTree with multiple duplicates, 
     * calls remove method on both leaf and more complicated positions in that
     * tree. Then uses print_tree and other public methods to make sure 
     * that rotations and such work correctly with tree formation by 
     * printing tree both before and after removal.
     */
     
     BinarySearchTree tree_2;
     make_template_tree(tree_2);
     
     cout << " ------- Remove method complicated tests -------"<< endl << endl
     << "Original tree: " << endl;
     
     tree_2.print_tree();
     
     cout << endl << "Testing removal from node with two leafs (Node 85)" 
     << endl << endl << "New tree" << endl;
     tree_2.remove(85);
     tree_2.print_tree();
     
     cout << endl << "Testing removal from node with single left leaf (Node 4\
8)" << endl << endl << "New tree" << endl;
     tree_2.remove(48);
     tree_2.print_tree();
     
     cout << endl << "Testing removal from node with single right leaf (Node 9\
5)" << endl << endl << "New tree" << endl;
     tree_2.remove(95);
     tree_2.print_tree();
     
     cout << endl << "Testing removal from node with double right leafs (Node \
30)" << endl << endl << "New tree" << endl;
     tree_2.remove(30);
     tree_2.print_tree();
     
     
}

/* make_template_tree function
 * Purpose: To add multiple Nodes to a BinarySearchTree in order to demonstrate
 * remove method functionality.
 */
void make_template_tree(BinarySearchTree& tree){
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(10);
    tree.insert(80);
    tree.insert(48);
    tree.insert(45);
    tree.insert(15);
    tree.insert(85);
    tree.insert(95);
    tree.insert(82);
}
