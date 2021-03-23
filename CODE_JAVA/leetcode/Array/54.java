/*
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<Integer>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return ans;
        }
        int rows = matrix.length, columns = matrix[0].length;
        boolean[][] visited = new boolean[rows][columns];
        int total = rows * columns;
        int row = 0, column = 0;
        int[][] directions = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int directionIndex = 0;
        for (int i = 0; i < total; i++) {
            ans.add(matrix[row][column]);
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns
                    || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return ans;
    }
}
*/
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<Integer>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return ans;
        int r = matrix.length, c = matrix[0].length;
        int left = 0, right = c - 1, top = 0, bottom = r - 1;
        while (left <= right && top <= bottom) {
            for (int i = top, j = left; j <= right; j++) {
                ans.add(matrix[i][j]);
            }
            for (int i = top + 1, j = right; i <= bottom; i++) {
                ans.add(matrix[i][j]);
            }
            for (int i = bottom, j = right - 1; i > top && j >= left; j--) {
                ans.add(matrix[i][j]);
            }
            for (int i = bottom - 1, j = left; i > top; i--) {
                ans.add(matrix[i][j]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return ans;
    }
}