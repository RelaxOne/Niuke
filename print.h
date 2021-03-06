/*
 * print.h
 *
 *  Created on: 2019年1月3日
 *      Author: zhoucw
 */

#ifndef PRINT_H_
#define PRINT_H_

#include "Solution.h"
#include <string.h>

void printVector(vector<int> vec);
void printVector(vector<string> vec);
void printArray(vector<vector<int> > arr);
void printString(const char *str);
void printListNode(ListNode* pListHead);
void printTreeNode(TreeNode *root);
void printStack(stack<int> stack);
void printVector(vector<vector<int> > vec);
void printRandomListNode(RandomListNode* root);

#endif /* PRINT_H_ */
