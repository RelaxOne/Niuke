/*
 * test.cpp
 *
 *  Created on: 2019年1月3日
 *      Author: zhoucw
 */

#include "test.h"

void testFind() {
	vector<vector<int> > array = initArray();
	cout << Find(7, array) << endl;
}

void testPrintListFromTailToHead() {
	ListNode *node = InitList();
	vector<int> result = printListFromTailToHead(node);
	printVector(result);
}

void testreplaceSpace() {
	char str[100] = "hello world";
	replaceSpace(str, strlen(str));
	printString(str);
}

void testminNumberInRotateArray() {
	vector<int> arr = InitVectorArray();
	int value = minNumberInRotateArray(arr);
	cout << value << endl;
}

void testFibonacci() {
	cout << Fibonacci(8) << endl;
}

void testPower() {
	double a = 2;
	int b = -3;
	cout << Power(a, b) << endl;
}

void testreOrderArray() {
	vector<int> arr = InitVectorArray();
	reOrderArray(arr);
	printVector(arr);
}

void testFindKthToTail() {
	ListNode *pListHead = InitList();
	ListNode *result = FindKthToTail(pListHead, 3);
	printListNode(result);
}

void testReverseList() {
	ListNode *list = InitList();
	ListNode *result = ReverseList(list);
	printListNode(result);
}

void testMerge() {
	ListNode *p1 = InitList();
	ListNode *p2 = InitList();

	ListNode *result = Merge(p1, p2);
	printListNode(result);
}

void testNumberOf1() {
	cout << NumberOf1(5) << endl;
}

void testreConstructBinaryTree() {
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

void testMirror() {
	TreeNode *root = InitTreeNode();
	Mirror(root);
	printTreeNode(root);
}

void testSum_Solution() {
	cout << Sum_Solution(5) << endl;
}

void testMoreThanHalfNum_Solution() {
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(5);
	numbers.push_back(4);
	numbers.push_back(2);
	cout << MoreThanHalfNum_Solution(numbers) << endl;
}

void testJumpFloor() {
	int number = 5;
	cout << JumpFloor(number) << endl;
}

void testJumpFloorII() {
	int target = 5;
	cout << JumpFloorII(target) << endl;
}

void testprintMatrix() {
	vector<vector<int>> matrix = initArray();
	vector<int> result = printMatrix(matrix);
	printVector(result);
}

void testIsPopOrder() {
	int pA[] = { 1, 2, 3, 4, 5 };
	vector<int> pushV(pA, pA + 5);
	int pB[] = { 3, 5, 4, 1, 2 };
	vector<int> popV(pB, pB + 5);
	cout << IsPopOrder(pushV, popV) << endl;
}

void testPrintFromTopToBottom() {
	TreeNode *root = InitTreeNode();
	vector<int> result = PrintFromTopToBottom(root);
	printVector(result);
}

void testFindPath() {
	TreeNode* root = InitTreeNode();
	auto result = FindPath(root, 10);
	printVector(result);
}

void testClone() {
	RandomListNode *root = InitRandomListNode();
	printRandomListNode(root);
	RandomListNode *result = Clone(root);
	printRandomListNode(result);
}

void testPermutation() {
	string str = "";
	vector<string> result = Permutation(str);
	printVector(result);
}

void testNumberOf1Between1AndN_Solution() {
	cout << NumberOf1Between1AndN_Solution(13) << endl;
}

void testPrintMinNumber() {
	int arr[] = { 3, 32, 321 };
	vector<int> numbers(arr, arr + 3);
	cout << PrintMinNumber(numbers) << endl;
}

void testFirstNotRepeatingChar() {
	string str = "thisisateststring";
	cout << FirstNotRepeatingChar(str) << endl;
}

void testGetNumberOfK() {
	int arr[] = { 2, 2, 2, 2, 2, 2 };
	vector<int> data(arr, arr + 6);
	cout << GetNumberOfK(data, 2) << endl;
}

void testFindContinousSequence() {
	auto result = FindContinousSequence(9);
	printVector(result);
}

void testReverseSentence() {
	string str = "student. a am I";
	cout << ReverseSentence(str) << endl;
}

void testIsContinuous() {
	int arr[5] = { 0, 1, 3, 5, 7 };
	vector<int> numbers(arr, arr + 5);
	cout << IsContinuous(numbers);
}

void testLastRemaining_Solution() {
	cout << LastRemaining_Solution(4, 2) << endl;
}

void testStrToInt() {
	string str = "-123";
	cout << StrToInt(str) << endl;
}

void testduplicate() {
	int numbers[5] = { 2, 1, 3, 1, 4 };
	int length = 5;
	int duplication;
	cout << duplicate(numbers, length, &duplication) << endl;
	cout << duplication << endl;
}

void testmultiply(){
	int numbers[] = {1,2,3,4,5};
	vector<int> A(numbers, numbers + 5);
	auto result = multiply(A);
	printVector(result);
}

void testdeleteDuplication(){
	ListNode* pHead = InitList();
	ListNode* result = deleteDuplication(pHead);
	printListNode(result);
}
