#include <stdio.h>
#include <math.h>

int scoreCount(int remainingScore, int scoredVals[]) {
	if (remainingScore == 0) { // checks if the passed in score is 0 meaning it has fully cleared and found a solution
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", scoredVals[0], scoredVals[1], scoredVals[2], scoredVals[3], scoredVals[4]); // prints the found combination of scoring
		return 1; // returns 1 to exit this function call
	}
	if ((remainingScore - 8) >= 0) { // checks if a touch down with 2 point conversion is possible with the current score
		scoredVals[0]++; // increases the scored touch downs with 2 point conversions count by 1
		scoreCount(remainingScore - 8, scoredVals); // recurses and calls the function with a reduced score and updated score count
		scoredVals[0]--; // decreases the scored touch downs with 2 point conversions count by 1 after exiting the recursion
	}

	if ((remainingScore - 7) >= 0) { // checks if a touch down with extra point is possible with the current score
		scoredVals[1]++; // increases the scored touch downs with extra points count by 1
		scoreCount(remainingScore - 7, scoredVals); // recurses and calls the function with a reduced score and updated score count
		scoredVals[1]--; // decreases the scored touch downs with extra points count by 1 after exiting the recursion
	}

	if ((remainingScore - 6) >= 0) { // checks if a touch down is possible with the current score
		scoredVals[2]++; // increases the scored touch downs count by 1
		scoreCount(remainingScore - 6, scoredVals); // recurses and calls the function with a reduced score and updated score count
		scoredVals[2]--; // decreases the scored touch downs count by 1 after exiting the recursion
	}

	if ((remainingScore - 3) >= 0) { // checks if a field goal is possible with the current score
		scoredVals[3]++; // increases the scored field goals count by 1
		scoreCount(remainingScore - 3, scoredVals); // recurses and calls the function with a reduced score and updated score count
		scoredVals[3]--; // decreases the scored field goals count by 1 after exiting the recursion
	}

	if ((remainingScore - 2) >= 0) { // checks if a safety is possible with the current score
		scoredVals[4]++; // increases the scored safeties count by 1
		scoreCount(remainingScore - 2, scoredVals); // recurses and calls the function with a reduced score and updated score count
		scoredVals[4]--; // decreases the scored safeties count by 1 after exiting the recursion
	}

	return 0; // returns 0 if the given score is not reduced to 0
}

int main() {
	int score; // int that will store the score value from the user
	int startScores[5] = {0, 0, 0, 0, 0}; // int array that will store how many of each scoring type for each combination
	printf("Enter a point value: "); // asks the user for the score value
	fflush(stdout); // adds a buffer so that the print statement prints before the buffer
	scanf("%d", &score); // scans the score given from the user
	scoreCount(score, startScores); // runs the scoreCount function that will find all combination of the given score and print them.
}
