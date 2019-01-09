#include "Solution.h"

/**
 * 1. ��һ����ά������(ÿ��һά����ĳ�����ͬ ),ÿһ�ж����մ����ҵ�����˳������, ÿһ�ж����մ��ϵ��µ�����˳������
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
 * 2. ʵ��һ������, ��һ���ַ����е�ÿ���ո��滻�ɡ�%20��
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
 * 3.  ����һ������, ������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��
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
 * 4. ���ݶ�������ǰ���������������ؽ����ö�����
 */
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	vector<int> left_pre, right_pre, left_vin, right_vin;
	if(pre.empty())
		return NULL;
	int root_val = pre[0];
	int len = vin.size();
	int index = 0;
	for(int i = 0; i < len; i++){
		if(vin[i] == root_val){
			index = i;
			break;
		}
		left_vin.push_back(vin[i]);
	}
	for(int i = 1; i < index + 1; i++){
		left_pre.push_back(pre[i]);
	}

	for(int i = index + 1; i < len; i++){
		right_vin.push_back(vin[i]);
		right_pre.push_back(pre[i]);
	}
	TreeNode *root = new TreeNode(root_val);
	root->val = root_val;

	root->left = reConstructBinaryTree(left_pre,left_vin);
	root->right = reConstructBinaryTree(right_pre,right_vin);

	return root;
}

/**
 * 6. ����һ���Ǽ�����������һ����ת, �����ת�������СԪ��
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
 * 7. ���쳲��������еĵ�n��
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
 * 11. ����һ������,������������Ʊ�ʾ��1�ĸ���, ���и����ò����ʾ��
 */
int NumberOf1(int n) {
	int count = 0;
//	unsigned int flag = 1;
//	while(flag){
//		if(n & flag)
//			count++;
//		flag = flag << 1;
//	}

	while (n != 0) {
		count++;
		n = n & (n - 1);
	}
	return count;
}

/**
 * 12. ����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
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
 * 13. ʹ�����е�����λ�������ǰ�벿��, ���е�ż��λ������ĺ�벿��,����֤�����λ�ò������ı�
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
 * 14. ����������е�����k����㡣
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
 * 15. ��ת�����, ���������ı�ͷ��
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
 * 16. �ϲ�������������������,�������������
 */
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	ListNode *result = (ListNode*) malloc(sizeof(ListNode));
	result->next = NULL;

	ListNode *p = result;

	ListNode *p1 = pHead1, *p2 = pHead2;

	ListNode *temp;

	while (p1 != NULL && p2 != NULL) {
		if (p1->val <= p2->val) {
			temp = p1;
			p1 = p1->next;
		} else {
			temp = p2;
			p2 = p2->next;
		}
		temp->next = p->next;
		p->next = temp;
		p = p->next;
	}
	if (p1 != NULL)
		p->next = p1;
	else if (p2 != NULL)
		p->next = p2;
	return result->next;
}
/**
 * 18. �������Ķ������任ΪԴ�������ľ���
 */
void Mirror(TreeNode *pRoot){
	if(pRoot == NULL)
		return;
	TreeNode *temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

/**
 * 37. ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��
 */
int Sum_Solution(int n) {
	bool a[n][n+1];	// ����һ�� n*n-1  ��  bool ���͵�����
	return sizeof(a)>>1;
}

