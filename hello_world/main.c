//
//  main.c
//  hello_world
//
//  Created by Austin Limanek on 4/6/25.
//

#include <stdio.h>
#include <math.h>

// int main(int argc, const char * argv[]) {
void addOne (int *p){
    *p = *p + 1;
}

void insertSort(int *arr, int size){
    if (size < 2){
        return;
    };
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

void printArray(int *arr, int size){
    int i;
    for(i = 0; i < size; i = i + 1){
        printf("%d\n", arr[i]);
    }
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
    
    int unsorted[3] = {7, 3, 4};
    
    
    printArray(unsorted, 3);
    insertSort(unsorted, 3);
    printArray(unsorted, 3);
    
    return 0;
}
