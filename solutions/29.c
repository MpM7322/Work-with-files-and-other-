#include <stdio.h>
#define MAX_STR_LEN 1000
#define FILE_PATH "D:\\Programming\\files\\29.txt"
#define TEMP_PATH "D:\\Programming\\files\\29temp.txt"

int main()
{
    FILE* file = fopen(FILE_PATH, "w");
    if (file == NULL)
        return 1;

    printf("Ввод текста в файл\n");
    char buffer[MAX_STR_LEN];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '\n')
            break;
        
        fputs(buffer, file);
    }

    fclose(file);
    
    file = fopen(FILE_PATH, "r");
    FILE* temp = fopen(TEMP_PATH, "w");
    if (file == NULL || temp == NULL) {
        if (file)
            fclose(file);
        if (temp)
            fclose(temp);

        return 1;
    
    }

    int ch, r, count = 0;
    printf("По сколько символов будут переписаны строки: ");
    scanf("%d", &r);

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n')
            continue;
        
        if (count == r) {
            fputc('\n', temp);
            count = 0;
        }

        fputc(ch, temp);
        count++;
    }

    fclose(file);
    fclose(temp);
    
    remove(FILE_PATH);
    rename(TEMP_PATH, FILE_PATH);

    return 0;
}