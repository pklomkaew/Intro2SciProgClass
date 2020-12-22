#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct text{
	string phrase;
	int K;
	string encrypted;
	string decrypted;

};

char shift(char x, int K1);
void encrypt(text &A);
void decrypt(text &B);

int main()
{
	text myText;

	/*
	cout << "Enter a phrase you wish to encrypt: " << endl;
	getline(cin, myText.phrase);
	cout << "Enter a K-shift value: " << endl;
	cin >> myText.K;
	cout << endl;
	*/

	myText.phrase = "Life the universe and everything equals 42";
	myText.K = 42;

	encrypt(myText);
	cout << "The encrypted phrase is: " << endl;
	cout << myText.encrypted << endl;
	cout << endl;

	decrypt(myText);
	cout << "The decrypted phrase (should be original phrase) is: " << endl;
	cout << myText.decrypted << endl;
	cout << endl;

	return 0;
}

// Function that shifts the ASCII of character x by +K1 and returns that new character
char shift(char x, int K1)
{
	// Convert character x to ASCII integer X
	int X = int(x);
	int Y; // ASCII shifted
	
	// If no shift	
	if (K1 == 0) {Y = X;}

	// Lower case letters: ASCII between 97 and 122
	else if (X >= 'a' && X <= 'z')
	{	
		if (K1 > 0) {Y = 'a' + (((X - 'a')+K1) % 26);}
		if (K1 < 0) {Y = 'a' + ( (X - 'a') + (26+(K1 % 26)) )%26;}
	} 

	// Capitalized letters: ASCII between 65 and 90		
	else if (X >= 'A' && X <= 'Z')
	{ 
		if (K1 > 0) {Y = 'A' + (((X - 'A')+ K1) % 26);}
		if (K1 < 0) {Y = 'A' + ( (X - 'A') + (26+(K1%26)) ) % 26;}
	}

	// Numbers: ASCII between 48 and 57
	else if (X >= '0' && X <= '9')
	{
		if (K1 > 0) {Y = '0' + (((X - '0')+ K1) % 10);}
		if (K1 < 0) {Y = '0' + ( (X - '0') + (10+(K1 % 10)) ) % 10;}
	}

	// Space & other characters --> No shift 
	else 
	{
		Y = X;
	}
 	
	return char(Y); 
}

void encrypt(text &A)
{
	for (int i = 0; i < A.phrase.size(); i++)
	{
		char a;
		a = A.phrase.at(i);
		A.encrypted = A.encrypted + shift(a, A.K);
	}
}

void decrypt(text &B)
{
	for (int i = 0; i < B.phrase.size(); i++)
	{
		char b;
		b = B.encrypted.at(i);
		B.decrypted = B.decrypted + shift(b, -B.K);
	}
}	
