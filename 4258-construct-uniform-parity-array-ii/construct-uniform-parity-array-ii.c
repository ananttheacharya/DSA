
bool uniformArray(int* nums, int numsSize) {
    int min_val = nums[0];
    bool has_odd = false;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        if (nums[i] % 2 != 0) {
            has_odd = true;
        }
    }

    
    if (min_val % 2 != 0) {
        return true;
    }

    
    return !has_odd;
}