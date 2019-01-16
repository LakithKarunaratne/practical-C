#include <stdio.h>

// for linux / mac the cursor movement can produce unwanted exceptions 
#include <stdlib.h>
// #include <editline/readline.h>
// #include <editline/history.h>

// declare buffer for user input
static char input[2048]; // global var declared outside of the main method

int main(int argc, char** argv){

	// print the version and exit info
	puts("lispy version 0.0.0.0.1");
	puts("Press Ctrl+C to Exit\n");

	// never ending loop
	while (1) {
		// output our prompt
		// DISABLE FOR *NIX
		fputs("lispy> ", stdout);

		// read a line of user input, max size 2048
		// DISABLE FOR *NIX
		fgets(input, 2048, stdin); // take the input and store in the global var

		// *nix , output and get input 
		// char* input = readline("lispy> "); // from editline

		// *nix , add to history
		// add_history(input); // from editline

		// echo input back to user
		printf("> %s", input);
		// printf("> %s\n", input); // NIX, the trailing new line is stripped

		// *nix , free the input 
		free(input); // from - stdlib.h
	}
	return 0;
}

/* 
// --------------- Whats happening (Non *nix)--------------- //

Let's go over this program in a little more depth.

The line static char input[2048]; declares a global array of 2048 characters. This is a reserved block of data we can access anywhere from our program. In it we are going to store the user input which is typed into the command line. The static keyword makes this variable local to this file, and the [2048] section is what declares the size.

We write an infinite loop using while (1). In a conditional block 1 always evaluates to true. Therefore commands inside this loop will run forever.

To output our prompt we use the function fputs. This is a slight variation on puts which does not append a newline character. We use the fgets function for getting user input from the command line. Both of these functions require some file to write to, or read from. For this we supply the special variables stdin and stdout. These are declared in <stdio.h> and are special file variables representing input to, and output from, the command line. When passed this variable the fgets function will wait for a user to input a line of text, and when it has it will store it into the input buffer, including the newline character. So that fgets does not read in too much data we also must also supply the size of the buffer 2048.

To echo the message back to the user we use the function printf. This is a function that provides a way of printing messages consisting of several elements. It matches arguments to patterns in the given string. For example in our case we can see the %s pattern in the given string. This means that it will be replaced by whatever argument is passed in next, interpreted as a string.

For more information on these different patterns please see the documentation on printf.

*/


/* 
// --------------- Whats happening (*nix)--------------- //
We have included a few new headers. There is #include <stdlib.h>, which gives us access to the free function used later on in the code. We have also added #include <editline/readline.h> and #include <editline/history.h> which give us access to the editline functions, readline and add_history.

Instead of prompting, and getting input with fgets, we do it in one go using readline. The result of this we pass to add_history to record it. Finally we print it out as before using printf.

Unlike fgets, the readline function strips the trailing newline character from the input, so we need to add this to our printf function. We also need to delete the input given to us by the readline function using free. This is because unlike fgets, which writes to some existing buffer, the readline function allocates new memory when it is called. When to free memory is something we cover in depth in later chapters.
*/

/* NIX COMPILATION ISSUES 

On Mac the editline library comes with Command Line Tools. Instructions for installing these can be found in Chapter 2. You may still get an error about the history header not being found. In this case remove the line #include <editline/history.h>, as this header may not be required.

On Linux you can install editline with sudo apt-get install libedit-dev. On Fedora you can use the command su -c "yum install libedit-dev*"
Once you have installed editline you can try to compile it again. This time you'll get a different error.

undefined reference to `readline'
undefined reference to `add_history'

This means that you haven't linked your program to editline. This linking process allows the compiler to directly embed calls to editline in your program. You can make it link by adding the flag -ledit to your compile command, just before the output flag.

cc -std=c99 -Wall prompt.c -ledit -o prompt
Run it and check that now you can edit inputs as you type them in.

*/
