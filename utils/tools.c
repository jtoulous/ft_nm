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


void    Init(arg)
{
    file_info.file_name = strdup(arg);
    file_info.file_fd = -1;
    file_info.arch_type = NULL;

    file_info.elf32_hdr.e_ident = NULL;
    file_info.elf64_hdr.e_ident = NULL;
}


void    Destroy(void)
{
    if (file_info.file_name != NULL)
        free(file_info.file_name);

    if (file_info.file_fd != -1)
        close(file_info.file_fd);

    if (file_info.arch_type != NULL)
        free(file_info.arch_type);

    file_info.file_name = NULL;
    file_info.file_fd = -1;
    file_info.arch_type = NULL;
}