#include <iostream>
#include <stdio.h>

void Encrypt(char message[], int key);
void Decrypt(char message[], int key);

int main()
{
	char message[100];
	int key = 0;

	printf("Caesar Encryption/Decryprion!\n");
	printf("Select operation\n");
	printf("1.Encrypt text.\n");
	printf("2.Decrypt text.\n");

	int operation = 0;
	scanf("%d", &operation);

	if (operation == 1)
	{
		printf("Message:\n");
		std::cin >> message;
		printf("Key:\n");
		scanf("%d", &key);

		Encrypt(message, key);
	}
	else if (operation == 2)
	{
		printf("Message:\n");
		std::cin >> message;
		printf("Key:\n");
		scanf("%d", &key);

		Decrypt(message, key);
	}
	printf("\n");

	system("pause");
}

void Encrypt(char message[], int key)
{
	char ch;

	for (int i = 0; message[i] != '\0'; i++)
	{
		ch = message[i];

		if (ch >= 97 && ch <= 122) // lowerCase a -> z
		{
			ch += key;

			if (ch > 122) //if gets after z
				ch = ch - 122 + 97 - 1; // then go and count from a

			message[i] = ch;
		}
		else if (ch >= 65 && ch <= 90) // upperCase a -> z
		{
			ch += key;

			if (ch > 90) //if gets after Z
				ch = ch - 90 + 65 - 1; // then go and count from A

			message[i] = ch;
		}
	}
	printf("Encrypted message: %s", message);
}

void Decrypt(char message[], int key)
{
	char ch;

	for (int i = 0; message[i] != '\0'; i++)
	{
		ch = message[i];

		if (ch >= 97 && ch <= 122) // lowerCase a -> z
		{
			ch -= key;

			if (ch < 97) //if gets after z
				ch = ch + 122 - 97 + 1; // then go and count from a

			message[i] = ch;
		}
		else if (ch >= 65 && ch <= 90) // upperCase a -> z
		{
			ch -= key;

			if (ch < 65) //if gets after Z
				ch = ch + 90 - 65 + 1; // then go and count from A

			message[i] = ch;
		}
	}
	printf("Decrypted message: %s", message);
}