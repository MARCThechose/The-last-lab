#include <iostream>
#include <cmath>

int* merge_sort( int * array, int size);
void merge(int * result, int* left, int Lsize, int* right, int right_size);


int main()
{
    int data[] = {24, 23, 45543, 3215};
    int* sorted_data = merge_sort(data, 4);
    
    for (int i = 0; i < 4; i++)
    {
        std::cout << sorted_data[i] << " ";
    }

}
int* merge_sort(int * array,int size)
{
    // TODO: implement a base case that automatically returns data 
    // sizeof(array)/sizeof(array[0]);
   // calculate data length
    if (size < 2) return array;
    
    int midpoint = floor(size / 2);
   
    int* left_half = new int[midpoint];
    int* right_half = new int[size - midpoint];

    for (int i = 0; i < midpoint; i++) 
    {
        left_half[i] = array[i];
    
    }
    for (int i = midpoint; i < size; i++) 
    {
        right_half[i - midpoint] = array[i];
    }

    left_half = merge_sort(left_half, midpoint);
    right_half = merge_sort(right_half, size - midpoint);
    
    merge (array, left_half, midpoint, right_half, size - midpoint);

    delete[] left_half;
    delete[] right_half;

    return array;
}

void merge(int * result, int* left, int Lsize, int* right, int Rsize)
{
    int i = 0; int j = 0; int k = 0;


    while ( i < Lsize && j < Rsize) result[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

    while (i < Lsize) result[k++] = left [i++];

    while (j < Rsize) result[k++] = right [j++];
}
