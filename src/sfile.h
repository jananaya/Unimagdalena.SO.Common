#ifdef SFILE_H
#define SFILE_H

FILE *try_fopen(const char *file_name,
                const char *mode,
                const char *error_message);
void try_fscanf(FILE *fd,
                const char *format, int num_args,
                const char *error_message, ...);

#endif