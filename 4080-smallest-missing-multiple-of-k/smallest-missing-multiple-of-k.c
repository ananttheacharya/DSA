int missingMultiple(int* nums, int numsSize, int k) {
   
    int seen[101] = {0};

    for (int i = 0; i < numsSize; i++) {
        seen[nums[i]] = 1;
    }

    
    int multiple = k;

    while (multiple <= 100) {
        if (seen[multiple] == 0) {
            return multiple;
        }

        multiple += k;
    }

   
    return multiple;
}