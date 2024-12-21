#ifndef SED_SIMPLIFIED_H
#define SED_SIMPLIFIED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void replace_text(FILE *file, const char *old_text, const char *new_text);
void delete_matching_lines(FILE *file, const char *regex_str);
void insert_text(FILE *file, const char *insert_text, int at_end);

#endif
