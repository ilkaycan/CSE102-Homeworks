#include <stdio.h>
char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current);
char* cat(char *destination, const char *source);
char* copy(char *destination, const char *source);
int main(){
	int expected_val=44, arr_len=6,i;
	int arr[6]={25,12,6,10,32,8};
	char operations[6];
	for(i=0;i<arr_len;i++){
		operations[i]=0;
	}
	printf("Operations:%s\n", find_operations(arr, expected_val, operations, arr_len, 1, arr[0]));
	return 0;
}
char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current){
	char op1[arr_len], op2[arr_len], op3[arr_len], control[arr_len]; /*every operation has an operation array*/
	copy(op1, operations); /*old operations copied to these customized arrays*/
	copy(op2, operations);
	copy(op3, operations);
	if(arr_len == (cursor)){    /*termination condition*/
		if(current==expected_val){ /*if reached to expected value*/
			return operations; /*return operations */
		}else{ /*else if can't reach */
			for(int i=0;i<arr_len ; i++){  
				operations[i]=' ';
			}
			return operations;   /*return list of spaces*/
		}
	}
	cat(op1,"+"); /*op1 is +'s array*/
	copy(control, find_operations(arr, expected_val, op1, arr_len, cursor+1, current+arr[cursor])); /*call function again*/
	if(control[0]!=' '){  								 /*and copy its return value to control array*/
			return copy(operations, control);  			 /*if succeeded it will be full with operations*/
	}									 /*but we can't return control cause it will dissappear with every recursion*/			
	cat(op2,"-");/*op2 is -'s array*/											
	copy(control, find_operations(arr, expected_val, op2, arr_len, cursor+1, current-arr[cursor]));
	if(control[0]!=' '){
			return copy(operations, control);				/*do the same thing for every operation*/
	}														/*so it will try every choice untill find the right one*/
	cat(op3,"*");/*op3 is *'s array*/
	copy(control, find_operations(arr, expected_val, op3, arr_len, cursor+1, current*arr[cursor]));		
	if(control[0]!=' '){
			return copy(operations, control);
	}	
	for(int i=0;i<arr_len-1; i++){  /*in fail situation return spaces*/
		operations[i]=' ';
	}
	return operations;
}
char* cat(char *destination, const char *source) /* strcat function */
{
    int i,j;
    for (i = 0; destination[i] != 0; i++);
    for (j = 0; source[j] != 0; j++){
        	destination[i+j] = source[j];
    	}
    destination[i+j] = 0;
    return destination;
}
char* copy(char *destination, const char *source){ /* strcpy function*/
 	 	char* result = destination;
 	 	if((destination!=0) && (source!=0)){
  	    	while (*source!=0){
 	       		*destination++ = *source++;
 	     	}
  	     	*destination = 0;
  	   	}
  	return result;
}