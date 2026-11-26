#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 1000
#define FILE_PATH "D:\\Programming\\files\\25.txt"

int main()
{
    FILE* file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи!\n");
        return 1;
    }
    
    printf("Ввод строк в файл\n");
    char buffer[MAX_STR_LEN];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] == '\n')
        break;
        
        fputs(buffer, file);
    }
    
    fclose(file);
    
    file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения!\n");
        return 1;
    }

    char previous_line[MAX_STR_LEN];
    char current_line[MAX_STR_LEN];
    int isSorted = 1;

    // Читаем первую фамилию в файле
    if (fscanf(file, "%s", previous_line) == 1) {
        while (fscanf(file, "%s", current_line) == 1) {
            // Сравнивает по алфавиту пред и текущей фамилии, и если строки равны или первая меньше по алфавиту,
            // то идём дальше, иначе прекращаем наш цикл, так как условие уже нарушено!
            if (strcmp(previous_line, current_line) > 0) {
                isSorted = 0;
                break;
            }

            strcpy(previous_line, current_line);
        }
    }

    fclose(file);

    if (isSorted)
        printf("Список фамилий упорядочен по алфавиту!\n");
    else
        printf("Список фамилий неупорядочен по алфавиту\n");

    return 0;
}