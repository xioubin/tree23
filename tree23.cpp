//
//  tree23.cpp
//  tree23
//
//  Created by 謝育斌 on 2020/11/26.
//

#include "tree23.h"

Node::Node(){
    this->leftchild=nullptr;
    this->rightchild=nullptr;
    this->midchild=nullptr;
    this->parent=nullptr;
    this->full=false;
    this->leftdata=-1;
    this->rightdata=-1;
}

Node::Node(int data){
    this->leftchild=nullptr;
    this->rightchild=nullptr;
    this->midchild=nullptr;
    this->parent=nullptr;
    this->full=false;
    this->leftdata=data;
    this->rightdata=-1;
}

tree23::tree23(){
    this->root=nullptr;
}

tree23::tree23(Node* root){
    this->root=root;
}

void tree23::split(Node*& currentNode, Node*& currentNode_papa) {
    if (!currentNode_papa) {
        this->root = currentNode;
    }
    else {
        if (!currentNode_papa->full) {
            currentNode_papa->full = true;
            if (currentNode_papa->leftdata > currentNode->leftdata) {
                currentNode_papa->rightdata = currentNode_papa->leftdata;
                currentNode_papa->leftdata = currentNode->leftdata;
                currentNode_papa->midchild = currentNode_papa->midchild;
                currentNode_papa->leftchild = currentNode->leftchild;
                currentNode_papa->midchild = currentNode->midchild;
                currentNode_papa->leftchild->parent = currentNode_papa;
                currentNode_papa->midchild->parent = currentNode_papa;
            }
            else {
                currentNode_papa->rightdata = currentNode->leftdata;
                currentNode_papa->midchild = currentNode->leftchild;
                currentNode_papa->midchild = currentNode->midchild;
                currentNode_papa->midchild->parent = currentNode_papa;
                currentNode_papa->midchild->parent = currentNode_papa;
            }
        }
        else {
            if (currentNode->leftdata < currentNode_papa->leftdata) { //left children split
                Node* root = new Node();
                root->leftdata = currentNode_papa->leftdata;
                Node* left = currentNode;
                Node* right = new Node();
                right->leftdata = currentNode_papa->rightdata;
                right->leftchild = currentNode_papa->midchild;
                right->midchild = currentNode_papa->midchild;
                if (right->leftchild) right->leftchild->parent = right;
                if (right->midchild) right->midchild->parent = right;
                root->leftchild = left;
                root->midchild = right;
                left->parent = root;
                right->parent = root;
                split(root, currentNode_papa->parent);
            }
            else if (currentNode->leftdata < currentNode_papa->rightdata) {
                Node* root = currentNode;
                Node* left = new Node();
                Node* right = new Node();
                left->leftdata = currentNode_papa->leftdata;
                right->leftdata = currentNode_papa->rightdata;
                left->leftchild = currentNode_papa->leftchild;
                left->midchild = currentNode->leftchild;
                if (left->leftchild) left->leftchild->parent = left;
                if (left->midchild) left->midchild->parent = left;
                right->leftchild = currentNode->midchild;
                right->midchild = currentNode_papa->midchild;
                if (right->leftchild) right->leftchild->parent = right;
                if (right->midchild) right->midchild->parent = right;
                root->leftchild = left;
                root->midchild = right;
                root->parent = currentNode_papa->parent;
                left->parent = root;
                right->parent = root;
                split(root, currentNode_papa->parent);
            }
            else {
                Node* root = new Node();
                root->leftdata = currentNode_papa->rightdata;
                Node* left = new Node();
                Node* right = currentNode;
                left->leftdata = currentNode_papa->leftdata;
                left->leftchild = currentNode_papa->leftchild;
                left->midchild = currentNode_papa->midchild;
                if (left->leftchild) left->leftchild->parent = left;
                if (left->midchild) left->midchild->parent = left;
                root->leftchild = left;
                root->midchild = right;
                left->parent = root;
                right->parent = root;
                split(root, currentNode_papa->parent);
            }
        }
    }

}

void tree23::split(Node*& currentNode) {
    if (currentNode == nullptr) return;
    
    if (currentNode->parent == nullptr) {
        Node* root = new Node(currentNode->extradata);
        Node* left = new Node(currentNode->leftdata);
        Node* right = new Node(currentNode->rightdata);
        left->parent = root;
        right->parent = root;
        root->leftchild = left;
        root->midchild = right;
        delete currentNode;
        this->root = root;
    }
    else {
        //it's parent are not full
        if (!currentNode->parent->full) {
            currentNode->parent->full = true;
            if (currentNode->extradata > currentNode->parent->leftdata) {
                //right children split
                currentNode->parent->rightdata = currentNode->extradata;
                Node* right = new Node(currentNode->rightdata);
                Node* mid = new Node(currentNode->leftdata);
                right->parent = currentNode->parent;
                mid->parent = currentNode->parent;
                currentNode->parent->midchild = mid;
                currentNode->parent->rightchild = right;
            }
            else { //left children split
                currentNode->parent->rightdata = currentNode->parent->leftdata;
                currentNode->parent->leftdata = currentNode->extradata;
                Node* left = new Node(currentNode->leftdata);
                Node* mid = new Node(currentNode->rightdata);
                left->parent = currentNode->parent;
                mid->parent = currentNode->parent;
                currentNode->parent->leftchild = left;
                currentNode->parent->midchild = currentNode->parent->midchild;
                currentNode->parent->midchild = mid;
            }
        }
        //it's parent is full
        else {
            Node* root = new Node(currentNode->extradata);
            Node* left = new Node(currentNode->leftdata);
            Node* right = new Node(currentNode->rightdata);
            root->leftchild = left;
            root->midchild = right;
            left->parent = root;
            right->parent = root;
            split(root, root->parent);
        }
    }
}

void tree23::insert(Node*& currentNode, int data) {
    if (currentNode == nullptr) {
        currentNode = new Node();
        currentNode->leftdata = data;
        return;
    }
    //if has child
    if (currentNode->leftchild!=nullptr||
        currentNode->midchild!=nullptr||
        currentNode->rightchild!=nullptr) {
        if (data > currentNode->leftdata) {
            if (!currentNode->full || data <= currentNode->rightdata) {
                insert(currentNode->midchild, data);
            }
            else if (currentNode->full && data > currentNode->rightdata) {
                insert(currentNode->midchild, data);
            }
        }
        else {
            insert(currentNode->leftchild, data);
        }
    }
    //has no child
    else {
        //has one data
        if (!currentNode->full) {
            if (data < (currentNode->leftdata)) {
                currentNode->rightdata = currentNode->leftdata;
                currentNode->leftdata = data;
                currentNode->full = true;
                return;
            }
            else if (data >= (currentNode->leftdata)) {
                currentNode->rightdata = data;
                currentNode->full = true;
                return;
            }
        }
        //has two child
        else {
            if (data >= currentNode->rightdata) {
                currentNode->extradata = currentNode->rightdata;
                currentNode->rightdata = data;
            }
            else if (data < (currentNode->leftdata)) {
                currentNode->extradata = currentNode->leftdata;
                currentNode->leftdata = data;
            }
            else {
                currentNode->extradata = data;
            }
            split(currentNode);
        }
        return;
    }
}

void tree23::traverse(Node* currentNode, std::vector < std::vector< std::vector <int> > >& output, int level) {
    if (!currentNode)
        return;
    else{
        std::vector <int> numbers;
        numbers.push_back(currentNode->leftdata);
        if (currentNode->full) {
            numbers.push_back(currentNode->rightdata);
        }
        if (output.size() >= level) {
            output[level - 1].push_back(numbers);
        }
        else {
            std::vector < std::vector <int> > current_level;
            current_level.push_back(numbers);
            output.push_back(current_level);
        }
        traverse(currentNode->leftchild, output, level + 1);
        traverse(currentNode->midchild, output, level + 1);
        traverse(currentNode->midchild, output, level + 1);
        }
}
