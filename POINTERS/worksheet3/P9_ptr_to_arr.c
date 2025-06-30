/*9.Function Returning Pointer to Fixed-Size Array
Goal: Implement a function that returns a pointer to a fixed-size calibration data array.
Activity:
Use typedef to declare a pointer to an array of 10 integers:
typedef int (*CalibArrayPtr)[10];
Log Session a function that returns a pointer to a static array of calibration values:
CalibArrayPtr get_calibration_data(void);
From the calling function, access calibration data via the returned pointer.*/

#include <stdio.h>

typedef int (*CalibArrayPtr)[10];

CalibArrayPtr get_calibration_data(void) 
{
    static int calib_data[10] = {100, 105, 110, 115, 120, 125, 130, 135, 140, 145};
    return &calib_data;
}

int main() 
{
    CalibArrayPtr calib_ptr = get_calibration_data();

    printf("Calibration data:\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("%d ", (*calib_ptr)[i]);
    }
    printf("\n");

    return 0;
}
