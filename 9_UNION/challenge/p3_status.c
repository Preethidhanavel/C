/*You are making a device driver, and sometimes your hardware gives you a 32-bit error code, 
sometimes a floating-point value, and sometimes a short text message. 
How can you use a union in a structure to store these different values? What are the good and bad things about this approach?
struct StatusReport {
    int type; // 0: error code, 1: sensor value, 2: message
    union {
        int errorCode;
        float sensorValue;
        char message[8];
    } data;
};*/


#include <stdio.h>
#include <string.h>

struct StatusReport 
{
int type;
    union 
    {
    int errorCode;
    float sensorValue;
    char message[8];
    } data;
};

int main() 
{
struct StatusReport report;

report.type = 0;
report.data.errorCode = 404;
if (report.type == 0)
printf("Error Code: %d\n", report.data.errorCode);

report.type = 1;
report.data.sensorValue = 23.75f;
if (report.type == 1)
printf("Sensor Value: %.2f\n", report.data.sensorValue);

report.type = 2;
strncpy(report.data.message, "OK", sizeof(report.data.message));
if (report.type == 2)
printf("Message: %s\n", report.data.message);

}
