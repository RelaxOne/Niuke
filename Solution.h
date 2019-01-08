/*
 * Solution.h
 *
 *  Created on: 2019年1月3日
 *      Author: zhoucw
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

// 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
bool Find(int target, vector<vector<int> > array);

// 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList
vector<int> printListFromTailToHead(ListNode *head);

// 实现一个函数，将一个字符串中的每个空格替换成“%20”
void replaceSpace(char *str, int length);

// 输出旋转数组中最小的元素
int minNumberInRotateArray(vector<int> rotateArray) ;

// 输入一个整数n，请你输出斐波那契数列的第n项
int Fibonacci(int n);

// 求base的exponent次方
double Power(double base, int exponent);

// 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分,并保证其相对位置不发生改变
void reOrderArray(vector<int> &array);

// 链表中倒数第k个结点。
ListNode* FindKthToTail(ListNode* pListHead, int k);

// 反转链表后，输出新链表的表头。
ListNode* ReverseList(ListNode* pHead);

// 合并两个单调递增的链表，并保持其递增性
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);


#endif /* SOLUTION_H_ */
