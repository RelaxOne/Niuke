#include "Solution.h"

/**
 * 1. 在一个二维数组中(每个一维数组的长度相同 ),每一行都按照从左到右递增的顺序排序, 每一列都按照从上到下递增的顺序排序
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
 * 2. 实现一个函数, 将一个字符串中的每个空格替换成“%20”
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
 * 3.  输入一个链表, 按链表值从尾到头的顺序返回一个ArrayList。
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
 * 4. 根据二叉树的前序遍历和中序遍历重建出该二叉树
 */
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	vector<int> left_pre, right_pre, left_vin, right_vin;
	if (pre.empty())
		return NULL;
	int root_val = pre[0];
	int len = vin.size();
	int index = 0;
	for (int i = 0; i < len; i++) {
		if (vin[i] == root_val) {
			index = i;
			break;
		}
		left_vin.push_back(vin[i]);
	}
	for (int i = 1; i < index + 1; i++) {
		left_pre.push_back(pre[i]);
	}

	for (int i = index + 1; i < len; i++) {
		right_vin.push_back(vin[i]);
		right_pre.push_back(pre[i]);
	}
	TreeNode *root = new TreeNode(root_val);
	root->val = root_val;

	root->left = reConstructBinaryTree(left_pre, left_vin);
	root->right = reConstructBinaryTree(right_pre, right_vin);

	return root;
}

/**
 * 6. 输入一个非减排序的数组的一个旋转, 输出旋转数组的最小元素
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
 * 7. 输出斐波那契数列的第n项
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

/*
 * 8. 跳台阶
 */
int JumpFloor(int number) {
	int *temp = new int[number + 1];
	temp[0] = 0;
	temp[1] = 1;
	temp[2] = 2;
	for (int i = 3; i <= number; i++) {
		temp[i] = temp[i - 1] + temp[i - 2];
	}
	return temp[number];
}

/**
 * 9. 变态跳台阶
 */
int JumpFloorII(int target) {
	if (target == 0)
		return 1;
	int count = 0;
	for (int i = 1; i < target; i++) {
		count += JumpFloor(target - i);
	}
	return count;
}

/**
 * 10. 矩形覆盖
 */
int RectCover(int target) {
	if (target <= 0)
		return 0;
	else if (target < 3)
		return target;
	else
		return RectCover(target - 1) + RectCover(target - 2);
}

/**
 * 11. 输入一个整数,输出该数二进制表示中1的个数, 其中负数用补码表示。
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
 * 13. 使得所有的奇数位于数组的前半部分, 所有的偶数位于数组的后半部分,并保证其相对位置不发生改变
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
 * 15. 反转链表后, 输出新链表的表头。
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
 * 16. 合并两个单调递增的链表,并保持其递增性
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

bool isSubtree(TreeNode* pRoot1, TreeNode * pRoot2) {
	if (!pRoot2)
		return true;
	if (!pRoot1)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;
	return isSubtree(pRoot1->left, pRoot2->left)
			&& isSubtree(pRoot1->right, pRoot2->right);
}

/**
 * 17. 树的子结构
 */
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (!pRoot1 || !pRoot2)
		return false;
	bool result = false;
	if (pRoot1->val == pRoot2->val)
		result = isSubtree(pRoot1, pRoot2);
	if (!result)
		result = HasSubtree(pRoot1->left, pRoot2);
	if (!result)
		result = HasSubtree(pRoot1->right, pRoot2);
	return result;
}

/**
 * 18. 将给定的二叉树变换为源二叉树的镜像
 */
void Mirror(TreeNode *pRoot) {
	if (pRoot == NULL)
		return;
	TreeNode *temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

/**
 * 19. 顺时针打印矩阵
 */
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> result;
	int row = matrix.size();
	if (row == 0)
		return result;
	int col = matrix[0].size();
	int left = 0, top = 0, bottom = row - 1, right = col - 1;
	while (left <= right && top <= bottom) {
		for (int i = left; i <= right; ++i)
			result.push_back(matrix[top][i]);
		for (int i = top + 1; i <= bottom; ++i)
			result.push_back(matrix[i][right]);
		if (top != bottom)
			for (int i = right - 1; i >= left; --i)
				result.push_back(matrix[bottom][i]);
		if (left != right)
			for (int i = bottom - 1; i > top; --i)
				result.push_back(matrix[i][left]);
		left++;
		right--;
		top++;
		bottom--;
	}
	return result;
}

/**
 * 21. 栈的压入、弹出序列
 */
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	stack<int> stav;
	for (int i = popV.size() - 1; i >= 0; i--)
		stav.push(popV[i]);

	stack<int> sta;
	int index = 0;
	for (int i = 0; i < pushV.size(); i++) {
		sta.push(pushV[i]);
		if (!sta.empty()) {
			while (!sta.empty() && sta.top() == stav.top()) {
				stav.pop();
				sta.pop();
			}
		}
	}
	return sta.empty();
}

/**
 * 28. 数组中出现次数超过一半的数字
 */
int MoreThanHalfNum_Solution(vector<int> numbers) {
	int len = numbers.size();
	vector<int> arr, arr_index;
	for (int i = 0; i < len; i++) {
		int number = numbers[i];
		bool flag = false;
		int index = -1;
		int l = arr.size();
		for (int j = 0; j < l; j++) {
			if (arr[j] == number) {
				flag = true;
				index = j;
				break;
			}
		}
		if (!flag) {
			arr.push_back(number);
			arr_index.push_back(1);
		} else {
			arr_index[index] += 1;
		}
	}
	int arr_size = arr_index.size();
	for (int i = 0; i < arr_size; i++) {
		if (arr_index[i] > len / 2)
			return arr[i];
	}
	return 0;
}
/**
 * 37. 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 */
int Sum_Solution(int n) {
	bool a[n][n + 1];	// 声明一个 n*n-1  的  bool 类型的数组
	return sizeof(a) >> 1;
}
