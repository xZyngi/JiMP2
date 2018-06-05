//
// Created by kamila on 04.06.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>
#include <iostream>
#include <vector>

namespace tree{

/*template <class T>
    class XOrderTreeIterator{
    public:
        //constructor
        virtual void OrderWalk(Node<T>* root)=0;
        void operator++(){
            ++position;
        }
        T operator*(){
            return order_array[position];
        }

        bool operator!=(const XOrderTreeIterator<T> &other){
            return position!=other.position;
        }




    protected:
        std::vector<Tree<T>> order_array;
        int position;

    };*/

    template <class T>
    class InOrderTreeIterator{
    public:

        InOrderTreeIterator(Node<T>* root){
            OrderWalk(root);
            position=0;
        }
        void OrderWalk(Node<T>* root){
            if( root != nullptr){
                OrderWalk(root->left_.get());
                order_array.push_back(root->key_);
                OrderWalk(root->right_.get());
            }

        }

        InOrderTreeIterator<T> ReturnEnd(){
            position=order_array.size();
            return *this;
        }

        void operator++(){
            ++position;
        }
        T operator*(){
            return order_array[position];
        }

        bool operator!=(const InOrderTreeIterator<T> &other)const{
            return position!=other.position;
        }


    private:
        std::vector<T> order_array;
        int position;


    };

    template <class T>
    class InOrderTreeView{
    public:
        InOrderTreeView( Tree<T> *tree){
          root_=tree->Root();
        }

        InOrderTreeIterator<T> begin(){
            return InOrderTreeIterator<T>(root_);
        }

        InOrderTreeIterator<T> end(){
            return InOrderTreeIterator<T>(root_).ReturnEnd();
        }

    private:
        Node<T> * root_;
    };


    template <class T>
    InOrderTreeView<T> InOrder( Tree<T> *tree){
        return InOrderTreeView<T>(tree);
    }


    template <class T>
    class PreOrderTreeIterator{
    public:

        PreOrderTreeIterator(Node<T>* root){
            OrderWalk(root);
            position=0;
        }
        void OrderWalk(Node<T>* root){
            if( root != nullptr){
                
                order_array.push_back(root->key_);
                OrderWalk(root->left_.get());
                OrderWalk(root->right_.get());
            }

        }

        PreOrderTreeIterator<T> ReturnEnd(){
            position=order_array.size();
            return *this;
        }

        void operator++(){
            ++position;
        }
        T operator*(){
            return order_array[position];
        }

        bool operator!=(const PreOrderTreeIterator<T> &other)const{
            return position!=other.position;
        }


    private:
        std::vector<T> order_array;
        int position;


    };

    template <class T>
    class PreOrderTreeView{
    public:
        PreOrderTreeView( Tree<T> *tree){
            root_=tree->Root();
        }

        PreOrderTreeIterator<T> begin(){
            return PreOrderTreeIterator<T>(root_);
        }

        PreOrderTreeIterator<T> end(){
            return PreOrderTreeIterator<T>(root_).ReturnEnd();
        }

    private:
        Node<T> * root_;
    };


    template <class T>
    PreOrderTreeView<T> PreOrder( Tree<T> *tree){
        return PreOrderTreeView<T>(tree);
    }


    template <class T>
    class PostOrderTreeIterator{
    public:

        PostOrderTreeIterator(Node<T>* root){
            OrderWalk(root);
            position=0;
        }
        void OrderWalk(Node<T>* root){
            if( root != nullptr){

                
                OrderWalk(root->left_.get());
                OrderWalk(root->right_.get());
                order_array.push_back(root->key_);
            }

        }

        PostOrderTreeIterator<T> ReturnEnd(){
            position=order_array.size();
            return *this;
        }

        void operator++(){
            ++position;
        }
        T operator*(){
            return order_array[position];
        }

        bool operator!=(const PostOrderTreeIterator<T> &other)const{
            return position!=other.position;
        }


    private:
        std::vector<T> order_array;
        int position;


    };

    template <class T>
    class PostOrderTreeView{
    public:
        PostOrderTreeView( Tree<T> *tree){
            root_=tree->Root();
        }

        PostOrderTreeIterator<T> begin(){
            return PostOrderTreeIterator<T>(root_);
        }

        PostOrderTreeIterator<T> end(){
            return PostOrderTreeIterator<T>(root_).ReturnEnd();
        }

    private:
        Node<T> * root_;
    };


    template <class T>
    PostOrderTreeView<T> PostOrder( Tree<T> *tree){
        return PostOrderTreeView<T>(tree);
    }





}



#endif //JIMP_EXERCISES_TREEITERATORS_H
