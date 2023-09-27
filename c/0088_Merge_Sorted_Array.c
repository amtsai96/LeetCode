// time: O(n), space: O(1)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1, j = n - 1, cur = m + n - 1;

    if (n == 0) return;
    while (cur >= 0)
    {
        if (i < 0) break;
        if (j < 0) break;
        nums1[cur--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }

    while (cur >= 0)
        if (i >= 0)
            nums1[cur--] = nums1[i--];
        else
            nums1[cur--] = nums2[j--];
}