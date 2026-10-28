*𝘛𝘩𝘪𝘴 𝘱𝘳𝘰𝘫𝘦𝘤𝘵 𝘩𝘢𝘴 𝘣𝘦𝘦𝘯 𝘤𝘳𝘦𝘢𝘵𝘦𝘥 𝘢𝘴 𝘱𝘢𝘳𝘵 𝘰𝘧 𝘵𝘩𝘦 42  𝘤𝘶𝘳𝘳𝘪𝘤𝘶𝘭𝘶𝘮 𝘣𝘺 𝘮𝘪𝘵𝘳𝘰𝘷𝘪.*
# get_next_line

## Description
`get_next_line` is a 42 school project that challenges us to create a function capable of reading a single line from a fd (file descriptor). Repeated calls to this function allow you to read a text file compleetely, line by line, without losing the thread of what was read previously. 

# The Magic of BUFFER_SIZE
This project heavily relies on a macro called BUFFER_SIZE. It dictates exactly how many bytes the read() function will fetch from the file in a single call.
You can easily modify this value during compilation to test how the function behaves with very small chunks (e.g., 1) or very large ones (e.g., 9999). The code dynamically adapts and correctly extracts the line regardless of the size you choose!

# Doxigen Comment
To better understand my code functions and parameters, please look at the breaf explanation in Doxigen comments.
There you can see breaf explaination what function does, as well as an explanation of the parameters and what it returns.
Additionally, there is a small comment section regarding static variables in the main.c file to help you understand the core concept of this project.

# LIMITS:
You can check file descriptor limits directly in your terminal. Not the integrated VScode, but your native Linux terminal, using these two lines:
1. If you wanna check the soft limit:
   ```bash
   ulimit -Sn
You should see: 1024

2. If you wanna check hard limit:
   ```bash
   ulimit -Hn
I see now: 1048576

---

## Instructions

1. Clone the repository with `git clone`.
2. Run the following command at the root of the project to compile! P.S. You can change the 42 to any number you want to test different buffer sizes:
   ```bash
   cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42 -o gnl
3. You can copy my main.c and make a file to test GNL:
   ```bash
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

	fd = open(filename, O_RDONLY );
	// umesto da bude ovde -> 
	if (fd < 0)
	{
		//printf("Greska pri otvaranju fajla!\n");
		perror("open"); //treba da bude ovde? a ovaj printf mogu obrisati?
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
	//close(fd);
	if (close(fd) == -1)
    	perror("close"); // this is printing error to see did I close or open it right
	//perror("close"); // ali kako da proverim za close?
   }
   void    create_huge_file(char *filename, int num_lines)
   {
      int     fd;
      int     i;
      char    *line = "Ovo je ogromna linija za testiranje mog GNL-a!\n";

      fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
      if (fd >= 0)
      {
         i = 0;
         // Vrtimo petlju 10,000 puta (ili koliko god prosledimo)
         while (i < num_lines)
         {
               write(fd, line, ft_strlen(line));
               i++;
         }
         close(fd);
      }
   }

   void    create_single_file(char *filename, char *content)
   {
      int fd;
      
      // Otvaramo fajl za pisanje, pravimo ga ako ne postoji, brišemo stari sadržaj
      fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
      if (fd >= 0)
      {
         // Koristimo tvoj ft_strlen da znamo koliko bajtova upisujemo
         write(fd, content, ft_strlen(content)); 
         close(fd);
      }
   }

   void    make_all_test_files(void)
   {
      create_single_file("test.txt", "Prva linija\nDruga linija\nTreca linija\n");
      create_single_file("one_char.txt", "A");
      create_single_file("empty.txt", "");
      create_single_file("no_nl.txt", "Ovo je tekst bez novog reda na kraju");
      create_single_file("newlines.txt", "\n\n\n");
      // "file_non_existing.txt" namerno NE pravimo da bi testirali grešku!

      create_huge_file("test.txt", 10000);
   }

   int	main(void)
   {
      make_all_test_files();
      // Ovde izlistaš sve svoje .txt fajlove
      char *files[] = {
         "test.txt",
         "one_char.txt",
         "empty.txt",
         "no_nl.txt",
         "newlines.txt",
         "file_non_existing.txt",
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
4. Por el fin, just start the program:
   ```bash
   ./gnl
5. To check memory leaks use valgrind:
   ```bash
   valgrind ./gnl
## Explanation
# what should you see? 

You should see new files my main will make it, open and write into them.

After that GNL will read files, and depending on the BUFFER you send, you will see the extracted lines printed int your terminal.

## Resources:
Documentation: Man pages, Geekforgeeks, Gemini.

Peers: git hub: dmsosa, 42-alberto, Caperale, sebasvdata, cvizcain.

# AI usage:
AI was used as a supporting tool exclusively for proofreading, spell-checking, and correcting grammar in this README file.

## Thank you for your time!