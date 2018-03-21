//
// Created by zyngi on 21.03.18.
//

#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include "SmartTree.h"

using namespace std;

int main(){

    unique_ptr<datastructures::SmartTree> root;
    root = datastructures::CreateLeaf(99);
    root = datastructures::InsertLeftChild(move(root), datastructures::CreateLeaf(100));
    root = datastructures::InsertRightChild(move(root), datastructures::CreateLeaf(88));
    root->left = datastructures::InsertLeftChild(move(root->left), datastructures::CreateLeaf(1234));
    root->left = datastructures::InsertRightChild(move(root->left), datastructures::CreateLeaf(4321));
    root->right = datastructures::InsertLeftChild(move(root->right), datastructures::CreateLeaf(897));
    root->right = datastructures::InsertRightChild(move(root->right), datastructures::CreateLeaf(761));

    datastructures::DumpTree(root);

    return 0;
}