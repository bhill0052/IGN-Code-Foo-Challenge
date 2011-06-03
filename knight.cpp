// Knight's Tour Program
// Bradley Hill      (2011)

#include <iostream>
#include <time.h>
using namespace std;

int board[8][8];
int currentposx = 6;
int currentposy = 4;
bool end = false;


void move(int x)  // Moves the knight to a new position
{
 switch(x) {
case 1: currentposx=currentposx+1;
    currentposy=currentposy+2;
    break;
case 2: currentposx=currentposx+2;
    currentposy=currentposy+1;
    break;
case 3: currentposx=currentposx+2;
    currentposy=currentposy-1;
    break;
case 4: currentposx=currentposx+1;
    currentposy=currentposy-2;
    break;
case 5: currentposx=currentposx-1;
    currentposy=currentposy-2;
    break;
case 6: currentposx=currentposx-2;
    currentposy=currentposy-1;
    break;
case 7: currentposx=currentposx-2;
    currentposy=currentposy+1;
    break;
case 8: currentposx=currentposx-1;
    currentposy=currentposy+2;
    break;
}
   board[currentposx][currentposy] = 1;
}

int findempty() {    // Finds an unvisited space on the board
    int x = rand() % 2;
    for(int i=0; i < 8; i++)  {
         for(int k=0; k < 8; k++)  {
                 if((board[i][k] == 0) && (i >= currentposx) && (k > currentposy) && (x == 1)) 
                                 return 0;
                 else if((board[i][k] == 0) && ( i > currentposx) && (k > currentposy))
                                 return 1;
                 else if((board[i][k] == 0) && (i > currentposx) && (k <= currentposy) && (x == 1))
                                 return 2;
                 else if((board[i][k] == 0) && (i > currentposx) && (k < currentposy))
                                 return 3; 
                 else if((board[i][k] == 0) && (i < currentposx) && (k <= currentposy)  && (x == 1))
                                 return 4;
                 else if((board[i][k] == 0) && (i < currentposx) && (k < currentposy))
                                 return 5;
                 else if((board[i][k] == 0) && (i <= currentposx) && (k > currentposy) && (x == 1))
                                 return 6;
                 else if((board[i][k] == 0) && (i < currentposx) && (k > currentposy))
                                 return 7;
         }
    }    
}

void unstuck(int x) {  // If no space was found, move toward an unvisited space
if((x == 0) &&
    (currentposx+1 >= 0 && currentposx+1 <= 7) &&
    (currentposy+2 >= 0 && currentposy+2 <= 7))
  move(1); 
 else if((x == 1) &&
            (currentposx+2 >= 0 && currentposx+2 <= 7) &&
            (currentposy+1>= 0 && currentposy+1 <= 7))
  move(2); 

else if((x == 2) &&
            (currentposx+2 >= 0 && currentposx+2 <= 7) &&
            (currentposy-1 >= 0 && currentposy-1<= 7))
  move(3); 
else if((x == 3) &&
            (currentposx+1 >= 0 && currentposx+1 <= 7) &&
            (currentposy-2 >= 0 && currentposy-2 <= 7))
  move(4); 
else if((x == 4) &&
            (currentposx-1 >= 0 && currentposx-1 <= 7) &&
            (currentposy-2 >= 0 && currentposy-2 <= 7))
  move(5); 
else if((x == 5) &&
            (currentposx-2 >= 0 && currentposx-2 <= 7) &&
            (currentposy-1 >= 0 && currentposy-1 <= 7))
  move(6); 
else if((x == 6) &&
            (currentposx-2>= 0 && currentposx-2 <= 7) &&
            (currentposy+1 >= 0 && currentposy+1 <= 7))
  move(7); 
    else if((x == 7) &&
            (currentposx-1 >= 0 && currentposx-1 <= 7) &&
            (currentposy+2 >= 0 && currentposy+2 <= 7))
  move(8);
}
     

void direction()  // Moves to an unvisited space
{
if((board[currentposx+1][currentposy+2] == 0) &&
    (currentposx+1 >= 0 && currentposx+1 <= 7) &&
    (currentposy+2 >= 0 && currentposy+2 <= 7))
  move(1); 

else if((board[currentposx+2][currentposy+1] == 0) &&
            (currentposx+2 >= 0 && currentposx+2 <= 7) &&
            (currentposy+1>= 0 && currentposy+1 <= 7))
  move(2); 

else if((board[currentposx+2][currentposy-1] == 0) &&
            (currentposx+2 >= 0 && currentposx+2 <= 7) &&
            (currentposy-1 >= 0 && currentposy-1<= 7))
  move(3); 

else if((board[currentposx+1][currentposy-2] == 0) &&
            (currentposx+1 >= 0 && currentposx+1 <= 7) &&
            (currentposy-2 >= 0 && currentposy-2 <= 7))
  move(4); 

else if((board[currentposx-1][currentposy-2] == 0) &&
            (currentposx-1 >= 0 && currentposx-1 <= 7) &&
            (currentposy-2 >= 0 && currentposy-2 <= 7))
  move(5); 

else if((board[currentposx-2][currentposy-1] == 0) &&
            (currentposx-2 >= 0 && currentposx-2 <= 7) &&
            (currentposy-1 >= 0 && currentposy-1 <= 7))
  move(6); 

else if((board[currentposx-2][currentposy+1] == 0) &&
            (currentposx-2>= 0 && currentposx-2 <= 7) &&
            (currentposy+1 >= 0 && currentposy+1 <= 7))
  move(7); 

else if((board[currentposx-1][currentposy+2] == 0) &&
            (currentposx-1 >= 0 && currentposx-1 <= 7) &&
            (currentposy+2 >= 0 && currentposy+2 <= 7))
  move(8);
 
else 
  unstuck(findempty());  //None within one move's range

}

int main()
{

   int movecount = 0;
   int covered;
   
   srand ( time(0) );
   
   while(!end) {
      
      direction();
      movecount++;

      end = true;
      covered = 0;
      for(int i=0; i < 8; i++)  {
         for(int k=0; k < 8; k++)  {
             if(board[i][k] == 0) 
                 end = false;    
             else
                covered++;
         }       
       }
    cout << "Moves: " << movecount << "   Spaces Covered: " << covered << endl;
    }
    cin.get();
}
