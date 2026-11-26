#include <stdio.h>
#define FILE_PATH "D:\\Programming\\files\\27.txt"

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
    if (file == NULL) {
        printf("Ошибка открытия файла при чтении!\n");
        return 1;
    }
    
    // Очистка буфера
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n');

    int min, max;
    printf("Ввод нижней и верхней границ диапазона для подсчёта суммы чисел, которые в него входят: ");
    scanf("%d %d", &min, &max);

    if (min > max) {
        printf("\nНеправильный ввод\n");
        return 1;
    }

    int read_number, summ = 0;
    while (fscanf(file, "%d", &read_number) == 1) {
        if (read_number >= min && read_number <= max)
            summ += read_number;
    }

    fclose(file);

    printf("\nСумма чисел, записанных в файл и входящих в [%d; %d] = %d", min, max, summ);

    return 0;
}