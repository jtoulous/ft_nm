#ifndef
#define FT_NM_H

#define ELF32 1
#define ELF64 2

typedef struct {
    unsigned char e_ident[16];   // Identification ELF
    uint16_t e_type;             // Type de fichier
    uint16_t e_machine;          // Architecture
    uint32_t e_version;          // Version
    uint64_t e_entry;            // Point d'entrée
    uint64_t e_phoff;            // Offset du tableau de programme
    uint64_t e_shoff;            // Offset du tableau de sections
    uint32_t e_flags;            // Flags
    uint16_t e_ehsize;           // Taille de cette structure
    uint16_t e_phentsize;        // Taille d'une entrée de tableau de programme
    uint16_t e_phnum;            // Nombre d'entrées dans le tableau de programme
    uint16_t e_shentsize;        // Taille d'une entrée de tableau de sections
    uint16_t e_shnum;            // Nombre d'entrées dans le tableau de sections
    uint16_t e_shstrndx;         // Index de la section de nom de chaîne
} Elf64_hdr;


typedef struct {
    unsigned char e_ident[16];  // Identification ELF
    uint16_t e_type;             // Type de fichier
    uint16_t e_machine;          // Architecture
    uint32_t e_version;          // Version
    uint32_t e_entry;            // Point d'entrée
    uint32_t e_phoff;            // Offset du tableau de programme
    uint32_t e_shoff;            // Offset du tableau de sections
    uint32_t e_flags;            // Flags
    uint16_t e_ehsize;           // Taille de cette structure
    uint16_t e_phentsize;        // Taille d'une entrée de tableau de programme
    uint16_t e_phnum;            // Nombre d'entrées dans le tableau de programme
    uint16_t e_shentsize;        // Taille d'une entrée de tableau de sections
    uint16_t e_shnum;            // Nombre d'entrées dans le tableau de sections
    uint16_t e_shstrndx;         // Index de la section de nom de chaîne
} Elf32_hdr;


typedef struct f_list
{
    char        *file_name;
    int         file_fd;
    char        *arch_type;
    
    Elf32_hdr   elf32_hdr;
    Elf64_hdr   elf64_hdr;
}   FileInfo;


extern  FileInfo file_info;

void    Init(void);
void    Destroy(void);
void    ExitError(char *type, char *info_str);
void    Parsing(void);



#endif