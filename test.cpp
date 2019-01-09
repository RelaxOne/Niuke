/*
 * test.cpp
 *
 *  Created on: 2019Äê1ÔÂ3ÈÕ
 *      Author: zhoucw
 */

#include "test.h"

void testFind() {
	vector<vector<int>> array = initArray();
	cout << Find(7, array) << endl;
}

void testPrintListFromTailToHead() {
	ListNode *node = InitList();
	vector<int> result = printListFromTailToHead(node);
	printVector(result);
}

void testreplaceSpace(){
	char str[100] = "hello world";
	replaceSpace(str,strlen(str));
	printString(str);
}

void testminNumberInRotateArray(){
	vector<int> arr = InitVectorArray();
	int value = minNumberInRotateArray(arr);
	cout<<value<<endl;
}

void testFibonacci(){
	cout<<Fibonacci(8)<<endl;
}

void testPower(){
	double a = 2;
	int b = -3;
	cout<< Power(a,b)<<endl;
}

void testreOrderArray(){
	vector<int> arr = InitVectorArray();
	reOrderArray(arr);
	printVector(arr);
}

void testFindKthToTail(){
	ListNode *pListHead = InitList();
	ListNode *result = FindKthToTail(pListHead, 3);
	printListNode(result);
}

void testReverseList(){
	ListNode *list = InitList();
	ListNode *result = ReverseList(list);
	printListNode(result);
}

void testMerge(){
	ListNode *p1 = InitList();
	ListNode *p2 = InitList();

	ListNode *result = Merge(p1,p2);
	printListNode(result);
}


void testNumberOf1(){
	cout<< NumberOf1(5)<<endl;
}

void testreConstructBinaryTree(){
	vector<int> pre, vin;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(7);
	pre.push_back(3);
	pre.push_back(5);
	pre.push_back(6);
	pre.push_back(8);

	vin.push_back(4);
	vin.push_back(7);
	vin.push_back(2);
	vin.push_back(1);
	vin.push_back(5);
	vin.push_back(3);
	vin.push_back(8);
	vin.push_back(6);
	TreeNode* root = reConstructBinaryTree(pre, vin);
	printTreeNode(root);
}

void testMirror(){
	TreeNode *root = InitTreeNode();
	Mirror(root);
	printTreeNode(root);
}

void testSum_Solution(){
	cout<< Sum_Solution(5)<<endl;
}
