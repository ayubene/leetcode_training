//��д��ʱ�ո��Ӷȶ��Ƚϲ���˱��˵�д���ź�һ��

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
			
			//right = mid;�Ǳ��˵�д��
			right = mid;
			mid = (right - left) / 2 + left;
		}
		else
		{
			//if (isBadVersion(mid + 1)) return mid + 1;
			left = mid + 1;
			mid = (right - left) / 2 + left;
		}
		//����Ǳ��˵�д��
		if (isBadVersion(mid) == 1 && isBadVersion(mid - 1) == 0)
			return mid;
	}
	return -1;
}