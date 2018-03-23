//
// Created by zyngi on 21.03.18.
//

#include <sstream>
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

        *out << unique_ptr->value << ", ";

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

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){

        int count=0;
        string tab[tree.size()];
        string tmp="";

        if(tree == "[null]") return nullptr; //brak korzenia

        for (int i=0; i<tree.size(); i++) {
            if (isdigit(tree[i])){
                for(int j=i; j<tree.size(); j++){
                    if(!isdigit(tree[j])) break;
                    tmp+=tree[j];

                    i=j+1;
                }
                tmp+=",";
            }
            else if(tree[i]=='e'){
                tmp+="#,";
            }
        }

        SmartTree root = nullptr;
        queue<SmartTree> q;
        q.push(root);
        string::iterator first = tmp.begin();
        while (first != tmp.end()) {
            SmartTree pp = q.front();
            if (*first == '#') {
                pp = nullptr;
                advance(first, 2);
            }
            else {
                string::iterator last = find(first, tmp.end(), ',');
                int val = stoi(string(first, last));
                pp = new SmartTree(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first = next(last);
            }
            q.pop();
        }



        return nullptr;
    }
}