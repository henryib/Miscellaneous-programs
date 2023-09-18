
#include <stdio.h>
const int m = 5;
const int n = 5;

// development log :
// passing 2d array through pointer- solved/worked around
// update table after each move - kinda solved
// current program state - can input data into table freely.
// user can play outside the board - fixed 
// player 1 and 2 turn tracking - somewhat done - touching up needed 
// look through commented out code.
// current state update user can play freely within the board only and user turn is tracked
// 23/01/20 -  current program state - horizantal testing works - verical testing needs completion 
// 27/0120 - vertical and horizontal testing completed - clean up the duplicate code in win_test function
// ^^^^^^ - naming system still in development , diagonal testing needed to complete win_test function

char mode_select();
void ai_move(char(*test) [m]);
void display_table( char table[m][n]);
void live_game(char game_mode);
int  win_test(char table[m][n]);
void user_info(char *name[]); 
void place(int player ,int  x , int y, char(*test) [m]);

void main(void)
{
	int i, j;
	char table[5][5] = {0};
	char names[] = {0};

	char mode = mode_select();
	live_game(mode);
		
}

char mode_select()
{
	printf("\n Welcome to my Tic Tac Toe game \n");
	printf("Select your game mode :\n(a) Human vs Human\n(b)Human vs ai\n ");
	char mode = getchar();
	return mode;
	
}

void display_table( char table[m][n])// pretty much complete
{

	printf("    0  1  2  3  4\n\n");
	int i ;
	int j;
	
	for(i =0;i <5;i++)
	{
		printf(" %d",i);
		for(j =0;j <5;j++)
		{	
			printf(" |%c",table[i][j]);
			if(j > 3)
			{
				printf("\n    ______________\n");
			}
			
		}
		
	}
}

void live_game(char game_mode)
{
	int x ,y;
	int move_counter = 0;
	char test[5][5] = {0};
	int game_status = 1;
	display_table(test);
	

		move_counter+=1;
		
		printf("\npick a position to play (x then y):\n");
		
		
		if(game_mode == 'a'){
			
			while(game_status == 1){
				fflush(stdin);
				scanf("%d%d",  &x, &y);
				place(1 , x, y, &test);
				game_status = win_test(test);
				
	
				fflush(stdin);
				scanf("%d%d",  &x, &y);
				place(2 , x, y, &test);
				game_status = win_test(test);
							
			}
		
			
			
		}
		else if(game_mode =='b' ){
			while(game_status == 1){	
				fflush(stdin);
				scanf("%d%d",  &x, &y);
				place(1 , x, y, &test);
				game_status = win_test(test);
				
				ai_move(&test);	
					
			}
	
			
					
		}

		
		

		
		// idea for turn tracking , assign moves to two arrays , player and player 2 
	}
	


void place(int player ,int  x , int y ,char(*test) [m]){
	
	// prevents user from playing outside the grid 	
		while( x > 5 || y > 5 )
		{
			printf("\n(%d,%d)",x,y);
			printf(" is not a postion on the grid, try again:\n ");
			fflush(stdin);
			scanf("%d%d",  &x, &y);
		}	
		
// checking if it is player 1 or 2				
		if(player == 2 )
		{	
				test[x][y] = 'O';
				display_table(test);
				printf("\nplayer 1's turn:  \n");
		}		
		else if(player == 1)
		{
			test[x][y] = 'X';
			display_table(test);
			printf("\nplayer 2's turn: \n");
		}
		
					
}


int  win_test(char table[m][n])
{
	
	int i, j = 0;
	int x_score = 0;
	int o_score = 0;
	int game_state = 1;
	//display_table(table); just checkign if the data passed through
	printf("win tested\n");
	
	
// testing horizontally for wins 

	for(i = 0; i < 5; i++)
	{
		
		// testing horizontally 		
		for(j = 0; j < 5; j++)
		{
			if(x_score >3 || o_score > 3 ){
				printf("Game over");
				game_state = 1;
			}
			
			
			if(table[i][j] == 'X')
			{
				x_score +=1;
				o_score = 0;
			}
			else if(table[i][j] == 'O')
			{
				o_score += 1;
				x_score =0;	
			}
			else 
			{
				o_score = 0;
				x_score =0;	
			}
					
		}			
		
	}	
	
// testing vertically 
	for(j = 0; j < 5; j++)
	{
		for(i = 0; i < 5; i++)
		{
			
			if(x_score >3 || o_score > 3 ){
					printf("Game over");
					game_state = 0;
			}
			
			
			if(table[i][j] == 'X')
			{
				x_score +=1;
				o_score =0;
				
			}
			else if(table[i][j] == 'O')
			{
				o_score += 1;
				x_score =0;
					
			}
			else 
			{
				o_score = 0;
				x_score =0;	
			}
	
	
		}	
		
	}
	
	

// left to right diagonal
	for(i = 0; i < 5;i++){
		
		for(j = 0; j< 5 ; j++){
			
			if(table[i] == table[j] ){
				
				
				if(x_score >3 || o_score > 3 ){
					printf("Game over");
					game_state = 0;
			}
				
				
				if(table[i][j] == 'X')
			{
				x_score +=1;
				o_score =0;
				
			}
			else if(table[i][j] == 'O')
			{
				o_score += 1;
				x_score =0;
					
			}
			else 
			{
				o_score = 0;
				x_score =0;	
			}
			
			
			}
			
		}
	}
	
// right to left diagonal 
	
		for(i = 0; i < 5;i++){
			
			for(j = 0; j < 5;j++){
			 if ((i + j) == (n - 1)){
		
			 	
				
				if(x_score >3 || o_score > 3 ){
					printf("Game over");
					game_state = 0;
			}
				
				
				if(table[i][j] == 'X')
			{
				x_score +=1;
				o_score =0;
				
			}
			else if(table[i][j] == 'O')
			{
				o_score += 1;
				x_score =0;
					
			}
			else 
			{
				o_score = 0;
				x_score =0;	
			}
						
			}
			
		}
}
	return game_state;

}

ai_move(char(*test) [m]){
	
	int i , j;
// checking if it is player 1 or 2				
		for(i = 0;i < 5; i++){
		
			for(j = 0;j < 5; j++){
				if(test[i][j] = '0'){
					
				}
			}
			
		}
		

		
		// idea for turn tracking , assign moves to two arrays , player and player 2 
	}
	
	

















