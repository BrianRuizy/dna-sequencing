// Brian Ruiz - April 2019

/* The scope of this program is to practice and showcase
	understanding of finite automata. In essence the program
	implements a deterministic finite automata (DFA) 
	programming language to extract matching patterns from a given 
	input DNA sequence string.
*/

#include <string>
#include <iostream>
#include <algorithm> //library solely used to capitalize the users input
using namespace std;

string dna; 

string getInput()
{
	cout << "Input a DNA sequence string: ";
	cin >> dna;
	return dna;
}

int countSameEndingsSubstrings(string dna)
{
	int result = 0;
	int n = dna.length();
	cout << "\nMatching patterns are... " << endl;
	
	/* For loop will reiterate through the existing substrings,
	to find first and last characters */
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (dna[i] == dna[j])
			{
				if (dna[i] == 'A' || dna[i] == 'T')
				{
					cout << "- ";
					result++;
					for (int k = i; k <= j; k++) 
					{
						cout << dna[k];
					}
					cout << endl;
				}		
			}
	  result++;

	return result;
}


int main()
{
	getInput(); // get user dna sequence 
	transform(dna.begin(), dna.end(), dna.begin(), ::toupper); //capitalizes the users input
	countSameEndingsSubstrings(dna); // primary function

	return 0;
}