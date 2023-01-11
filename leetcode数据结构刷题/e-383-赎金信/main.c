bool canConstruct(char* ransomNote, char* magazine) {
	if (strlen(ransomNote) > strlen(magazine)) {
		return false;
	}
	int str[26] = { 0 };
	for (int i = 0; magazine[i] != '\0'; i++) {
		str[magazine[i] - 'a'] += 1;
	}
	for (int i = 0; ransomNote[i] != '\0'; i++) {
		str[ransomNote[i] - 'a'] -= 1;
		if (str[ransomNote[i] - 'a'] < 0) {
			return false;
		}
	}
	return true;
}