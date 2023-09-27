/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // time: O(n), space: O(1)
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *res = malloc(2 * sizeof(int));
    int sum, l = 0, r = numbersSize - 1;

    *returnSize = 2;

    while (l < r)
    {
        sum = numbers[l] + numbers[r];

        if (sum == target)
        {
            res[0] = l + 1;
            res[1] = r + 1;
            return res;
        }

        if (sum > target) r--;
        if (sum < target) l++;
    }

    return res;
}