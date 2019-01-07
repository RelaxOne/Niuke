/*
 * Solution.h
 *
 *  Created on: 2019��1��3��
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

// ��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
// �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�����
bool Find(int target, vector<vector<int> > array);

// ����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList
vector<int> printListFromTailToHead(ListNode *head);

// ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20��
void replaceSpace(char *str, int length);

// �����ת��������С��Ԫ��
int minNumberInRotateArray(vector<int> rotateArray) ;

// ����һ������n���������쳲��������еĵ�n��
int Fibonacci(int n);

#endif /* SOLUTION_H_ */
