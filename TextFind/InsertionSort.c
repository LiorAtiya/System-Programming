#include <stdio.h>
#define ARR_SIZE 50

void shift_element(int* arr, int i){
    int j;
    for(j = i ; j > 0 ; j--){
        *(arr+j) = *(arr+j-1);
    }
}

void insertion_sort(int* arr , int len){
    for (int i = 1; i < len; i++)
    {
        int j = i;
        int a = *(arr+i);
        while ((j > 0) && *(arr+j-1) > a)
        {
            shift_element(arr+j-1,1);
            j--;
        }
        *(arr+j) = a;
    }
}

void runSort(){
    int arr[ARR_SIZE];

    for(int i=0 ; i < ARR_SIZE ; i++){
        scanf("%d", arr+i);
    }

    insertion_sort(arr,ARR_SIZE);

    for (int i = 0; i < ARR_SIZE-1; i++){
        printf( "%d,", arr[i]);
    }
    printf("%d", arr[ARR_SIZE-1]);
    printf("%c", '\n');
}