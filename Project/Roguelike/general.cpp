#include "stdafx.h"
#include "tiles.h"

void wColorOn(WINDOW *win, int foreground, int background) {
	int x = returnColorPair(foreground, background);
	wattron(win, COLOR_PAIR(x)); 
}

void wColorOff(WINDOW *win, int foreground, int background) {
	int x = returnColorPair(foreground, background);
	wattroff(win, COLOR_PAIR(x));
}

void initializeColors() {
	int ind = 1;
	if (has_colors() == TRUE) {						/* Initialize all possible color pairs */
		start_color();
		for (int i = 0; i <= 8; i++) {
			for (int j = 0; j <= 8; j++) {
				init_pair(ind, i, j);
				ind++;
			}
		}
	}
}

int randomNumber(int minValue, int maxValue) {		/* Return random number*/
	if (minValue == 0 && maxValue == 1) {			/* return 0/1 */
		return  (rand() % 2 + 1) / 2;
	}
	maxValue -= minValue;
	return (rand() % maxValue + minValue);			/* return max/min */
}

bool checkForEncounter() {
	static double chance = 99;						/* 1% chance to start random encounter at start*/
	if (randomNumber(1, 100) > chance) {			/* If encounter happens reset chance */
		chance = 97.5;
		return true;
	}
	else {
		chance -= 0.2;								/* Increases the chance to find encounter by 0.2% everytime you move */
		return false;
	}
}