#include "sed_simplified.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Недостаточно аргументов.\n");
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    if (strcmp(argv[2], "-r") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Неверное количество аргументов для замены.\n");
            fclose(file);
            return 1;
        }
        replace_text(file, argv[3], argv[4]);
    }
    else if (strcmp(argv[2], "-d") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Неверное количество аргументов для удаления.\n");
            fclose(file);
            return 1;
        }
        delete_matching_lines(file, argv[3]);
    }
    else if (strcmp(argv[2], "-i") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Неверное количество аргументов для вставки.\n");
            fclose(file);
            return 1;
        }
        if (strcmp(argv[3], "-f") == 0) {
            insert_text(file, argv[4], 0);
        }
        else if (strcmp(argv[3], "-b") == 0) {
            insert_text(file, argv[4], 1);
        }
    }
    else {
        fprintf(stderr, "Неверный флаг.\n");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
