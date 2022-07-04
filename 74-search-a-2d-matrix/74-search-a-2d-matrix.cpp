class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, col, t1, t2, rows = matrix.size(), cols = matrix[0].size();
		t1 = 0, t2 = rows - 1;
		while (t1 <= t2) {
			row = (t1 + (t2 - t1) / 2);
			if (target > matrix[row][cols-1])
				t1 = row + 1;
			else if (target < matrix[row][0])
				t2 = row - 1;
			else
				break;
		}
		t1 = 0, t2 = cols-1;
		while (t1 <= t2) {
			col = (t1 + (t2 - t1) / 2);
			if (target > matrix[row][col])
				t1 = col + 1;
			else if (target < matrix[row][col])
				t2 = col - 1;
			else if (target == matrix[row][col])
				return true;
		}
        cout<<row<<" "<<col;
		return false;
    }
};