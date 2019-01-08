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
