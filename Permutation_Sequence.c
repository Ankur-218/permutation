#include <stdio.h>
#include <stdlib.h>

char* getPermutation(int n, int k) {
    // Create an array to hold the numbers
    int* nums = (int*)malloc(n * sizeof(int));
    int* factorial = (int*)malloc(n * sizeof(int));
    
    // Initialize the numbers and factorial array
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1; // Fill nums with 1 to n
        factorial[i] = (i == 0) ? 1 : factorial[i - 1] * i; // Compute factorials
    }

    // Convert k to zero-based index
    k--;
    char* result = (char*)malloc((n + 1) * sizeof(char)); // +1 for null-terminator
    result[n] = '\0'; // Null-terminate the result string

    // Build the k-th permutation
    for (int i = 0; i < n; i++) {
        int idx = k / factorial[n - 1 - i]; // Determine which number to use
        result[i] = nums[idx] + '0'; // Convert int to char
        // Shift remaining numbers left
        for (int j = idx; j < n - 1 - i; j++) {
            nums[j] = nums[j + 1];
        }
        k %= factorial[n - 1 - i]; // Update k
    }

    free(nums);
    free(factorial);
    return result;
}

int main() {
    int n = 4;
    int k = 9;

    char* permutation = getPermutation(n, k);
    printf("The %d-th permutation of the sequence 1 to %d is: %s\n", k, n, permutation);

    free(permutation);
    return 0;
}