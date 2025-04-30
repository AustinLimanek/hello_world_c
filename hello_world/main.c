//
//  main.c
//  hello_world
//
//  Created by Austin Limanek on 4/6/25.
//

#include <stdio.h>
#include <math.h>
// this is required for malloc to be called in the program
#include <stdlib.h>
// for using strcpy
#include <string.h>

// int main(int argc, const char * argv[]) {
void addOne (int *p){
    *p = *p + 1;
}

void insertSort(int *arr, int size){
    int i;
    for(i = 1; i < size; i++){
        // we are comparing to a key that is held in the right hand
        int key = arr[i];
        int j = i - 1;
        // searches the left hand for number greater than the key. Right hand is at eye and moving all cards that are larger than is to the right.
        // if right hand pulls the smallest card in the deck, then j will terminate exiting the while loop with a value of -1. This puts the pulled card at the front of the array.
        // we always shift the
        while (j >= 0 && arr[j] > key){
            // either j + 1 is the key and getting written over or we are shifting
            arr[j + 1] = arr[j];
            //look at the next card in the left hand or terminate at the end
            j = j - 1;
        }
        
        // there is a position where the current end of left hand is greater than right hand card.
        // also the key could remain where it is.
        arr[j + 1] = key;
    }
    
}

void selectionSort(int *arr, int size){
    // the value of the alloted memory in the stack is being allocated but not filled int with a value until it is "initialized". What is the proper definition of initialzied in c? Initialization is the process of setting the variable to a given set of bits. Initially this bits are whatever they were before. 
    int i;
    
    
}

// does the function need to call an array? Or can it just be the lower bound and the upper bound?
void mergeSort(int *arr, int size, int left, int right){
    if(left == right){
        return;
    };
    
    int middle = left + (right - left) / 2;
    
    mergeSort(arr, size, left, middle);
    mergeSort(arr, size, middle + 1, right);
    
    int first = left;
    int second = middle + 1;
    
    while(first <= middle || second <= right){
        if(arr[first] < arr[second]){
            
        }
    }
    
}

void printArray(int *arr, int size){
    int i;
    for(i = 0; i < size; i = i + 1){
        printf("%d\n", arr[i]);
    }
}

struct Node{
    char *value;
    struct Node *next;
};

// typedef is defining "struct Node *" as List. So List is a pointer.
typedef struct Node * List;

// Function that returns a List type with value NULL.
List ListNew(void){
    return NULL;
};

// this function adds a new node to the front of the list.
List listAdd(List list, char *string){
    struct Node *node = (struct Node *) malloc (sizeof(struct Node));
    node -> value = (char *) malloc (strlen(string) + 1);
    strcpy(node -> value, string);
    node -> next = list;
    return node;
}

int *getAddress(void){
    int y;
    y = 3;
    return &y;
}

int main(void) {

    // insert code here...
    // printf("Hello, World!\n");
    int angle_degree;
    double angle_radian, pi, value;
    
    printf("\nCompute a table of the sine function\n\n");
    pi = M_PI;
    printf("PI = %f \n\n", pi);
    printf("Angle\tSine \n");
    angle_degree = 0;
    while(angle_degree <= 360){
        angle_radian = angle_degree * pi / 180.0;
        value = sin(angle_radian);
        printf("%3d\t%f \n", angle_degree, value);
        angle_degree += 10;
    }
    
    int y = 3;
    printf("%i\n", y);
    addOne(&y);
    printf("%i\n", y);
    
    int x;
    printf("%zu\n", sizeof(x));
    
    double n = 1;
    
    double power = 1;
    double quadratic = 100;
    
    printf("int\tpower\tquadratic\n");
    while(power < quadratic){
        power = pow(2, n);
        quadratic = 100 * pow(n, 2);
        n += 1;
        printf("%lf\t%lf\t%lf\n", n, power, quadratic);
    };
    
    double second = 1;
    double minute = 60 * second;
    double hour = 60 * minute;
    double day = 24 * hour;
    double month = 28 * day;
    double year = 365 * day;
    double century = 1000 * year;
    
    double array[7] = {second, minute, hour, day, month, year, century};
    
    int unsorted[6] = {5, 2, 4, 6, 1, 3};
    int length = 6;
    
    printArray(unsorted, length);
    insertSort(unsorted, length);
    printArray(unsorted, length);
    
    int unsortedSmall[1] = {5};
    int lengthShort = 1;
    
    printArray(unsortedSmall, lengthShort);
    insertSort(unsortedSmall, lengthShort);
    printArray(unsortedSmall, lengthShort);
    
    printf("%lu\tbytes\twhich is %lu bits\n", sizeof(int), sizeof(int) * 8);
    
    int stack = 42;
    int *stackPtr = &stack;
    printf("%p address of the stackPtr pointer\n", &stackPtr); // memory address in the stack of the pointer which is defined after stack. So the memory location is lower by 8 what?
    printf("%p address of the stack variable\n", stackPtr);   // memory address on the stack slightly higher because the address of stack was defined first to higher in memory. As in was put in the stack first.
    printf("%d\n", *stackPtr); // should be 42
    // what does the value of 8 represent in the difference in the address? Is it 8 bits?
    printf("%lu bytes for a int pointer\n", sizeof(int *));
    // pointer takes up 8 bytes for an int pointer? In a 64 bit machine the pointer variable has 8 bytes.
    
    // malloc returns a void* so there is a cast necessary to make it work. You need to tell the c compiler what type you want the bytes to be.
    int *ptr = (int *) malloc (sizeof(int));
    *ptr = 42; //dereferencing ptr to store the value 42 in that heap-allocated space
    
    printf("%p\n", (void *) &ptr); // Address of the pointer variable is in the stack (same location each time)
    printf("%p\n", (void *) ptr); // Address lower down, so the address held in ptr is in the heap? (diff each time)
    printf("%d\n", *ptr); // prints 0x2a because hex for 42, why error of void * from smaller int?
    
    int *otherPtr = (int *) malloc (sizeof(int));
    *otherPtr = 41;
    
    printf("%p address of the otherPtr variable\n", &otherPtr);
    printf("%p address that the otherPtr is pointing to\n", otherPtr);
    
    int *finalPtr; // This declares the pointer variable finalPtr, which has garabage at this location in the stack.
    printf("%p address finalPtr in point to\n", finalPtr);
    
    finalPtr = (int *) malloc (sizeof(int));
    
    printf("%d is the value at the location\n", *finalPtr);
    
    *finalPtr = 40; // This would set the value at some random address to 40. This seems really bad.
    
    printf("%d is the value at the location after dereferencing\n", *finalPtr);
    
    // The pointer is on the stack and has an address that is high. The ptr value is the address of what variable or where in memory a given value is located. Dereferencing the ptr really just follows the pointer to the address it is pointing to and return that value.
    
//    int *null = NULL;
//    printf("%d", *null);
    
    printf("%p\n", &array);
    
    // the List pointer variable list is only pointing to a NULL value
    List list = ListNew();
    
    // This set of imperative code is assigning an address that was called in a subroutine that is then returned. The value is maintained but the location in memory of the address is overwritten when the printf function is called.
    int *stackAddress, content;
    stackAddress = getAddress();
    content = *stackAddress;
    printf("%d\n", content);
    content = *stackAddress;
    printf("%d\n", content);
    
    // notes that the address in the heap can be shared from other procedures in the program so if malloc and free have a certain defined address location, then the pointer should be freed or malloced in the same procedure. Malloc is in the heap even thought the pointer is in the stack. The pointer in the stack is ther variable and the malloc is a procedure that runs and allocates where in the heap is large enough and free that can have that pointer point to a given address in the heap. The reallocate will again have a look up table for the given defined address. If the address is changed then that is a problem if not dealt with appropriately.
    
    return 0;
}
