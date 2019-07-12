/*
 * Init.cpp
 *
 *  Created on: 2019年1月3日
 *      Author: zhoucw
 */

#include "Init.h"

ListNode * InitList() {
	ListNode * node1 = (ListNode*) malloc(sizeof(ListNode));
	ListNode * node2 = (ListNode*) malloc(sizeof(ListNode));
	ListNode * node3 = (ListNode*) malloc(sizeof(ListNode));
	ListNode * node4 = (ListNode*) malloc(sizeof(ListNode));
	ListNode * node5 = (ListNode*) malloc(sizeof(ListNode));
	ListNode * node6 = (ListNode*) malloc(sizeof(ListNode));
	ListNode * node7 = (ListNode*) malloc(sizeof(ListNode));
	node1->val = 1;
	node1->next = node2;
	node2->val = 2;
	node2->next = node3;
	node3->val = 3;
	node3->next = node4;
	node4->val = 3;
	node4->next = node5;
	node5->val = 4;
	node5->next = node6;
	node6->val = 4;
	node6->next = node7;
	node7->val = 5;
	node7->next = NULL;

	return node1;
}

vector<vector<int> > initArray() {

	vector<vector<int> > array;

	vector<int> temp1;
	temp1.push_back(2);
	temp1.push_back(7);
	temp1.push_back(9);
	temp1.push_back(11);
	temp1.push_back(11);

	vector<int> temp2;
	temp2.push_back(3);
	temp2.push_back(8);
	temp2.push_back(10);
	temp2.push_back(13);
	temp2.push_back(13);

	vector<int> temp3;
	temp3.push_back(5);
	temp3.push_back(11);
	temp3.push_back(15);
	temp3.push_back(17);
	temp3.push_back(17);

	vector<int> temp4;
	temp4.push_back(7);
	temp4.push_back(12);
	temp4.push_back(17);
	temp4.push_back(19);
	temp4.push_back(19);

	vector<int> temp5;
	temp5.push_back(-1);
	temp5.push_back(-2);
	temp5.push_back(-3);
	temp5.push_back(-4);
	temp5.push_back(-4);

	array.push_back(temp1);
	array.push_back(temp2);
	array.push_back(temp3);
	array.push_back(temp4);
	array.push_back(temp5);
	return array;
}

vector<int> InitVectorArray() {
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);
	return arr;
}

TreeNode* InitTreeNode() {
	TreeNode* root = (TreeNode*) malloc(sizeof(TreeNode));
	TreeNode* root1 = (TreeNode*) malloc(sizeof(TreeNode));
	TreeNode* root2 = (TreeNode*) malloc(sizeof(TreeNode));
	TreeNode* root3 = (TreeNode*) malloc(sizeof(TreeNode));
	TreeNode* root4 = (TreeNode*) malloc(sizeof(TreeNode));
	TreeNode* root5 = (TreeNode*) malloc(sizeof(TreeNode));
	TreeNode* root6 = (TreeNode*) malloc(sizeof(TreeNode));
	TreeNode* root7 = (TreeNode*) malloc(sizeof(TreeNode));

	root->val = 1;
	root1->val = 2;
	root2->val = 4;
	root3->val = 7;
	root4->val = 3;
	root5->val = 6;
	root6->val = 6;
	root7->val = 8;

	root2->left = NULL;
	root2->right = NULL;

	root3->left = NULL;
	root3->right = NULL;

	root5->left = NULL;
	root5->right = NULL;

	root7->left = NULL;
	root7->right = NULL;

	root6->right = NULL;
	root6->left = root7;

	root4->left = root5;
	root4->right = root6;

	root1->left = root2;
	root1->right = root3;

	root->left = root1;
	root->right = root4;
	return root;
}

RandomListNode* InitRandomListNode(){
	RandomListNode *node1 = new RandomListNode(1);
	RandomListNode *node2 = new RandomListNode(2);
	RandomListNode *node3 = new RandomListNode(3);
	RandomListNode *node4 = new RandomListNode(4);
	RandomListNode *node5 = new RandomListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = nullptr;

	node1->random = node3;
	node2->random = node5;
	node3->random = nullptr;
	node4->random = node2;
	node5->random = nullptr;

	return node1;
}
