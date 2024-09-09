#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursive_fibonacci(int n) {     // Takes in the nth number to calculate to
   // Checks certain cases that do not need calculation
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

int iterative_fibonacci(int n) {     // Takes in the nth number to calculate to
   int first = 0;
   int second = 1;
   int sum;
   int ix;                 // Iterator variable that keeps track of the nth iteration of the Fibonacci sequence
   
   // Checks certain cases that do not need calculation
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   for (ix = 3; ix <= n; ix++) {
      sum = first + second;         // Stores the current Fibonacci number
      first = second;               // Sets variable to the next Fibonacci number
      second = sum;                 // Sets variable to the next Fibonacci number
   }
   return sum;
}

int main(int argc, char *argv[]) {   // Reads command line arguments and stores them in argv
   
   int command_line_input = atoi(argv[1]);   // Stores the integer to be added to the one in the file
   const char *method = argv[2];             // Stores the method of calculating the Fibonacci Sequence
   const char *file_name = argv[3];          // Stores the file name 
   char file_string[50];                     // Creates a string to store the contents of the file
   int file_integer;                         // Creates an integer to store the converted file_string
   int answer;                               // Creates an integer to store the answer

   FILE *file_pointer = fopen(file_name, "r");  // Opens the file in read mode
   fgets(file_string, 50, file_pointer);        // Reads up to 50 characters from the file and stores it in file_string
   fclose(file_pointer);                        // Closes the file

   file_integer = atoi(file_string);            // Converts file_string to an integer

   int nth_fibonacci_number = file_integer + command_line_input;

   // Checks the method of calculation and calls the respective function and returns the result
   if (strcmp(method, "i") == 0) {
      answer = iterative_fibonacci(nth_fibonacci_number);
      printf("%d", answer);
      return answer;
   } else if (strcmp(method, "r") == 0) {
      answer = recursive_fibonacci(nth_fibonacci_number);
      printf("%d", answer);
      return answer;
   } else {                                     // Prints an error in case of an invalid input
      printf("Unrecognized method.\n");
   }
   return 0;
}