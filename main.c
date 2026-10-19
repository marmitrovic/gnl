/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 12:45:00 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/10/19 13:16:05 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

/** @brief			using systems function named Open();
 * a powerfull tool we use to open a file, and with different flags, we can just
 * read, write, append in that file you can find that function in fcntl library
 * that function returns just a number, that represents a stack number above 2,
 * because 0 represents input, 1 output, and 2 output error
 * at the end what we open needs to be close(fd);
 * 
 * @param filename	
 */
void	test_file(char *filename)
{
	int		fd;
	char	*line;
	int		line_count;

	printf("\n========================================\n");
	printf("TESTIRAM FAJL: %s\n", filename);
	printf("========================================\n");

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Greska pri otvaranju fajla!\n");
		return ;
	}
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s", line_count, line);
		free(line); // Obavezno oslobađamo izvučenu liniju!
		line_count++;
	}
	printf("\n--- KRAJ FAJLA (GNL je vratio NULL) ---\n");
	close(fd);
}

int	main(void)
{
	// Ovde izlistaš sve svoje .txt fajlove
	char *files[] = {
		"test.txt",
		"one_char.txt",
		"empty.txt",
		"no_nl.txt",
		NULL // Oznaka za kraj niza
	};

	int i = 0;
	while (files[i] != NULL)
	{
		test_file(files[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>


// this is a test for static int

void test_staticka(void)
{
	static int a = 0; // Inicijalizuje se SAMO PRVI PUT!
	a++;
	printf("%d \n", a);
}

int main()
{
	test_staticka();
	test_staticka();
	test_staticka();
	return 0;
} */