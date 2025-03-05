#include "../headers/common.h"
#include "../headers/localShared.h"

void buildAndPrintSampleTree(void (*printTree)(struct charNode *node, int level))
{
    struct charNode *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->left = newNode('F');
    root->right->left->left = newNode('O');
    root->right->left->right = newNode('P');
    root->right->right = newNode('G');
    root->right->right->left = newNode('L');
    root->right->right->right = newNode('M');
    root->left->left->left = newNode('H');
    root->left->left->right = newNode('I');
    root->left->right->left = newNode('J');
    root->left->right->right = newNode('K');

    printf("Sample Binary Tree:\n");
    printTree(root, 0);
    freeTree(root);
}

void printTreePortraitRightSideUp(struct charNode *node, int level)
{
    if (node == NULL)
        return;

    printTreePortraitRightSideUp(node->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        printf("   ");
        if (i == level - 1)
            printf("|-");
        else
            printf(" ");
    }

    printf("%c\n", node->c);

    printTreePortraitRightSideUp(node->left, level + 1);
}

void printTreePortraitLeftSideUp(struct charNode *node, int level)
{
    if (node == NULL)
        return;

        printTreePortraitLeftSideUp(node->left, level + 1);

    for (int i = 0; i < level; i++)
    {
        printf("   ");
        if (i == level - 1)
            printf("|-");
        else
            printf(" ");
    }

    printf("%c\n", node->c);

    printTreePortraitLeftSideUp(node->right, level + 1 );
}

void printTreeLandscape(struct charNode *node, int level)
{
    if (node == NULL)
        return;

    printTreeLandscape(node->left, level + 1);

    for (int i = 0; i < level; i++)
    {
        printf("   ");
        if (i == level - 1)
            printf("/-");
        else
            printf(" ");
    }

    printf("%c\n", node->c);

    printTreeLandscape(node->right, level + 1 );
}

void freeTree(struct charNode *node)
{
    if (node == NULL)
        return;

    freeTree(node->left);
    freeTree(node->right);

    // Free the current node
    free(node);
}