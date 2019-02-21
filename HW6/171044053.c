/*hocam sanirim mac te hazirlamissiniz openmsgyi.
sanal makinede linux kullaniyorum ben.
kendi txt dosyami hazirlayinca calisti.
eger hata verirse sikinti input dosyasinda*/
#include<stdio.h>
#include<stdlib.h>
#define MSIZE 1024
void menu();
void encrypt_open_msg();
void decrypt_secret_msg();
int find_size_of_line(char line[]);
void reverse_line(char line[], int line_lenght);
int main(){	
	menu();
	return 0;	
}
int find_size_of_line(char line[]){ 						/* Finds the size of a string*/
int count;
	for ( count = 0; line[count]!= 0; ++count); 			/* counts until NULL*/
	return count;
}
void reverse_line(char line[], int line_lenght){			 /* reverses a string */
int i;
char temp;
	for(i=0;i<line_lenght/2;i++){ 							/*if dont use lenght/2 it reverses back and you get the first string*/				
		temp = line[i];  									/* simple swap operation */
		line[i] = line[line_lenght-i-1];
		line[line_lenght-i-1] = temp;
	}
}
void menu(){												/*menu function*/
	int choice;
	do{
		printf("\n 1.Encrypt\n 2.Decrypt\n 0.Exit\n Choice:"); /*print menu*/
		scanf("%d", &choice); 									/*make a choice*/
		switch (choice){
			case 1:
			encrypt_open_msg();
			break;
			case 2:
			decrypt_secret_msg();
			break;
			case 0:												/*to not be in default*/
			break;
			default:
			printf("False choice\n");
		}
	}while(choice!=0);											/*0 is exit*/
}
void encrypt_open_msg(){										/*encryt message*/
	int key,i,j,temp;
	char line[MSIZE];
	printf("Key:");
	scanf("%d", &key);												/*take key*/
	FILE *inp;
	FILE *outp;													/*file pointers*/			
	if((inp = fopen("open_msg.txt", "r"))== NULL){
		printf("ERROR\n");
		exit(0);												/*check if able to open files else print error*/
	}
	if((outp = fopen("secret_msg.txt", "w"))== NULL){
		printf("ERROR\n");
		exit(0);
	}
	if(key>0 && key<27){											
		while(fgets(line, 1024, inp)!=0){							/* read untill end of file*/
			j=0;
			while(line[j]!='\n'){									/*put null to the end of line*/
				j++;
			}
			line[j]='\0';
			reverse_line(line , find_size_of_line(line));			/*reverse line*/
			for(i=0; i<find_size_of_line(line); i++){				/* encrypt depending on key*/
				if(line[i]==' '){
					line[i]='_';
				}else if(line[i]=='.'){
					line[i]='*';
				}else if(line[i]<123 || line[i]>96){
					if((line[i]-key)<97){
						temp = 97-(line[i]-key);
						line[i] = 'z'-temp+1; 
					}else{
						line[i]-=key;
					}
				}	
			}	
			fputs(line, outp);										/*write to the file line by line*/
			putc('\n', outp);										/* go to the next line after every line */
			printf("%s\n" ,line);									/* print for terminal*/
		}	
	} else{
		printf("Key must be between 1-26!\n");
	}
	fclose(inp);												/*close the files */
	fclose(outp);
}
void decrypt_secret_msg(){ 										/* decrypts message*/
	int key,i,j,temp;
	char line[MSIZE];
	printf("Key:");												/*take a key*/				
	scanf("%d", &key);
	FILE *inp;
	FILE *outp;
	if((inp = fopen("secret_msg.txt", "r"))== NULL){
		printf("ERROR\n");
		exit(0);
	}
	if((outp = fopen("open_msg.txt", "w"))== NULL){					/*open files*/
		printf("ERROR\n");
		exit(0);
	}
	if(key<27 && key>0){											/*check for key's range*/
		while(fgets(line, 1024, inp)!=0){								/*read until end of file*/
			j=0;
			while(line[j]!='\n'){
				j++;
			}															/*null after \n*/
			line[j]='\0';
			for(i=0; i<find_size_of_line(line); i++){					/*decrypt to the key*/
				if(line[i]=='_'){
					line[i]=' ';
				}else if(line[i]=='*'){
					line[i]='.';
				}else if(line[i]<123 || line[i]>96){
					if((line[i]+key)>122){
						temp = (line[i]+key)-122;
						line[i] = 'a'+temp-1; 
					}else{
						line[i]+=key;
					}
				}
			}
			reverse_line(line , find_size_of_line(line));			/*reverse line to the normal*/
			fputs(line, outp);
			putc('\n', outp);											/*write to the file*/
			printf("%s\n" ,line);									/*printf for terminal*/		
		}
	}else {
		printf("Key must be between 1-26!!\n");
	}
	fclose(inp);
	fclose(outp);													/*close files*/	
}