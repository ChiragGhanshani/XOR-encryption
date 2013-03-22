#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

string& operator ^(string&, string&);

int main()
{
	string encryptMe, useMe;
	//enter the string to be encrypted
	cout << "Please enter a string to encrypt\n";
	getline(cin, encryptMe);
	cout << "You entered: " << encryptMe << endl;
	cin.get();

	//enter the encryption key
	cout << "Please enter an encryption key\n";
	getline(cin, useMe);
	cout << "Your key is: " << useMe << endl;
	cin.get();

	//encrypt the string and display resulting string
	encryptMe = encryptMe ^ useMe;
	cout << "The encrypted string is: "<< endl;
	for(int i = 0; i < encryptMe.length(); i++)
	{
		printf("%x", encryptMe[i]);

	}
	cin.get();

	//decrypt the string and display the original string
	encryptMe = encryptMe ^ useMe;
	printf("%c[2J",27);
	cout << "The decrypted string is: " << encryptMe << endl;
	cin.get();	

	cout << "Press any key to continue\n";
	cin.get();
	return 0;
}

string& operator ^(string& toBeEncrypted, string& encryptionKey)
{
	int i = 0, j = 0;
	while(toBeEncrypted[i] != '\0')
	{
		if( ((toBeEncrypted[i] ^ encryptionKey[j]) >= 32) && ((toBeEncrypted[i] ^ encryptionKey[j]) != 127))
		{
			toBeEncrypted[i] = toBeEncrypted[i] ^ encryptionKey[j];
		}
		i++;
		j++;
		if(encryptionKey[j] == '\0')
		{
			j = 0;
		}
	}
	return toBeEncrypted;
}
