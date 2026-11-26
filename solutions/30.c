#include <stdio.h>
#define MAX_STR_LEN 1000
#define FILE_PATH "D:\\Programming\\files\\30.txt"

int main()
{
    FILE* file = fopen(FILE_PATH, "w");
    if (file == NULL)
        return 1;

    printf("Ввод текста в файл\n");
    char buffer[MAX_STR_LEN];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] == '\n')
            break;

        fputs(buffer, file);
    }

    fclose(file);

    file = fopen(FILE_PATH, "r");
    int count = 0;
    char string[MAX_STR_LEN];
    while (fscanf(file, "%s", string) == 1)
        count++;

    fclose(file);
    
    printf("\nКоличество слов = %d", count);

    return 0;
}