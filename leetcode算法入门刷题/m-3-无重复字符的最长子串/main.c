int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int lengthOfLongestSubstring(char* s) {
	int ch[128] = { 0 };
	int start = 0, end = 0, ans = 0;
	int index = -1;

	for (int i = 0; i < strlen(s); i++) {
		index = s[i] - '\0';
		if (ch[index] != 0) {
			start = max(start, ch[index]);
			ch[index] = i + 1;
			ans = max(end - start + 1, ans);
		}
		else {
			ch[index] = i + 1;
			ans = max(end - start + 1, ans);
			//end+=1;
		}
		end += 1;
	}
	return ans;
}