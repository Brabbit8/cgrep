#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Usage: %s <filename> <search_string>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    char line[1000];
    while (fgets(line, sizeof line, fp) != NULL) {
        if(strstr(line, argv[1]) != NULL) {
            printf("%s", line);
        }
}
    fclose(fp);
    return 0;
}