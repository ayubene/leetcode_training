int searchInsert(int* nums, int numsSize, int target) {
	int left = 0;
	int right = numsSize - 1;
	int mid = (right - left) / 2 + left;
	while (right >= left)
	{
		if (target == nums[mid])
		{
			return mid;
		}
		else if (target > nums[mid])
		{
			left = mid + 1;
			mid = (right - left) / 2 + left;
		}
		else
		{
			right = mid - 1;
			mid = (right - left) / 2 + left;
		}
	}
	return mid;
}