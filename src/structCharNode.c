#include "../headers/common.h"
#include "../headers/localShared.h"

struct charNode *newNode(char ch)
{
    struct charNode *node = (struct charNode *)malloc(sizeof(struct charNode));
    node->c = ch;
    node->left = NULL;
    node->right = NULL;

    return node;
}
