#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 
#define MAX_SIZE 100
int numbers[1000000]; //blank array
//allocation because of giving argument of pointer on array 
int *allocate_number(){
  int *number = malloc(MAX_SIZE * (sizeof(int)));
  if (number == NULL){
    exit (-1);
  }
  //initialization of all values in array
  for (int i = 0; i < MAX_SIZE; i++){
    number[i] = 0;
  }
  return number;
}
//dividing number as in elementary school
//returning legth of result after dividing
int divide_number(int number[], int pr_number, int size){
  int result[size]; 
  int div = 0; //reamining number after diving 
  int i = 0; 
  int res = 0; //length of result of dividing
 
  while (i < size + 1){
    //making number from array we need to divide
    if (div < pr_number && res == 0){
      div *= 10;
      div += number[i];
      i++;
    }else{
      result[res] = div/pr_number;
      res++;
      div = div % pr_number;
      div *= 10;
      div += number[i];
      i++;
    }
  }
  //write down the result into a pointer(we cant return it)
  if (div == 0){
    for (int k = 0; k < size; k++){
      if (k >= res){
        number[k] = 0; //other elements should be 0 for seperation of the number we need
      }else{
        number[k] = result[k];
      }
    }
    return res;
  }else{
    return 0;
  }
    
}
 
/* The main program */
int main(int argc, char *argv[])
{
  //computeSieve
  int maxsize = 1000000; 
  int prime_number[80000]; //array with all prime numbers we find in numbers
  int n = 0; //variable needed for noting down all prime numbers from numbers in prime_number[]
   
  //creating array of prime numbers 
  for (int k = 2; k < maxsize; k++){ //going through array from index 2 to maxsize
    if (numbers[k] == 0){ 
      for (int l = 2; l*k < maxsize; l++){ //counting every multiplicand of prime number 
        numbers[l*k] = 1;
      }
      prime_number[n] = k; //noting down the index of numbers[], because the element is just saying if it's prime or non prime number 
      n++; 
    }
  }
   
  int temp = 0;
   
  while(temp == 0){
    char c;
    int *number;
    number = allocate_number();
    int len = 0;
    //scanning one number
    while ((c = getc(stdin)) != '\n'){
      //c should be a digit if not -> error
      if (c >= '0' && c <= '9'){
        number[len] = (int)c - 48;
        len++;
      }else{
        fprintf(stderr, "Error: Chybny vstup!\n");
        free(number);
        return 100;
      }
    }
    if (number[0] == 0 && len == 1){ //EOF is 0
      temp = 1;
    }else{
       
      printf("Prvociselny rozklad cisla ");
      for (int j = 0; j < len; j++){
        printf("%d", number[j]);
      }
      printf(" je:\n");
 
      //decompose
      int count = 0; //the number of times the prime number fits into number
      int x = 0; //temporary variable for printing x in between numbers
      int pr_number;
     
      if (number[0] == 1 && len == 1){ //handeling exeption when number is 1
        printf("%d", number[0]);
      }
      for (int i = 0; i < n; i++){ //going through all prime numbers
        pr_number = prime_number[i]; 
         
        //delime nase cislo pr_number a vracime modulo
        int result;
        while ((result = divide_number(number, pr_number, len)) != 0 ){ //testing if the prime number is in decomposition
           
          count +=1; //counting how many times is the number cutted down by the prime number 
          len = result; 
        }
       
        if (count > 0){ //is counted
         
          if (x == 1){ //we have printed prime number already
            printf(" x ");
          }
 
          if (count == 1){ 
            printf("%d", pr_number);
          }else{
            printf ("%d^%d", pr_number, count);
          }
         
          x = 1; //set temp to alert we have prime number
        }
        count = 0;
        if (number[0] == 1 && result == 1){ //decomposition is done
          break;
        }
      }
      printf("\n");
    }
    free(number);
  }
 
  return 0;
}
