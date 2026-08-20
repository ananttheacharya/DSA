/**
 * Note: The returned array must be dynamically allocated.
 * LeetCode will handle the memory.
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    int *arr1 = (int *)malloc(numsSize * sizeof(int));
    int *arr2 = (int *)malloc(numsSize * sizeof(int));
    int *result = (int *)malloc(numsSize * sizeof(int));

    int size1 = 1;
    int size2 = 1;

    arr1[0] = nums[0];
    arr2[0] = nums[1];


    for (int i = 2; i < numsSize; i++) {
        if (arr1[size1 - 1] > arr2[size2 - 1]) {
            arr1[size1++] = nums[i];
        } else {
            arr2[size2++] = nums[i];
        }
    }


    int k = 0;

    for (int i = 0; i < size1; i++) {
        result[k++] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        result[k++] = arr2[i];
    }

    *returnSize = numsSize;

    free(arr1);
    free(arr2);

    return result;
}