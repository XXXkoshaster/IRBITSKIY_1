#include "../include/functions_2_4.h"

int main()
{
    enum ERRORS status_1 = check_convex_polygon(8, 0.0, 0.0, 1.0, 0.0, 0.5, 0.5, 1.0, 1.0);
    heandler_status(status_1);

    enum ERRORS status_2 = method_gorner(3, 3, 0.0, 4.0, 0.0);
    heandler_status(status_2);

    enum ERRORS status_3 = find_kaprekar_number(10, 4, "0", "99", "257", "297");
    heandler_status(status_3);

    return 0;
}