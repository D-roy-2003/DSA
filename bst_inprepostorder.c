#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Stack {
    int top;
    struct TreeNode* array[MAX_STACK_SIZE];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct TreeNode* item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = item;
}

struct TreeNode* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;
    
    struct Stack* stack = createStack();
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) 
    {
        while (current != NULL) 
        {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->val);
        current = current->right;
    }
    free(stack);
}

void preorderTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;
    
    struct Stack* stack = createStack();
    push(stack, root);

    while (!isEmpty(stack)) 
    {
        struct TreeNode* current = pop(stack);
        printf("%d ", current->val);
        
        if (current->right != NULL)
            push(stack, current->right);
        if (current->left != NULL)
            push(stack, current->left);
    }
    free(stack);
}

void postorderTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;
    
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();
    push(stack1, root);

    while (!isEmpty(stack1)) 
    {
        struct TreeNode* current = pop(stack1);
        push(stack2, current);
        
        if (current->left != NULL)
            push(stack1, current->left);
        if (current->right != NULL)
            push(stack1, current->right);
    }
    
    while (!isEmpty(stack2)) 
    {
        struct TreeNode* current = pop(stack2);
        printf("%d ", current->val);
    }
    free(stack1);
    free(stack2);
}

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

int main() {
    struct TreeNode* root = NULL;
    int val, choice;
    
    do {
        printf("\n1. Insert a node\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                root = insert(root, val);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    
    // Free memory
    // This can be done recursively but requires additional implementation
    // to free the entire tree.
    return 0;
}