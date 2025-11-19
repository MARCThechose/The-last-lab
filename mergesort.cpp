#include <iostream>

// Function prototypes
int* merge_sort( int * array, int size);
void merge(int * result, int* left, int Lsize, int* right, int Rsize);

// Magic number
#define datasize 7

int main()
{
    // // data
    // int data[] = {24, 23, 45543, 3215};
    // Test for odd data
    int data2[] = {24, 23, 45543, 3215, 32, 31, 33};
    // // Test for same values
    // int data3[] = {1, 1, 2, 2, 3, 4, 5};


    

    int* sorted_data = merge_sort(data2, datasize);
    
    // Display loop
    for (int i = 0; i < datasize; i++) std::cout << sorted_data[i] << " ";
    delete[] sorted_data;
}

int* merge_sort(int * array,int size)
{
    
    // Base-Case 
    // if array has 1 element then it is already at its simplest form (arranged)
    if (size < 2)
    {
    int* result = new int[1];
    result[0] = array[0];
    return result;
    }
    

    // Determine the middle
    int midpoint = size / 2;
   
    // create temporary arrays to contain both halves
    int* left_half = new int[midpoint];
    int* right_half = new int[size - midpoint];

    // loop to populate the Left half and stop at middle
    for (int i = 0; i < midpoint; i++) left_half[i] = array[i];

    // loop to populate the right half start at middle
    for (int i = midpoint; i < size; i++) right_half[i - midpoint] = array[i];

    // define a new starting point then call this again
    left_half = merge_sort(left_half, midpoint);
    right_half = merge_sort(right_half, size - midpoint);
    
    // Does the actual sorting
    merge(array, left_half, midpoint, right_half, size - midpoint);


    // Release used memory
    delete[] left_half;
    delete[] right_half;

    return array;
}

void merge(int * result, int* left, int Lsize, int* right, int Rsize)
{   
    // Indices for counting
    int ileft = 0; int iright = 0; int ioutput = 0;

    // Merge elements from both arrays while they both have elements
    while ( ileft < Lsize && iright < Rsize)
    {
        if (left[ileft] <= right[iright])
        {
            result[ioutput++] = left[ileft++];
        }
        else
        {
            result[ioutput++] = right[iright++];
        }
    }
    

    // Copy remaining elements from left array
    while (ileft < Lsize)result[ioutput++] = left [ileft++];

    // Copy remaining elements from right array
    while (iright < Rsize) result[ioutput++] = right [iright++];
}
