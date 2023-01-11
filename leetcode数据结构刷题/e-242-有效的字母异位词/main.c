int cmpfunc(const void* a, const void* b)
{
	return (*(char*)a - *(char*)b);
}
bool isAnagram(char* s, char* t) {
	if (strlen(s) > strlen(t) || strlen(s) < strlen(t)) {
		return false;
	}

	qsort(s, strlen(s), sizeof(char), cmpfunc);
	qsort(t, strlen(t), sizeof(char), cmpfunc);
	int ret = !strcmp(s, t);
	return ret;
}