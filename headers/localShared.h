
#ifndef LOCALSHARED_H
#define LOCALSHARED_H

#include "structCharNode.h"
struct charNode *newNode(char ch);
void freeTree(struct charNode *node);

void printTreePortraitLeftSideUp(struct charNode *node, int level);
void printTreePortraitRightSideUp(struct charNode *node, int level);
void printTreeLandscape(struct charNode *node, int level);
void buildAndPrintSampleTree(void (*printTree)(struct charNode *node, int level));

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#endif // LOCALSHARED_H