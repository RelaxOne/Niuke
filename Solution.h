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

#endif /* SOLUTION_H_ */
