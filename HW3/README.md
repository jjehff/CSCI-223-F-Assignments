HW03: Fun With Character I/O
Here's your chance to experiment with character I/O and redirection operators. You're to write a pair of programs that encode and decode the input stream. The char2byte program should simply copy characters from stdin to stdout. However, after reading an input character the program should write it out in its hexadecimal format. Thus, a hexadecimal dump of stdin is created. The byte2char program should basically do the same thing in reverse -- it will read a hexadecimal value from stdin and write it to stdout in its ASCII character representation. (Hmm, think about that for a moment -- how can you read a char from stdin, then write it to stdout in hex? It might be easier than you think...)

All of this is fine and dandy, but it's not much fun if we have to type all the data in from the keyboard. So what you should do instead is use the redirection operators from the command line. To illustrate, I created a simple text file using the "man" command and called it uname_org.txt Download uname_org.txt (click on the filename link to see what it looks like). After building the char2byte executable, I typed this at the command line prompt:

   ./c2b < uname_org.txt > uname_hex.txt

(BTW -- there are a few ways to rename your executable file to something other than the default "a.out"... One way is to use the -o switch, like this: gcc char2byte.c -o c2b. That tells the compiler that the name of the output file should be c2b instead of a.out. For this assignment it might be easier for you to have different names for the executable files you build, like c2b and b2c, so you won't have to keep rebuilding and overwriting them with a.out.)

This command would run the char2byte program and attach stdin to the file uname_org.txt (instead of the keyboard) and attach stdout to uname_hex.txt Download uname_hex.txt (click on the filename link to see the results). Thus, the program would read characters from the input file and write them to the output file. What you end up with is a hexadecimal dump of "uname_org.txt" in the file "uname_hex.txt".

Next, I made sure that I was able to derive a duplicate of the original "uname_org.txt" using "uname_hex.txt". After building the byte2char program I typed this:

   ./b2c < uname_hex.txt > uname_new.txt

which caused the byte2char program to read its input from "uname_hex.txt" and write its output to "uname_new.txt". Thus, uname_new.txt and uname_org.txt are identical copies of each other.

NOTE: The programs should work with any text files, I only used the "uname" set as an example. To test your programs use any text file(s) you want!

When you produce the hexadecimal output you should make sure that the values are all expressed using two digits (use leading zeros if necessary). Also, there should be no more than 20 hex values on a single row. (Hint: before you jump to the keyboard and start typing code, take a few moments to think about how printf and scanf can help you out with these programs...) You should place your code in the files byte2char.c and char2byte.c in the HW03 subdirectory.

48 61 76 65 20 66 75 6E 21 21 0A
