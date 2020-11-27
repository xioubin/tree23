//
//  tree23.h
//  tree23
//
//  Created by 謝育斌 on 2020/11/26.
//

#ifndef tree23_h
#define tree23_h

typedef struct node{
    int leftdata;
    int rightdata;
    struct node* parent;
    struct node* leftchild;
    struct node* midchild;
    struct node* rightchild;
    node();
    node(int data);
}Node;

class tree23{
private:
public:
    node* root;
    
    tree23();
    tree23(Node* root);
    void insert(int data, Node* currentNode);
    
};

#endif /* tree23_h */
