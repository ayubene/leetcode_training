/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//��ͨ�����ⷨ���Լ�д�ģ�
//ʵ���벻ͨ�����returnSize��ʲô��
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int sub;
	int *index;
	index = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize; i++)
	{
		sub = target - nums[i];
		index[0] = i;
		for (int j = i + 1; j < numsSize; j++)
		{
			if (sub == nums[j])
			{
				index[1] = j;
				*returnSize = 2;
				return index;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}
