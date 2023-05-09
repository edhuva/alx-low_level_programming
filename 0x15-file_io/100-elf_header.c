#include <stdlib.h>
#include <elf.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

void prnt_class(unsigned char *e_ident);
void prnt_data(unsigned char *e_ident);
void prnt_magic(unsigned char *e_ident);
void prnt_version(unsigned char *e_ident);
void prnt_type(unsigned int e_type, unsigned char *e_ident);
void prnt_entry(unsigned long int e_entry, unsigned char *e_ident);
void prnt_abi(unsigned char *e_ident);
void prnt_osabi(unsigned char *e_ident);
void close_elf(int elf);
void check_elf(unsigned char *e_ident);

/**
 * prnt_class - prints class of ELF_header.
 * @e_ident: points an array containing ELF_class.
 */
void prnt_class(unsigned char *e_ident)
{
	printf(" Class: ");
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
 * prnt_data - prints data of ELF_header.
 * @e_ident: points an array containing ELF_class.
 */
void prnt_data(unsigned char *e_ident)
{
	printf(" Data: ");
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * prnt_magic - prints magic num of ELF_header.
 * @e_ident: points an array containing ELF magic_num.
 *
 * Description: Magic_nums are separated by spaces.
 */
void prnt_magic(unsigned char *e_ident)
{
	int indx;

	printf(" Magic: ");
	for (indx = 0; indx < EI_NIDENT; indx++)
	{
		printf("%02x", e_ident[indx]);
		if (indx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * prnt_version - prints version of ELF_header.
 * @e_ident: points an array containing ELF_version.
 */
void prnt_version(unsigned char *e_ident)
{
	printf(" Version: %d", e_ident[EI_VERSION]);
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
 * prnt_type - prints type of ELF_header.
 * @e_type: ELF_type.
 * @e_ident: points an array containing ELF_class.
 */
void prnt_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf(" Type: ");
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
 * prnt_entry - prints entry_point of ELF_header.
 * @e_entry: address of ELF_entry_point.
 * @e_ident: points an array containing ELF_class.
 */
void prnt_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * prnt_abi - prints ABI_version of ELF_header.
 * @e_ident: points an array containing ELF_ABI_version.
 */
void prnt_abi(unsigned char *e_ident)
{
	 printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}
/**
 * prnt_osabi - prints OS/ABI of ELF_header.
 * @e_ident: points an array containing ELF_version.
 */
void prnt_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
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
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
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
 * close_elf - closes ELF_file.
 * @elf: file_descriptor of ELF_file.
 *
 * Description: If file not_closed - exit_code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
/**
 * check_elf - Checks if file is ELF_file.
 * @e_ident: points an array containing ELF_magic_num.
 *
 * Description: If file is not_ELF_file - exit_code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int indx;

	for (indx = 0; indx < 4; indx++)
	{
		if (e_ident[indx] != 127 &&
		    e_ident[indx] != 'E' &&
		    e_ident[indx] != 'L' &&
		    e_ident[indx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * main - displays infor contained in ELF_header
 * at start of ELF_file.
 * @argc: num of arguments_supplied to program.
 * @argv: array of pointers to arguments.
 *
 * Return: 0 success.
 *
 * Description: If file is not ELF_File else
 * func fails - exit_code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *headerr;
	int rd, opn;

	opn = open(argv[1], O_RDONLY);
	if (opn == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	headerr = malloc(sizeof(Elf64_Ehdr));
	if (headerr == NULL)
	{
		close_elf(opn);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(opn, headerr, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(headerr);
		close_elf(opn);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(headerr->e_ident);
	printf("ELF Header:\n");
	prnt_magic(headerr->e_ident);
	prnt_class(headerr->e_ident);
	prnt_data(headerr->e_ident);
	prnt_version(headerr->e_ident);
	prnt_osabi(headerr->e_ident);
	prnt_abi(headerr->e_ident);
	prnt_type(headerr->e_type, headerr->e_ident);
	prnt_entry(headerr->e_entry, headerr->e_ident);

	free(headerr);
	close_elf(opn);
	return (0);
}
