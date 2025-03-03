#include "../headers/common.h"
#include "../headers/localshared.h"

int testcallocinteger(int countOfIntegersNeeded)
{
    int *arr = calloc(countOfIntegersNeeded, sizeof(int));  // Allocates memory for 10 integers and initializes all to 0.
    if (arr == NULL) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }
    
    // arr now points to an array of 10 ints, all set to zero.
    for (int i = 0; i < countOfIntegersNeeded; i++) {
        printf("before assignment [%d]: %d -- ", i, arr[i]);
        
        arr[i] = i;
        printf("after: %d \n", arr[i]);
    }
    
    free(arr);
}