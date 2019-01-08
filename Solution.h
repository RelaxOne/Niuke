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
#include <math.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

// ��һ����ά������(ÿ��һά����ĳ�����ͬ),ÿһ�ж����մ����ҵ�����˳������, ÿһ�ж����մ��ϵ��µ�����˳������
// �����һ������, ����������һ����ά�����һ������, �ж��������Ƿ��и�����
bool Find(int target, vector<vector<int> > array);

// ����һ������,������ֵ��β��ͷ��˳�򷵻�һ��ArrayList
vector<int> printListFromTailToHead(ListNode *head);

// ʵ��һ������, ��һ���ַ����е�ÿ���ո��滻�ɡ�%20��
void replaceSpace(char *str, int length);

// �����ת��������С��Ԫ��
int minNumberInRotateArray(vector<int> rotateArray) ;

// ����һ������ n, �������쳲��������еĵ� n ��
int Fibonacci(int n);

// 11. ����һ������,������������Ʊ�ʾ��1�ĸ���, ���и����ò����ʾ��
int NumberOf1(int n);

// �� base �� exponent �η�
double Power(double base, int exponent);

// ʹ�����е�����λ�������ǰ�벿��,���е�ż��λ������ĺ�벿��,����֤�����λ�ò������ı�
void reOrderArray(vector<int> &array);

// �����е�����k����㡣
ListNode* FindKthToTail(ListNode* pListHead, int k);

// ��ת�����, ���������ı�ͷ��
ListNode* ReverseList(ListNode* pHead);

// �ϲ�������������������,�������������
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);

// ���մ���������˳ʱ���˳�����δ�ӡ�������ÿһ������
vector<int> printMaxtrix(vector<vector<int> > matrix);

#endif /* SOLUTION_H_ */
