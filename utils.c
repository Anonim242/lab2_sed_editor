#include "sed_simplified.h"

void replace_text(FILE *file, const char *old_text, const char *new_text) {
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file) != -1) {
        char *pos = strstr(line, old_text);
        while (pos) {
            strncpy(pos, new_text, strlen(new_text));
            pos = strstr(pos + strlen(new_text), old_text);
        }
        printf("%s", line);
    }
    free(line);
}

void delete_matching_lines(FILE *file, const char *regex_str) {
    char *line = NULL;
    size_t len = 0;
    regex_t regex;
    if (regcomp(&regex, regex_str, REG_EXTENDED)) {
        fprintf(stderr, "Ошибка компиляции регулярного выражения\n");
        return;
    }

    while (getline(&line, &len, file) != -1) {
        if (regexec(&regex, line, 0, NULL, 0)) {
            printf("%s", line);
        }
    }
    free(line);
    regfree(&regex);
}

void insert_text(FILE *file, const char *insert_text, int at_end) {
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file) != -1) {
        if (at_end) {
            printf("%s%s", line, insert_text);
        } else {
            printf("%s%s", insert_text, line);
        }
    }
    free(line);
}
