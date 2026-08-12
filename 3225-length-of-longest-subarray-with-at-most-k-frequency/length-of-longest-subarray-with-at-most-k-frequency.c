typedef struct {
    int key;
    int count;
    int used;
} HashNode;

int hash(int key, int size) {
    unsigned int x = (unsigned int)key;
    x ^= x >> 16;
    x *= 0x45d9f3b;
    x ^= x >> 16;
    return x % size;
}

int maxSubarrayLength(int* nums, int numsSize, int k) {
    int size = numsSize * 2 + 1;
    HashNode* table = calloc(size, sizeof(HashNode));

    int left = 0;
    int ans = 0;

    for (int right = 0; right < numsSize; right++) {
        int index = hash(nums[right], size);

        while (table[index].used && table[index].key != nums[right]) {
            index = (index + 1) % size;
        }

        if (!table[index].used) {
            table[index].key = nums[right];
            table[index].used = 1;
            table[index].count = 0;
        }

        table[index].count++;

        while (table[index].count > k) {
            int removeIndex = hash(nums[left], size);

            while (table[removeIndex].key != nums[left]) {
                removeIndex = (removeIndex + 1) % size;
            }

            table[removeIndex].count--;
            left++;
        }

        int len = right - left + 1;

        if (len > ans) {
            ans = len;
        }
    }

    free(table);
    return ans;
}