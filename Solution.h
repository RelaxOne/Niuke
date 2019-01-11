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

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL),right(NULL){}
};

// 1. ��һ����ά������(ÿ��һά����ĳ�����ͬ),ÿһ�ж����մ����ҵ�����˳������, ÿһ�ж����մ��ϵ��µ�����˳������
// �����һ������, ����������һ����ά�����һ������, �ж��������Ƿ��и�����
bool Find(int target, vector<vector<int> > array);

// 2. ʵ��һ������, ��һ���ַ����е�ÿ���ո��滻�ɡ�%20��
void replaceSpace(char *str, int length);

// 3. ����һ������,������ֵ��β��ͷ��˳�򷵻�һ��ArrayList
vector<int> printListFromTailToHead(ListNode *head);

// 4. ���ݶ�������ǰ���������������ؽ����ö�����
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);

// 6. �����ת��������С��Ԫ��
int minNumberInRotateArray(vector<int> rotateArray) ;

// 7. ����һ������ n, �������쳲��������еĵ� n ��
int Fibonacci(int n);

// 11. ����һ������,������������Ʊ�ʾ��1�ĸ���, ���и����ò����ʾ��
int NumberOf1(int n);

// 12. �� base �� exponent �η�
double Power(double base, int exponent);

// 13. ʹ�����е�����λ�������ǰ�벿��,���е�ż��λ������ĺ�벿��,����֤�����λ�ò������ı�
void reOrderArray(vector<int> &array);

// 14. �����е�����k����㡣
ListNode* FindKthToTail(ListNode* pListHead, int k);

// 15. ��ת�����, ���������ı�ͷ��
ListNode* ReverseList(ListNode* pHead);

// 16. �ϲ�������������������,�������������
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);

// 18. �������Ķ������任ΪԴ�������ľ���
void Mirror(TreeNode *pRoot);

// 28. �����г��ִ�������һ�������
int MoreThanHalfNum_Solution(vector<int> numbers);

// 37. ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��
int Sum_Solution(int n);

#endif /* SOLUTION_H_ */
