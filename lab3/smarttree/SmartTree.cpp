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

        /*
        int count=0;
        string tab[tree.size()];
        string tmp="";

        if(tree == "[null]") return nullptr; //brak korzenia

        for (int i=0; i<tree.size(); i++) {
            tmp="";
            if (isdigit(tree[i])){
                for(int j=i; j<tree.size(); j++){
                    if(!isdigit(tree[j])) break;
                    tmp+=tree[j];

                    i=j+1;
                }
                tab[count] = tmp;
                tab[count+1] = "finish";
                count++;
            }
            else if(tree[i]=='e'){
                tab[count] = "null";
                tab[count+1] = "finish";
                count++;
            }
        }
*/
        //unique_ptr<SmartTree> root;
        //unique_ptr<SmartTree> head;
        //root = InsertLeftChild(move(root), CreateLeaf(100));
        //root = InsertRightChild(move(root), CreateLeaf(88));
        //root->left = InsertLeftChild(move(root->left), CreateLeaf(1234));
        //root->left = InsertRightChild(move(root->left), CreateLeaf(4321));
        //root->right = InsertLeftChild(move(root->right), CreateLeaf(897));
        //root->right = InsertRightChild(move(root->right), CreateLeaf(761));
/*

        bool going_down = true;
        int level = 1;
        int liczenie = 1;

        count = 1;
        while(tab[liczenie]!="finish") {


            cout << tab[liczenie] << " ";
            liczenie++;
        }

        cout << endl;


        unique_ptr<SmartTree> root;
        int start = 0;
        datastructures::help(tab, &start);
*/


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


        unique_ptr <SmartTree> root;
        queue<SmartTree> q;

        int first = 0, last = 0;
        while (first != tmp.length()) {

            if (tmp[first] == '#') {
                root = nullptr;
            }
            else {
                string pom = "";
                while(tmp[last] != ',') {
                    pom+=tmp[last];
                    last++;
                }

                if(pom != "#") {
                    int val = stoi(pom);
                    root = InsertLeftChild(move(root), CreateLeaf(val));
                    root = InsertRightChild(move(root), CreateLeaf(val));
                }

                first = last;
            }
        }

        return root;
    }
}