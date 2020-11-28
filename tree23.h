//
//  tree23.h
//  tree23
//
//  Created by 謝育斌 on 2020/11/26.
//

#ifndef tree23_h
#define tree23_h
#include <iostream>
#include <algorithm>
#include <vector>

typedef struct node{
    int leftdata;
    int rightdata;
    struct node* parent;
    struct node* leftchild;
    struct node* midchild;
    struct node* rightchild;
    node();
    node(int data);
    node(int data1,int data2);
}Node;

class tree23{
private:
public:
    node* root;
    
    tree23();
    tree23(Node* root);
    void insert(int data, Node* currentNode);
    void merge(Node* currentNode,int data);
    
};

#endif /* tree23_h */
