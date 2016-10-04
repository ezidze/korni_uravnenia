#include <stdio.h>

#include<stdlib.h>

#include<assert.h>

<<<<<<< HEAD


int strlen(const char* link){

   assert(link);

   int numerator = 0;

   while ( *(link++) ) ++numerator; 

   return numerator;

=======
int strlen(const char* link){
   
   int numerator = 0;
   while ( *(link++) != "\0") ++numerator;
   
   return numerator;   
>>>>>>> c22a0bb55c56a2cb58a6af8eabbe96c91867f786
}

int main(){

	char line[] = "blablabla Ivanov Iliy";
	printf("enter a line of text\n");
	scanf(line);
	printf("the string has a length ");
	printf("%d\n", strlen(line));

	system("pause");

	return 0;

}