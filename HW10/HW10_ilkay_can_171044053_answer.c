#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 10000000
typedef struct node_s{
	int data;
	struct node_s *next;
}Node;

int get_line(FILE *inp);
int find_prime_num(int num);
void prime_linked(int find_timeof);
Node *InsertAtHead(Node **head, int data); 
void prime_arr(int *arr, int find_timeof);

int main(){
	int *arr;
	arr = (int*)malloc(MAX*sizeof(int));
	FILE *outp, *outp2;
	outp = fopen("output_prime_LinkedList.txt", "w");/*open files to write times*/
	outp2 = fopen("output_prime_dynamic_array.txt", "w");
	fclose(outp);
	fclose(outp2);
	clock_t t; /*calculate times with clock function*/
	double time_taken1, time_taken2, time_taken3;
    t = clock();
	prime_linked(500000);
    t = clock() - t;
    time_taken1 = ((double)t)/CLOCKS_PER_SEC; /*result is second; turn it to millisecond and write to the file*/
   	t = clock();
	prime_linked(750000);
    t = clock() - t;
    time_taken2 = ((double)t)/CLOCKS_PER_SEC;	
	prime_linked(1000000);
    t = clock() - t;
    time_taken3 = ((double)t)/CLOCKS_PER_SEC;
 	outp = fopen("output_prime_LinkedList.txt", "a");
 	fprintf(outp, "Process time for linked list between 1-500000:%lf millisecond \n", time_taken1*1000 );
 	fprintf(outp, "Process time for linked list between 1-750000:%lf millisecond \n", time_taken2*1000 );
 	fprintf(outp, "Process time for linked list between 1-1000000:%lf millisecond\n", time_taken3*1000 ); 
    clock_t a;
    a = clock();
	prime_arr(arr, 500000);
    a = clock() - a;
    time_taken1 = ((double)a)/CLOCKS_PER_SEC; 
    a = clock();
	prime_arr(arr, 750000);
    a = clock() - a;
    time_taken2 = ((double)a)/CLOCKS_PER_SEC;
    a = clock();
	prime_arr(arr, 1000000);
    a = clock() - a;
    time_taken3 = ((double)a)/CLOCKS_PER_SEC;
 	outp2 = fopen("output_prime_dynamic_array.txt", "a");
 	fprintf(outp2, "Process time for array between 1-500000:%lf millisecond \n", time_taken1*1000 );
 	fprintf(outp2, "Process time for array between 1-750000:%lf millisecond \n", time_taken2*1000 );
 	fprintf(outp2, "Process time for array between 1-1000000:%lf millisecond \n", time_taken3*1000 );
 	fclose(outp); /*close files*/
    fclose(outp2);
    free(arr);
    return 0;
}
int get_line(FILE *inp){ /* this function read 1 line from data*/
	int num;
	char str[1024];
	if(!feof(inp) ){ /* checks if file continuous and takes line */
		fgets(str,1024,inp);
		sscanf(str,"%d", &num); /* turns data to integer */
	} else {
		return -1; 					/* return -1 if file is finished*/
	}

	return num;						/* return num */
}
int find_prime_num(int num){ /* this function checks if a given number is prime number or not */
	int i;
	if(num<2){				/*if number is smaller than 2 it is not prime */
		return 0;			/* return 0*/
	}else {
		for(i=2; i<=(num/2); i++){	/*checks number */
			if(num%i==0){
				return 0;
			}
		}
	}	
	return 1; 				/*return 1 if number is prime */
}
void prime_linked(int find_timeof){ /*this function creates a link list and finds prime number in it*/
	int num,j;
	
	FILE *inp, *outp;
	Node *listHead=NULL;
	Node *currentNode;
 	
	inp = fopen("data.txt", "r");  /* open file */
	outp = fopen("output_prime_LinkedList.txt", "a");
		while(1){
			num = get_line(inp); /*read line get number*/
			if(num == -1 || num > find_timeof){ /*check for eof and when to stop in order to calculate time */
				break;
			}
			InsertAtHead(&listHead,num); /* create linked list*/
		}
		currentNode=listHead;
	while (currentNode->next != NULL) {		/*check for prime numbers through the link list and print*/
		if(find_prime_num(currentNode->data)==1){
			printf("%d\n",currentNode->data); 
			fprintf(outp, "%d\n",currentNode->data); 
		}          
		currentNode = currentNode->next;
    }
    Node * tempp = listHead;	/*free the memory*/
	while(tempp->next != NULL){
		tempp = tempp->next;
		free(listHead);
		listHead = tempp;
	}

    fclose(inp); /*close file*/
	fclose(outp);
}

Node *InsertAtHead(Node **head, int data) { /*this functions inserts a new node to linked list*/
    
	Node *newNode = (Node *) malloc(sizeof(Node));
	 if (*head == NULL) {	/*check if head is null and this is the first data and insert*/
       	
    	newNode->data = data; 
    	newNode->next = NULL;
        *head = newNode;
    } 
    else if (newNode != NULL) { /*else check if new node has a memory allocation and insert*/
        newNode->data = data;
        newNode->next = *head;
        *head = newNode; /*new node becomes head*/
    }
    return newNode; /*return new node which is head now*/
}

void prime_arr(int *arr, int find_timeof){
	int num=1, n=0 ;
	FILE *inp, *outp;
	inp = fopen("data.txt", "r");  /* open file */
	outp = fopen("output_prime_dynamic_array.txt", "a");
	arr = (int*)malloc(MAX*sizeof(int)); /*memory allocation*/
	while(num!=-1 && num <= find_timeof){ /*check eof and when to stop in order to calculate time*/
		num = get_line(inp); /*read each line and take numbers*/
		arr[n]=num; /**fill the array*/
		n++;
	}
	n=0;
	while(n<MAX){ /*go through the array */
		if(find_prime_num(arr[n])==1){ /* find prime numbers and print them */
			printf("%d\n", arr[n]);
			fprintf(outp, "%d\n", arr[n]);
		}
		n++;
	}
	fclose(inp); /*close file*/
	fclose(outp);
	free(arr); /*free memory */
}






