#include "../ft_nm.h"

void    PrintHeader(void)
{
    if (file_info.arch_type == ELF32)
    {
        Elf32_hdr   *header = &file_info.elf32_hdr;
        
        printf("ELF32 Header:\n");
        printf("e_ident: ");
        for (int i = 0; i < 16; i++)
            printf("%02x ", header->e_ident[i]);
        printf("\ne_type: %u\n", header->e_type);
        printf("e_machine: %u\n", header->e_machine);
        printf("e_version: %u\n", header->e_version);
        printf("e_entry: %u\n", header->e_entry);
        printf("e_phoff: %u\n", header->e_phoff);
        printf("e_shoff: %u\n", header->e_shoff);
        printf("e_flags: %u\n", header->e_flags);
        printf("e_ehsize: %u\n", header->e_ehsize);
        printf("e_phentsize: %u\n", header->e_phentsize);
        printf("e_phnum: %u\n", header->e_phnum);
        printf("e_shentsize: %u\n", header->e_shentsize);
        printf("e_shnum: %u\n", header->e_shnum);
        printf("e_shstrndx: %u\n", header->e_shstrndx);
    }

    else if (file_info.arch_type == ELF64)
    {
        Elf64_hdr *header = &file_info.elf64_hdr;
        
        printf("ELF64 Header:\n");
        printf("e_ident: ");
        for (int i = 0; i < 16; i++)
            printf("%02x ", header->e_ident[i]);
        printf("\ne_type: %u\n", header->e_type);
        printf("e_machine: %u\n", header->e_machine);
        printf("e_version: %u\n", header->e_version);
        printf("e_entry: %lu\n", header->e_entry);
        printf("e_phoff: %lu\n", header->e_phoff);
        printf("e_shoff: %lu\n", header->e_shoff);
        printf("e_flags: %u\n", header->e_flags);
        printf("e_ehsize: %u\n", header->e_ehsize);
        printf("e_phentsize: %u\n", header->e_phentsize);
        printf("e_phnum: %u\n", header->e_phnum);
        printf("e_shentsize: %u\n", header->e_shentsize);
        printf("e_shnum: %u\n", header->e_shnum);
        printf("e_shstrndx: %u\n", header->e_shstrndx);
    }
}