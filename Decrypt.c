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
	
}

/*
 * Compare the data in array found with the frequency data
 * given, looking for a key that will give you the best match. 
 * To do this, try each of the 26 rotations, and remember which gives
 * the smallest difference between the frequences you observed and the 
 * frequencies given. Return the key
 */
int findKey(float given[], float found[]) {
	
}

/*
 * Decrypt the encoded text in the input file using the key and display
 * the decoded text
 */
void decrypt(int key) {
	
}

/*
 * Helper for findKey() 
 */
void rotate() {
	
}