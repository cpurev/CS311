// treesorter.h  SKELETON
// Glenn G. Chappell
// 2021-11-08
//
// For CS 311 Fall 2021
// Header for function template treesort
// There is no associated source file.
//
// Chuluunbat Purev
// 2021-11-10

#ifndef FILE_TREESORTER_H_INCLUDED
#define FILE_TREESORTER_H_INCLUDED

#include <iterator> // For std::iterator_traits
#include <memory>   // For std::unique_ptr & std::make_unique


// BSTreeNode
// Consists of left and right node & value.
template<typename Value>
struct BSTreeNode{
    std::unique_ptr<BSTreeNode> left;
    std::unique_ptr<BSTreeNode> right;
    Value val;
};


// insert
// If the pointer is null/empty, then set it to point to a new node.
// Otherwise, it points to a node. Compare that node’s item with the 
// given item. Recurse with the node’s left- or right-child pointer, as 
// appropriate.
// Requirements on Types:
//     Copy assignment and op< must be written in Value
// Exception safety guarantee:
//     Strong Guarantee
template<typename Value>
void insert(std::unique_ptr<BSTreeNode<Value>> & head, const Value & item){

    // Check empty
    if(!head){
        head = std::make_unique<BSTreeNode<Value>>();
        head->val = item;
        return;
    }

    if(head->val < item){
        insert(head->right, item);
        return;
    }
    if(item < head->val){
        insert(head->left, item);
        return;
    }

    //If equal -- Has to be done for stable algorithm
    //            If equal swap the 2 nodes values.
    auto x = head->val;
    head->val = item;
    insert(head->left, x);

    return;
}


// traversal
// Inorder traversal
// Change given iter value
// Requirements on Types:
//     Post increment on FDIter,
//     Copy assignment on Value
// Exception safety guarantee:
//     No-Throw Guarantee
template<typename Value, typename FDIter>
void traversal(std::unique_ptr<BSTreeNode<Value>> & head, FDIter & iter){

    if(!head)
        return;

    traversal(head->left, iter);

    *iter++ = head->val;

    traversal(head->right, iter);
}

// treesort
// Sort a given range using Treesort.
// Requirements on Types:
//     Copy assignment on FDIter
// Exception safety guarantee:
//     Strong Guarantee
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;

    // Tree root
    std::unique_ptr<BSTreeNode<Value>> p;// = std::make_unique<BSTreeNode<Value>>();
    
    //Create BST
    for (FDIter it = first; it != last; ++it)
        insert(p, *it);
    
    //Inorder traversal
    traversal(p, first);
}


#endif //#ifndef FILE_TREESORTER_H_INCLUDED
