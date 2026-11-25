#include <stdio.h>
#include <string.h>
#define STR_MAX_LEN 1000
#define FILE_PATH "D:\\Programming\\files\\22.txt"

int main()
{
    
    FILE* file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 1;
    }
    
    for (int i = 0; i < 10; i++)
    fprintf(file, "The result of the fprintf %d\n", i + 1);
    
    fclose(file);
    
    file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения\n");
        return 1;
    }

    char current_line[STR_MAX_LEN];
    char line_with_max_len[STR_MAX_LEN] = "";

    while(fgets(current_line, sizeof(current_line), file) != NULL) {
        current_line[strcspn(current_line, "\n")] = '\0';
        if (strlen(current_line) > strlen(line_with_max_len))
            strcpy(line_with_max_len, current_line);
    }

    printf("Самая длинная строка из файла: %s; Её длина = %d", 
        line_with_max_len, strlen(line_with_max_len));

    fclose(file);

    return 0;
}