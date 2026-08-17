class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (check(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean check(int i, int j, int idx, String word, char[][] board) {
        if (idx == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || word.charAt(idx) != board[i][j]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        boolean found = check(i + 1, j, idx + 1, word, board) ||
                check(i, j + 1, idx + 1, word, board) ||
                check(i - 1, j, idx + 1, word, board) ||
                check(i, j - 1, idx + 1, word, board);
        board[i][j] = temp;
        return found;
    }
}