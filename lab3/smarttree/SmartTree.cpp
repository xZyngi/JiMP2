//
// Created by zyngi on 21.03.18.
//

#include "SmartTree.h"

namespace datastructures {

    std::unique_ptr <SmartTree> CreateLeaf(int value){
        unique_ptr <SmartTree> node = make_unique<SmartTree>();
        node->value = value;

        return node;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left = move(left_subtree);

        return tree;
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right = move(right_subtree);

        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr->left){
            PrintTreeInOrder(unique_ptr->left, out);
        }

        //*out << unique_ptr->value << ", ";

        if(unique_ptr->right){
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    void DumpTree(const std::unique_ptr<SmartTree> &tree){

        if(tree == NULL) {
            cout << " [null]";
        }
        else {
            cout << " [" << tree->value << "";
        }

        if(tree == NULL) return;

        //cout << "x";
        DumpTree(tree->left);
        DumpTree(tree->right);
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);
}