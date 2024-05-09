// Created by Aditya Daharwal

// Functions in this header file:
// 1. init(struct Array *arr, int cap) : initialise an array struct
// 2. isFull(struct Array a) : check if array is full
// 3. add(struct Array *a, int elem) : add elements in array
// 4. print(struct Array arr) : print the array
// 5. getInput(char message[]) : get single input (print ask message)
// 6. create(struct Array *a) : add elements till input not equal to 999
// 7. indexOutOfBound(struct Array a, int indx) : check index is in range 
// 8. delete(struct Array *a, int indx) : delete element in array
// 9. copy(struct Array a, struct Array *a2)
// 10. insert(struct Array *a, int indx, int ele)
// 11. linearSearch(struct Array a, int key)
// 12. sort(struct Array *a)
// 13. merge(struct Array *a,struct Array *b,struct Array *c)
// 14. binarySearch(struct Array a, int key)

#include <stdio.h>
#define Max 50

struct Array
{
    int capacity;
    int array[Max];
    int lastIndex;
};

void init(struct Array *arr, int cap)
{
    arr->lastIndex = -1; // for  pointer to sturct we use ->
    arr->capacity = cap; // set max capacity of array 
}

int isFull(struct Array a) // check array is full 
{
    if (a.lastIndex == a.capacity - 1)// is last index reached max capacity
        return 1;
    return 0;
}

int add(struct Array *a, int elem)
{   
    if (isFull(*a))
    { // * (means value at) dereferencing
        printf("Array is full\n");
        return 0;
    }
    else // array is not full
    {
        (a->lastIndex)++;
        a->array[(a->lastIndex)] = elem;
        return 1;
    }
}

int print(struct Array arr)
{

    printf("[");
    for (int i = 0; i < arr.lastIndex; i++)
    {
            printf("%d,", arr.array[i]);
       
    }
    printf("%d", arr.array[arr.lastIndex]);
    printf("]\n");
}

int getInput(char message[])
{
    printf("%s", message);
    int n;
    scanf("%d", &n);
    return n;
}

void create(struct Array *a)
{
    int elem = getInput("Enter a no: Enter 999 to stop : ");

    while ((elem != 999) && add(a, elem) )
    {
        elem = getInput("Enter a no: Enter 999 to stop : ");
    }
}

int indexOutOfBound(struct Array a, int indx)
{
    // index out of bound
    if (indx < 0 || indx > a.lastIndex)
    {
        printf("Index out of bound \n");
        return 1;
    }
    return 0;
}

int delete(struct Array *a, int indx)
{
    // case 1 : index out of bound
    if (indexOutOfBound(*a, indx))
        return 0;
    //copy the elements from indx to 1 element back
    for (int i = indx; i < a->lastIndex; i++)
    {
        a->array[i] = a->array[i + 1];
    }
    a->lastIndex--;//remove the last duplicate element
    printf("Delete Successful\n");
    return 1;
}

int copy(struct Array a, struct Array *a2)
{   // copy array1 to array2
    int limit = a2->capacity - 1; 
    if (a.lastIndex > limit)//checking array1 can fit in array2 
    { 
        printf("array elements greater than capacity by %d\n", a.lastIndex - limit);
    }
    for (int i = 0; i <= a.lastIndex; i++)//add all of array1 to array2
    {   
        add(a2, a.array[i]);
    }
}

int get(struct Array a, int indx) // get element in array at index indx
{
    if (!indexOutOfBound(a, indx))
    {
        return a.array[indx];
    }
    return -1;
}

int length(struct Array *a)
{ // length == lastIndex+1
    return a->lastIndex+1;
}

int insert(struct Array *a, int indx, int ele)
{
    // case1: index out of bound and case2: array is full
    if (!indexOutOfBound(*a, indx) && (!isFull(*a)))
    {
        for (int i = a->lastIndex; i > indx; i--)
        {
            a->array[i] = a->array[i-1];
        }
        a->array[indx] = ele;
        a->lastIndex++;
        return 1;
    }
    else
    {
        printf("some error occured(indexOutOfBound or array is Full)");
        return 0;
    }
}

int linearSearch(struct Array a, int key)
{
    for (int i = 0; i <= a.lastIndex; i++)
    {
        if (key == a.array[i])
            return i;
    }
    printf("Element not found");
    return -1;
}

int sort(struct Array *a)
{   //bubble sort 
    int swapped=0;
    for (int j = 0; j < a->lastIndex; j++)
    {   swapped=0;
        for (int i = 0; i < a->lastIndex-j; i++)
        {
            if (a->array[i] > a->array[i + 1])
            {
                int t = a->array[i];
                a->array[i] = a->array[i + 1];
                a->array[i + 1] = t;
                swapped=1;
            }
        }
        if(!swapped){
            //as swapping not occurred array is sorted
            break;
        }
    }
    print(*a);

}

// merge sorted array in bigger sorted array
int merge(struct Array *a,struct Array *b,struct Array *c){
        sort(a);
        sort(b);
        //c->capacity=length(a)+length(b);
        int i=0,j=0;
        //add greater elemnet first
        while(i<=a->lastIndex && j<=b->lastIndex){
            if(a->array[i]<=b->array[j]){
                add(c,a->array[i]);
                i++;
            }else{
                add(c,b->array[j]);
                j++;
            }
        }
        //add remainig element left in array
        while(i<=a->lastIndex){
            add(c,a->array[i]);
            i++;
        }
        while(j<=b->lastIndex){
            add(c,b->array[j]);
            j++;
        }
        printf("\nMerged Array:");
        print(*c);
}

int binarySearch(struct Array a, int key){
    int h=a.lastIndex;
    int l=0;
    int mid=(h+l)/2;
    sort(&a);
    while(l<=h){   
        if(a.array[mid]==key)
            return 1;
        else if(a.array[mid]>key)
            l=mid+1;
        else
            h=mid-1;
        mid=(h+l)/2;
        }
    return 0;
   }
