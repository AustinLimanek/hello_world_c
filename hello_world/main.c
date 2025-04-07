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
    return 0;
}
