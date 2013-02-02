#include <stdio.h>

/*
 * Load given array with the letter frequencies for English
 * from file LetFreq.txt
 */
void readFreq(float given[]) {
	int i = 0;
	float freq;
	char buff[20];
	char c;
	FILE *ifp;
	
	/* Open file */
	ifp = fopen("LetFreq.txt", "r");
	if (ifp == NULL) {
		printf("File could not be opened\n");
		
	}
	
	/* Read file and insert into array */
	do {
	fscanf (ifp, "%c %f", &c, &freq);
	given[i] = freq;
	i++;
	} while (fgets(buff, sizeof buff, ifp) != NULL);
		
	
	fclose(ifp);
} 

/*
 * Read the encoded text from an input file and accumulate
 * the letter frequency data for the encoded text. Store the 
 * frequency data in array found.
 */
void calcFreq(float found[]) {
	int i;
	int count[26] = {0};
	float total = 0;
	char ch;
	FILE *ifp;
	
	/* Open file */
	ifp = fopen("out.txt", "r");
	if (ifp == NULL) {
		printf("File could not be opened\n");
	}

	/* Read file and calculate letter frequency */
	while (fscanf(ifp,"%c",&ch) == 1) {
		
		/* keep total of characters found */
		ch = tolower(ch);
		if (ch >= 'a' && ch <= 'z' && !isspace(ch)) {
			count[ch-'a']++;
			total++;
		} 
	}
	fclose(ifp);
	
	/* Puts the frequencies in the found array */
	for (i=0; i < 26; i++) {
		
		if (count[i] != 0) {
			found[i] = (float)count[i]/total;
		}
	}
}

/*
 * Helper for findKey() 
 */
void rotate(float found[]) {
	
	int i;
	float temp;
	
	/* Gets the first element */
	temp = found[0];
	
	/* Shifts the array contents by one */
	for (i=0; i < 25; i++) {
		found[i] = found[i+1];
	}
	
	/* Sets the last array element to what the first was */
	found[25] = temp;
	
}

/*
 * Compare the data in array found with the frequency data
 * given, looking for a key that will give you the best match. 
 * To do this, try each of the 26 rotations, and remember which gives
 * the smallest difference between the frequences you observed and the 
 * frequencies given. Return the key
 */
int findKey(float given[], float found[]) {
	
	int i, j, k, key;
	float tempGiven, tempFound, diff, small, sum;
	
	/* Holds the sums for each index */
	float sums[26] = {0};
	
	
	for (i=0; i < 26; i++) {
		
		/* Calculates the frequency difference between arrays */
		for (j=0; j < 26; j++) {
			tempGiven = given[j];
			tempFound = found[j];
			//printf("tempFound is %f and found[i] is %f at index %d\n",tempFound,found[j],j);
			tempGiven = tempGiven * tempGiven;
			tempFound = tempFound * tempFound;
			//printf("TempGiven is %f and TempFound is %f\n",tempGiven,tempFound);
			/* Gets the difference */
			if (tempGiven >= tempFound) {
				diff = tempGiven - tempFound;
			} else {
				diff = tempFound - tempGiven;
			}
			sum += diff;
			//printf("Sum is %f\n",sum);
		}
		
		/* Add frequences difference to that key and rotate */
		sums[i] = sum;
		sum = 0;
		rotate(found);
	}
	
	small = sums[0];
	key = 0;
	
	/* Find the smallest difference */
	for (k=1; k < 26; k++) {
		
		/* If smaller */
		if (small > sums[k]) {
			small = sums[k];
			key = k;
		}
	}
	
	return key;
}

/*
 * Decrypt the encoded text in the input file using the key and display
 * the decoded text
 */
void decrypt(int key) {
	
}



int main() {
	
	float given[26] = {0};
	float found[26] = {0};
	
	readFreq(given);
	calcFreq(found);
	int answer;
	
	answer = findKey(given,found);
	printf("Answer is %d\n", answer);
	
	
	
}