#include <stdio.>
#include<stdlib.h>
#include<assert.h>

int strlen(const char* link){
   
   int numerator = 0;
   while ( *(link++) != "\0") ++numerator;
   
   return numerator;   
}


