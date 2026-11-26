#include <stdio.h>
#define MAX_SIZE 1000
#define FILE_PATH "D:\\Programming\\files\\28.txt"

void clear_input() {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n');
}

int main()
{
    FILE* file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла для записи!\n");
        return 1;
    }

    printf("Ввод чисел\n");
    int number;
    while (scanf("%d", &number) == 1) {
        fprintf(file, "%d\n", number);
    }

    fclose(file);
    clear_input();

    int target;
    printf("Введите число, которое нужно исключить: ");
    scanf("%d", &target);

    int arr[MAX_SIZE];
    int n = 0;
    file = fopen(FILE_PATH, "r");
    while (n < MAX_SIZE && fscanf(file, "%d", (arr + n)) == 1) {
        n++;
    }
    fclose(file);

    file = fopen(FILE_PATH, "w");
    for (int i = 0; i < n; i++) {
        if (arr[i] != target)
            fprintf(file, "%d\n", arr[i]);
    }
    
    return 0;
}