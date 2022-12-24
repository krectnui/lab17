#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define A -100
#define B 100

int sort_buble(int* ptrarr, int n);
int sheikerSort(int* ptrarr, int n);
int sort_select(int* ptrarr, int n);
int sort_insert(int* ptrarr, int n);
int* full_array(int*, int);
int show_array(int*, int);

int main() {
    setlocale(LC_ALL, "RUS");
    // 2
    int* ptrarr = (int*)malloc(100 * sizeof(int));
    ptrarr = full_array(ptrarr, 100);
    // show_array(ptrarr, 100);
    puts("\n\n\n");
    double t = clock();

    sort_insert(ptrarr, 100);

    double time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    // show_array(ptrarr, 100);
    free(ptrarr);

    // 3.1

    ptrarr = (int*)malloc(100 * sizeof(int));
    ptrarr = full_array(ptrarr, 100);
    t = clock();
    sort_buble(ptrarr, 100);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(100 * sizeof(int));
    ptrarr = full_array(ptrarr, 100);
    t = clock();
    sheikerSort(ptrarr, 100);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(100 * sizeof(int));
    ptrarr = full_array(ptrarr, 100);
    t = clock();
    sort_select(ptrarr, 100);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(100 * sizeof(int));
    ptrarr = full_array(ptrarr, 100);
    t = clock();
    sort_insert(ptrarr, 100);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    puts("\n\n\n");
    ptrarr = (int*)malloc(1000 * sizeof(int));
    ptrarr = full_array(ptrarr, 1000);
    t = clock();
    sort_buble(ptrarr, 1000);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(1000 * sizeof(int));
    ptrarr = full_array(ptrarr, 1000);
    t = clock();
    sheikerSort(ptrarr, 1000);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(1000 * sizeof(int));
    ptrarr = full_array(ptrarr, 1000);
    t = clock();
    sort_select(ptrarr, 1000);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(1000 * sizeof(int));
    ptrarr = full_array(ptrarr, 1000);
    t = clock();
    sort_insert(ptrarr, 1000);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    puts("\n\n\n");
    ptrarr = (int*)malloc(10000 * sizeof(int));
    ptrarr = full_array(ptrarr, 10000);
    t = clock();
    sort_buble(ptrarr, 10000);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(10000 * sizeof(int));
    ptrarr = full_array(ptrarr, 10000);
    t = clock();
    sheikerSort(ptrarr, 10000);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(10000 * sizeof(int));
    ptrarr = full_array(ptrarr, 10000);
    t = clock();
    sort_select(ptrarr, 10000);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);

    ptrarr = (int*)malloc(10000 * sizeof(int));
    ptrarr = full_array(ptrarr, 10000);
    t = clock();
    sort_insert(ptrarr, 10000);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Массив отсортирован за %lf секунд\n", time);
    free(ptrarr);
    return 0;
}

int sort_buble(int* ptrarr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {
            if (ptrarr[j - 1] > ptrarr[j])
            {
                int temp = ptrarr[j - 1];
                ptrarr[j - 1] = ptrarr[j];
                ptrarr[j] = temp;
            }
        }
    }
    return 0;
}

int sheikerSort(int* ptrarr, int n) {
    int left = 0, right = n - 1;
    int flag = 1;
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)
        {
            if (ptrarr[i] > ptrarr[i + 1])
            {
                int t = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = t;
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (ptrarr[i - 1] > ptrarr[i])
            {
                int t = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = t;
                flag = 1;
            }
        }
        left++;
    }
    return 0;
}

int sort_select(int* ptrarr, int n) {
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ptrarr[j] < ptrarr[min])
                min = j;
        }
        temp = ptrarr[i];
        ptrarr[i] = ptrarr[min];
        ptrarr[min] = temp;
    }
    return 0;
}

int sort_insert(int* ptrarr, int n) {
    int newElement, location;

    for (int i = 1; i < n; i++)
    {
        newElement = ptrarr[i];
        location = i - 1;
        while (location >= 0 && ptrarr[location] > newElement)
        {
            ptrarr[location + 1] = ptrarr[location];
            location = location - 1;
        }
        ptrarr[location + 1] = newElement;
    }
    return 0;
}

int* full_array(int* ptr_array, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        ptr_array[i] = A + rand() % (B - A);
    }
    return ptr_array;
}

int show_array(int* ptr_array, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %.2d\n", i, ptr_array[i]);
    }
    return 0;
}
