#include "../include/functions_2_4.h"

int main()
{
    // Тест 1: Выпуклый многоугольник (шестиугольник)
    VERTEX a = {0, 0};
    VERTEX b = {2, 0};
    VERTEX c = {2, 2};
    VERTEX d = {1, 2};
    VERTEX e = {0.5, 1.5};
    VERTEX f = {0, 1};
    printf("TEST 1:\n");
    enum ERRORS status = check_convex_polygon(6, a, b, c, d, e, f);
    heandler_status(status);

    // Тест 2: Невыпуклый многоугольник (пятиугольник)
    VERTEX g = {0, 0};
    VERTEX h = {2, 0};
    VERTEX i = {2, 2};
    VERTEX j = {1, 1};
    VERTEX k = {0, 2};
    printf("TEST 2:\n");
    status = check_convex_polygon(5, g, h, i, j, k);
    heandler_status(status);

    // Тест 3: Недостаточно вершин (две вершины)
    VERTEX l = {0, 0};
    VERTEX m = {1, 1};
    printf("TEST 3:\n");
    status = check_convex_polygon(2, l, m);
    heandler_status(status);

    // Тест 4: Выпуклый многоугольник (треугольник)
    VERTEX n = {0, 0};
    VERTEX o = {1, 0};
    VERTEX p = {0, 1};
    printf("TEST 4:\n");
    status = check_convex_polygon(3, n, o, p);
    heandler_status(status);

    // Тест 1: Полином 3x^2 + 4x + 5 при x = 2
    printf("TEST 1:\n");
    status = method_gorner(2.0, 3, 3.0, 4.0, 5.0);
    heandler_status(status);

    // Тест 2: Полином x^3 - 2x^2 + x - 1 при x = 1
    printf("TEST 2:\n");
    status = method_gorner(1.0, 4, 1.0, -2.0, 1.0, -1.0);
    heandler_status(status);

    // Тест 3: Полином 2x^4 + 3x^3 + 4x^2 + 5x + 6 при x = -1
    printf("TEST 3:\n");
    status = method_gorner(-1.0, 5, 2.0, 3.0, 4.0, 5.0, 6.0);
    heandler_status(status);

    // Тест 4: Полином 0 при x = 0
    printf("TEST 4:\n");
    status = method_gorner(0.0, 1, 0.0);
    heandler_status(status);

    // Тест 5: Полином x^2 + 2x + 1 при x = 3
    printf("TEST 5:\n");
    status = method_gorner(3.0, 3, 1.0, 2.0, 1.0);
    heandler_status(status);

    status = find_kaprekar_number(10, 52, "1","9","45","55","99","297","703","999","2223","2728","4879","4950","5050","7272","7777","9999","17344","22222","77778","82656","95121","99999","142857","148149","181819","187110","208495","318682","329967","351352","356643","390313","461539","466830","499500","500500","533170","538461","609687","643357","648648","670033","681318","791505","812890","818181","851851","857143","961038","994708","999999", "999998");  
    heandler_status(status);

    status = find_kaprekar_number(16, 73, "1", "6", "A", "F", "33", "55", "5B", "78", "88", "AB", "CD", "FF", "15F", "334", "38E", "492", "4ED", "7E0", "820", "B13", "B6E", "C72", "CCC", "EA1", "FA5", "FFF", "191A", "2A2B", "3C3C", "4444", "5556", "6667", "7F80", "8080", "9999", "AAAA", "BBBC", "C3C4", "D5D5", "E6E6", "FFFF", "1745E", "20EC2", "2ACAB", "2D02E", "30684", "3831F", "3E0F8", "42108", "47AE1", "55555", "62FCA", "689A3", "7278C", "76417", "7A427", "7FE00", "80200", "85BD9", "89AE5", "89BE9", "8D874", "9765D", "9D036", "AAAAB", "AF0B0", "B851F", "BDEF8", "C1F08", "C7CE1", "CF97C", "D5355", "D5354");
    heandler_status(status);
    
    return 0;
}
