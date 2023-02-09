#include <stdio.h>

int main() {
	char fileName[20]; // creates a character array that will store the name of the input file
	printf("Enter a file name for the input: "); // asks for the input file
	fflush(stdout); // adds a buffer so that the print statement prints before scanning
	scanf("%s", fileName); // scans for the file name input from the user

	FILE* inputFile = fopen(fileName, "r"); // opens the file
	float monthlySales[13]; // creates an array that will store each month's sales

	if (inputFile == NULL) { // runs if the file is empty
		printf("no such file");
		return 0; // ends the program
	}

	printf("Monthly sales report for 2022:\n\nMonth		Sales\n"); //

	for (int i = 0; i < 12; i++) { // for loop to add the sales to the array and print them out
		fscanf(inputFile, "%f ", &monthlySales[i]); // scans the line for a float and adds the number to the array

		switch(i) { // switch statement to print the correct month
			case 0:
				printf("January		");
				break;
			case 1:
				printf("February	");
				break;
			case 2:
				printf("March		");
				break;
			case 3:
				printf("April		");
				break;
			case 4:
				printf("May		");
				break;
			case 5:
				printf("June		");
				break;
			case 6:
				printf("July		");
				break;
			case 7:
				printf("August		");
				break;
			case 8:
				printf("September	");
				break;
			case 9:
				printf("October		");
				break;
			case 10:
				printf("November	");
				break;
			case 11:
				printf("December	");
				break;
		}
		printf("%f\n", monthlySales[i]); // prints the month's sales
	}

	printf("\n\nSales summary:\n\n");

	float min = monthlySales[0]; // sets the starting minimum as January's sales
	float max = monthlySales[0]; // sets the starting maximum as January's sales
	int minIndex = 0; // sets the starting minimum index value as January
	int maxIndex = 0; // sets the starting maximum index value as January

	float average = monthlySales[0]; // sets the starting average value as January's sales

	for (int i = 1; i < 12; i++) { // for loop to go over every month and find the min and max and add all to the average
		average = average + monthlySales[i]; // adds the current month's sales to the average
		if (monthlySales[i] < min) { // runs if the current month's sales are less than the stored min
			min = monthlySales[i]; // changes the min value to the new smallest value found
			minIndex = i; // sets the minIndex as the index of the smallest month
		}
		if (monthlySales[i] > max) { // runs if the current month's sales are more than the stored max
			max = monthlySales[i]; // changes the max value to the new largest value found
			maxIndex = i; // sets the maxIndex as the index of the largest month
		}
	}

	printf("Minimum sales:		$%f		", min); // prints the minimum sales month

	switch(minIndex) { // switch statement to print the month that has the smallest amount of sales
		case 0:
			printf("(January)\n");
			break;
		case 1:
			printf("(February)\n");
			break;
		case 2:
			printf("(March)\n");
			break;
		case 3:
			printf("(April)\n");
			break;
		case 4:
			printf("(May)\n");
			break;
		case 5:
			printf("(June)\n");
			break;
		case 6:
			printf("(July)\n");
			break;
		case 7:
			printf("(August)\n");
			break;
		case 8:
			printf("(September)\n");
			break;
		case 9:
			printf("(October)\n");
			break;
		case 10:
			printf("(November)\n");
			break;
		case 11:
			printf("(December)\n");
			break;
	}

	printf("Maximum sales:		$%f		", max); // prints the maximum sales month

	switch(maxIndex) { // switch statement to print the month that has the largest amount of sales
		case 0:
			printf("(January)\n");
			break;
		case 1:
			printf("(February)\n");
			break;
		case 2:
			printf("(March)\n");
			break;
		case 3:
			printf("(April)\n");
			break;
		case 4:
			printf("(May)\n");
			break;
		case 5:
			printf("(June)\n");
			break;
		case 6:
			printf("(July)\n");
			break;
		case 7:
			printf("(August)\n");
			break;
		case 8:
			printf("(September)\n");
			break;
		case 9:
			printf("(October)\n");
			break;
		case 10:
			printf("(November)\n");
			break;
		case 11:
			printf("(December)\n");
			break;
	}

	average = average / 12; // averages all the months
	printf("Average sales:  	$%f\n", average); // prints the average of all the months

	printf("\n\nSix-Month Moving Average Report:\n\n");

	for (int i = 0; i < 7; i++) { // for loop to find every six month average of the year
		float sixMonthAverage = 0; // creates the sixMonthAverage variable with a starting 0 value
		switch(i) { // switch to see which six month average is being found
			case 0:
				printf("January		-	June		");
				break;
			case 1:
				printf("February	-	July		");
				break;
			case 2:
				printf("March		-	August		");
				break;
			case 3:
				printf("April		-	September	");
				break;
			case 4:
				printf("May		-	October		");
				break;
			case 5:
				printf("June		-	November	");
				break;
			case 6:
				printf("July		-	December	");
				break;
		}

		for (int j = 0; j < 6; j++) { // for loop to add the six month stretch together
			sixMonthAverage = sixMonthAverage + monthlySales[i + j]; // adds the month to the average
		}

		sixMonthAverage = sixMonthAverage / 6; // averages the six months
		printf("$%f\n", sixMonthAverage); // prints the six month average
	}

		printf("\n\nSales Report (Highest to Lowest):\n\nMonth		Sales\n");

		for (int i = 0; i < 12; i++) { // for loop to print the monthly sales in descending order
			float currentMax = 0; // sets the currentMax as 0 to compare to others
			int currentMaxIndex; // currentMaxIndex will store the index of the next value needing to be printed

			for (int j = 0; j < 12; j++) { // for loop to find the largest value still in the array
				if (monthlySales[j] > currentMax) { // checks if the current index value is larger than the current largest
					currentMax = monthlySales[j]; // sets the current index as the currentMax value
					currentMaxIndex = j; // sets the currentMaxIndex as j in order to print the right month
				}
			}

			switch(currentMaxIndex) { // switch to print the correct month for the current line
				case 0:
					printf("January		");
					break;
				case 1:
					printf("February	");
					break;
				case 2:
					printf("March		");
					break;
				case 3:
					printf("April		");
					break;
				case 4:
					printf("May		");
					break;
				case 5:
					printf("June		");
					break;
				case 6:
					printf("July		");
					break;
				case 7:
					printf("August		");
					break;
				case 8:
					printf("September	");
					break;
				case 9:
					printf("October		");
					break;
				case 10:
					printf("November	");
					break;
				case 11:
					printf("December	");
					break;
				default:
					printf("shit");
					break;
			}
			printf("$%f\n", currentMax); // prints the current line value
			monthlySales[currentMaxIndex] = 0; // set the index of the currentMax as 0 so that it isn't printed again next loop

		}
		return 0;
}
