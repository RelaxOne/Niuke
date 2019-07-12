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
 * 22. 从上至下打印二叉树
 */
vector<int> PrintFromTopToBottom(TreeNode *root) {
	queue<TreeNode *> queue;
	vector<int> result;
	if (root == nullptr)
		return result;
	queue.push(root);
	while (!queue.empty()) {
		TreeNode* temp = queue.front();
		if (temp->left != nullptr)
			queue.push(temp->left);
		if (temp->right != nullptr)
			queue.push(temp->right);
		result.push_back(temp->val);
		queue.pop();
	}
	return result;
}

/**
 * 23. 判断一个序列是否是某二叉树的后序遍历序列
 */
bool VerifySquenceOfBST(vector<int> sequence) {

}

void iteator(vector<vector<int>> &result, vector<int> &temp, int target,
		TreeNode* node) {
	if (node == nullptr || target < 0)
		return;
	temp.push_back(node->val);
	if (target - node->val == 0 && node->left == nullptr
			&& node->right == nullptr)
		result.push_back(temp);
	iteator(result, temp, target - node->val, node->left);
	iteator(result, temp, target - node->val, node->right);
	if (!temp.empty())
		temp.pop_back();
}

/**
 * 24. 二叉树和为某一值的路径
 */
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int> > result;
	vector<int> temp;
	iteator(result, temp, expectNumber, root);
	return result;
}

/**
 * 25. 复制链表的复制
 */
RandomListNode* Clone(RandomListNode* pHead) {
	if (pHead == nullptr)
		return nullptr;
	RandomListNode *p = pHead;
	while (p != nullptr) {
		RandomListNode *cloneNode = new RandomListNode(p->label);
		cloneNode->next = p->next;
		p->next = cloneNode;
		p = cloneNode->next;
	}
	p = pHead;
	while (p != nullptr) {
		p->next->random = p->random == nullptr ? nullptr : p->random->next;
		p = p->next->next;
	}
	p = pHead;
	RandomListNode* result = pHead->next;
	while (p != nullptr) {
		RandomListNode *pClone = p->next;
		p->next = pClone->next;
		pClone->next = pClone->next == nullptr ? nullptr : pClone->next->next;
		p = p->next;
	}
	return result;
}

/**
 * 27. 字符串的全排列
 */
vector<string> Permutation(string str) {
	vector<string> result;
	if (str == "")
		return result;
	sort(str.begin(), str.end());
	result.push_back(str);
	while (next_permutation(str.begin(), str.end())) {
		result.push_back(str);
	}
	return result;
}

/**
 * 28. 数组中出现次数超过一半的数字
 */
int MoreThanHalfNum_Solution(vector<int> numbers) {
	int len = numbers.size();
	if (len == 0)
		return 0;
	int num = numbers[0], count = 1;
	for (int i = 0; i < len; i++) {
		if (num == numbers[i])
			count++;
		else
			count--;
		if (count == 0) {
			num = numbers[i];
			count = 1;
		}
	}
	count = 0;
	for (int i = 0; i < len; i++) {
		if (num == numbers[i])
			count++;
	}
	if (count > len >> 1)
		return num;
	return 0;
}

/**
 * 29. 求最小的 K 个数
 */
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> result;
	if (input.size() < k)
		return result;
	sort(input.begin(), input.end());
	for (int i = 0; i < k; i++)
		result.push_back(input[i]);
	return result;

}

/**
 * 30. 连续子数组的最大和
 */
int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.size() == 0)
		return 0;
	int sum = array[0], tempsum = array[0];
	for (int i = 1; i < array.size(); i++) {
		tempsum = tempsum < 0 ? array[i] : tempsum + array[i];
		sum = tempsum > sum ? tempsum : sum;
	}
	return sum;
}

int getnum1ofN(int n) {
	int count = 0;
	while (n) {
		if (n % 10 == 1)
			count++;
		n /= 10;
	}
	return count;
}

/**
 * 31. 整数中 1 出现的次数
 */
int NumberOf1Between1AndN_Solution(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += getnum1ofN(i);
	}
	return result;
}

static bool compareNum(int num1, int num2) {
	string str1 = to_string(num1);
	string str2 = to_string(num2);
	if (str1 + str2 < str2 + str1)
		return true;
	else
		return false;
}

/**
 * 32. 把数组排成最小的数
 */
string PrintMinNumber(vector<int> numbers) {
	sort(numbers.begin(), numbers.end(), compareNum);
	string result = "";
	for (int i = 0; i < numbers.size(); i++) {
		result += to_string(numbers[i]);
	}
	return result;
}

/**
 * 33. 丑数
 */
int GetUglyNumber_Solution(int index) {
	if (index < 1)
		return 0;
	int *result = new int[index];
	result[0] = 1;
	int i = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	while (i < index) {
		int temp = min(result[i2] * 2, min(result[i3] * 3, result[i5] * 5));
		if (temp == result[i2] * 2)
			i2++;
		if (temp == result[i3] * 3)
			i3++;
		if (temp == result[i5] * 5)
			i5++;
		result[i++] = temp;
	}
	return result[index - 1];
}

/**
 * 34. 第一个只出现一次的字符
 */
int FirstNotRepeatingChar(string str) {
	map<char, int> strmap;
	for (auto i = 0; i < str.size(); i++) {
		if (strmap.find(str[i]) == strmap.end()) {
			strmap.insert(pair<char, int>(str[i], i));
		} else if (strmap[str[i]] == -1) {
			continue;
		} else {
			strmap[str[i]] = -1;
		}
	}
	auto result = str.size() + 1;
	for (auto k : strmap) {
		if (k.second == -1)
			continue;
		result = (k.second < result) ? k.second : result;
	}
	return result == str.size() + 1 ? -1 : result;
}

/**
 * 36. 两个链表的第一个公共节点
 */
ListNode* FindFirsCommonNode(ListNode* pHead1, ListNode* pHead2) {
	ListNode* p1 = pHead1, *p2 = pHead2;
	int len1 = 0, len2 = 0;
	while (p1 != nullptr) {
		p1 = p1->next;
		len1++;
	}
	while (p2 != nullptr) {
		p2 = p2->next;
		len2++;
	}
	if (p1 != p2)
		return nullptr;
	p1 = pHead1;
	p2 = pHead2;
	if (len1 > len2) {
		for (int i = 0; i < len1 - len2; i++) {
			p1 = p1->next;
		}
	} else {
		for (int i = 0; i < len2 - len1; i++) {
			p2 = p2->next;
		}
	}
	while (p1 != nullptr && p2 != nullptr) {
		if (p1 == p2)
			return p1;
		p1 = p1->next;
		p2 = p2->next;
	}
	return nullptr;
}

/**
 * 37. 数字在排序数组中出现的次数
 */
int GetNumberOfK(vector<int> data, int k) {
	auto result = equal_range(data.begin(), data.end(), k);
	return result.second - result.first;
}

/**
 * 38. 二叉树的深度
 */
int TreeDepth(TreeNode *pRoot) {
	int depth = 0;
	if (pRoot == nullptr)
		return depth;
	queue<TreeNode*> que;
	que.push(pRoot);
	while (!que.empty()) {
		depth++;
		int size = que.size();
		int index = 0;
		while (index < size) {
			index++;
			TreeNode* temp = que.front();
			if (temp->left)
				que.push(temp->left);
			if (temp->right)
				que.push(temp->right);
			que.pop();
		}
	}
	return depth;
}

/**
 * 39. 平衡二叉树
 */
bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == nullptr)
		return true;
	bool flag = IsBalanced_Solution(pRoot->left)
			&& IsBalanced_Solution(pRoot->right);
	int leftDepth = TreeDepth(pRoot->left);
	int rightDepth = TreeDepth(pRoot->right);
	if (abs(leftDepth - rightDepth) <= 1 && flag)
		return true;
	return false;
}

/**
 * 40. 数组中只出现一次的数字
 */
void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {

}

/**
 * 41. 和为 S 的连续正数序列
 */
vector<vector<int> > FindContinousSequence(int sum) {
	vector<vector<int>> result;
	int left = 1, right = 1;
	int tempsum = 1;
	while (left <= right) {
		right++;
		tempsum += right;
		while (tempsum > sum) {
			tempsum -= left;
			left++;
		}
		if (tempsum == sum && left != right) {
			vector<int> temp;
			for (int i = left; i <= right; i++)
				temp.push_back(i);
			result.push_back(temp);
		}
	}
	return result;
}

/**
 * 42. 和为 S 的两个数字
 */
vector<int> FindNumberWithSum(vector<int> array, int sum) {
	int left = 0, right = array.size() - 1;
	vector<int> result;
	while (left < right) {
		int tempsum = array[left] + array[right];
		if (tempsum > sum) {
			right--;
		} else if (tempsum == sum) {
			result.push_back(array[left]);
			result.push_back(array[right]);
			break;
		} else {
			left++;
		}
	}
	return result;
}

/**
 * 43. 左旋字符串
 */
string LeftRotateString(string str, int n) {
	string result;
	for (int i = n; i < str.length(); i++) {
		result += str[i];
	}
	for (int i = 0; i < n; i++) {
		result += str[i];
	}
	return result;
}

vector<string> split(string str, const string pattern) {
	vector<string> result;
	string::size_type pos;
	str += pattern;
	for (int i = 0; i < str.size(); i++) {
		pos = str.find(pattern, i);
		if (pos < str.size()) {
			string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

/**
 * 44. 翻转单词顺序列
 */
string ReverseSentence(string str) {
	auto strs = split(str, " ");
	string result = "";
	for (int i = strs.size() - 1; i > 0; i--) {
		result += strs[i];
		result += " ";
	}
	result += strs[0];
	return result;
}

/**
 * 45. 扑克牌顺子
 */
bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5)
		return false;
	sort(numbers.begin(), numbers.end());
	int num0 = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0) {
			num0++;
		} else {
			if (i == 0 || numbers[i - 1] == 0)
				continue;
			if (numbers[i - 1] == numbers[i])
				return false;
			else if ((numbers[i] - numbers[i - 1]) > 1) {
				num0 -= numbers[i] - numbers[i - 1] - 1;
			}
		}
	}
	if (num0 < 0)
		return false;
	return true;

}

/**
 * 46. 孩子们的游戏(圆圈中最后剩下的数)
 */
int LastRemaining_Solution(int n, int m) {
	if (n == 0)
		return -1;
	int s = 0;
	for (int i = 2; i <= n; i++) {
		s = (s + m) % i;
	}
	return s;
}

/**
 * 47. 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 */
int Sum_Solution(int n) {
	bool a[n][n + 1];	// 声明一个 n*n-1  的  bool 类型的数组
	return sizeof(a) >> 1;
}

/**
 * 48. 不用加减乘除做加法
 */
int Add(int num1, int num2) {

}

/**
 * 49. 字符串转整数
 */
int StrToInt(string str) {
	if (str.size() == 0)
		return 0;
	int result = 0;
	int value = str[0] - '0';
	if (value >= 0 && value <= 9) {
		result = result * 10 + value;
	} else if (str[0] != '+' && str[0] != '-')
		return 0;
	for (int i = 1; i < str.size(); i++) {
		int value = str[i] - '0';
		if (value >= 0 && value <= 9) {
			result = result * 10 + value;
		} else
			return 0;
	}
	return str[0] == '-' ? -result : result;
}

/**
 * 50. 数组中重复的数字
 */
bool duplicate(int numbers[], int length, int* duplication) {
	bool *temp = new bool[length];
	for (int i = 0; i < length; i++)
		temp[i] = false;
	for (int i = 0; i < length; i++) {
		int value = numbers[i];
		if (temp[value] == true) {
			duplication[0] = value;
			return true;
		}
		temp[value] = true;
	}
	return false;
}

/**
 * 51.构建乘积数组
 */
vector<int> multiply(const vector<int> & A) {
	int size = A.size();
	vector<int> result(size, 1);
	for (int i = 1; i < size; i++) {
		result[i] = result[i - 1] * A[i - 1];
	}
	vector<int> temp(size, 1);
	for (int i = size - 2; i >= 0; i--) {
		temp[i] = temp[i + 1] * A[i + 1];
	}
	for (int i = 0; i < size; i++) {
		result[i] = result[i] * temp[i];
	}
	return result;
}

/**
 * 52. 正则表达式匹配
 */
bool match(char* str, char* pattern) {

}

/**
 * 53. 表示数值的字符串
 */
bool isNumberic(char* string) {
	int len = strlen(string);
	bool hasE = false, hasD = false;
	for (int i = 0; i < len; i++) {

	}
}
/**
 * 55. 链表中环的入口节点
 */
ListNode* EntryNodeOfLoop(ListNode *pHead) {
	if (pHead == nullptr || pHead->next == nullptr
			|| pHead->next->next == nullptr)
		return nullptr;
	ListNode* fast = pHead->next->next, *slow = pHead->next;
	while (fast != slow) {
		if (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		} else
			return nullptr;
	}
	fast = pHead;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

/**
 * 56. 删除链表中重复的节点
 */
ListNode* deleteDuplication(ListNode* pHead) {
	if(!pHead->next)
		return pHead;
	ListNode* pre = pHead, *p = pHead->next;
	while (p && p->next) {
		if(pre->val != p->val && p->val != p->next->val)

		p = p->next;
	}

}
