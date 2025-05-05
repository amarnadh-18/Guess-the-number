#include <stdio.h>
#include <string.h>

int main() {
  // Get word to guess
  int i,j,k,m,chances=6;
  char answer[20];
  printf("Enter word to guess: ");
  fflush(stdout);
  scanf(" %s", answer);

  // Set the mask array - mask[i] is true if the
  // character s[i] has been guessed.  The mask
  // must be allocated, and initialized to all false
  int N = strlen(answer);
  int mask[N];
  for ( i=0; i < N; ++i) {
    mask[i] = 0;
  }

  // Loop over each round of guessing
  int gameover = 0;
  while ( !gameover) {
    // Print word with *s for unguessed letters
    printf("The word is : ");
    for( j=0; j < N; ++j) {
      if (mask[j]) {
        printf("%c", answer[j]);
      }
      else {
        printf("*");
      }
    }
    printf("\n");

    // Get player's next guess
    char guess;
    printf("Letter? ");
    fflush(stdout);
    scanf(" %c", &guess);

    // Mark true all mask positions corresponding to guess
    for( k=0; k < N; ++k) {
      if (answer[k] == guess) {
	mask[k] = 1;
      }
    }

    // Determine whether the player has won!
    gameover = 1;
    for( m = 0; m < N; ++m) {
      if (!mask[m] && chances!=0) {
        chances--;
        gameover = 0;
        if(chances!=0)
        printf("Try again \n");
        break;
      }
    }
    if(chances==0){
    	printf("The man is hanged.\n");
        printf("\nYou Lose! Better luck next time!");
        break;
    }
    
  }
  if(chances!=0)
  // Print victory message!
  printf("Victory! The word is \"%s\".\n", answer);


  return 0;
}
