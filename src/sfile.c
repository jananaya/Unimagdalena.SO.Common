#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "sfile.h"

#define ERROR_READING_DATA "Error al leer dato desde archivo de texto\n"
#define ERROR_OPENING_FILE "Error al abrir archivo de texto\n"

FILE *try_fopen(const char *file_name,
                const char *mode,
                const char *error_message)
{
    FILE *fd;

    fd = fopen(file_name, mode);

    if (fd == NULL)
    {
        perror(error_message != NULL ? error_message : ERROR_OPENING_FILE);
        exit(EXIT_FAILURE);
    }

    return fd;
}

void try_fscanf(FILE *fd,
                const char *format, int num_args,
                const char *error_message, ...)
{
    va_list args;
    va_start(args, error_message);

    int i;
    for (i = 0; i < num_args; ++i)
    {
        if (fscanf(fd, format, va_arg(args, void *)) == EOF)
        {
            perror(error_message != NULL ? error_message : ERROR_READING_DATA);
            exit(EXIT_FAILURE);
        }
    }

    va_end(args);
}
