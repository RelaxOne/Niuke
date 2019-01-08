#include "Solution.h"

/**
 * 1. 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
bool Find(int target, vector<vector<int> > array) {
	if (array.empty()) {
		return false;
	}
	int rows = array.size();
	int cols = array[0].size();
	int i = rows - 1, j = 0;
	while (i >= 0 && j < cols) {
		if (target < array[i][j])
			i--;
		else if (target > array[i][j])
			j++;
		else
			return true;
	}
	return false;
}

/**
 * 2. 实现一个函数，将一个字符串中的每个空格替换成“%20”
 */
void replaceSpace(char *str, int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ')
			count++;
	}

	for (int i = length; i >= 0; i--) {
		if (str[i] == ' ') {
			count--;
			str[i + count * 2] = '%';
			str[i + count * 2 + 1] = '2';
			str[i + count * 2 + 2] = '0';
		} else {
			str[i + count * 2] = str[i];
		}
	}
}

/**
 * 3.  输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
 */
vector<int> printListFromTailToHead(ListNode *head) {
	vector<int> result;
	stack<int> temp;

	ListNode *p = head;
	if (p == NULL)
		return {};
	while (p != NULL) {
		temp.push(p->val);
		p = p->next;
	}
	int len = temp.size();
	for (int i = 0; i < len; i++) {
		result.push_back(temp.top());
		temp.pop();
	}
	return result;
}

/**
 * 6. 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素
 */
int minNumberInRotateArray(vector<int> rotateArray) {
	int len = rotateArray.size();
	if (len == 0) {
		return 0;
	}
	for (int j = len - 1; j >= 0; j--) {
		if (rotateArray[j] < rotateArray[j - 1]) {
			return rotateArray[j];
		}
	}
	return rotateArray[0];
}

/**
 * 7. 输入一个整数n，请你输出斐波那契数列的第n项
 */
int Fibonacci(int n) {
	if (n == 0 || n == 1)
		return n;
	int a = 0, b = 1;
	int c;
	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

/**
 * 12. 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 */
double Power(double base, int exponent) {
	double result = 1.0;
	if (exponent == 0) {
		return 1;
	} else {
		int abs_exponent;
		exponent > 0 ? abs_exponent = exponent : abs_exponent = -exponent;
		for (int i = 0; i < abs_exponent; i++) {
			result *= base;
		}
		if (exponent < 0) {
			result = 1.0 / result;
		}
		return result;
	}
}

/**
 * 13. 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分,并保证其相对位置不发生改变
 */
void reOrderArray(vector<int> &array) {
	int i = 0, pos = 0, len = array.size();
	while (i < len) {
		if (array[i] % 2 == 1) {
			int temp = array[i];
			for (int k = i; k > pos; k--) {
				array[k] = array[k - 1];
			}
			array[pos] = temp;
			pos++;
		}
		i++;
	}
}
/**
 * 14. 输出该链表中倒数第k个结点。
 */
ListNode* FindKthToTail(ListNode* pListHead, int k) {
	if (pListHead == NULL || k == 0)
		return NULL;
	ListNode* p = pListHead;
	ListNode* result = NULL;
	int i = 1;
	while (p != NULL) {
		if (i == k)
			result = pListHead;
		else if (i > k)
			result = result->next;
		p = p->next;
		i++;
	}
	return result;
}

/**
 * 15. 反转链表后，输出新链表的表头。
 */
ListNode* ReverseList(ListNode* pHead) {
	if (pHead == NULL)
		return NULL;
	ListNode *p = pHead;
	ListNode *result = (ListNode*) malloc(sizeof(ListNode));
	result->next = NULL;

	while (p != NULL) {
		ListNode *t = p;
		p = p->next;
		t->next = result->next;
		result->next = t;
	}
	return result->next;
}

/**
 * 16. 合并两个单调递增的链表，并保持其递增性
 */
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {

}
