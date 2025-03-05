#ifndef STRUCT_CHAR_NODE_H
#define STRUCT_CHAR_NODE_H

typedef struct charNode
{
    char c;
    struct charNode *left;
    struct charNode *right;
} charNode;

#endif // STRUCT_CHAR_NODE_H
