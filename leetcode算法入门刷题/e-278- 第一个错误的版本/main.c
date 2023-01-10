//我写的时空复杂度都比较差，用了别人的写法才好一点

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
	int left = 1;
	int right = n;
	int mid = (right - left) / 2 + left;
	while (right >= left)
	{
		if (isBadVersion(mid))
		{
			//if (!isBadVersion(mid - 1)) return mid;
			//right = mid - 1;
			
			//right = mid;是别人的写法
			right = mid;
			mid = (right - left) / 2 + left;
		}
		else
		{
			//if (isBadVersion(mid + 1)) return mid + 1;
			left = mid + 1;
			mid = (right - left) / 2 + left;
		}
		//这个是别人的写法
		if (isBadVersion(mid) == 1 && isBadVersion(mid - 1) == 0)
			return mid;
	}
	return -1;
}