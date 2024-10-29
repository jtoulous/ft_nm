#include "ft_nm.h"


Filesinfo  file_info;

void    ft_nm(void)
{
    return;
}

int main(int argc, char **argv)
{           
    if (argc > 1)
    {
        for (int i = 1; argv[i]; i++)
        {    
            Init(argv[i]);
            Parsing();
            ft_nm();
            Destroy();
        }
    }
    
    else
    {
            Init("a.out");
            Parsing();
            ft_nm();
            Destroy();
    }

    return (0);
}