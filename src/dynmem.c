#include "../headers/common.h"
#include "../headers/localshared.h"

int testcallocinteger(int countOfIntegersNeeded)
{

    int *arr = calloc(countOfIntegersNeeded, sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed.");
        return EXIT_FAILURE;
    }
    
    for (int i = 0; i < countOfIntegersNeeded; i++) {
        printf("init [%d]: %d -- ", i, arr[i]);
        
        arr[i] = i;
        printf("set: %d \n", arr[i]);
    }
    
    arr = realloc(arr, 2 * countOfIntegersNeeded * sizeof(int));  // Resize the array 
    if (arr == NULL) {
        perror("Memory reallocation failed.");
        return EXIT_FAILURE;
    }

    // Note: Just as is the case with malloc, realloc doesn't perform any initialization. 
    // Any memory past the memory that was present in the original block is left uninitialized.
    // This means that the values in the new memory are indeterminate.
    printf("--- after realloc to twice the size ---\n");
    for (int i = 0; i < 2 * countOfIntegersNeeded; i++) {
        printf("init [%d]: %d -- ", i, arr[i]);
        
        arr[i] = i;
        printf("set: %d \n", arr[i]);
    }

    // Free the allocated memory
    // Note: free(NULL) is guaranteed to be safe. From section 7.20.3.2/2 of the C99 standard -- no need to check for null here
    free(arr);
}