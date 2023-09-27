/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 // time: O(n^2), space: O(n^2)
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int m = gridSize, n = *gridColSize;

    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    k %= (m * n);

    if (k == 0) return grid;
    int *res = malloc(m * n * sizeof(int));
    int newVal, newRow, newCol;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            newVal = ((i * n + j) + k) % (m * n); // shift k steps
            res[newVal] = grid[i][j];
        }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            newVal = (i * n + j) % (m * n);
            grid[i][j] = res[newVal];
        }
    
    free(res);
    return grid;
}