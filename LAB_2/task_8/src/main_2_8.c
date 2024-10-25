#include "../include/task_2_8.h"

int main() 
{
    enum ERRORS status = getting_sums(36, 2, "Z", "1");
    heandler_status(status);

    return 0;
}