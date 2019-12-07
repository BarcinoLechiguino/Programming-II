#include "Ex5.h"
#include <cstring>
#include <iostream>
using namespace std;

void printCharPtr(char *myString) {
	for (int i = 0; myString[i] != '\0'; ++i) {
		cout << myString[i];
	}
	cout << endl;
}

int sizeWord(char *word)
{
	int result = 0;
	for (int i = 0; word[i] != '\0'; ++i) {
		result++;
	}
	return result;;
}

void concat(char *word1, char *word2, char *result)
{
	int i = 0;
	for (i = 0; word1[i] != '\0'; ++i) {
		result[i] = word1[i];
	}
	for (int j = 0; word2[j] != '\0'; ++i, ++j) {
		result[i] = word2[j];
	}
	result[i] = '\0';
}

void ex5()
{
	char word1[64];
	char word2[64];
	cout << "First word: " << flush;
	cin >> word1;
	cout << "Second word: " << flush;
	cin >> word2;

	int word1Len = sizeWord(word1);
	int word2Len = sizeWord(word2);

	// Size for the two words + 1 null character
	char *arr = (char*)malloc(word1Len + word2Len + 1);

	concat(word1, word2, arr);

	printCharPtr(arr);

	free(arr);
}