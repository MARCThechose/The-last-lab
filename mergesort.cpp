#include <iostream>
#include <cmath>

int* merge(int * array,int size)
{
    // TODO: implement a base case that automatically returns data
    int length_array = size; 
    // sizeof(array)/sizeof(array[0]);
   // calculate data length
    if (length_array < 2) return array;
    
    int midpoint = floor(length_array / 2);
   
    int*left_half = new int[midpoint];
    int*right_half = new int[length_array - midpoint];

    for (int i = 0; i < midpoint; i++) 
    {
        left_half[i] = array[i];
    
    }
    for (int i = midpoint; i < length_array; i++) 
    {
        right_half[i - midpoint] = array[i];
    }

    left_half = merge(left_half, midpoint);
    right_half = merge(right_half, midpoint);
    
    //merge(left_half, right_half, data)
    for (int i = 0; i < length_array; i++) 
    {
        
        if (left_half[0] < left_half[0])
        {
            array[i] = left_half[0];
            
        }
        else
        {
            array[i] = right_half[0];
        }
    }
    

    return array;
}

int main()
{
    int data[] = {24, 23, 45543, 3215};
    int* sorted_data = merge(data, 4);

    for (int i = 0; i < 4; i++)
    {
        std::cout << sorted_data[i];
    }

}
