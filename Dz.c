#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "RUS");
    int n;

    // Ввод количества элементов
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ошибка: количество элементов должно быть положительным числом.\n");
        return 1;
    }

    // Динамическое выделение памяти для массива
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // Ввод элементов массива
    printf("Введите %d целых чисел (положительных и отрицательных):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Поиск максимального элемента и его индекса
    int max_value = INT_MIN;
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
            max_index = i;
        }
    }

    // Подсчет положительных элементов до максимального
    int count_positive = 0;
    for (int i = 0; i < max_index; i++) {
        if (arr[i] > 0) {
            count_positive++;
        }
    }

    // Вывод результатов
    printf("\nРезультаты:\n");
    printf("Максимальный элемент: %d\n", max_value);
    printf("Индекс максимального элемента: %d\n", max_index);
    printf("Количество положительных элементов до максимального: %d\n", count_positive);

    // Освобождение памяти
    free(arr);

    return 0;
}