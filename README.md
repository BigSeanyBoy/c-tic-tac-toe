# Noughts and Crosses

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

## Monte Carlo Tree Search
Monte Carlo Tree Search is an algorithm that randomly plays games, converging on the move from the current state most likely to result in a win. This algorithm isn't necessary for noughts and crosses, as minimax can already search the entire tree. However, it is interesting to play against because, compared to minimax, MCTS elicits a diverse play style without sacrificing quality due to the randomness of the search.
