#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_winner(char player1_turn, char player2_turn)
{
	if(player1_turn == player2_turn)
		return 0;

	if (player1_turn == 'R' && player2_turn == 'S')
		return 1;
	else if (player1_turn == 'P' && player2_turn == 'R')
		return 1;
	else if (player1_turn == 'S' && player2_turn == 'P')
		return 1;
	else
		return 2;
}


int main(int argc, char *argv[])
{
	char player1_turns[100];
	char player2_turns[100];
	int i, l, t;
	int player1_wins, player2_wins;

	while(1)
	{
		scanf("%s", player1_turns);
		scanf("%s", player2_turns);

		player1_wins = 0;
		player2_wins = 0;

		if(strcmp(player1_turns, "E") == 0 && strcmp(player2_turns, "E") == 0)
			break;

		l = strlen(player1_turns);

		for(i=0; i<l; i++)
		{
			t = get_winner(player1_turns[i], player2_turns[i]);

			if (t == 1)
				player1_wins++;
			else if (t == 2)
				player2_wins++;
		}

		printf("P1: %d\n", player1_wins);
		printf("P2: %d\n", player2_wins);
	}

	return 0;
}