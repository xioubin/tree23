//
//  tree23.cpp
//  tree23
//
//  Created by 謝育斌 on 2020/11/26.
//

#include "tree23.h"

node::node(){
    this->leftchild=nullptr;
    this->rightchild=nullptr;
    this->midchild=nullptr;
    this->parent=nullptr;
    this->leftdata=-1;
    this->rightdata=-1;
}

node::node(int data){
    this->leftchild=nullptr;
    this->rightchild=nullptr;
    this->midchild=nullptr;
    this->parent=nullptr;
    this->leftdata=data;
    this->rightdata=-1;
}

tree23::tree23(){
    this->root=nullptr;
}

tree23::tree23(Node* root){
    this->root=root;
}

void tree23::insert(int data, Node* currentNode){
    //step 1: if root==null -> new node=null
    if(currentNode==nullptr){
        currentNode=new Node(data);
    }
    else{
        if(currentNode->leftchild!=nullptr && data<currentNode->leftdata){
            insert(data,currentNode->leftchild);
        }
        if(currentNode->midchild!=nullptr &&
           data>currentNode->leftdata &&
           data<currentNode->rightdata){
            insert(data,currentNode->midchild);
        }
        if(currentNode->rightchild!=nullptr && data>currentNode->rightdata){
            insert(data,currentNode->rightchild);
        }
        //step 2: if node has one data -> second data insert
        else{
            if(currentNode->rightdata==-1){
                currentNode->rightdata=data;
            }
            else{
                
            }
        }
    }
    
    //step 3: if data == 2 -> min,max of three =child, mid of three = parent
}
