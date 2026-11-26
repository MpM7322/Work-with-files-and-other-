#include <stdio.h>
#define MAX_SIZE 1000   
#define FILE_PATH "D:\\Programming\\files\\26.txt"

int main()
{
    FILE* file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла при записи!\n");
        return 1;
    }

    printf("Ввод чисел в текстовый файл\n");
    int number;
    while (scanf("%d", &number) == 1)
    fprintf(file, "%d\n", number);
    
    fclose(file);
    
    file = fopen(FILE_PATH, "r");
    int array[MAX_SIZE];
    int n = 0;
    
    while (n < MAX_SIZE && fscanf(file, "%d", &array[n]) == 1)
        n++;

    fclose(file);
        
        int max_index = 0, min_index = 0;
    for (int i = 1; i < n; i++) {
        if (*(array + i) > *(array + max_index))
            max_index = i;
        if (*(array + i) < *(array + min_index))
        min_index = i;
    }

    int temp = array[max_index];
    array[max_index] = array[min_index];
    array[min_index] = temp;
    
    file = fopen(FILE_PATH, "w");
    printf("Список целых чисел после обмена минимального и максимального\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", *(array + i));
        printf("%d\n", *(array + i));
    }
    
    return 0;
}