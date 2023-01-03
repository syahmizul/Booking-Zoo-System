#pragma once
#include "includes.h"
class CreateAccount
{
private:
	char firstname[10];
	char lastname[10];
	char fullname[20];
	int length;
	char username[10];
	int password;
	std::ofstream output;

public:
	CreateAccount();  //constructor
	~CreateAccount();//destructor
	void getInformation(char firstname[10], char lastname[10], char fullname[20]);  //information about user
	int Account(char fullname[20], char username[10]); //create account username and password
	int SecurityQuestion(char fullname[20]); //security question to reset password in case user forgot their password
	void outputFile(char firstname[10], char lastname[10], char fullname[20], int length, char username[10], int password, std::ofstream* output);  //data of user information save in .txt file
	void LogIn(int, int, char username[10], std::ofstream*);   //log in to zoo system 

};
