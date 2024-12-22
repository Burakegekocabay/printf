# printf
Alternative printf function in C language for 42 Istanbul Common Core project.

# Requirements

**Program name:** libftprintf.a <br>
**Turn in files:**  (Makefile) , (\*.h) ,  (\*/*.h) , (\*.c) ,  (\*/*.c) <br>
**External functs:** (malloc), (free), (write),
(va_start), (va_arg), (va_copy), (va_end) <br>
**Description:** Write a library that contains ft_printf(), a
function that will mimic the original printf()


**Here are the requirements:** <br>
• Don’t implement the buffer management of the original printf().<br>
• Your function has to handle the following conversions:<br> 
(%c %s %p %d %i %u %x %X %%)<br>
• Your function will be compared against the original printf().<br>
• You must use the command **ar** to create your library.<br>
Using the **libtool** command is forbidden.<br>
• Your **libftprintf.a** has to be created at the root of your repository.<br>


**You have to implement the following conversions:**
• %c Prints a single character. <br>
• %s Prints a string (as defined by the common C convention). <br>
• %p The void * pointer argument has to be printed in hexadecimal format <br>
• %d Prints a decimal (base 10) number. <br>
• %i Prints an integer in base 10. <br>
• %u Prints an unsigned decimal (base 10) number. <br>
• %x Prints a number in hexadecimal (base 16) lowercase format. <br>
• %X Prints a number in hexadecimal (base 16) uppercase format. <br>
• %% Prints a percent sign. <br>