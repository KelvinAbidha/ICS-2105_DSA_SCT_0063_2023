#include <stdio.h>

// Function to sort an array using Bubble Sort
void sortArray(int* nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

const char* find_duplicate(int* nums, int size) {
    sortArray(nums, size);
    //Checking for duplicates
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return "True"; 
        }
    }
    return "False"; 
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    const char* result = find_duplicate(nums, size);
    printf("Contains duplicates: %s\n", result);
    
    return 0;
}
