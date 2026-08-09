#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_file(int fd);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
	    e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		dprintf(2, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - Prints the ELF magic numbers.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "" : " ");
	}
	printf("\n");
}

/**
 * print_class - Prints the ELF class.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints the ELF data encoding.
 * @e_ident: A pointer to an array containing the ELF data encoding.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version - Prints the ELF version.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the ELF OS/ABI.
 * @e_ident: A pointer to an array containing the ELF OS/ABI.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64 UNIX\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ELF ABI version.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the ELF type.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the ELF entry point address.
 * @e_entry: The address of the entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		unsigned char *p = (unsigned char *)&e_entry;
		unsigned long int res = 0;
		int i;

		for (i = 7; i >= 0; i--)
		{
			res = (res << 8) | p[i];
		}
		e_entry = res;
	}

	printf("  Entry point address:               ");
	if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("%#lx\n", e_entry);
	}
	else
	{
		printf("%#x\n", (unsigned int)e_entry);
	}
}

/**
 * close_file - Closes an ELF file.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the ELF header.
 * @ac: The number of arguments.
 * @av: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	union {
		Elf64_Ehdr ehdr64;
		Elf32_Ehdr ehdr32;
	} header;
	int fd, r;

	if (ac != 2)
	{
		dprintf(2, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	r = read(fd, &header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		close_file(fd);
		exit(98);
	}

	check_elf(header.ehdr64.e_ident);
	printf("ELF Header:\n");
	print_magic(header.ehdr64.e_ident);
	print_class(header.ehdr64.e_ident);
	print_data(header.ehdr64.e_ident);
	print_version(header.ehdr64.e_ident);
	print_osabi(header.ehdr64.e_ident);
	print_abi(header.ehdr64.e_ident);

	if (header.ehdr64.e_ident[EI_CLASS] == ELFCLASS64)
	{
		print_type(header.ehdr64.e_type, header.ehdr64.e_ident);
		print_entry(header.ehdr64.e_entry, header.ehdr64.e_ident);
	}
	else
	{
		print_type(header.ehdr32.e_type, header.ehdr32.e_ident);
		print_entry(header.ehdr32.e_entry, header.ehdr32.e_ident);
	}

	close_file(fd);
	return (0);
}

