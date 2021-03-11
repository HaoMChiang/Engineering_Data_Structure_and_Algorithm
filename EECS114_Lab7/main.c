//
//  main.c
//  EECS114_Lab7
//
//  Created by Hao-Ming Chiang on 2/17/21.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct StackNode {
    int data;
    struct StackNode *next;
};

struct Node* createLinkedList() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head -> next = NULL;
    printf("Created a Linked List\n");
    return head;
}

struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode -> data = data;
    stackNode -> next = NULL;
    return stackNode;
};

struct StackNode* createStack() {
    struct StackNode* head = (struct StackNode*)malloc(sizeof(struct StackNode));
    head -> next = NULL;
    printf("Created a Stack\n");
    return head;
}

int isEmpty(struct StackNode* root) {
    if(root -> next == NULL) {
        printf("Stack is Empty!\n\n");
        return 1;
    }
    printf("Stack is not Empty!\n\n");
    return 0;
}

int peek(struct StackNode* root) {
    if(root -> next == NULL) {
        printf("Nothing to Peek. Stack is Empty!\n\n");
        return -1;
    } else {
        int result = root -> next -> data;
        printf("Peeked the Stack. The Data of the Peeked Element is %d.\n\n", result);
        return result;
    }
}

void push(struct StackNode* root, int data) {
    struct StackNode* node = newNode(data);
    struct StackNode* temp = root -> next;
    root -> next = node;
    node -> next = temp;
    printf("Pushed an Element. The Data of the Pushed Element is %d.\n", data);
}

int pop(struct StackNode* root) {
    if(root -> next != NULL) {
        struct StackNode* pop = root -> next;
        struct StackNode* temp = root -> next -> next;
        int result = pop -> data;
        free(pop);
        root -> next = temp;
        printf("Popped an Element. The Data of the Popped Element is %d.\n", result);
        return result;
    } else {
        printf("Nothing to Pop. Stack is Empty!\n\n");
        return -1;
    }
}

void printLinkedList(struct Node* root) {
    printf("Linked List:\n");
    if(root -> next == NULL) {
        printf("Linked List is Empty!!!\n\n");
        return;
    }
    struct Node* first = root -> next;
    int count = 1;
    while(first != NULL) {
        printf("Node %d: %d\n",count++, first -> data);
        first = first -> next;
    }
    printf("\n");
}

void printStack(struct StackNode* root) {
    printf("Stack:\n");
    if(root -> next == NULL) {
        printf("Stack is Empty!!!\n\n");
        return;
    }
    struct StackNode* first = root -> next;
    int count = 1;
    printf("Printing the Stack From Top to Bottom:\n");
    while(first != NULL) {
        printf("Node %d: %d\n",count++, first -> data);
        first = first -> next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    struct Node* head = createLinkedList();
    printLinkedList(head);
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    printf("Created a Node in Linked List\n");
    head -> next = first;
    first -> data = 1;
    first -> next = NULL;
    printLinkedList(head);
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    printf("Created a Node in Linked List\n");
    first -> next = second;
    second -> data = 2;
    second -> next = NULL;
    printLinkedList(head);
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    printf("Created a Node in Linked List\n");
    second -> next = third;
    third -> data = 3;
    third -> next = NULL;
    printLinkedList(head);
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    printf("Created a Node in Linked List\n");
    third -> next = fourth;
    fourth -> data = 4;
    fourth -> next = NULL;
    printLinkedList(head);

    struct StackNode* stack = createStack();
    printStack(stack);
    peek(stack);
    pop(stack);
    push(stack,100);
    printStack(stack);
    push(stack,200);
    printStack(stack);
    peek(stack);
    pop(stack);
    printStack(stack);
    push(stack,24);
    printStack(stack);
    isEmpty(stack);
    pop(stack);
    pop(stack);
    isEmpty(stack);
    printStack(stack);
    
    return 0;
}
