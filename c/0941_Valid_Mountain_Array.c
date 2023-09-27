// time: O(n), space: O(1)
bool validMountainArray(int* arr, int arrSize){
    int i, max = 0;

    if (arrSize < 3) return false;

    for (i = 1; i < arrSize; i++)
        max = arr[max] < arr[i] ? i : max;

    if (max == 0 || max == arrSize - 1) return false;
    
    for (i = 0; i < max - 1; i++)
    {
        if (arr[i] >= arr [i + 1]) return false;
    }
    
    for (i = max; i < arrSize - 1; i++)
    {
        if (arr[i] <= arr [i + 1]) return false;
    }

    return true;
}