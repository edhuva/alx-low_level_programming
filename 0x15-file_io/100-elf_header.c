#include <stdlib.h>
#include <elf.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

void prnt_class(unsigned char *e_identt);
void prnt_data(unsigned char *e_identt);
void prnt_magic(unsigned char *e_identt);
void prnt_version(unsigned char *e_identt);
void prnt_type(unsigned int e_typee, unsigned char *e_identt);
void prnt_entry(unsigned long int e_entryy, unsigned char *e_identt);
void prnt_abi(unsigned char *e_identt);
void prnt_osabi(unsigned char *e_identt);
void close_elf(int elff);
void check_elf(unsigned char *e_identt);

/**
 * prnt_class - prints class of ELF_header.
 * @e_identt: points an array containing ELF_class.
 */
void prnt_class(unsigned char *e_identt)
{
	printf(" Class: ");
	switch (e_identt[EI_CLASS])
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
		printf("<unknown: %x>\n", e_identt[EI_CLASS]);
	}
}
/**
 * prnt_data - prints data of ELF_header.
 * @e_identt: points an array containing ELF_class.
 */
void prnt_data(unsigned char *e_identt)
{
	printf(" Data: ");
	switch (e_identt[EI_DATA])
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
		printf("<unknown: %x>\n", e_identt[EI_CLASS]);
	}
}
/**
 * prnt_magic - prints magic num of ELF_header.
 * @e_identt: points an array containing ELF magic_num.
 *
 * Description: Magic_nums are separated by spaces.
 */
void prnt_magic(unsigned char *e_identt)
{
	int indx;

	printf(" Magic: ");
	for (indx = 0; indx < EI_NIDENT; indx++)
	{
		printf("%02x", e_identt[indx]);
		if (indx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * prnt_version - prints version of ELF_header.
 * @e_identt: points an array containing ELF_version.
 */
void prnt_version(unsigned char *e_identt)
{
	printf(" Version: %d", e_identt[EI_VERSION]);
	switch (e_identt[EI_VERSION])
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
 * @e_typee: ELF_type.
 * @e_identt: points an array containing ELF_class.
 */
void prnt_type(unsigned int e_typee, unsigned char *e_identt)
{
	if (e_identt[EI_DATA] == ELFDATA2MSB)
		e_typee >>= 8;
	printf(" Type: ");
	switch (e_typee)
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
		printf("<unknown: %x>\n", e_typee);
	}
}
/**
 * prnt_entry - prints entry_point of ELF_header.
 * @e_entryy: address of ELF_entry_point.
 * @e_identt: points an array containing ELF_class.
 */
void prnt_entry(unsigned long int e_entryy, unsigned char *e_identt)
{
	printf(" Entry point address: ");
	if (e_identt[EI_DATA] == ELFDATA2MSB)
	{
		e_entryy = ((e_entryy << 8) & 0xFF00FF00) |
			((e_entryy >> 8) & 0xFF00FF);
		e_entryy = (e_entryy << 16) | (e_entryy >> 16);
	}
	if (e_identt[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entryy);
	else
		printf("%#lx\n", e_entryy);
}
/**
 * prnt_abi - prints ABI_version of ELF_header.
 * @e_identt: points an array containing ELF_ABI_version.
 */
void prnt_abi(unsigned char *e_identt)
{
	 printf(" ABI Version: %d\n",
		e_identt[EI_ABIVERSION]);
}
/**
 * prnt_osabi - prints OS/ABI of ELF_header.
 * @e_identt: points an array containing ELF_version.
 */
void prnt_osabi(unsigned char *e_identt)
{
	printf(" OS/ABI: ");
	switch (e_identt[EI_OSABI])
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
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
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
		printf("<unknown: %x>\n", e_identt[EI_OSABI]);
	}
}
/**
 * close_elf - closes ELF_file.
 * @elff: file_descriptor of ELF_file.
 *
 * Description: If file not_closed - exit_code 98.
 */
void close_elf(int elff)
{
	if (close(elff) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elff);
		exit(98);
	}
}
/**
 * check_elf - Checks if file is ELF_file.
 * @e_identt: points an array containing ELF_magic_num.
 *
 * Description: If file is not_ELF_file - exit_code 98.
 */
void check_elf(unsigned char *e_identt)
{
	int indx;

	for (indx = 0; indx < 4; indx++)
	{
		if (e_identt[indx] != 127 &&
		    e_identt[indx] != 'E' &&
		    e_identt[indx] != 'L' &&
		    e_identt[indx] != 'F')
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
	check_elf(headerr->e_identt);
	printf("ELF Header:\n");
	prnt_magic(headerr->e_identt);
	prnt_class(headerr->e_identt);
	prnt_data(headerr->e_identt);
	prnt_version(headerr->e_identt);
	prnt_osabi(headerr->e_identt);
	prnt_abi(headerr->e_identt);
	prnt_type(headerr->e_typee, headerr->e_identt);
	prnt_entry(headerr->e_entryy, headerr->e_identt);

	free(headerr);
	close_elf(opn);
	return (0);
}
