#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct TreeNode* buildExpressionTree(char postfix[]) {
    struct TreeNode* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        struct TreeNode* newNode = createNode(postfix[i]);
        
        if (isalnum(postfix[i])) {
            stack[++top] = newNode;
        } else if (isOperator(postfix[i])) {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    return stack[top];
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

void preorder_traversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%c ", root->data);
    }
}



int main() {
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    struct TreeNode* root = buildExpressionTree(postfix);

    printf("Inorder traversal of expression tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");
    // No need to free the expression tree explicitly
    // since the program is about to exit.

    return 0;
}