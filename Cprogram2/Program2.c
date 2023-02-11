#include <stdio.h>
#include <math.h>

int scoreCount(int remainingScore, int scoredVals[], int checkedVals[]) {
	if (remainingScore == 0) { // checks if the passed in score is 0 meaning it has fully cleared and found a solution
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", scoredVals[0], scoredVals[1], scoredVals[2], scoredVals[3], scoredVals[4]); // prints the found combination of scoring
		return 1; // returns 1 to exit this function call
	}

	if (((remainingScore - 8) >= 0) & (checkedVals[0] == 0)) { // checks if a touch down with 2 point conversion is possible with the current score and hasn't already been tried fully
		scoredVals[0]++; // increases the scored touch downs with 2 point conversions count by 1
		if (scoreCount(remainingScore - 8, scoredVals, checkedVals) == 0) { // recurses and calls the function with a reduced score and updated score count
			//if statement runs if an output is not found in the recursion
			for (int i = 0; i < 5; i++) { // loops over each index in the checkedVals array
				checkedVals[i]--; // decreases the value of each by one so that the other scores can be checked
			}
		}
		scoredVals[0]--; // decreases the scored touch downs with 2 point conversions count by 1 after exiting the recursion
	}

	checkedVals[0]++; // increases the touch down with 2 point conversion value to show that all of that score type has been found for this output

	if (((remainingScore - 7) >= 0) & (checkedVals[1] == 0)) { // checks if a touch down with extra point is possible with the current score  and hasn't already been tried fully
		scoredVals[1]++; // increases the scored touch downs with extra points count by 1
		if (scoreCount(remainingScore - 7, scoredVals, checkedVals) == 0) { // recurses and calls the function with a reduced score and updated score count
			//if statement runs if an output is not found in the recursion
			for (int i = 0; i < 5; i++) { // loops over each index in the checkedVals array
				checkedVals[i]--; // decreases the value of each by one so that the other scores can be checked
			}
		}
		scoredVals[1]--; // decreases the scored touch downs with extra points count by 1 after exiting the recursion
	}
	checkedVals[1]++; // increases the touch down with extra point value to show that all of that score type has been found for this output

	if (((remainingScore - 6) >= 0) & (checkedVals[2] == 0)) { // checks if a touch down is possible with the current score and hasn't already been tried fully
		scoredVals[2]++; // increases the scored touch downs count by 1
		if (scoreCount(remainingScore - 6, scoredVals, checkedVals) == 0) { // recurses and calls the function with a reduced score and updated score count
			//if statement runs if an output is not found in the recursion
			for (int i = 0; i < 5; i++) { // loops over each index in the checkedVals array
				checkedVals[i]--; // decreases the value of each by one so that the other scores can be checked
			}
		}
		scoredVals[2]--; // decreases the scored touch downs count by 1 after exiting the recursion
	}
	checkedVals[2]++; // increases the touch down value to show that all of that score type has been found for this output

	if (((remainingScore - 3) >= 0) & (checkedVals[3] == 0)) { // checks if a field goal is possible with the current score and hasn't already been tried fully
		scoredVals[3]++; // increases the scored field goals count by 1
		if (scoreCount(remainingScore - 3, scoredVals, checkedVals) == 0) { // recurses and calls the function with a reduced score and updated score count
			//if statement runs if an output is not found in the recursion
			for (int i = 0; i < 5; i++) { // loops over each index in the checkedVals array
				checkedVals[i]--; // decreases the value of each by one so that the other scores can be checked
			}
		}
		scoredVals[3]--; // decreases the scored field goals count by 1 after exiting the recursion
	}
	checkedVals[3]++; // increases the field goal value to show that all of that score type has been found for this output

	if (((remainingScore - 2) >= 0) & (checkedVals[4] == 0)) { // checks if a safety is possible with the current score and hasn't already been tried fully
		scoredVals[4]++; // increases the scored safeties count by 1
		if (scoreCount(remainingScore - 2, scoredVals, checkedVals) == 0) { // recurses and calls the function with a reduced score and updated score count
			//if statement runs if an output is not found in the recursion
			for (int i = 0; i < 5; i++) { // loops over each index in the checkedVals array
				checkedVals[i]--; // decreases the value of each by one so that the other scores can be checked
			}
		}
		scoredVals[4]--; // decreases the scored safeties count by 1 after exiting the recursion
	}
	checkedVals[4]++; // increases the safety value to show that all of that score type has been found for this output

	return 0; // returns 0 if the given score is not reduced to 0
}

int main() {
	int score; // integer that will store the score value from the user
	printf("Enter a point value: "); // asks the user for the score value
	fflush(stdout); // adds a buffer so that the print statement prints before the buffer
	scanf("%d", &score); // scans the score given from the user

	while (score > 1) { // loops until an invalid score is entered
		int startScores[5] = {0, 0, 0, 0, 0}; // integer array that will store how many of each scoring type for each combination
		int checkedScores[5] = {0, 0, 0, 0, 0}; // integer array that will act as a check to make sure all of one score type has been found before moving to the next
		printf("\nScoring combinations for %d points\n", score);
		scoreCount(score, startScores, checkedScores); // runs the scoreCount function that will find all combination of the given score and print them.

		printf("\nEnter a point value: "); // asks the user for the score value
		fflush(stdout); // adds a buffer so that the print statement prints before the buffer
		scanf("%d", &score); // scans the score given from the user
	}

	printf("\nExiting..."); // prints an exit message

	return 0;
}
