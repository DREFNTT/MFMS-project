#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

int getValidInteger(const char *prompt);
int getValidPositiveInteger(const char *prompt);
void getValidNonEmptyString(const char *prompt, char *output, size_t size);

#endif


