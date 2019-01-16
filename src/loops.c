// // while loop
// int i = 10; // initial value
// while (i>0){ // condition statement
// 	puts("loop iteration"); // output statement
// 	i = i - 1; // initial value modifiyer 
// }

// // for loop
// for (int i=0; i<10; i++){
// 	puts ("For loop iteration");
// }

// ----- do while ---------
// i = 5
// do {
// 	puts("doing something !");
// 	i = i - 1 
// } while (i > 0);

// ----- Tested Examples ---------
#include <stdio.h>

int main (void){
 	printf("hello\n");

// print a for loop
for (int i = 0; i<5; i++){
	puts("for loop\n") ;
}

// print a while loop
int iter = 5;
while (iter > 0){
	puts("while loop \n");
	iter = iter - 1;
}

int i = 5;
do {
	printf("doing a count down : %d\n" , i);
	i = i - 1 ;
} while (i > 0);

return 0; // program exit safe verifyer 		
}
