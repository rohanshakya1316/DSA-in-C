// Write a C program to implement expression tree.
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
 
struct tree {
    char data;
    struct tree *left, *right;
};
 
int top = -1;
struct tree *stack[20];
struct tree *node;
 
void push(struct tree* node) {
    stack[++top] = node;
}
 
struct tree * pop() {
    return (stack[top--]);
}

int check(char ch) {
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return 2;
    else
        return 1;
}

int cal(struct tree *node) {
    int ch;
    ch = check(node->data);
    if (ch == 1)
        return node->data - 48;
    else if (ch == 2) {
        if (node->data == '+')
            return cal(node->left) + cal(node->right);
        if (node->data == '-')
            return cal(node->left) - cal(node->right);
        if (node->data == '*')
            return cal(node->left) * cal(node->right);
        if (node->data == '/')
            return cal(node->left) / cal(node->right);
    }
}
 
void inorder(struct tree *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%c", node->data);
        inorder(node->right);
    }
}

void operand(char b) {
    node = (struct tree*) malloc(sizeof(struct tree));
    node->data = b;
    node->left = NULL;
    node->right = NULL;
    push(node);
}
 
void operators(char a) {
    node = (struct tree*) malloc(sizeof(struct tree));
    node->data = a;
    node->right = pop();
    node->left = pop();
    push(node);
}
 
void main(int argc, char **argv) {
    int i, p, k, ans;
    char s[20];
    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    gets(s);
    k = strlen(s);
    i = 0;
    for (i = 0; s[i] != '\0'; i++) {
        p = check(s[i]);
        if (p == 1)
            operand(s[i]);
        else if (p == 2)
            operators(s[i]);
    }
    ans = cal(stack[top]);
    printf("\nThe value of the postfix expression you entered is %d\n", ans);
    printf("\nThe inorder traversal of the tree is \n");
    inorder(stack[top]);
}



// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>
// #include<string.h>

// // Structure for a tree node
// struct Node {
//     char value;
//     struct Node* left;
//     struct Node* right;
// };

// // Function to create a new tree node
// struct Node* newNode(char value) {
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->value = value;
//     node->left = NULL;
//     node->right = NULL;
//     return node;
// }

// // Stack structure and functions to handle nodes
// struct Stack {
//     int top;
//     unsigned capacity;
//     struct Node** array;
// };

// // Function to create a stack of given capacity
// struct Stack* createStack(unsigned capacity) {
//     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
//     stack->top = -1;
//     stack->capacity = capacity;
//     stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
//     return stack;
// }

// // Function to check if the stack is full
// int isFull(struct Stack* stack) {
//     return stack->top == stack->capacity - 1;
// }

// // Function to check if the stack is empty
// int isEmpty(struct Stack* stack) {
//     return stack->top == -1;
// }

// // Function to push an item to stack
// void push(struct Stack* stack, struct Node* item) {
//     if (isFull(stack))
//         return;
//     stack->array[++stack->top] = item;
// }

// // Function to pop an item from stack
// struct Node* pop(struct Stack* stack) {
//     if (isEmpty(stack))
//         return NULL;
//     return stack->array[stack->top--];
// }

// // Utility function to check if 'c' is an operator
// int isOperator(char c) {
//     return (c == '+' || c == '-' || c == '*' || c == '/');
// }

// // Function to construct an expression tree from postfix expression
// struct Node* constructTree(char postfix[]) {
//     struct Stack* stack = createStack(strlen(postfix));
//     struct Node* t, * t1, * t2;

//     // Traverse through every character of input expression
//     for (int i = 0; i < strlen(postfix); i++) {
//         // If the character is an operand, create a new node and push it to stack
//         if (!isOperator(postfix[i])) {
//             t = newNode(postfix[i]);
//             push(stack, t);
//         } else { // If the character is an operator
//             t = newNode(postfix[i]);

//             // Pop two top nodes
//             t1 = pop(stack);
//             t2 = pop(stack);

//             // make them children
//             t->right = t1;
//             t->left = t2;

//             // Push current node
//             push(stack, t);
//         }
//     }

//     // The only node left in stack is the root of expression tree
//     t = pop(stack);
//     return t;
// }

// // Function to perform inorder traversal
// void inorder(struct Node* t) {
//     if (t) {
//         inorder(t->left);
//         printf("%c ", t->value);
//         inorder(t->right);
//     }
// }

// // Function to evaluate the expression tree
// int evaluate(struct Node* root) {
//     // empty tree
//     if (root == NULL)
//         return 0;

//     // leaf node
//     if (!root->left && !root->right)
//         return root->value - '0';

//     // evaluate left subtree
//     int left_val = evaluate(root->left);

//     // evaluate right subtree
//     int right_val = evaluate(root->right);

//     // check which operator to apply
//     if (root->value == '+')
//         return left_val + right_val;

//     if (root->value == '-')
//         return left_val - right_val;

//     if (root->value == '*')
//         return left_val * right_val;

//     return left_val / right_val;
// }

// void main() {
//     char postfix[] = "53+82-*";
//     struct Node* root = constructTree(postfix);

//     printf("Inorder traversal of the constructed tree: ");
//     inorder(root);

//     printf("\nResult of the evaluation: %d\n", evaluate(root));
// }
