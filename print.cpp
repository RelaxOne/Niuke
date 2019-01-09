/*
 * print.cpp
 *
 *  Created on: 2019Äê1ÔÂ3ÈÕ
 *      Author: zhoucw
 */

#include "print.h"

/**
 * print the value of array with vector<vector<int >>
 */
void printArray(vector<vector<int>> arr) {
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

/**
 * print string value
 */
void printString(const char *str){
	int length = strlen(str);
	for(int i=0;i<length;i++){
		cout<<str[i];
	}
	cout<<endl;
}

/**
 * print list
 */
void printListNode(ListNode* pListHead){
	ListNode *p = pListHead;
	while(p != NULL){
		cout<< p->val;
		p = p->next;
		if(p != NULL)
			cout<< " -> ";
	}
	cout<<endl;
}

void printTreeNode(TreeNode *root){
	if(root == NULL)
		return;
	cout << root->val << " ";
	printTreeNode(root->left);
	printTreeNode(root->right);
}

void printStack(stack<int> stack){
	int len = stack.size();
	for(int i = 0; i < len; i++){
		cout<< stack.top() <<" ";
		stack.pop();
	}
	cout<<endl;
}
