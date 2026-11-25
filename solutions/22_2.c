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
    
    char buffer[STR_MAX_LEN];

    printf("Вводите строки для записи в файл!\n");
    while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '\n')
            break;

        fputs(buffer, file);
    }
    
    fclose(file);
    
    file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения\n");
        return 1;
    }

    char current_line[STR_MAX_LEN];
    current_line[0] = '\0';
    char line_with_max_len[STR_MAX_LEN] = "";
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            if (strlen(current_line) > strlen(line_with_max_len))
                strcpy(line_with_max_len, current_line);
            
            current_line[0] = '\0';
        } 
        
        else if (strlen(current_line) < sizeof(current_line) - 1) {
            current_line[strlen(current_line) + 1] = '\0';
            current_line[strlen(current_line)] = ch;
        }
    }

    printf("Самая длинная строка из файла: %s; Её длина = %d", 
        line_with_max_len, strlen(line_with_max_len));

    fclose(file);

    return 0;
}