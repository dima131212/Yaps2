#include <stdio.h>
#include <stdlib.h>
#include "collection.h"
#include "domain.h"

Node* createNode(Record r) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return NULL;
    }
    newNode->data = r;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, Record r) {
    if (!root) return createNode(r);

    int cmp = compareRecords(r, root->data);
    if (cmp < 0)
        root->left = insert(root->left, r);
    else if (cmp > 0)
        root->right = insert(root->right, r);
    else
        root->data.grade = r.grade;

    return root;
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* delete(Node* root, Record r) {
    if (!root) return root;

    int cmp = compareRecords(r, root->data);
    if (cmp < 0)
        root->left = delete(root->left, r);
    else if (cmp > 0)
        root->right = delete(root->right, r);
    else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void searchBySubject(Node* root, const char* subject) {
    if (!root) return;
    searchBySubject(root->left, subject);
    if (strcmp(root->data.subject, subject) == 0)
        printf("%s: %d\n", root->data.student, root->data.grade);
    searchBySubject(root->right, subject);
}

void printTree(Node* root) {
    if (!root) return;
    printTree(root->left);
    printf("Студент: %s | Предмет: %s | Оценка: %d\n",
        root->data.student,
        root->data.subject,
        root->data.grade);
    printTree(root->right);
}
