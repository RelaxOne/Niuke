#include "Solution.h"

/**
 * 1. ��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
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
 * 2. ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20��
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
 * 3.  ����һ��������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��
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
 * 6. ����һ���Ǽ�����������һ����ת�������ת�������СԪ��
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
 * 7. ����һ������n���������쳲��������еĵ�n��
 */
int Fibonacci(int n) {
	if (n == 0 || n == 1)
		return n;
	int a =0 ,b =1;
	int c;
	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}