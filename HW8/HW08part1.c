#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum{p,s,m,b,t,n}block_type;
typedef struct {
	char * text;
	int data;
	block_type type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
}block;

void init_board(block board[10][10]);
void print_board(block board[10][10]);
int single_player(block board[][10], int x, int y);
void double_player(block board[][10]);

int main(){
	int count;
	srand(time(NULL));
	block board[10][10];
	init_board(board);
	print_board(board);
	printf("Move count :%d\n",single_player(board, 9, 9));
	double_player(board);
	return 0;
}
void init_board(block board[10][10]){
	int i,j,k=1;
	for(i=9;i>=0;i--){   /*fill every block*/
		if(i%2!=0){
			for(j=9;j>=0;j--){
				board[i][j].text=0;
				board[i][j].data=k;
				board[i][j].type=n;
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].jump_x=0;
				board[i][j].jump_y=0;
				k++;
			}
		}else {
			for(j=0;j<10;j++){
				board[i][j].text=0;
				board[i][j].data=k;
				board[i][j].type=n;
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].jump_x=0;
				board[i][j].jump_y=0;
				k++;
			}
		}
	}      /*change special blocks*/
	board[0][2].text = "T";
	board[0][2].type = t;
	board[0][2].jump_x = 1;
	board[0][2].jump_y = 2;

	board[0][7].text = "S{72}";
	board[0][7].type = s;
	board[0][7].jump_x = 2;
	board[0][7].jump_y = 1;

	board[0][8].text = "S{56}";
	board[0][8].type = s;
	board[0][8].jump_x = 4;
	board[0][8].jump_y = 5;

	board[0][9].text = "100(f)";

	board[1][1].text = "M{94}";
	board[1][1].type = m;
	board[1][1].jump_x = 0;
	board[1][1].jump_y = 3;

	board[1][5].text = "P";
	board[1][5].type = p;

	board[1][8].text = "B";
	board[1][8].type = b;
	board[1][8].jump_x = 1;
	board[1][8].jump_y = 3;

	board[2][2].text = "S{68}";
	board[2][2].type = s;
	board[2][2].jump_x = 3;
	board[2][2].jump_y = 2;

	board[2][5].text = "M{83}";
	board[2][5].type = m;
	board[2][5].jump_x = 1;
	board[2][5].jump_y = 7;

	board[2][8].text = "T";
	board[2][8].type = t;
	board[2][8].jump_x = 2;
	board[2][8].jump_y = 3;

	board[3][1].text = "M{77}";
	board[3][1].type = m;
	board[3][1].jump_x = 2;
	board[3][1].jump_y = 6;

	board[3][4].text = "B";
	board[3][4].type = b;
	board[3][4].jump_x = 2;
	board[3][4].jump_y = 9;

	board[3][7].text = "S{52}";
	board[3][7].type = s;
	board[3][7].jump_x = 4;
	board[3][7].jump_y = 1;

	board[4][3].text = "T";
	board[4][3].type = t;
	board[4][3].jump_x = 5;
	board[4][3].jump_y = 1;

	board[4][6].text = "M{77}";
	board[4][6].type = m;
	board[4][6].jump_x = 2;
	board[4][6].jump_y = 6;

	board[4][9].text = "S{44}";
	board[4][9].type = s;
	board[4][9].jump_x = 5;
	board[4][9].jump_y = 6;	

	board[5][0].text = "B";
	board[5][0].type = b;
	board[5][0].jump_x = 4;
	board[5][0].jump_y = 4;

	board[5][2].text = "P";
	board[5][2].type = p;

	board[5][5].text = "S{22}";
	board[5][5].type = s;
	board[5][5].jump_x = 7;
	board[5][5].jump_y = 8;		

	board[6][1].text = "M{52}";
	board[6][1].type = m;
	board[6][1].jump_x = 4;
	board[6][1].jump_y = 1;

	board[6][5].text = "B";
	board[6][5].type = b;
	board[6][5].jump_x = 5;
	board[6][5].jump_y = 9;

	board[6][9].text = "T";
	board[6][9].type = t;
	board[6][9].jump_x = 6;
	board[6][9].jump_y = 4;

	board[7][1].text = "B";
	board[7][1].type = b;
	board[7][1].jump_x = 6;
	board[7][1].jump_y = 3;

	board[7][5].text = "S{12}";
	board[7][5].type = s;
	board[7][5].jump_x = 8;
	board[7][5].jump_y = 1;

	board[8][2].text = "P";
	board[8][2].type = p;

	board[8][6].text = "M{28}";
	board[8][6].type = m;
	board[8][6].jump_x = 7;
	board[8][6].jump_y = 2;	

	board[9][3].text = "M{11}";
	board[9][3].type = m;
	board[9][3].jump_x = 8;
	board[9][3].jump_y = 0;

	board[9][4].text = "S{1}";
	board[9][4].type = s;
	board[9][4].jump_x = 9;
	board[9][4].jump_y = 9;

	board[9][9].text = "1(s)";
}

void print_board(block board[10][10]){  /*print board*/
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(board[i][j].text==0)	{
				printf("   %5d   |", board[i][j].data);
			}else{
				printf("   %5s   |", board[i][j].text);
			}
		}
		printf("\n_______________________________________________________________________________________________________________________\n");
	}
}

int single_player(block board[][10], int x, int y){
	int dice, tempx=x, tempy=y, move=0;
	dice=rand()%6+1; /*roll the dice*/
	if((board[x][y].data + dice) < 100){ /* if hasn't reached to 100 yet */
		if(x%2!=0){ /*moves depending on dice*/
			if((y-dice)<0){
				x--;
				y= dice-(y-1)-2;
			}else{
				y-=dice;
			}
		}else{
			if((y+dice>9)){
				x--;
				y= 9-(dice-(9-y)-1);
			}else {
				y+=dice;
			}
		}
		/*if reached block has a jump value change x and y again */
		if(board[x][y].type==m || board[x][y].type==s || board[x][y].type==b || board[x][y].type==t){
			tempx = board[x][y].jump_x;
			tempy = board[x][y].jump_y;
			move = 1+single_player(board, tempx, tempy); /*to print last to first return a variable under printf*/
			printf("Move => Dice: %d New Block: %d \n", dice , board[tempx][tempy].data);
			return move; /*move is 1+function to increase move count with every move*/
		}
		else if(board[x][y].type==p){ /*if reached block is p get back */
			move = 1+single_player(board, tempx, tempy); /*call function again */
			printf("Move => Dice: %d New Block: %d \n", dice , board[tempx][tempy].data); /*use temp to get back*/
			return move;
		}
		else{
			move = 1+single_player(board, x, y); /*if reached block is normal just continue*/
			printf("Move => Dice: %d New Block: %d \n", dice , board[x][y].data);
			return move;
		}
	}else { 
		if((board[x][y].data + dice) == 100){ /*if data+dice= 100 game is finished */
			printf("You have finished the game\n");
			printf("Move => Dice: %d New Block: %d \n",dice, board[x][y].data+dice);
			return 1;/*to increase for last move */
		}else{ /*roll the dice again if bigger than 100*/
			return 1+single_player(board, tempx, tempy);
		}
	}
}

void double_player(block board[][10]){
	int pl1, pl2;
	/*call single_player 2 times, compare return values, least is winner*/
	pl1=single_player(board, 9, 9);
	printf("First players move count: %d\n", pl1);
	printf("\n");
	pl2=single_player(board, 9, 9);
	printf("Second players move count: %d\n", pl2);

	if(pl1<pl2){
		printf("Player 1 have won \n");
	}else if(pl2<pl1) {
		printf("Player 2 have won\n");
	}else {/*equal move count means tie*/
		printf("No winner. Its a tie situation.\n");
	}
}