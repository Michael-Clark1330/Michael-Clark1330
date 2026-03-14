/****************************
* Title: qSort.c            *
* Programmer: Michael Clark *
* Professor: Dr. Lee        *
* File Created: 3/14/2026   *
* File Updated: 3/14/2026   *
*****************************/

#include <stdio.h>                                 // include standard input/output header file
#define N 10

void quicksort(int a[], int low, int high);        // 
int split(int a[], int low, int high);             // 

int main() {                                       // start main block
  int a[N], i;                                     // 

  printf("Enter %d numbers to be sorted: ", N);    //
  for(i = 0; i < N; i++)                           // for incrementer variable i = 0,1,2,3,4,5,6,7,8,9: 
    scanf("%d", &a[i]);                            // scanner takes integer input and assigns it to the
                                                   // array index corresponding to the value of i (sequentially from 1 to 9)
    
   quicksort(a, 0, N - 1);                         // 
   printf("In sorted order: ", N - 1);             // 
   
   for(i = 0; i < N; i++)                          // 
     printf("%d", a[i]);                           // 
   printf("\n");                                   // 
   
   return 0;                                       // 
}                                                  // end main block

void quicksort(int a[], int low, int high) {       // 
  int middle;                                      // declares new integer 'middle'
  
  if(low == high) return;                          //
  middle = split(a, low, high);                    // 
  quicksort(a, low, middle - 1);                   // 
  quicksort(a, middle + 1, high);                  // 
}                                                  // end quicksort block

int split(int a[], int low, int high) {            // 
  int part_element = a[low];                       // 
  
  for(;;) {                                        // 
    while (low < high && part_element <= a[high])  // 
      high--;                                      //
    if(low >= high) break;                         // 
    a[low++] = a[high];                            // 
    
    while (low < high && a[low] <= part_element)
      low++;                                       // 
    if(low >= high) break;                         // 
    a[high--] = a[low];                            // 
  }                                                // 
  
  a[high] = part_element;                          // 
  return high;                                     // 
}                                                  // end split function


