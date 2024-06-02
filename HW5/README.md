Okay, now you've gone too far! Or, at least your text file has...

For your next program, you get to inspect the contents of a text file and see if it has any lines that contain more than 80 characters. To get a feel for how the program should behave, I've gone ahead and created a HW05 subdirectory for you and placed line_lengths_starter_kit.tar.gz in there. (To extract the files, type tar xvzf line_lengths_starter_kit.tar.gz at the command line prompt.) In the archive you'll find an executable file called sample_linelen along with several text files that can be used as test input files. The executable simply reads from stdin one character at a time. If it finds any lines in an input file that exceed 80 characters, it will display the lengths of those lines. For example, if you execute your program like this:

   ./sample_linelen <test1.txt

you should see output like this:

   Line 2 has 81 characters
   Line 3 has 82 characters
   Line 4 has 83 characters
   Line 5 has 84 characters
   Line 6 has 84 characters
   Line 7 has 83 characters
   Line 8 has 82 characters
   Line 9 has 81 characters

All the program is doing is reporting to stdout any lines on the input stream that exceed 80 characters; if no lines are of excessive length a message appears indicating the input file is valid. So think carefully about how you're going to do this before you do it! Taking the time to plan carefully and derive a working algorithm before you write any code will save you lots of time and frustration. The starter kit I've provided contains some sample text files you can use as input to your program, and at the bottom of each text file is the output your program should produce when processing the text file. Of course, feel free to try using your own test files as well! You can save your code in a file called line_lengths.c in the HW05 subdirectory. So go ahead and give it your best shot!

