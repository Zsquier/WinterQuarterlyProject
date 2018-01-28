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
int PROGMEM board[][];
int PROGMEM pins[];

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
int getNeighbors(int x, int y){
  int neighbors = 0;   //amount of neighbors around a cell
  for (int a = y-1; a <= y+1; a++){
    for (int b = x-1; b <= x+1; b++){
      if((a == y && b == x) || (a < 0) || (a > 31) || (b < 0) || (b > 31)) continue;    //This makes sure not to increase neighbors if it is itself or out or bounds.
      if(board[a][b] == 1) neighbors++;         //when a neighbor is alive increase neighbors by one
      if(neighbors == 4) return neighbors;      //It doesn't matter if there are more then 4 neighbors around a cell so we can return at 4
    }
  }
  return neighbors;
}

/*
 * clearBoard Function
 * Purpose: Clears the board to all zero/dead
 */
void clearBoard(){
  for(x=0;x<32;x++){
    for(y=0;y<32;y++){
      board[x][y]==0;
    }
  }
}
