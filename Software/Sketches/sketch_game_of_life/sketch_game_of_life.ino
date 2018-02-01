/**
 * CPP IEEE Winter 2018 Quarterly Project
 * 
 * Purpose:
 * Replicate Conway's Game of Life on an Arduino
 * with a 32x32 LED display. Control the generation
 * cycle speed, to manually set up the board, to
 * randomly generate a new board once the board's
 * state stops changing for an amount of time, and
 * to control LED brightness.
 * 
 * These goals may change throughout the course
 * of the project depending on how other teams
 * in the project are doing.
 * 
 * 
 * The Circuit:
 * Inputs:
 * Outputs:
 * 
 * Created January 17, 2017
 * By Jacob London
 * Modified January 17,2017
 * By Jacob London
 * Modified January 28, 2017
 * By Christopher Dunn
 * 
 * https://github.com/Zsquier/WinterQuarterlyProject
 */
byte PROGMEM board[][];
byte PROGMEM pins[];

// code to run once
void setup() {
    

}

// code to run repeatedly
void loop() {


}

// functions

/*
 * getNeighbors Function
 * Purpose: To determine how many neighbors each cell has.
 * Function takes input x and y as coordinates of cell that needs to be checked and returns the amount of neighbors that the cell has
 * Notes: Don't check cells that are out of bounds. Can return once neighbors is 4 since greater then 4 doesnt effect state.
 */
byte getNeighbors(byte x, byte y){
  byte neighbors = 0;   //amount of neighbors around a cell
  for (byte a = y-1; a <= y+1; a++){
    for (byte b = x-1; b <= x+1; b++){
      if((a >= 0) && (a <= 31) && (b >= 0) && (b <= 31)){
        if((a == y && b == x)) 
          continue;    //This makes sure not to increase neighbors if it is itself or out or bounds.
        if(board[a][b] == 1)
          neighbors++;         //when a neighbor is alive increase neighbors by one
        if(neighbors > 3) 
          return neighbors;      //It doesn't matter if there are more then 4 neighbors around a cell so we can return at 4
      }
    }
  }
  return neighbors;
}

/*
 * clearBoard Function
 * Purpose: Clears the board to all zero/dead
 */
void clearBoard(){
  for(byte x=0;x<32;x++){
    for(byte y=0;y<32;y++){
      board[x][y]=0;
    }
  }
}

/*
 * Randomize Board
 * Purpose: Set all cells to either 0 or 1
 */
 void ranodmizeBoard(){
  for(byte x=0;x<32;x++){
    for(byte y=0;y<32;y++){
      board[x][y]=random(0,2);
    }
  }
 }

 /*
  * Update Board
  * Purpose: Update the gameBoard to new state
  * TO DO: Try to make pointers work
  */
void updateBoard(){
  byte boardNew[32][32];
  byte neighbors = 0;
  for(byte x=0;x<32;x++){
    for(byte y=0;y<32;y++){
      neighbors = getNeighbors(x,y);
      //rule 1.
      if(neighbors < 2 && board[x][y]==1)
        boardNew[x][y] = 0;
      //rule 2.
      else if((neighbors == 2 || neighbors == 3) && board[x][y]==1 )
        boardNew[x][y] = 1;
      //rule 3.
      else if( neighbors > 3 && board[x][y]==1)
        boardNew[x][y] = 0;
      //rule 4.
      else if(neighbors == 3 && board[x][y]==0)
        boardNew[x][y] = 1;
      //Set boardNew dead needs to stay dead
      else
        boardNew[x][y] = 0;
    }
  }
  for(x=0;x<32;x++){
    for(y=0;y<32;y++){
      board[x][y] = boardNew[x][y];
    }
  }
}
/*
 * Determrine Equilibrium
 * Find average values to detect when board stops changing. Check when the board enters a state of equilibrium
 */
void determineEquilibrium(byte eSize, int counter){
  float Equilibrium[eSize];
  
}

