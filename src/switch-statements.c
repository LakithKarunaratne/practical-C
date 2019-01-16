#include <stdio.h>

int main(){ // here the main is declared without void

	// local variable to be tested
	// change the below to A B C D F and check output 
	char grade = 'B'; // chars are single quotes, can store 1 char 

	switch(grade){
		case 'A' :
			printf("Great Score!\n");
			break;
		// intentionally left blank
		case 'B': 
			// no break statements means it'll overflow
		case 'C':
			// no break statements means it'll overflow
		case 'D':
			printf("Try harder! \n");
		case 'F':
			printf("sit for the exam again \n");
			break;// much needed to stop overflow of condition
		default: // no conditions are met this will be shown
			printf("invalid grade \n");
	}
	printf("Your grade is %c\n", grade);

	return 0; // end of programme 
}
