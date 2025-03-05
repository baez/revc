
#ifndef LOCALSHARED_H
#define LOCALSHARED_H

#include "structCharNode.h"
struct charNode *newNode(char ch);


void freeTree(struct charNode *node);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#endif // LOCALSHARED_H