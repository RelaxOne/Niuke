/*
 * test.cpp
 *
 *  Created on: 2019��1��3��
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
