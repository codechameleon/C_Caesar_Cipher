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
	float freq;
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

int main() {
	float found[26];
	
	calcFreq(found);
}