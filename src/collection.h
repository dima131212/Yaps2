#ifndef COLLECTION_H
#define COLLECTION_H

#include "domain.h"

typedef struct Node {
    Record data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(Record r);
Node* insert(Node* root, Record r);
Node* delete(Node* root, Record r);
Node* findMin(Node* root);
void searchBySubject(Node* root, const char* subject);
void printTree(Node* root);

#endif
