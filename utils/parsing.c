#include "../ft_nm.h"

void    CheckSignature(unsigned char *e_ident)
{
    unsigned char   elf_signature[4] = {0X7F, 'E', 'L', 'F'};

    if (memcmp(e_ident, elf_signature, 4) != 0)
        ExitError("FORMAT_ERROR");
}


void    CheckHeader(void)
{
    int bytes_read;

    if (file_info.arch_type == ELF32)
        bytes_read = read(file_info.file_fd, ((char *)&file_info.elf32_hdr) + 16, sizeof(Elf32_hdr) - 16);
    else if (file_info.arch_type == ELF64)
        bytes_read = read(file_info.file_fd, ((char *)&file_info.elf64_hdr) + 16, sizeof(Elf64_hdr) - 16);

    if (bytes_read < 0)
        ExitError("READ_ERROR");

    PrintHeader();
    return;
}


void    CheckArchType(unsigned char *e_ident)
{
    file_info.arch_type = e_ident[4];
    if (file_info.arch_type == ELF32)
        memcpy(file_info.elf32_hdr.e_ident, e_ident, 16);
    else if (file_info.arch_type == ELF64)
        memcpy(file_info.elf64_hdr.e_ident, e_ident, 16);
    else
        ExitError("BAD_ARCH");
}


void    Parsing(void)
{
    unsigned char   e_ident[16];
    int             bytes_read;

    file_info.file_fd = open(file_info.file_name, O_RDONLY);
    if (file_info.file_fd < 0)
        ExitError("OPEN_ERROR");

    bytes_read = read(file_info.file_fd, e_ident, 16);
    if (bytes_read < 0)
        ExitError("READ_ERROR");

    CheckSignature(e_ident);
    CheckArchType(e_ident);
    CheckHeader();
}