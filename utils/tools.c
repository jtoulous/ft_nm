#include "../ft_nm.h"

void    ExitError(char *type)
{
    int exit_code = 0;

    if (strcmp(type, "OPEN_ERROR") == 0)
    {
        exit_code = 1;
        if (errno == ENOENT)
            printf("nm: '%s': no such file", file_info.file_name);
        if (errno == EACCES)
            printf("nm: '%s': Permission denied", file_info.file_name);
    }
    
    else if (strcmp(type, "FORMAT_ERROR") == 0)
    {
        exit_code = 1;
        printf("nm: %s: file format not recognized", file_info.file_name);
    }

    else if (strcmp(type, "READ_ERROR") == 0)
    {
        exit_code = 1;
        printf("nm: %s: problem rading the file", file_info.file_name);
    }
    
    Destroy();
    exit(exit_code);
}


void    Init(char *arg)
{
    file_info.file_name = strdup(arg);
    file_info.file_fd = -1;
    file_info.arch_type = -1;

    memset(file_info.elf32_hdr.e_ident, 0, sizeof(file_info.elf32_hdr.e_ident));
    memset(file_info.elf64_hdr.e_ident, 0, sizeof(file_info.elf64_hdr.e_ident));
}


void    Destroy(void)
{
    if (file_info.file_name != NULL)
        free(file_info.file_name);

    if (file_info.file_fd != -1)
        close(file_info.file_fd);

    file_info.file_name = NULL;
    file_info.file_fd = -1;
    file_info.arch_type = -1;
    memset(file_info.elf32_hdr.e_ident, 0, sizeof(file_info.elf32_hdr.e_ident));
    memset(file_info.elf64_hdr.e_ident, 0, sizeof(file_info.elf64_hdr.e_ident));
}