# NegaMax Noughts and Crosses

<img width="373" alt="sample_game" src="https://user-images.githubusercontent.com/95873993/196990448-a495a449-6b56-4ead-a837-cdd2aadb7b22.png">

## Overview
An implementation of the NegaMax algorithm on Noughts and Crosses. All games will either end in a win or a draw for the computer.

## Board Representation
A binary bitboard representation is used for each marker type. The bit order to encode for a 3x3 board is as follows:

```
0 1 2
3 4 5
6 7 8
. . .
. . .
. . .
```

Along with the bitboards, an array of previous moves, the number of moves played, and the current side to play are also tracked.

## NegaMax
The NegaMax algorithm is a derivative of the MiniMax algorithm. By negating the score returned by recursive calls, only one routine is needed to support both players. Evaluation is done once and end game state is reached, and the position is score depending on whether the current side won or lost, or if the game resulted in a draw.
