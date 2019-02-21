#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Customer{
	int number;
	char name[30];
	char surname[30];
	int age;
	char gender[30];
	struct Customer *link;
} Customer;

typedef struct Room{
	int number;
	int capasity;
	int floor;
	Customer *customer;
	Customer *previous; 
	struct Room *link;
} Room;

void create_room(Room **head,Room **previous);
Room *add_room_to_end(Room **head, Room **previousNode, int num, int capa, int flo);
void add_room_after_room_number(Room **head, int pre_room_number, int num, int capa, int flo, Customer *custom);
void create_customer(Customer **head,Customer **previous);Customer *add_customer_to_end(Customer **head, Customer **previousNode,	int num, char *name, 
char *surname, int age, char *gender);
void link_customers_to_room(Room **headRoom, Customer **headCustomer);
void remove_room(Room **head, int room_number);
void show_vacancy(Room *head);
void get_by_floor(Room *head, int floor_num);
void print_list(Room *head);
Room *find_node(Room **head, int num);

int main(){
	Room *roomhead = NULL;
	Room *roomTail = NULL;
	Room *temp;
	Customer *customerhead = NULL;
	Customer *customerTail = NULL;
	Customer *tempp;
	create_room(&roomhead,&roomTail);
	create_customer(&customerhead,&customerTail);
	//add_room_after_room_number(&roomhead, 408, 409, 5, 5, NULL); 
	//get_by_floor(roomhead, 1);
	link_customers_to_room(&roomhead, &customerhead);
	//show_vacancy(roomhead);
	print_list(roomhead);
	temp = roomhead; 
	tempp = customerhead;
	while(temp->link != NULL){   /* free the lists*/
		temp = temp->link;
		free(roomhead);
		roomhead = temp;
	}
	while(tempp->link != NULL){
		tempp = tempp->link;
		free(customerhead);
		customerhead = tempp;
	}
	return 0;
}
/*This function reads infos from file and creates a room linked list by using add_room_to_end*/ 
void create_room(Room **head,Room **previous){ 
	FILE *inp;
	int num, capa, flo;
	
	inp = fopen("rooms.txt" , "r");
	while(!feof(inp))
	{
		fscanf(inp, "%d,%d,%d\n", &num, &capa, &flo);
		*previous = add_room_to_end(head, previous, num, capa, flo);
	}

	fclose(inp);
}
/*This function adds a new node to end*/
Room *add_room_to_end(Room **head, Room **previousNode, int num, int capa, int flo){
	Room *newNode = (Room *) malloc(sizeof(Room));
	if (*head == NULL) {	/*check if head is null and this is the first data and insert*/
       	
    	newNode->number = num; 
    	newNode->capasity = capa;
   		newNode->floor = flo;
   		newNode->customer = NULL; /* all rooms are empty first */
   		newNode->link = NULL;
   		*head = newNode;
   		*previousNode=*head;

    } else if (newNode != NULL) { /*else check if new node has a memory allocation and insert*/
      	newNode->number = num; 
    	newNode->capasity = capa;
   		newNode->floor = flo;
   		newNode->customer = NULL;
   		newNode->link = NULL;
   		(*previousNode)->link = newNode;
   		*previousNode = (*previousNode)->link;

    }
    return *previousNode; /*return previous node to use as parameter for next function call*/
}
/*This function reads infos from file and creates a linked list for customer by using add_customer_to_end*/ 
void create_customer(Customer **head,Customer **previous){

	FILE *inp;
	int num, age;
	char *name, *surname, *gender;
	char temp[1024], *numc, *agec;
	
	inp = fopen("customers.txt" , "r");
	
	while(fgets(temp,1024,inp)) /*take all line to a string and seperate it*/
	{                 
		numc = strtok(temp, ",");
		sscanf(numc, "%d", &num);
		name = strtok(NULL, " ");
		surname = strtok(NULL, ",");
		agec = strtok(NULL,",");
		sscanf(agec, "%d", &age);
		gender = strtok(NULL, "\n");
		*previous = add_customer_to_end(head, previous, num, name, surname, age, gender);

	}
	fclose(inp);
}
/*This function adds a new node to end for customer linked list*/
Customer *add_customer_to_end(Customer **head, Customer **previousNode,	int num, char *name, 
char *surname, int age, char *gender){

	Customer *newNode = (Customer *) malloc(sizeof(Customer));

	if (*head == NULL) {	/*check if head is null and this is the first data and insert*/
       	
    	newNode->number = num; 
    	strcpy(newNode->name, name);
   		strcpy(newNode->surname, surname);
   		newNode->age = age;
   		strcpy(newNode->gender, gender);
   		newNode->link = NULL;
   		*head = newNode;
   		*previousNode=*head;
    } else if (newNode != NULL) { /*else check if new node has a memory allocation and insert*/
      	
    	newNode->number = num; 
    	strcpy(newNode->name, name);
   		strcpy(newNode->surname, surname);
   		newNode->age = age;
   		strcpy(newNode->gender, gender);
   		newNode->link = NULL;
   		(*previousNode)->link = newNode;
   		*previousNode = (*previousNode)->link;
    }
    return *previousNode;  /*return previous node to use as parameter for next function call*/
}
/*This function deletes the node with given room number*/
void remove_room(Room **head, int room_number){
	Room *current;
	Room *prev;
	prev = *head;
	if(prev!=NULL && prev->link!=NULL) /*check for memory allocation*/
		current = prev->link;
	else
		return;
	if(prev->number!=room_number){   /*find the room number and remove*/
		while(current->number!=room_number && current->link!=NULL){
			prev = prev->link;
			current = current->link;
		}
		if(current->number==room_number){ /*check if given number is in the list*/
			prev->link = current->link;
			free(current); /*free the memory of removed node*/
		}
	} else {
		*head = prev->link;
		free(prev); /*free the memory of removed node*/
	}
}
/*This function adds a new node after given room number*/
void add_room_after_room_number(Room **head, int pre_room_number, int num, int capa, int flo, Customer *custom){
	Room *current;
	Room *next;
	Room *newNode = (Room *)malloc(sizeof(Room)); /* allocate memory for new node*/
	current = *head;
	newNode->number = num;
	newNode->capasity = capa;
	newNode->floor = flo; 
	newNode->customer = custom;
	if(current->number!=pre_room_number){ /*find the previous node*/
		while(current->number!=pre_room_number && current->link!=NULL){
			current = current->link;
		}
	}	
	/*link the new node*/
	next = current->link;
	current->link = newNode;
	newNode->link = next;
}
/*This function lists the rooms with the given floor number */
void get_by_floor(Room *head, int floor_num){
	Room *temp;
	temp = head;
	while(temp->link!=NULL){
		if(temp->floor==floor_num){
			printf("Room %d is on floor %d.\n", temp->number, floor_num);
		}
		temp = temp->link;
	}

}
/*The function prints the room list with customers*/
void print_list(Room *head){
    Room *current = head;
    Customer *curr;
    if(current==NULL){  /*Check memory */
        printf("There is no room!\n");
        return;
    }
    /* go through the room list and print*/
    while(current->link != NULL){
        printf("Room %d (Floor %d - capacity %dx)\n", current->number, current->floor, current->capasity );
        curr = current->customer;
        
        if(curr!=NULL){
            while(curr->link != NULL){  /* go through the customer list and print*/
               printf(" ->%s %s (%d-%s)\n", curr->name,curr->surname, curr->age,curr->gender);
               curr = curr->link;
            }
        }else {
            printf("Empty Room!\n");
        }
        current = current->link;
    } /*to print last member of the list*/
    printf("Room %d (Floor %d - capacity %dx)\n", current->number, current->floor, current->capasity );
    curr = current->customer;
    if(curr!=NULL){
        while(curr->link != NULL){  /* go through the customer list and print*/
 		       printf(" ->%s %s (%d-%s)\n", curr->name,curr->surname, curr->age,curr->gender);
               curr = curr->link;
        }
    }  else {
        printf("Empty Room!\n");
    }

}
/*This function list all available rooms that don’t have any customer. */
void show_vacancy(Room *head){
	Room *current;
	current = head;

	while(current->link!=NULL){  /* go through list*/
		if(current->customer==NULL){ /* print if it is empty*/
			printf("%d. Room is avaible\n", current->number);
		}
		current = current->link;
	}	
}
/* will use this function to linking customers to rooms*/
Room *find_node(Room **head, int num){
	Room *current;
	if(*head!=NULL){
		current = *head;
	}
	while(current->link!=NULL){
		if(current->number==num){
			return current;
		}
		current = current->link;
	}
	return NULL;
}

/* Some rooms don't have customer information as i print them */
/*i dont know why and couldnt be able to fix it */
/*it may be related to this function */
/*i've created a customer list, i go through the list and add customers to rooms*/
void link_customers_to_room(Room **headRoom, Customer **headCustomer){
	Customer *newNode = (Customer*)malloc(sizeof(Customer));
	Room *current_room = *headRoom;
	Customer *current_customer =  *headCustomer;
	do{ /*find the room with same room number as customer and add to it with add_customer_to_end fucntion */
		current_room = find_node(headRoom, current_customer->number);
		current_room->previous = add_customer_to_end(&(current_room->customer), &(current_room->previous), current_customer->number, 
		current_customer->name, current_customer->surname, current_customer->age, current_customer->gender);
		current_customer = current_customer->link;
	}while(current_customer->link!=NULL);
}

/*

// This is another add function but i writed a new one because this 
// is a little bit slow because
// it goes to the end of the list every time 

Customer *add_customer_to_end(Customer **head, int num, char *name,
char *sname, int age, char *gender){
    Customer *current;    
    Customer *newNode = (Customer *) malloc(sizeof(Customer));
    newNode->number = num;
    strcpy (newNode->name , name);
    strcpy (newNode->surname ,sname);
    newNode->age = age;
    strcpy (newNode->gender , gender);
    newNode->gender = gender;
    newNode->link = NULL;
    
    if (*head == NULL) {
       
        *head = newNode;
    } 
    else {
        current = *head;

        while (current->link != NULL) {
            current = current->link;
        }

       
        current->link = newNode;
    }

    return *head;
}*/





