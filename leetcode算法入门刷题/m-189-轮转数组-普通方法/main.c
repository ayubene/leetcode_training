void rotate(int* nums, int numsSize, int k) {
	int* ret = malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		ret[(i + k) % numsSize] = nums[i];
	}
	for (int j = 0; j < numsSize; j++) {
		nums[j] = ret[j];
	}
}