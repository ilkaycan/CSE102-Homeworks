#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct /*struct for forest*/
{
	int width;
	int height;
	int flower_x;
	int flower_y;
	char **map;
}Forest;

typedef struct /*struct for botanist*/
{
	int water_bottle_size;
	int coord_x;
	int coord_y;
}Botanist;
void init_game (Forest *forest, Botanist *botanist);
void print_map (Forest forest);
int search(Forest *forest, Botanist *botanist);

int main(){
	srand(time(NULL));
	int i;
	Forest *forest; 
	Botanist *botanist;
	botanist = (Botanist*)malloc(sizeof(Botanist)); /* allocate storage for botanist */
	forest = (Forest*)malloc(sizeof(Forest)); /* allocate storage for forest */
	init_game(forest, botanist);
	print_map(*forest);
	printf("Searching...\n");
	search(forest, botanist);
	free(forest); /* free the memory*/
	free(botanist);
	for(i=0; i<forest->height; i++){
		free(forest->map[i]);
	}
	free(forest->map);
	return 0;
}
void init_game (Forest *forest, Botanist *botanist){ /* initilaze the map*/
	FILE *inp;  		
	inp = fopen("init.csv", "r");  /* open file */
	int i=0, j=0, k=0;
	char str[1024], a;
		fgets(str, 1024, inp);              /*read first two lines and take water size, width, height*/
		sscanf(str, "%d", &botanist->water_bottle_size );
		fgets(str, 1024, inp);
		sscanf(str, "%d,%d", &forest->width, &forest->height);
		forest->map = (char**)calloc(forest->height, sizeof(char*)); /*memory allocation for map*/
		for(k=0;k<forest->height;k++){
			forest->map[k]=(char*)calloc(forest->width,sizeof(char));
		}
		while(fscanf(inp,"%c", &a)!=EOF){  /*read from file and build map*/
			if(a!=','){
				 if(a=='\n'){
					i++;
					j=0;
				}else{
					if(a=='B'){
						botanist->coord_x=i;
						botanist->coord_y=j;
						}else if(a=='F'){
						forest->flower_x=i;
						forest->flower_y=j;
						}
					forest->map[i][j]=a;
					j++;
				}
			}
		}
	fclose(inp);
}
void print_map(Forest forest){  /* this function print map*/
	int i, j;
	for(i=0; i< forest.width; i++){
		for(j=0;j<forest.height; j++){
			printf("%c", forest.map[i][j]);
		}
		printf("\n");
	}
}
int search(Forest *forest, Botanist *botanist){ /*search randomly*/
	int dice = rand()%4; /* to make a random move*/
	if((forest->flower_x == botanist->coord_x) && (forest->flower_y==botanist->coord_y)){ /*if flower is found*/
		print_map(*forest);
		printf("I've found it on (%d,%d)!!\n", forest->flower_x, forest->flower_y);
		return 1;
	}
	if(botanist->water_bottle_size == 0){ /*if botanist is out of water*/
		print_map(*forest);
		printf("Help!! I'm on (%d,%d)\n", botanist->coord_x, botanist->coord_y);
		return 0;
	}else {  
		if(dice == 0){ //North    
			if(botanist->coord_x>0 && (forest->map[botanist->coord_x-1][botanist->coord_y]!='#')){ /*check if move is valid*/
				forest->map[botanist->coord_x][botanist->coord_y]=' ';
				forest->map[botanist->coord_x-1][botanist->coord_y]='B';
				botanist->coord_x--;
				botanist->water_bottle_size--;
			}
			return search(forest, botanist); /*make a new move*/
		} else if(dice == 1){ //South
			if(botanist->coord_x<9 && (forest->map[botanist->coord_x+1][botanist->coord_y]!='#')){
				forest->map[botanist->coord_x][botanist->coord_y]=' ';
				forest->map[botanist->coord_x+1][botanist->coord_y]='B';
				botanist->coord_x++;
				botanist->water_bottle_size--;
			}
			return search(forest, botanist);
		}else if(dice == 2){ //East 
			if(botanist->coord_y<9 && (forest->map[botanist->coord_x][botanist->coord_y+1]!='#')){
				forest->map[botanist->coord_x][botanist->coord_y]=' ';
				forest->map[botanist->coord_x][botanist->coord_y+1]='B';
				botanist->coord_y++;
				botanist->water_bottle_size--;
			}
			return search(forest, botanist);
		}else if (dice == 3) {              //West
			if(botanist->coord_y>0 && (forest->map[botanist->coord_x][botanist->coord_y-1]!='#')){
				forest->map[botanist->coord_x][botanist->coord_y]=' ';
				forest->map[botanist->coord_x][botanist->coord_y-1]='B';
				botanist->coord_y--;
				botanist->water_bottle_size--;
			}
			return search(forest, botanist);
		}
	}
}
