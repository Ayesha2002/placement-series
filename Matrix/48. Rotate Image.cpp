class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Rotate the matrix by swapping elements in groups of four
        for (int row = 0; row < n / 2; row++) {
            for (int col = row; col < n - row - 1; col++) {
                // Save the top-left value
                int temp = matrix[row][col];

                // Move bottom-left to top-left
                matrix[row][col] = matrix[n - 1 - col][row];

                // Move bottom-right to bottom-left
                matrix[n - 1 - col][row] = matrix[n - 1 - row][n - 1 - col];

                // Move top-right to bottom-right
                matrix[n - 1 - row][n - 1 - col] = matrix[col][n - 1 - row];

                // Move top-left (saved) to top-right
                matrix[col][n - 1 - row] = temp;
            }
        }
    }
};
