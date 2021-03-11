//
//  main.c
//  EECS114_Lab8
//
//  Created by Hao-Ming Chiang on 2/24/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int data) {
    struct TreeNode* TreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    TreeNode -> data = data;
    TreeNode -> left = NULL;
    TreeNode -> right = NULL;
    return TreeNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    struct TreeNode* curr = newNode(data);
    struct TreeNode* parent = NULL;
    struct TreeNode* track = root;
    while(track != NULL) {
        parent = track;
        if(data <= track -> data) {
            track = track -> left;
        } else {
            track = track -> right;
        }
    }
    if(parent == NULL) {
        root = curr;
    } else if(data > parent -> data) {
        parent -> right = curr;
    } else {
        parent -> left = curr;
    }
    return root;
}

struct TreeNode* search(struct TreeNode* root, int data) {
    if(root == NULL || root -> data == data) {
        return root;
    }
    if(data > root -> data) {
        return search(root -> right, data);
    } else {
        return search(root -> left, data);
    }
}


void printNode(struct TreeNode* root) {
    if(root != NULL) {
        printNode(root -> left);
        printf("%d ", root -> data);
        printNode(root -> right);
    }
}

void printBST(struct TreeNode* root) {
    printf("BST Inorder Traversal:\n");
    printNode(root);
    printf("\n");
}

void printSearchVal(struct TreeNode* node) {
    if(node == NULL) {
        printf("The value you want to find is not in the BST.\n\n");
    } else {
        printf("%d is in the BST.\n\n", node -> data);
    }
}

int main(int argc, const char * argv[]) {

    struct TreeNode* root = NULL;
    printf("Inserting...\n");
    root = insert(root, -50);
    root = insert(root, 30);
    root = insert(root, 2);
    root = insert(root, -234);
    root = insert(root, 892);
    root = insert(root, 22);
    root = insert(root, 739);
    root = insert(root, -98);
    root = insert(root, 19);
    printf("Finished Inserting\n");
    printBST(root);
    
    printf("\nSeaching for Value -100:\n");
    struct TreeNode* searchVal = search(root, -100);
    printSearchVal(searchVal);
    printf("Searching for Value 22:\n");
    searchVal = search(root, 22);
    printSearchVal(searchVal);
    printf("Searching for Value -234:\n");
    searchVal = search(root, -234);
    printSearchVal(searchVal);
    return 0;
}
