#include <stdio.h>
#include <string.h>
#define STR_MAX_LEN 1000
#define FILE_PATH "D:\\Programming\\files\\23.txt"

int main()
{
    FILE* file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла для записи!\n");
        return 1;
    }
    
    printf("Ввод строк в текстовый файл: \n");
    
    char buffer[STR_MAX_LEN];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '\n')
            break;
        
        fputs(buffer, file);
    }
    
    fclose(file);

    file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла для чтения!\n");
        return 1;
    } 
    
    int n, count = 0;
    printf("Введите необходимую длину n для строки: ");
    scanf("%d", &n);

    char current_line[STR_MAX_LEN];
    while(fgets(current_line, sizeof(current_line), file) != NULL) {
        current_line[strcspn(current_line, "\n")] = '\0';
        if (strlen(current_line) > n)
            count++;
    }

    printf("\nКоличество строк с необходимой длиной(%d) = %d", n, count);

    fclose(file);

    return 0;
}