#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 1000
#define FILE_PATH "D:\\Programming\\files\\24.txt"

int main()
{
    FILE* file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла для записи!\n");
        return 1;
    }

    printf("Ввод строк в файл .txt\n");
    char buffer[MAX_STR_LEN];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '\n') {
            break;
        }

        fputs(buffer, file);
    }

    fclose(file);

    file = fopen(FILE_PATH, "r");
    int lines_counter = 0;
    char current_line[MAX_STR_LEN];
    while (fgets(current_line, sizeof(current_line), file) != NULL) {
        lines_counter++;
    }
    
    printf("Количество строк в файле .txt = %d\n", lines_counter);
    fclose(file);
    
    file = fopen(FILE_PATH, "r");
    int i;
    printf("Введите номер i-ой строки(от 1 до %d), чтобы посчитать в ней количество символов: ", lines_counter);
    scanf("%d", &i);

    int need = 1;
    while (fgets(current_line, sizeof(current_line), file) != NULL) {
        current_line[strcspn(current_line, "\n")] = '\0';
        if (need == i) {
            printf("Количество символов в %d-строке = %d", i, strlen(current_line));
            break;
        }
        need++;
    }

    fclose(file);

    return 0;
}