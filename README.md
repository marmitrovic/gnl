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

---

## Instructions

1. Clone the repository with `git clone`.
2. Run the following command at the root of the project to compile! P.S. You can change the 42 to any number you want to test different buffer sizes:
   ```bash
   cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42 -o gnl
3. Por el fin, just start the program:
   ```bash
   ./gnl
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