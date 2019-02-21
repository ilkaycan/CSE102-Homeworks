#include <stdio.h>
#include<stdlib.h>
typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;
void init_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void display_board(piece board[][8]);
void sample_game_1();
void sample_game_2();


int main()
{
	int a,b;
	piece board[8][8];
	init_board(board);
	display_board(board);
	b = move(board, 2,1,3,1,black);
	move(board, 3,1,4,1,black);
	display_board(board);
	move(board,5, 0, 4,0, white);
	display_board(board);
	move(board,4, 0, 4,2, white);
	display_board(board);

	a = check_end_of_game(board);

	printf("%d %d\n", a ,b);
	printf("sample1\n");
	sample_game_1();
	printf("sample2\n");
	sample_game_2();
	return 0;
}

void init_board(piece board[][8]){ /* board at the start*/
int i;	
	for(i=0; i<8;i++){
		board[0][i]=empty;
		board[1][i]=black_man;
		board[2][i]=black_man;
		board[3][i]=empty;
		board[4][i]=empty;
		board[5][i]=white_man;
		board[6][i]=white_man;
		board[7][i]=empty;
	}
	
}
int check_end_of_game(piece board[][8]){ /*checks if game is over*/
piece check[64];
int a=0,whi=0, bl=0,res,i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			check[a]=board[i][j];
			a++;
		}
	}
	
	for(a=0;a<64;a++){ 
		if(check[a]!=black_man && check[a]!=black_king){
			whi++;
		}else if(check[a]!=white_man && check[a]!=white_king){ 
			bl++;
		}
	}

	if(whi==64){ /*if there is no black pieces*/
		res=white;
	} else if(bl==64){ /*if there is no white pieces*/
		res=black;
	} else { /*if there are both on the board */
		res =-1;
	}
return res;
}
void display_board(piece board[][8]){
int i,j;

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j]==empty){
				printf(" - ");
			}else if(board[i][j]==black_man){
				printf(" b ");
			}else if(board[i][j]==white_man){
				printf(" w ");
			}else if(board[i][j]==white_king){
				printf(" W ");
			}else if(board[i][j]==black_king){
				printf(" B ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
int n, result,temp,x,y,ax,ay,i,count;
	x=from_x-to_x;
	y=from_y-to_y;
	ax=abs(x);
	ay=abs(y);	
	if(p==white){/*move for white*/
		if(board[from_x][from_y]==black_man || board[from_x][from_y]==black_king){ /* checks for true piece*/
			result=-1;
		}else if(board[to_x][to_y]!=empty){ /* checks if destination is empty*/
			result=-2;
		}else if(board[from_x][from_y]==empty){ /* checks if there is a piece */
			result=-2;
		}else if(board[from_x][from_y]==white_man){ /*move for white man*/
			if(x<0){ /* white man cant go back*/
				result=-2;
			}else if(ay==1 && ax==0){ /* one square on y axis*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_man;
				result=0;
			} else if(x==1 && ay==0){ /*1 square on x axis*/
				if(to_x==0){ /* king or still man?*/
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
					result=0;	
				}else{
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_man;
					result=0;
				}
			}else if(ay==2 && ax==0){ /*2 square on y axis*/
					board[from_x][from_y]=empty;
					board[from_x][((from_y+to_y)/2)]=empty;
					board[to_x][to_y]=white_man;
					result=1;
			}else if(x==2 && ay==0){/* 2 square on x axis*/ /*cant capture your own piece or move 2 square if middle is empty*/
				if(board[from_x-1][from_y]!=white_man && board[from_x-1][from_y]!=white_king&&board[from_x-1][from_y]!=empty ){
					if(to_x==0){ /* king or not?*/
						board[from_x][from_y]=empty;
						board[from_x-1][from_y]=empty;
						board[to_x][to_y]=white_king;	
						result=1;
					}else{
						board[from_x][from_y]=empty;
						board[from_x-1][from_y]=empty;
						board[to_x][to_y]=white_man;
						result=1;;
					}
				}else{ /*cant capture own piece*/
					result = -2;
				}
			}else{ /* cant move cross or more than 2 square */
				result=-2;
			}
		}else if(board[from_x][from_y]==white_king){ /*move for white king*/
			if(ay==1 && ax==0){ /* one square on y axis*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
				result=0;
			} else if(ax==1 && ay==0){ /*1 square on x axis*/
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
					result=0;
			}else if(ay>1 && ax==0){ 
				if(y<ay){/* moves to right*/
					if(board[to_x][to_y-1]==black_man || board[to_x][to_y-1]==black_king || board[to_x][to_y-1]==empty ){
						count=0;
						for(i=1;i<(ay-1);i++){
							if(board[to_x][from_y+i]!=empty){
								count++;
							}
						}
						if(count!=0){
							result = -2;
						}else if(board[to_x][to_y-1]==empty){
							result = 0; 
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
						}else {
							result = 1;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
							board[to_x][to_y-1]=empty;
						}
					}else{
						result = -2;
					}
				}else{ /* moves to left*/
					if(board[to_x][to_y+1]==black_man || board[to_x][to_y+1]==black_king || board[to_x][to_y+1]==empty ){
						count=0;
						for(i=1;i<(ay-1);i++){
							if(board[to_x][from_y-i]!=empty){
								count++;
							}
						}
						if(count!=0){
							result = -2;
						}else if(board[to_x][to_y+1]==empty){
							result = 0; 
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
							result = 0; 
						}else {
							result = 1;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
							board[to_x][to_y+1]=empty;
						}
					}else {
						result = -2;
					}
				}
			}else if(ax>1 && ay==0){ 
				if(x<ax){/* moves to down*/
					if(board[to_x-1][to_y]==black_man || board[to_x-1][to_y]==black_king || board[to_x-1][to_y]==empty ){
						count=0;
						for(i=1;i<(ax-1);i++){
							if(board[from_x+i][to_y]!=empty){
								count++;
							}
						}
						if(count!=0){
							result = -2;
						}else if(board[to_x-1][to_y]==empty){
							result = 0; 
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
						}else {
							result = 1;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
							board[to_x-1][to_y]=empty;
						}
					}else{
						result = -2;
					}
				}else{ /* moves to up*/
					if(board[to_x+1][to_y]==black_man || board[to_x+1][to_y]==black_king || board[to_x+1][to_y]==empty ){
						count=0;
						for(i=1;i<(ax-1);i++){
							if(board[from_x-i][to_y]!=empty){
								count++;
							}
						}
						if(count!=0){
							result = -2;
						}else if(board[to_x+1][to_y]==empty){
							result = 0; 
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
							result = 0; 
						}else {
							result = 1;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=white_king;
							board[to_x+1][to_y]=empty;
						}
					}else {
						result = -2;
					}
				}
			}
		}
	}else if(p==black){ /*move for black*/
		if(board[from_x][from_y]==white_man || board[from_x][from_y]==white_king){ /* checks for true piece*/
			result=-1;
		}else if(board[to_x][to_y]!=empty){ /* checks if destination is empty*/
			result=-2;
		}else if(board[from_x][from_y]==empty){ /* checks if there is a piece */
			result=-2;
		}else if(board[from_x][from_y]==black_man){ /*move for black man*/
			if(x>0){ /*  man cant go back*/
				result=-2;
			}else if(ay==1 && ax==0){ /* one square on y axis*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_man;
				result = 0;
			} else if(x==-1 && ay==0){ /*1 square on x axis*/
				if(to_x==7){ /* king or still man?*/
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
					result = 0;	
				}else{
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_man;
					result = 0;
				}
			}else if(ay==2 && ax==0){ /*2 square on y axis*/
					board[from_x][from_y]=empty;
					board[from_x][((from_y+to_y)/2)]=empty;
					board[to_x][to_y]=black_man;
					result = 1;
			}else if(x==-2 && ay==0){/* 2 square on x axis*/ /*cant capture your own piece or move 2 square if middle is empty*/
				if(board[from_x+1][from_y]!=black_man && board[from_x+1][from_y]!=black_king&&board[from_x+1][from_y]!=empty ){
					if(to_x==7){ /* king or not?*/
						board[from_x][from_y]=empty;
						board[from_x+1][from_y]=empty;
						board[to_x][to_y]=black_king;	
						result = 1;
					}else{
						board[from_x][from_y]=empty;
						board[from_x+1][from_y]=empty;
						board[to_x][to_y]=black_man;
						result = 1;
					}
				}else{ /*cant capture own piece*/
					result = -2;
				}
			}else{ /* cant move cross or more than 2 square */
				result=-2;
			}
		}else if(board[from_x][from_y]==black_king){ /*move for black king*/
			if(ay==1 && ax==0){ /* one square on y axis*/
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
				result=0;
			} else if(ax==1 && ay==0){ /*1 square on x axis*/
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
					result=0;
			}else if(ay>1 && ax==0){ 
				if(y<ay){/* moves to right*/
					if(board[to_x][to_y-1]==white_man || board[to_x][to_y-1]==white_king || board[to_x][to_y-1]==empty ){
						count=0;
						for(i=1;i<(ay-1);i++){
							if(board[to_x][from_y+i]!=empty){
								count++;
							}
						}
						if(count!=0){
							result = -2;
						}else if(board[to_x][to_y-1]==empty){
							result = 0; 
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
						}else {
							result = 1;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
							board[to_x][to_y-1]=empty;
						}
					}else{
						result = -2;
					}
				}else{ /* moves to left*/
					if(board[to_x][to_y+1]==white_man || board[to_x][to_y+1]==white_king || board[to_x][to_y+1]==empty ){
						count=0;
						for(i=1;i<(ay-1);i++){
							if(board[to_x][from_y-i]!=empty){
								count++;
							}
						}
						if(count!=0){
							result = -2;
						}else if(board[to_x][to_y+1]==empty){
							result = 0; 
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
							result = 0; 
						}else {
							result = 1;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
							board[to_x][to_y+1]=empty;
						}
					}else {
						result = -2;
					}
				}
			}else if(ax>1 && ay==0){ 
				if(x<ax){/* moves to down*/
					if(board[to_x-1][to_y]==white_man || board[to_x-1][to_y]==white_king || board[to_x-1][to_y]==empty ){
						count=0;
						for(i=1;i<(ax-1);i++){
							if(board[from_x+i][to_y]!=empty){
								count++;
							}
						}
						if(count!=0){
							result = -2;
						}else if(board[to_x-1][to_y]==empty){
							result = 0; 
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
						}else {
							result = 1;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
							board[to_x-1][to_y]=empty;
						}
					}else{
						result = -2;
					}
				}else{ /* moves to up*/
					if(board[to_x+1][to_y]==white_man || board[to_x+1][to_y]==white_king || board[to_x+1][to_y]==empty ){
						count=0;
						for(i=1;i<(ax-1);i++){
							if(board[from_x-i][to_y]!=empty){
								count++;
							}
						}
						if(count!=0){
							result = -2;
						}else if(board[to_x+1][to_y]==empty){
							result = 0; 
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
							result = 0; 
						}else {
							result = 1;
							board[from_x][from_y]=empty;
							board[to_x][to_y]=black_king;
							board[to_x+1][to_y]=empty;
						}
					}else {
						result = -2;
					}
				}
			}
		}
	}
return result;
}
void sample_game_1(){
	piece game[8][8];
	init_board(game);
	display_board(game);

	move(game, 5, 7, 4, 7, white);
	display_board(game);
	move(game, 2, 0, 3, 0, black);
	display_board(game);
	move(game, 5, 6, 4, 6, white);
	display_board(game);
	move(game, 2, 1, 3, 1, black);
	display_board(game);
	move(game, 5, 5, 4, 5, white);
	display_board(game);
	move(game, 2, 4, 3, 4, black);
	display_board(game);
	move(game, 5, 3, 4, 3, white);
	display_board(game);
	move(game, 1, 4, 2, 4, black);
	display_board(game);
	move(game, 4, 3, 4, 4, white);
	display_board(game);
	move(game, 1, 5, 1, 4, black);
	display_board(game);
	move(game, 6, 3, 5, 3, white);
	display_board(game);
	move(game, 2, 2, 3, 2, black);
	display_board(game);
	move(game, 6, 4, 6, 3, white);
	display_board(game);
	move(game, 2, 3, 3, 3, black);
	display_board(game);
	move(game, 6, 5, 6, 4, white);
	display_board(game);
	move(game, 1, 3, 2, 3, black);
	display_board(game);
	move(game, 6, 6, 6, 5, white);
	display_board(game);
	move(game, 1, 2, 2, 2, black);
	display_board(game);
	move(game, 5, 1, 4, 1, white);
	display_board(game);
	move(game, 3, 1, 5, 1, black);
	display_board(game);
	move(game, 5, 1, 7, 1, black);
	display_board(game);
	move(game, 5, 2, 5, 1, white);
	display_board(game);
	move(game, 7, 1, 4, 1, black);
	display_board(game);
	move(game, 4, 1, 2, 1, black);
	display_board(game);
	move(game, 6, 0, 6, 1, white);
	display_board(game);
	move(game, 2, 1, 7, 1, black);
	display_board(game);
	move(game, 4, 7, 3, 7, white);
	display_board(game);
	move(game, 2, 7, 4, 7, black);
	display_board(game);
	move(game, 5, 3, 4, 3, white);
	display_board(game);
	move(game, 3, 3, 5, 3, black);
	display_board(game);
	move(game, 5, 3, 5, 5, black);
	display_board(game);
	move(game, 5, 5, 7, 5, black);
	display_board(game);
	move(game, 5, 0, 4, 0, white);
	display_board(game);
	move(game, 3, 4, 5, 4, black);
	display_board(game);
	move(game, 5, 4, 7, 4, black);
	display_board(game);
	move(game, 4, 0, 2, 0, white);
	display_board(game);
	move(game, 2, 0, 0, 0, white);
	display_board(game);
	move(game, 7, 5, 3, 5, black);
	display_board(game);
	move(game, 0, 0, 0, 7, white);
	display_board(game);
	move(game, 4, 7, 4, 5, black);
	display_board(game);
	move(game, 0, 7, 2, 7, white);
	display_board(game);
	move(game, 2, 7, 3, 7, white);
	display_board(game);
	move(game, 3, 7, 3, 4, white);
	display_board(game);
	move(game, 3, 4, 3, 3, white);
	display_board(game);
	move(game, 3, 3, 1, 3, white);
	display_board(game);
	move(game, 1, 3, 1, 5, white);
	display_board(game);
	move(game, 1, 5, 3, 5, white);
	display_board(game);
	move(game, 3, 5, 5, 5, white);
	display_board(game);
	move(game, 5, 5, 7, 5, white);
	display_board(game);
	move(game, 7, 5, 7, 3, white);
	display_board(game);
	move(game, 7, 3, 7, 0, white);
	display_board(game);
	move(game, 1, 6, 1, 7, black);
	display_board(game);
	move(game, 7, 0, 3, 0, white);
	display_board(game);
	move(game, 3, 2, 4, 2, black); 
	display_board(game);
	move(game, 3, 0, 4, 0, white);
	display_board(game);
	move(game, 4, 2, 5, 2, black);
	display_board(game);
	move(game, 6, 2, 4, 2, white);
	display_board(game);
	move(game, 1, 1, 2, 1, black);
	display_board(game);
	move(game, 4, 2, 3, 2, white);
	display_board(game);
	move(game, 2, 2, 4, 2, black);
	display_board(game);
	move(game, 4, 0, 4, 3, white);
	display_board(game);
	move(game, 4, 3, 4, 7, white);
	display_board(game);
	move(game, 4, 7 , 0, 7, white);
	display_board(game);
	move(game, 2, 4, 3, 4, black);
	display_board(game);
	move(game, 0, 7, 3, 7, white);
	display_board(game);
	move(game, 2, 6, 3, 6, black);
	display_board(game);
	move(game, 3, 7, 3, 5, white);
	display_board(game);
	move(game, 3, 5, 3, 3, white);
	display_board(game);
	move(game, 3, 3, 3, 1, white);
	display_board(game);
	move(game, 3, 1, 1, 1, white);
	display_board(game);
	printf("%d\n", check_end_of_game(game));

}	

void sample_game_2(){
		
		piece game[8][8]={ empty, empty, empty, empty, empty, empty, empty, empty,
						   empty, empty, black_man, black_man, black_man, black_man, empty, empty,
						   empty, black_man, black_man, black_man, black_man, empty, black_man, black_man,
						   black_man, black_man, black_man, empty, empty, black_man, empty, black_man,
						   empty, empty, white_man, white_man, white_man, black_man, white_man, white_man,
						   white_man, white_man, white_man, white_man, white_man, empty, white_man, white_man,
						   empty, empty, white_man, white_man, white_man, white_man, empty, empty,
						   empty, empty, empty, empty, empty, empty, empty, empty 	};
		display_board(game);
		move(game, 5, 1, 4, 1, white);
		display_board(game);
		move(game, 3, 1, 5, 1, black);
		display_board(game);
		move(game, 4, 3, 3, 3, white);
		display_board(game);
		move(game, 4, 5, 4, 3, black);
		display_board(game);
		move(game, 4, 3, 4, 1, black);
		display_board(game);
		move(game, 3, 3, 3, 1, white);
		display_board(game);
		move(game, 3, 1, 1, 1, white);
		display_board(game);
		move(game, 1, 2, 1, 0, black);
		display_board(game);
		move(game, 5, 3, 4, 3, white);
		display_board(game);
		move(game, 5, 1, 5, 3, black);
		display_board(game);
		move(game, 5, 3, 5, 5, black);
		display_board(game);
		move(game, 5, 5, 7, 5, black);
		display_board(game);
		move(game, 4, 3, 3, 3, white);
		display_board(game);
		move(game, 2, 3, 4, 3, black);
		display_board(game);
		move(game, 5, 1, 5, 3, black);
		display_board(game);
		move(game, 5, 6, 5, 5, white);
		display_board(game);
		move(game, 7, 5, 4, 5, black);
		display_board(game);
		move(game, 4, 6, 4, 4, white);
		display_board(game);
		move(game, 4, 4, 4, 2, white);
		display_board(game);
		move(game, 4, 2, 4, 0, white);
		display_board(game);
		move(game, 4, 0, 2, 0, white);
		display_board(game);
		move(game, 2, 0, 0, 0, white);
		display_board(game);
}
