#include <stdio.h>
#include <math.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

/* Глобальні змінні */
int group_number = 79;
int variant_number = 10;
const int NAME_NUMBER = 12;

/* Функція перевірки кореня з номера групи */
void check_sqrt(int group, const char *name)
{
    double root = sqrt((double)group);
    size_t len = strlen(name);
    double sum = root + (double)len;
    double prod = root * (double)len;

    if (fabs(root - (double)len) < 1e-9) {
        printf("Значення рівні: sqrt = %f, довжина = %zu\n", root, len);
        printf("Сума = %f, добуток = %f\n", sum, prod);
    } else if (root > (double)len) {
        printf("sqrt(%d) = %f > %zu. Сума = %f s\n", group, root, len, sum);
    } else {
        printf("sqrt(%d) = %f < %zu. Добуток = %f n\n", group, root, len, prod);
    }
}

int main(void)
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    /* Пункт 2: синус для парного номера, косинус для непарного */
    if (variant_number % 2 == 0) {
        printf("Мій номер за журналом %d. Його Sin = %f\n",
               variant_number, sin(variant_number));
    } else {
        printf("Мій номер за журналом %d. Його Cos = %f\n",
               variant_number, cos(variant_number));
    }

    /* Пункт 3а: локальний рядок і вивід в одному рядку */
    char name[] = "Іван";
    printf("Група: %d, варіант: %d, ім'я: %s\n",
           group_number, variant_number, name);

    /* Пункт 3b, 3c: добуток і явне приведення до int */
    double product = variant_number * 3.14;
    int product_int = (int)product;
    printf("Добуток: %f, після конвертації в int: %d\n", product, product_int);

    /* Пункт 4: цикл for */
    int start = variant_number + NAME_NUMBER;
    long long total = 0;
    for (int i = start - 1; i >= 1; i--) {
        total += i;
    }
    printf("NAME_NUMBER = %d, сума чисел від %d до 1 = %lld\n",
           NAME_NUMBER, start - 1, total);

    /* Пункт 5: виклик функції */
    check_sqrt(group_number, name);

    /* Пункт 6: switch за номером групи */
    int input_group;
    printf("Введіть номер групи: ");
    if (scanf("%d", &input_group) != 1) {
        printf("Помилка введення.\n");
        return 1;
    }

    switch (input_group) {
        case 92: case 93: case 94: case 95:
        case 96: case 97: case 98: case 99:
            printf("Група %d навчається на I курсі.\n", input_group);
            break;
        case 87: case 88: case 89: case 90: case 91:
            printf("Група %d навчається на II курсі.\n", input_group);
            break;
        case 81: case 82: case 83: case 84: case 85: case 86:
            printf("Група %d навчається на III курсі.\n", input_group);
            break;
        case 75: case 76: case 77: case 78: case 79: case 80:
            printf("Група %d навчається на IV курсі.\n", input_group);
            break;
        default:
            printf("Такої групи в коледжі немає.\n");
            break;
    }

    return 0;
}