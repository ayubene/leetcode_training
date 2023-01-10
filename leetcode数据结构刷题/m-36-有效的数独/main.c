
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
	int row[9][9] = { 0 };
	int col[9][9] = { 0 };
	int subbox[3][3][9] = { 0 };
	int tmp = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				tmp = board[i][j] - '0' - 1;
				row[i][tmp] += 1;
				col[j][tmp] += 1;
				subbox[i / 3][j / 3][tmp] += 1;
				if (row[i][tmp] > 1 || col[j][tmp] > 1 || subbox[i / 3][j / 3][tmp] > 1) {
					return false;
				}
			}
		}
	}
	return true;
}