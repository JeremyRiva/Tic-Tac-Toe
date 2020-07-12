# Tic Tac Toe

## Outline

The aim of the game is to enter 4 of a kind in a row (horizontal, vertical or diagonal) before the other player does.

## User Manual
The game starts displaying a menu as follows:

```
============ MENU ============

1. Play Multiplayer game 

2. Help 

3. Exit 

==============================
```

If an invalid selection is chosen, an error message is displayed prompting the user to reselect a valid option:
`invalid option - try again`

When the user selects the play option, the user is prompted to enter a name. 
The player then is required to choose where to play entering a value for the row and the column.
_i.e. if player 1 chooses (2, 3)_ the result will show as follows:

```
    1 2 3 4
  1 - - - -
  2 - - x -
  3 - - - -
  4 - - - -
```

### Error messages
Error messages are displayed for invalid options.

When the place is already taken on the board the following message is displayed: 
`position has already been taken - try again`

When the choice is out of range the following message is displayed:
`out of range - try again`




