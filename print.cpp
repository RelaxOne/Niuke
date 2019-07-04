/*
 * print.cpp
 *
 *  Created on: 2019年1月3日
 *      Author: zhoucw
 */

#include "print.h"

/**
 * print the value of array with vector<vector<int >>
 */
void printArray(vector<vector<int> > arr) {
	if (arr.empty()) {
		cout << "the array is empty" << endl;
		return;
	}
	int length = arr.size();
	int cols = arr[0].size();
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

/**
 * print the value of vector<int >
 */
void printVector(vector<int> vec) {
	int length = vec.size();
	for (int i = 0; i < length; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

void printVector(vector<string> vec) {
	int length = vec.size();
	cout<< "[ ";
	for (int i = 0; i < length; i++) {
		cout << vec[i] << " ";
	}
	cout << "]" << endl;
}

/**
 * print the value of vector<int >
 */
void printVector(vector<vector<int> > vec) {
	int len = vec.size();
	if (len == 0) {
		cout << "[]" << endl;
	} else {
		cout << "[ ";
		for (int i = 0; i < len; i++) {
			int num = vec[i].size();
			cout << "[ ";
			for (int j = 0; j < num; j++) {
				cout << vec[i][j] << " ";
			}
			cout << "] ";
		}
		cout << " ]" << endl;
	}
}

/**
 * print string value
 */
void printString(const char *str) {
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		cout << str[i];
	}
	cout << endl;
}

/**
 * print list
 */
void printListNode(ListNode* pListHead) {
	ListNode *p = pListHead;
	while (p != NULL) {
		cout << p->val;
		p = p->next;
		if (p != NULL)
			cout << " -> ";
	}
	cout << endl;
}

void printTreeNode(TreeNode *root) {
	if (root == NULL)
		return;
	cout << root->val << " ";
	printTreeNode(root->left);
	printTreeNode(root->right);
}

void printStack(stack<int> stack) {
	int len = stack.size();
	for (int i = 0; i < len; i++) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
}

void printRandomListNode(RandomListNode* root) {
	RandomListNode* p = root;
	while (p != nullptr) {
		cout << p->label << " ";
		p = p->next;
	}
	p = root;
	while( p != nullptr){
		if(p->random == nullptr)
			cout << "#" << " ";
		else
			cout << p->random->label << " ";
		p = p->next;
	}
	cout << endl;
}
