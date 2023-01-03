#include "CreateAccount.h"
CreateAccount::CreateAccount()  //cons
{
	std::cout << "Hello! welcome to DSA ZOO SYSTEM. ";
	std::cout << "To get into our program.. first, you need to create an account :) \n";
}

CreateAccount::~CreateAccount() //des
{
	std::cout << "\n\nWelcome to DSA ZOO SYSTEM! \n";
}
void selectionSort(int[], int);
void CreateAccount::getInformation(char firstname[10], char lastname[10], char fullname[20])
{

	char copy[20];
	std::cout << "Please insert your first name : ";
	std::cin.get(firstname, 10);
	std::cin.ignore();
	std::cout << "please insert your last name : ";
	std::cin.getline(lastname, 10);

	strcpy_s(copy, firstname);  //copy first name to copy
	strcat_s(copy, lastname);  //combine first name and lastname


	for (int i = 0; i < strlen(copy); i++)  //fullname will get combine name inside copy
	{


		fullname[i] = copy[i];


	}

	for (int i = (strlen(copy)); i < 20; i++)  //to make sure balance index in fullname will be null. without this, error occur which is balance of index are error symbol
	{

		fullname[i] = '\0';
	}


}

int CreateAccount::Account(char fullname[20], char username[10])
{
	//create username
	int random;
	srand(time(0));
	random = rand() % 9 + 0;
	char crandom = '0' + random;


	for (int i = 0; i < 9; i++)  //want to limit in username they will have 8 char in fullname only. 9th index will have random number(so that its not the same username for every user)
	{
		username[i] = fullname[i];
		if (i == 8)
		{
			username[i] = crandom;
		}
	}

	for (int i = 9; i < strlen(username); i++)  //balance index will be null. 
	{
		username[i] = '\0';
	}



	//create password
	int const many = 3;
	int randompassword[3];
	std::cout << "\n\n\nWe will give you random a password";
	std::cout << "\nplease choose 1 and make sure it is in LOWER CASE \n";
	srand(time(0));
	char choose[many] = { 'a', 'b', 'c' };
	for (int j = 0; j < many; ++j)
	{
		randompassword[j] = rand() % 9999 + 1000;   //random number 1000-9999
	}
	selectionSort(randompassword, 3);
	for (int j = 0; j < many; ++j)
	{
		std::cout << "(" << choose[j] << ") " << randompassword[j];
		std::cout<<std::endl;
	}
	char answer;
	std::cout << " your choose? = ";
	std::cin >> answer;

	for (int j = 0; j < many; j++)
	{
		if (answer == choose[j])
		{
			password = randompassword[j];
			break;
		}

	}
	std::cout << "\n\nYour Password : " << password;
	std::cout << "\nYour Username : ";
	for (int i = 0; i < strlen(username); i++)
	{
		std::cout << username[i];
	}

	return password;
}

int CreateAccount::SecurityQuestion(char fullname[20])
{
	length = strlen(fullname);

	std::cout << "\n\n\nTHIS IS YOUR SECURITY QUESTION AND ANSWER. WHENEVER YOU FORGOT YOUR PASSWORD, THIS WILL BE YOUR ANSWER TO GET BACK YOUR PASSWORD.";
	std::cout << "\n\nQUESTION : how many length is in your name? ";
	std::cout << "\nANSWER: " << length;

	return length;
}

void CreateAccount::outputFile(char firstname[10], char lastname[10], char fullname[20], int length, char username[10], int password, std::ofstream* output)
{

	*output << "THIS IS YOUR PRIVACY INFORMATION. PLEASE DONT SHARE WITH ANYONE ELSE. \n\n";
	*output << "YOUR NAME : ";
	for (int i = 0; i < strlen(firstname); i++)
	{
		*output << (firstname[i]);
	}
	*output << " ";
	for (int i = 0; i < strlen(lastname); i++)
	{
		*output << lastname[i];
	}

	*output << "\nYOUR USERNAME : ";
	for (int i = 0; i < strlen(username); i++)
	{
		*output << username[i];
	}
	*output << "\nYOUR PASSWORD : " << password;
	*output << "\n\nTHIS IS YOUR SECURITY QUESTION AND ANSWER. WHENEVER YOU FORGOT YOUR PASSWORD, THIS WILL BE YOUR ANSWER TO RESET YOUR OLD PASSWORD.";
	*output << "\n\nQUESTION : how many length is in your name? ";
	*output << "\nANSWER: " << length;

}

void CreateAccount::LogIn(int length, int password, char username[10], std::ofstream* output)
{
	int pass;
	char usern[10];
	int count = 0;
	char reset;
	int security;
	do {


		std::cout << "USERNAME : ";
		std::cin >> usern;

		std::cout << "PASSWORD: ";
		std::cin >> pass;

		if (pass == password)
		{
			break;
		}

		if (pass != password)
		{
			std::cout << "USERNAME OR PASSWORD NOT VALID. PLEASE TRY AGAIN \n\n\n";
			count++;

		}

		if (count == 3)
		{
			std::cout << "\nIt seems like you don't know the password. do you want to reset your password? (y/n)\nYour Answer: ";
			std::cin >> reset;
			if (reset == 'y' || reset == 'Y')
			{
				std::cout << "\nthis is a security question.\nHOW MANY LENGTH IN YOUR NAME? ";
				std::cout << "\nYour Answer : ";
				std::cin >> security;
				if (security == length)
				{
					std::cout << "\n\n\nYou are required to have a new password\n";

					password = rand() % 999 + 100; //100-999
					std::cout << "this is your new password : " << password;
					*output << "\n\nYour New Password : " << password;
					std::cout << "\nPress anything....";
					std::cout << "\n\n\nUSERNAME : ";
					std::cin >> username;
					std::cout << "PASSWORD: ";
					std::cin >> pass;

					if (pass == password)
						break;
					else
					{
						std::cout << "Unfortunately, you will exit automatically from our system. " << std::endl;
						exit(0);
					}

				}
				else
				{
					std::cout << "you answered it uncorrectly. you will automatically exit from our system. sorry. " << std::endl;
					exit(0);
				}
			}
			else
			{
				exit(0);
			}
		}
	} while (pass != password);


}
void selectionSort(int array[], int size)
{
	int temp; // temporary variable used for swapping
	int i;
	int j;
	// sort array until only one element is left
	for (i = 0; i < size; i++) // You used the const SIZE, which is unknown to the routine, plus 
							// you were sorting with size - 2 ( < size-1)
	{
		j = i;
		while (j > 0 && (array[j - 1] > array[j]))
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
} // end method selectionSort 
