#include <stdio.h>
void recursiveTower(int, char, char, char);
void oneDirection(int, char, char, char);

int main(int argc, char *argv[]){
   recursiveTower(3,'A','C','B');
   return 0;

}

// this function moves disks from A to C recursively
void recursiveTower(int numOfDisks, char fromRod, char toRod, char midRod){
   if (numOfDisks > 1){
      recursiveTower(numOfDisks - 1, fromRod, toRod, midRod);
      printf("MOVE %c TO %c\n", fromRod, midRod);
      oneDirection(numOfDisks-1, midRod, toRod, fromRod);
      printf("MOVE %c TO %c\n", midRod, toRod);
      recursiveTower(numOfDisks-1, fromRod, toRod, midRod);
   }else{
      printf("MOVE %c TO %c\n", fromRod, midRod);
      printf("MOVE %c TO %c\n", midRod, toRod);
   }
}

// this function moves the disk one space
void oneDirection(int numOfDisks, char fromRod, char toRod, char midRod){
   if(numOfDisks > 1){
      recursiveTower(numOfDisks-1, toRod, fromRod, midRod);
      printf("MOVE %c TO %c\n", toRod, midRod);
      recursiveTower(numOfDisks-1, fromRod, midRod, toRod);
   }
   else
      printf("MOVE %c TO %c\n", toRod, midRod);
   
}