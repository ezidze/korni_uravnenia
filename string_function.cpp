#include <stdio.h>

#include<stdlib.h>

#include<assert.h>



int strlen(const char* link){

   assert(link);

   int numerator = 0;

   while ( *(link++) ) ++numerator; 

   return numerator;

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