//
// Created by owsikami on 30.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <memory>
namespace tree {

    template<class T>
    class Node {
    public:
        Node(T key) {
            right_ = nullptr;
            left_ = nullptr;
            // parent_= nullptr;
            key_ = key;
        }

        std::unique_ptr<Node<T>> right_;
        std::unique_ptr<Node<T>> left_;
        //Node<T> * parent_; // shouldn't be owner of the memory
        T key_;
    };


    template<class T>
    class Tree {
    public:

        Tree() : size_(0), depth_(0) { root_ = nullptr; }

        Tree(T key) : size_(1), depth_(1) {
            root_ = std::make_unique<Node<T>>(key);
        } // tree with contructor which set root imidiately

        size_t Size()const { return size_; }

        size_t Depth()const { return depth_; }

        T Value() { return root_->key_; }
        //Root ??

        void Insert(const T &key);
        bool Find(const T &key);
        Node<T> * Root()const{
            return root_.get();
        }


    private:
        std::unique_ptr<Node<T>> root_;
        size_t depth_;
        size_t size_;

    };

    template<class T>
    void Tree<T>::Insert(const T &key) {
        size_++;
        size_t new_depth = 1;

        Node<T> *temp = root_.get();


        //NO ROOT
        if (root_ == nullptr) {         // NOT THE CASE IN THIS TESTS;
            depth_ = 1;
            root_ = std::make_unique<Node<T>>(key);
        } else {


            bool added = false;
            while (not added) {
                new_depth++;

                if (temp->key_ < key) {
                    //go right

                    //right has no child -> add there
                    if (temp->right_ == nullptr) {
                        temp->right_ = std::make_unique<Node<T>>(key);
                        added = true;
                    }

                        //right has child -> check child in next while iteration
                    else {
                        temp = temp->right_.get();
                    }


                } else {
                    //go left

                    //left has no child -> add there
                    if (temp->left_ == nullptr) {
                        temp->left_ = std::make_unique<Node<T>>(key);
                        added = true;
                    }

                        //left has child -> check child in next while iteration
                    else {
                        temp = temp->left_.get();
                    }


                }

            }

            if (new_depth > depth_) {
                depth_ = new_depth;
            }

        }
    }


    template <class T>
    bool Tree<T>::Find(const T &e) {
        Node<T> * temp = root_.get();

        while(temp!= nullptr){
            if( temp->key_==e){
                return true;
            }

            else if(temp->key_<e){
                //right
                temp=temp->right_.get();
            }
            else{ // >e
                temp=temp->left_.get();
                //left

            }
        }

        return false;
    }

}



#endif //JIMP_EXERCISES_TREE_H






//------------ MEMORY LEAK ---------------------------
/*template <class T>
struct Node{
    T key;
    std::unique_ptr<Node<T>> right, left;
    Node()= default;
    Node(T k){
        key=k;
        right= nullptr;
        left = nullptr;
    }
    ~Node()= default;
};

template <class T>
Node<T> * NewNode(T key ){
    Node<T> * new_node = new Node<T>;
    new_node->key= key;
    new_node->right =nullptr;
    new_node->left = nullptr;

    return new_node;
}

template <class T>
class Tree {
public:
    Tree():root(nullptr),size(0),depth(0){}
    Tree(T x):root(NewNode(x)),size(1),depth(1){}

    void Insert(const T &e);
    bool Find(const T &e);
    size_t Depth(){ return depth;}
    size_t Size(){return size;}

    T Value(){ return root->key;}
    //Root

private:
    Node<T> * root;
    size_t size;
    size_t depth;

};

template <class T>
bool Tree<T>::Find(const T &e) {
    Node<T> * temp = root;

    while(temp!= nullptr){
        if( temp->key==e){
            return true;
        }

        else if(temp->key<e){
            //right
            temp=temp->right.get();
        }
        else{ // >e
            temp=temp->left.get();
            //left

        }
    }

    return false;
}



//make uniqe <tree> v
template <class T>
void Tree<T>::Insert(const T &e) {
    size++;
    size_t new_depth=1;
    Node<T> * temp = root;
    //Node<T> * new_node = NewNode(e);
    if(root== nullptr){
        depth=1;
        root=new Node<T>(e);
    }
    else{

        bool added = false;
        while(not added){
            new_depth++;

            if(temp->key<e){
                //right
                if(temp->right== nullptr){
                    temp->right=std::make_unique<Node<T>>(e); //make unique?????
                    added=true;
                }
                else{
                    temp=temp->right.get();
                }



            }
            else{ // >=e
                //left
                if(temp->left== nullptr){
                    temp->left=std::make_unique<Node<T>>(e);
                    added=true;
                } else{
                    temp=temp->left.get();
                }



            }

        }

        if(new_depth>depth){
            depth=new_depth;
        }
    }
}

*/
