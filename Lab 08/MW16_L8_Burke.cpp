/*
//  Author: Jason Burke;

//  Lab 8: Programming Challenge, Tic-Tac-Toe game.
*/
/*
This program is a tic-tac-toe game that lets checks the player's move for validity and uses an array to store the boardgame values.
It uses a Board class to hold the board info and to allow the board to be manipulated and displayed.  The game works for 2 players. 
The game also checks for a tie game and displays a message.
*/
#include <iostream>
#include<cstdlib>
#include<iomanip>
#include <string> 
#include <windows.h> // for the HANDLE
using namespace std;


class Board {
	
	private:
		char GameBoard[3][3] = {{'7','8','9'},// had to change the boardCols/Rows to this so it would run
						        {'4','5','6'},
					            {'1','2','3'}};	
		int red=12, yellow=14, white=7;		
	public:
		Board();//default constructor
		void drawBoard(HANDLE);
		void placeCursor(HANDLE, int, int);
		void newGameMessage(HANDLE);
		int getPlayerMove(HANDLE, int);
		int setPlayerMove(HANDLE, int, int);
		void setPlayerTwoMove(HANDLE, int);
		void setPlayerOneMove(HANDLE, int);
		void freshBoard(HANDLE);
		bool checkWin(bool);
		bool isValidMove(char);
};

// Default constructor
Board::Board() {
	//initialize here
}

/*********************************\
        drawBoard function         // draws the gameboard, showing any changes made to the array.
\*********************************/

void Board::drawBoard(HANDLE screen) {
	
	//int X=5, Y=3;
	//placeCursor(screen, Y, X);
	int boardRows=3, Y=5;// Y is used for cursor placement 
	for (int row=0; row < boardRows; row++, Y+=2 ) {
			
		int boardCols = 3, X=10;// the x value is used for the placeCursor function
		for (int col=0; col<boardCols; col++, X+=4) {// is +=4 due to the 3 spaces the " | " seperator take up	
			placeCursor(screen, Y, X);
			if(GameBoard[row][col]=='X') {
				SetConsoleTextAttribute(screen, red);// reversing to see if it works again
			} else if(GameBoard[row][col]=='O') {
				SetConsoleTextAttribute(screen, yellow);
			}
			cout<< GameBoard[row][col];
			SetConsoleTextAttribute(screen, white);
			if(col<boardCols-1) cout<<" | "<<endl;		
		}	
		if(row<boardRows-1){
			placeCursor(screen, Y+1, X-12);	
			cout<<"---------"<<endl;
		}
	}	
	cout<<endl<<endl;
}

/*********************************\
        placeCursor function        //  This places the cursor on the screen HANDLE to print where we want to on the grid
\*********************************/

void Board::placeCursor(HANDLE screen, int row, int col) {
	
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}

/*********************************\
        newGame function           // Welcome message and fresh game board.. 
\*********************************/

void Board::newGameMessage(HANDLE screen){
	cout<< "\nLet's play some Tic-Tac-Toe!\n"<<endl;
	cout<< " To play, pick the number on the board where you want to move (1-9) or press -1 to quit"<<endl;
	
	freshBoard(screen);
}

/*********************************\
    getPlayerMove function       // // Gets the players move from the user.
\*********************************/

int Board::getPlayerMove(HANDLE screen, int playerTurn) {
	if(playerTurn<1) {
		SetConsoleTextAttribute(screen, red);
	} else {
		SetConsoleTextAttribute(screen, yellow);
	}	
	//cout<<"playerTurn is: "<<playerTurn<<endl;
	cout<< "\n Player "<<playerTurn+1;
	SetConsoleTextAttribute(screen, white);
	cout<<", pick your move now (1-9) or -1 to quit: ";
	char userMove = '0';
	cin>> userMove;
	
	if(userMove<'0') {
		return -1;// returns a quit value
	}
	while(userMove>'9' || userMove<'1') {
		cout<< " Error.  Please enter a valid number between 1 and 9: ";
		cin.ignore(1024, '\n');
		cin.clear();
		cin>> userMove;
	}
	return userMove;	
}

/*********************************\
    setPlayerMove function       // Sets the players move on the gameboard
\*********************************/

int Board::setPlayerMove(HANDLE screen, int movePosition, int playerTurn) {
	if (playerTurn%2==0) {
	
		for(int row=0;row<3; row++ ) {
	      for(int col=0;col<3; col++){
	      	
			if(GameBoard[row][col]==movePosition) {
				GameBoard[row][col] = 'X';
			}
	 	  }
		}			
		drawBoard(screen);
	} else {
	
		for(int row=0;row<3; row++ ) {
	  		for(int col=0;col<3; col++){

			if(GameBoard[row][col]==movePosition) {
				GameBoard[row][col] = 'O';
			}
	      }
	    }	
		drawBoard(screen);
	}
	playerTurn++;
	if (playerTurn>1) playerTurn=0;
	return playerTurn;
}

/*********************************\
        freshBoard function        // fresh game board..function is called in the newGame function..resets the board array to initial values 
\*********************************/

void Board::freshBoard(HANDLE screen) {
	//int boardCols = 3, boardRows = 3;//wouldnt let me pass these into the array as row.col nums
	char NewGameBoard[3][3] = {{'7','8','9'},// used to reset the board for a new game.
						       {'4','5','6'},
					           {'1','2','3'}}; 
	// using a nested for loop to copy data from the newGameBoard to the GameBoard[]
	for(int row=0;row<3;row++){
		for(int col=0;col<3;col++){
			GameBoard[row][col] = NewGameBoard[row][col];
		}
	}
}

/*********************************\
       checkWinner function        // working
\*********************************/

bool Board::checkWin(bool win) {
	
	
	// Diagonal winner check
	if (GameBoard[0][0]=='X' && GameBoard[1][1]=='X' && GameBoard[2][2]=='X'){
		return win=true;
	}
	if (GameBoard[0][0]=='O' && GameBoard[1][1]=='O' && GameBoard[2][2]=='O'){
		return win=true;
	}
	// Checking for 3 in a row by rows
	for(int row=0;row<3;row++){
		
		int checkColX=0, checkColO=0;//resetting for inner loop	
		for(int col=0;col<3;col++) {
			
			if(GameBoard[row][col]=='X') {checkColX++;}
			else if(GameBoard[row][col]=='O') {checkColO++;}
			
			if(checkColX >=3 || checkColO >=3) {return win = true;}

		}
	}
	// Checking for 3 in a row by columns
	for(int col=0 ;col<3;col++){
		
		int checkRowX=0, checkRowO=0;//resetting for inner loop
		for(int row=0;row<3;row++) {
			
			if(GameBoard[row][col]=='X') {checkRowX++;}
			else if(GameBoard[row][col]=='O'){checkRowO++;}
			
			if(checkRowX >=3 || checkRowO >=3) {return win = true;}
	
		}
	}	
	return win;
}

/*********************************\
      isValidMove function         // Check if the move is a valid one
\*********************************/

bool Board::isValidMove(char userChoice) {
	bool valid=true; 
	for(int row=0;row<3;row++){
		for(int col=0;col<3;col++){
			
			if(GameBoard[row][col] ==userChoice){
			
				return valid;
			}
		}
	}
	// cout<<"That square is taken.";
	
	return valid = false;
}


/*******************************************************************/
int main() {
	
	// Get a handle to the standard output device for the game board
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	Board ourGame;
	ourGame.newGameMessage(screen);
	ourGame.drawBoard(screen);
	ourGame.freshBoard(screen);
		
	int moveCounter=0;
	bool winner = false;// will set up a function to check for a winner, and set this to true.  That will stop the turns
	int playerTurn=0;

	while(!winner){
		
		int playerMove = ourGame.getPlayerMove(screen, playerTurn);
		if(playerMove<0) break;
		
		bool isValid = ourGame.isValidMove(playerMove);
		
		while (!isValid) {
			cout<<"Error. That is not a valid move.";	
			playerMove = ourGame.getPlayerMove(screen, playerTurn);		
			if(playerMove<0) break;	
			isValid = ourGame.isValidMove(playerMove);
		}
		
		system("cls");
		ourGame.drawBoard(screen);
		playerTurn = ourGame.setPlayerMove(screen, playerMove, playerTurn);
		moveCounter++;
		
		winner = ourGame.checkWin(winner);
		
		if(winner) {
			cout<<"\nGame over.  You Win!!\t\t\t\t\t\t\n";
			moveCounter=0;		
		}
		if(moveCounter>=9) {
			cout<<"\nTie Game.  Sorry.\t\t\t\t\t\t\t\t\t\t"<<endl;
		}
		if(winner || moveCounter>=9){
			cout<<"\n Do you want to play again? Y/N: ";
			char playAgain; cin>>playAgain;
			if(toupper(playAgain)=='Y') {
				winner=false;
				system("cls");
				ourGame.freshBoard(screen);
				ourGame.newGameMessage(screen);
				ourGame.drawBoard(screen);
				moveCounter=0;
				playerTurn=0;
			}
			else if(playAgain=='N') {
				break;
			}
		}
	}
	cout<< " \nThanks for playing!\t\t\t\t\t"<<endl;
		
	return 0;
}

/*
Let's play some Tic-Tac-Toe!

 To play, pick the number on the board where you want to move (1-9) or press -1 to quit

          7 | 8 | 9
          ---------
          4 | 5 | 6
          ---------
          1 | 2 | 3


 Player 1, pick your move now (1-9) or -1 to quit:

          7 | 8 | 9
          ---------
          O | X | 6
          ---------
          1 | 2 | 3


 Player 1, pick your move now (1-9) or -1 to quit: 4
Error. That is not a valid move.
 Player 1, pick your move now (1-9) or -1 to quit: 4
Error. That is not a valid move.
 Player 1, pick your move now (1-9) or -1 to quit:


          7 | 8 | 9
          ---------
          O | X | X
          ---------
          1 | 2 | 3


 Player 2, pick your move now (1-9) or -1 to quit: 7


          O | X | 9
          ---------
          O | X | X
          ---------
          O | 2 | 3


Game over.  You Win!!
 Do you want to play again? Y/N:


Let's play some Tic-Tac-Toe!

 To play, pick the number on the board where you want to move (1-9) or press -1 to quit

          7 | 8 | 9
          ---------
          4 | 5 | 6
          ---------
          1 | 2 | 3


 Player 1, pick your move now (1-9) or -1 to quit:

          X | X | O
          ---------
          O | O | X
          ---------
          X | O | X


 Tie Game.  Sorry.
 
 Do you want to play again? Y/N:


*/
