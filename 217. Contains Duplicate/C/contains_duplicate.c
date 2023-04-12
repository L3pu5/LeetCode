#include <stdbool.h>


//Faster QSort?
int comparator(const void* a, const void* b){
    return ( *(const int*)a- *(const int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
    //Sort from smallest to largest
    qsort(nums, numsSize, sizeof(int), &comparator);
    //Read with a window of 2.
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i-1]){
            return 1;
        }
    }
    return 0;
}

//Pasing by address seems faster?


//Using Qsort
// Reference: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm

int comp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i+1]) return true;
    }
    return false;
}

//Qsort, this was too slow with a window of 2.
int comparator(const void* a, const void* b){
    return ( *(int*)a- *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
    //Sort from smallest to largest
    qsort(nums, numsSize, sizeof(int), comparator);
    //Read with a window of 2.
    for(int i = 1; i < numsSize, i += 2;){
        if(nums[i] == nums[i=1]){
            return true;
        }
    }
    return false;
}



//This is too slow
bool containsDuplicate(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        int currentNumber = nums[i];
        for(int j = i+1; j < numsSize; j++){
            if(nums[j] == currentNumber){
                return true;
            }
        }
    }
    return false;
}

//Define an array to keep track of individually accessed items on the heap (too slow).
bool containsDuplicate(int* nums, int numsSize){
    int* tempArray = calloc(numsSize, sizeof(int));
    int tempArraySz = 0;

    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < tempArraySz; j++){
            if(tempArray[j] == nums[i]){
                free(tempArray);
                return true;
            }
        }
        tempArray[tempArraySz] = nums[i];
        tempArraySz++;
    }
    free(tempArray);
    return false;
}