#include "ft_nm.h"

void    CheckSignature(unsigned char *e_ident)
{
    unsigned char   elf_signature[4] = {0X7F, 'E', 'L', 'F'};

    if (memcmp(e_ident, elf_signature, 4 ) != 0)
        ExitError("FORMAT_ERROR");
}


void    CheckHeader(void):
{
    unsigned char   elf32_buff[36];
    unsigned char   elf64_buff[48];
    int             bytes_read;

    if (arch_type == 1)
        bytes_read = read(file_info.file_fd, elf32_buff, 36);
    else if (arch_type == 2)
        bytes_read = read(file_info.file_fd, elf64_buff, 48);


}


void    CheckFileType(void)
{
    unsigned char   e_ident[16];

    bytes_read = read(file_info.file_fd, e_ident, 16);
    if (bytes_read < 0)
        ExitError("READ_ERROR");

    CheckSignature(e_ident);

    file_info.arch_type = e_ident[4];
    if (file_info.arch_type == ELF32)
        memcpy(file_info.elf32_hdr.e_ident, e_ident, 16);
    else if (file_info.file_type == ELF64)
        memcpy(file_info.elf64_hdr.e_ident, e_ident, 16);
    else
        ExitError("BAD_ARCH");

    CheckHeader();
}


void    Parsing(void)
{
    file_info.file_fd = open(file_info.file_name, O_RDONLY);
    if (file_info.file_fd < 0)
        ExitError("OPEN_ERROR");

    CheckFileType();

}