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
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

// 1. 在一个二维数组中(每个一维数组的长度相同),每一行都按照从左到右递增的顺序排序, 每一列都按照从上到下递增的顺序排序。
// 请完成一个函数, 输入这样的一个二维数组和一个整数, 判断数组中是否含有该整数
bool Find(int target, vector<vector<int> > array);

// 2. 实现一个函数, 将一个字符串中的每个空格替换成“%20”
void replaceSpace(char *str, int length);

// 3. 输入一个链表,按链表值从尾到头的顺序返回一个ArrayList
vector<int> printListFromTailToHead(ListNode *head);

// 4. 根据二叉树的前序遍历和中序遍历重建出该二叉树
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);

// 6. 输出旋转数组中最小的元素
int minNumberInRotateArray(vector<int> rotateArray);

// 7. 输入一个整数 n, 请你输出斐波那契数列的第 n 项
int Fibonacci(int n);

// 8. 跳台阶
int JumpFloor(int number);

// 9. 变态跳台阶
int JumpFloorII(int number);

// 10. 矩形覆盖
int RectCover(int number);

// 11. 输入一个整数,输出该数二进制表示中1的个数, 其中负数用补码表示。
int NumberOf1(int n);

// 12. 求 base 的 exponent 次方
double Power(double base, int exponent);

// 13. 使得所有的奇数位于数组的前半部分,所有的偶数位于数组的后半部分,并保证其相对位置不发生改变
void reOrderArray(vector<int> &array);

// 14. 链表中倒数第k个结点。
ListNode* FindKthToTail(ListNode* pListHead, int k);

// 15. 反转链表后, 输出新链表的表头。
ListNode* ReverseList(ListNode* pHead);

// 16. 合并两个单调递增的链表,并保持其递增性
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);

// 17. 判断一棵树是否是另一棵树的子树
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);

// 18. 将给定的二叉树变换为源二叉树的镜像
void Mirror(TreeNode *pRoot);

// 19. 顺时针打印矩阵
vector<int> printMatrix(vector<vector<int> > matrix);

// 21. 栈的压入、弹出序列
bool IsPopOrder(vector<int> pushV, vector<int> popV);

// 22. 从上至下打印二叉树
vector<int> PrintFromTopToBottom(TreeNode *root);

// 23. 二叉树的后序遍历序列
bool VerifySquenceOfBST(vector<int> sequence);

// 24. 二叉树和为某一值的路径
vector<vector<int> > FindPath(TreeNode* root, int expectNumber);

// 25. 复杂链表的复制
RandomListNode* Clone(RandomListNode* pHead);

// 27. 字符串的全排列
vector<string> Permutation(string str);

// 28. 数组中出现次数超过一半的数字
int MoreThanHalfNum_Solution(vector<int> numbers);

//29. 最小的 K 个数
vector<int> GetLeastNumbers_Solution(vector<int> input, int k);

// 30. 连续子数组的最大和
int FindGreatestSumOfSubArray(vector<int> array);

//31. 整数中 1 出现的次数
int NumberOf1Between1AndN_Solution(int n);

//32. 把数组排成最小的数
string PrintMinNumber(vector<int> numbers);

//33. 丑数
int GetUglyNumber_Solution(int index);

//34. 第一个只出现一次的字符
int FirstNotRepeatingChar(string str);

//36. 两个链表的第一个公共节点
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);

//37. 数字在排序数组中出现的次数
int GetNumberOfK(vector<int> data, int k);

//38. 二叉树的深度
int TreeDepth(TreeNode *pRoot);

// 37. 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
int Sum_Solution(int n);

#endif /* SOLUTION_H_ */
