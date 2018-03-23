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

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        string serialized_tree;

        serialized_tree+="[" + to_string(tree->value) + " ";

        //LEWA!
        if (tree->left == NULL)
            serialized_tree+="[none] ";
        else
            serialized_tree+=DumpTree(tree->left) + " ";

        //PRAWA!
        if (tree->right == NULL)
            serialized_tree+="[none]";
        else
            serialized_tree+=DumpTree(tree->right);

        serialized_tree+="]";

        return serialized_tree;
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);
}