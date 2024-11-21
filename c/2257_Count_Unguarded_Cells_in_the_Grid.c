// time: O(m*n), space: O(m*n)
void checkMark(int* map, bool* mark)
{
    if(*map == 1) // guarded
    {
        return;
    }
    else if(*map == 2) // guard
    {
        *mark = true;
    }
    else if(*map == 3) // wall
    {
        *mark = false;
    }
    else if(*mark)
    {
        *map = 1;
    }
}

int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    int total = (m * n) - guardsSize - wallsSize;
    int guard_map[m][n];
    bool mark = false;
    int i, j;
    memset(guard_map, 0, m*n*sizeof(int));
    // unguarded: 0, guarded: 1, guards: 2, walls: 3

    for(i = 0; i < guardsSize; i++)
    {
        guard_map[guards[i][0]][guards[i][1]] = 2;
    }
    for(i = 0; i < wallsSize; i++)
    {
        guard_map[walls[i][0]][walls[i][1]] = 3;
    }

    for(i = 0; i < m; i++)
    {
        mark = false;
        for(j = 0; j < n; j++) // left to right
        {
            checkMark(&guard_map[i][j], &mark);
        }
        mark = false;
        for(j = n - 1 ; j >= 0; j--) // right to left
        {
            checkMark(&guard_map[i][j], &mark);
        }
    }

    for(j = 0; j < n; j++)
    {
        mark = false;
        for(i = 0; i < m; i++) // up to down
        {
            checkMark(&guard_map[i][j], &mark);
        }
        mark = false;
        for(i = m - 1 ; i >= 0; i--) // down to up
        {
            checkMark(&guard_map[i][j], &mark);
        }
    }

    for(i = 0; i < m * n; i++)
    {
        total -= (guard_map[i/n][i%n] == 1 ? 1 : 0);
    }

    return total;
}