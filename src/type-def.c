// // structures are custom types
// // these are several variables bundled together

// // following is a structure called a point
// // this needs to be placed above any function that uses it 
typedef struct {
	float x;
 	float y;
} point;

// // construct a new point 'p'
point p;
p.x = 0.1;
p.y = 10.0;

// // call the values of point 'p' by using . 
float length = sqrt(p.x * p.x + p.y * p.y);

// -------- type def custom data type extended ---------

// typedef are performed by the compiler
// #define are performed by the preprocessor

#include <stdio.h>
#include <string.h>

// below is a data type for storing books
typedef struct Books{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
} Book;

int main(){
	Book book;

	strcpy(book.title, "C Programming");
	strcpy(book.author, "Lakith");
	strcpy(book.subject, "Programming Tute");
	book.book_id = 1241355;

	printf ( "Book title : %s\n", book.title);
	printf ( "Book author : %s\n", book.author);
	printf ( "Book subject : %s\n", book.subject);
	printf ( "Book title : %d\n", book.book_id);

	return 0;
}
