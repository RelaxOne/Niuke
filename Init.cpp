/*
 * Init.cpp
 *
 *  Created on: 2019Äê1ÔÂ3ÈÕ
 *      Author: zhoucw
 */

#include "Init.h"


ListNode * InitList(){
	ListNode * node1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode * node2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode * node3 = (ListNode*)malloc(sizeof(ListNode));
	ListNode * node4 = (ListNode*)malloc(sizeof(ListNode));
	ListNode * node5 = (ListNode*)malloc(sizeof(ListNode));
	ListNode * node6 = (ListNode*)malloc(sizeof(ListNode));
	ListNode * node7 = (ListNode*)malloc(sizeof(ListNode));
	node1->val = 1;
	node1->next = node2;
	node2->val = 2;
	node2->next = node3;
	node3->val = 3;
	node3->next = node4;
	node4->val = 4;
	node4->next = node5;
	node5->val = 5;
	node5->next = node6;
	node6->val = 6;
	node6->next =node7;
	node7->val = 7;
	node7->next = NULL;

	return node1;
}


vector<vector<int>> initArray() {

	vector<vector<int>> array;

	vector<int> temp1;
	temp1.push_back(2);
	temp1.push_back(7);
	temp1.push_back(9);
	temp1.push_back(11);

	vector<int> temp2;
	temp2.push_back(3);
	temp2.push_back(8);
	temp2.push_back(10);
	temp2.push_back(13);

	vector<int> temp3;
	temp3.push_back(5);
	temp3.push_back(11);
	temp3.push_back(15);
	temp3.push_back(17);

	vector<int> temp4;
	temp4.push_back(7);
	temp4.push_back(12);
	temp4.push_back(17);
	temp4.push_back(19);

	array.push_back(temp1);
	array.push_back(temp2);
	array.push_back(temp3);
	array.push_back(temp4);
	return array;
}

vector<int> InitVectorArray(){
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
