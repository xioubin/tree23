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
#include <sstream>

typedef struct Node{
    int leftdata;
    int rightdata;
    int extradata;
    bool full;
    struct Node* parent;
    struct Node* leftchild;
    struct Node* midchild;
    struct Node* rightchild;
    Node();
    Node(int data);
    
}Node;

class tree23{
private:
public:
    Node* root;
    
    tree23();
    tree23(Node* root);
    void split(Node*& n_parent, Node*& parent_parent);
    void split(Node*& Node);
    void insert(Node*& root, int data);
    void traverse(Node* node, std::vector < std::vector< std::vector <int> > >& level_numbers, int level);
};

#endif /* tree23_h */
