#include <string>
#include <conio.h>
#include <iostream>
#include <Windows.h> // For using custom colors..
#include <iomanip> // For manipulating stream data..

using namespace std;
// Sending Handle in all functions to allow for font color changing.
void Starting(HANDLE); // Starting Points of the program, asks for Gender.
void Male(HANDLE); // The Male branch, can lead to any of the 3 male teachers.
void Female(HANDLE); // Female Branch, can lead to any of the 4 female teachers.
void F_Facial_Hair(HANDLE, struct Male_Teacher[], int, int); // Asks if the person has facial hair and return string to "Male()".
void F_Hair_Color(HANDLE, struct Male_Teacher[], int, int); // Asks for the hair color of the person and returns string to "Male()".
void F_Glasses(HANDLE, struct Male_Teacher[], int, int); // Asks if the person wears glasses and returns string to "Male()".
void F_Old(HANDLE, struct Male_Teacher[], int, int); // Asks if the person is relaively young and returns string to "Male()".
void Hijab(HANDLE, struct Female_Teacher[], int, int);// Asks if the person wears Hijab and returns string to "Female()".
void Scarf(HANDLE, struct Female_Teacher[], int, int);// Asks if the person wears a Scarf and retruns string to "Female()".
void Niqab(HANDLE, struct Female_Teacher[], int, int);// Asks if the person wears a Niqab and returns string to "Female()".
void Output_Male(struct Male_Teacher[], HANDLE, int, int); // Compares the values taken from user to static struct for output. Male branch ends here..
void Output_Female(struct Female_Teacher[], HANDLE, int, int); //Compares the values taken from user to static struct for output. Female branch ends here..
string CheckReplay(string, HANDLE);// For restarting the program based on user needs.
struct Male_Teacher {
	int Points = 0;
	string Facial_Hair;
	string Hair_Color;
	string Glasses;
	string old;
	struct Male_Teacher* Next;
};
struct Female_Teacher {
	int Points = 0;
	string Scarf;
	string Hijab;
	string Niqab;
	struct Female_Teacher* Next;
};

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // For assigning the handle of the text to "h"...
	string Replay;
	do {
		system("CLS");
		Starting(h); // Start of the program.
		Replay = CheckReplay(Replay, h); //Can't do nested do-while loops, so needed to make a different function..
	} while (Replay == "yes");
	SetConsoleTextAttribute(h, 3);
	cout << "\t \t Thank you for playing :)" << endl;
	SetConsoleTextAttribute(h, 15);
}

string CheckReplay(string Replay, HANDLE h) {
	do {
		SetConsoleTextAttribute(h, 2);
		cout << "\t \t Do you want to run the program again?" << endl;
		SetConsoleTextAttribute(h, 15);
		cout << "\t \t ";
		getline(cin, Replay);
		cout << endl;
		for (int ctrl = 0; ctrl < Replay.length(); ctrl++) {
			Replay[ctrl] = tolower(Replay[ctrl]);
		}
		if (Replay != "yes" && Replay != "no") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t You can only respond with \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Replay != "yes" && Replay != "no");
	return Replay;
}

void Starting(HANDLE h) {
	string Gender;
	SetConsoleTextAttribute(h, 4);
	cout << endl;
	cout << "\t \t REMINDER: This program uses Yes or No questions to determine what teacher you're thinking of. " << endl;
	cout << "\t \t REMINDER: Make sure to answer in yes or no responses only. " << endl;
	cout << "\t \t REMINDER: Use of capital and lowercase letters is allowed. " << endl;
	SetConsoleTextAttribute(h, 2);
	cout << "\t \t Think of a single teacher from NUML BSCS-1(B)." << endl << endl << endl;
	SetConsoleTextAttribute(h, 15);
	do {
		cout << "\t \t 1. Is the person you're thinking of a male or female?" << endl;
		cout << "\t \t ";
		getline(cin, Gender);
		cout << endl;
		for (int ctrl = 0; ctrl < Gender.length(); ctrl++) {
			Gender[ctrl] = tolower(Gender[ctrl]);
		}
		if (Gender != "male" && Gender != "female") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t You can only respond with \"Male\" or \"Female\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Gender != "male" && Gender != "female");

	if (Gender == "male") {
		Male(h);
	}
	else {
		Female(h);
	}
}

void Male(HANDLE h) {
	struct Male_Teacher* node;
	struct Male_Teacher* head;
	struct Male_Teacher* ptr;
	int TotalMaleTeachers = 0;// Total number of male questions.(All loops run in accordance to it)..
	node ->Next = CreateMaleTeacherNode();
	int  Male_Questions = 4; // Total number of questions for male questions.(All loops run in accordance to it)..
	struct Male_Teacher male[4];
	struct Male_Teacher Taken[2]; // Can't pass this structure without making it an array of 2 ...
	//// Sir Abrar:
	//male[0].Facial_Hair = "no";
	//male[0].Hair_Color = "mixed";
	//male[0].Glasses = "yes";
	//male[0].old = "no";
	////Sir Kumail:
	//male[1].Facial_Hair = "yes";
	//male[1].Hair_Color = "black";
	//male[1].Glasses = "no";
	//male[1].old = "yes";
	////Sir Adnan:
	//male[2].Facial_Hair = "yes";
	//male[2].Hair_Color = "black";
	//male[2].Glasses = "no";
	//male[2].old = "no";
	//// Sir Abrar (2): // Sir Abrar kind of has a stubble so the user might or might count that as facial hair...
	//male[3].Facial_Hair = "yes";
	//male[3].Hair_Color = "mixed";
	//male[3].Glasses = "yes";
	//male[3].old = "no";

	//User Input:
	F_Facial_Hair(h, male, Male_Questions, TotalMaleTeachers);
	F_Hair_Color(h, male, Male_Questions, TotalMaleTeachers);
	F_Glasses(h, male, Male_Questions, TotalMaleTeachers);
	F_Old(h, male, Male_Questions, TotalMaleTeachers);

	Output_Male(male, h, Male_Questions, TotalMaleTeachers);
}
struct Male_Teacher* CreateMaleTeacherNode() {
	struct Male_Teacher* CurrentNode = (struct Male_Teacher*)malloc(sizeof(struct Male_Teacher) * 1);
	FileInputTo


}
void Output_Male(struct Male_Teacher male[], HANDLE h, int MaleQustions, int TotalMaleTeachers) {
	bool CheckAnswer = 0; //  Created to check if the loop hit any teacher or not..
	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++) {
		if (male[ctrl].Points == MaleQustions) {
			CheckAnswer = 1;
			switch (ctrl)
			{
			case 0:
				cout << "\t \t You're thinking of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Mr. Abrar Ali!" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			case 1:
				cout << "\t \t You're thinking of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Mr. Kumail Javaid!" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			case 2:
				cout << "\t \t You're thining of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Mr. Adnan Ahmad!" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			case 3:
				cout << "\t \t You're thinking of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Mr. Abrar Ali!" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			default:
				cout << "I didn't find anyone matching those requiements.. Try again!" << endl;
				break;
			}
		}
	}
	if (CheckAnswer == 0) {
		SetConsoleTextAttribute(h, 4);
		cout << "\t \t I'm sorry, I didn't find anyone matching those requiements in BSCS-1(B).. Please try again!" << endl;
	}	SetConsoleTextAttribute(h, 15);
}

void F_Hair_Color(HANDLE h, struct Male_Teacher male[], int MaleQustions, int TotalMaleTeachers) {
	string color;
	do {
		cout << "\t \t 2. Does the person you're thinking of have mixed (Black and White) or Black hair? " << endl;
		cout << "\t \t ";
		getline(cin, color);
		cout << endl;
		for (int ctrl = 0; ctrl < color.length(); ctrl++) {
			color[ctrl] = tolower(color[ctrl]);
		}
		if (color != "mixed" && color != "black") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Mixed\" or \"Black\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (color != "mix" && color != "black");
	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++) {
		if (color == (string)male[ctrl].Hair_Color) {
			male[ctrl].Points++;
		}
	}
}

void F_Facial_Hair(HANDLE h, struct Male_Teacher male[], int MaleQustions, int TotalMaleTeachers) {
	string hair;
	do {
		cout << "\t \t 3. Does the person you're thinking of have Facial Hair? (Yes/No)" << endl;
		cout << "\t \t ";
		getline(cin, hair);
		cout << endl;
		for (int ctrl = 0; ctrl < hair.length(); ctrl++) {
			hair[ctrl] = tolower(hair[ctrl]);
		}
		if (hair != "yes" && hair != "no") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"yes\" or \"no\" " << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (hair != "yes" && hair != "no");
	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++) {
		if (hair == (string)male[ctrl].Facial_Hair) {
			male[ctrl].Points++;
		}
	}
}

void F_Glasses(HANDLE h, struct Male_Teacher male[], int MaleQustions, int TotalMaleTeachers) {
	string Glasses;
	do {
		cout << "\t \t 4. Does the person you're thinking of wear prescription glasses?(Yes/No)" << endl;
		cout << "\t \t ";
		getline(cin, Glasses);
		cout << endl;
		for (int ctrl = 0; ctrl < Glasses.length(); ctrl++) {
			Glasses[ctrl] = tolower(Glasses[ctrl]);
		}
		if (Glasses != "yes" && Glasses != "no") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"yes\" or \"no\" " << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Glasses != "yes" && Glasses != "no");

	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++) {
		if (Glasses == (string)male[ctrl].Glasses) {
			male[ctrl].Points++;
		}
	}
}

void F_Old(HANDLE h, struct Male_Teacher male[], int MaleQustions, int TotalMaleTeachers) {
	string Old;
	do {
		cout << "\t \t 5. Is the person you're thinking of relatively Young? (Yes/No)" << endl;
		cout << "\t \t ";
		getline(cin, Old);
		cout << endl;
		for (int ctrl = 0; ctrl < Old.length(); ctrl++) {
			Old[ctrl] = tolower(Old[ctrl]);
		}
		if (Old != "yes" && Old != "no") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"yes\" or \"no\" " << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Old != "yes" && Old != "no");
	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++) {
		if (Old == (string)male[ctrl].old) {
			male[ctrl].Points++;
		}
	}
}

void Female(HANDLE h) {
	int Female_Qustions = 3; // Total number of questions for female teachers..
	int TotalFemaleTeachers = 5;
	struct Female_Teacher female[5];

	////Ms Maimoona Shahzadi
	//female[0].Hijab = "no";
	//female[0].Scarf = "no";
	//female[0].Niqab = "no";
	//
	////Ms Alkanz Fatima
	//female[1].Hijab = "yes";
	//female[1].Scarf = "yes";
	//female[1].Niqab = "yes";
	//
	////Ms Alkanz Fatima 2 // Some people might not consider her to be wearing a Scarf..
	//female[4].Hijab = "yes";
	//female[4].Scarf = "no";
	//female[4].Niqab = "yes";
	//
	//// Ms Fizza Ali
	//female[2].Hijab = "yes";
	//female[2].Scarf = "yes";
	//female[2].Niqab = "no";
	//
	//// Ms Sana Amjad
	//female[3].Hijab = "no";
	//female[3].Scarf = "yes";
	//female[3].Niqab = "no";

	Hijab(h, female, Female_Qustions, TotalFemaleTeachers);
	Scarf(h, female, Female_Qustions, TotalFemaleTeachers);
	Niqab(h, female, Female_Qustions, TotalFemaleTeachers);
	Output_Female(female, h, Female_Qustions, TotalFemaleTeachers);
}

void Hijab(HANDLE h, struct Female_Teacher female[], int femalequestions, int TotalFemaleTeachers) {
	string Hijab;
	do {
		cout << "\t \t 2. Does the person you're thinking of wear a Hijab? " << endl;
		cout << "\t \t ";
		getline(cin, Hijab);
		cout << endl;
		for (int ctrl = 0; ctrl < Hijab.length(); ctrl++) {
			Hijab[ctrl] = tolower(Hijab[ctrl]);
		}
		if (Hijab != "yes" && Hijab != "no") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Hijab != "yes" && Hijab != "no");

	for (int ctrl = 0; ctrl < TotalFemaleTeachers; ctrl++) {
		if (Hijab == (string)female[ctrl].Hijab) {
			female[ctrl].Points++;
		}
	}
}

void Scarf(HANDLE h, struct Female_Teacher female[], int femalequestions, int TotalFemaleTeachers) {
	string Scarf;
	do {
		cout << "\t \t 2. Does the person you're thinking of wear a Scarf? " << endl;
		cout << "\t \t ";
		getline(cin, Scarf);
		cout << endl;
		for (int ctrl = 0; ctrl < Scarf.length(); ctrl++) {
			Scarf[ctrl] = tolower(Scarf[ctrl]);
		}
		if (Scarf != "yes" && Scarf != "no") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Scarf != "yes" && Scarf != "no");

	for (int ctrl = 0; ctrl < TotalFemaleTeachers; ctrl++) {
		if (Scarf == (string)female[ctrl].Scarf) {
			female[ctrl].Points++;
		}
	}
}

void Niqab(HANDLE h, struct Female_Teacher female[], int femalequestions, int TotalFemaleTeachers) {
	string Niqab;
	do {
		cout << "\t \t 2. Does the person you're thinking of wear Niqab (Cover their face)? " << endl;
		cout << "\t \t ";
		getline(cin, Niqab);
		cout << endl;
		for (int ctrl = 0; ctrl < Niqab.length(); ctrl++) {
			Niqab[ctrl] = tolower(Niqab[ctrl]);
		}
		if (Niqab != "yes" && Niqab != "no") {
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Niqab != "yes" && Niqab != "no");

	for (int ctrl = 0; ctrl < TotalFemaleTeachers; ctrl++) {
		if (Niqab == (string)female[ctrl].Niqab) {
			female[ctrl].Points++;
		}
	}
}

void Output_Female(struct Female_Teacher female[], HANDLE h, int FemaleQuestions, int TotalFemaleTeachers) {
	bool CheckAnswer = 0;
	for (int ctrl = 0; ctrl < TotalFemaleTeachers; ctrl++) {
		if (female[ctrl].Points == FemaleQuestions) {
			CheckAnswer = 1;
			switch (ctrl)
			{
			case 0:
				cout << "\t \t You're thinking of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Ms Maimoona Shahzadi!" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			case 1:
				cout << "\t \t You're thinking of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Ms Alkanz Fatima!" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			case 2:
				cout << "\t \t You're thinking of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Ms Fizza Ali" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			case 3:
				cout << "\t \t You're thinking of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Ms Sana Amjad!" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			case 4:
				cout << "\t \t You're thinking of ";
				SetConsoleTextAttribute(h, 10);
				cout << "Ms Alkanz Fatima!" << endl << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			default:
				cout << "I didn't find anyone matching those requiements.. Try again!" << endl;
				break;
			}
		}
	}
	if (CheckAnswer == 0) {
		SetConsoleTextAttribute(h, 4);
		cout << "\t \t I'm sorry. didn't find anyone matching those requiements in BSCS-1(B).. Please try again!" << endl;
	}	SetConsoleTextAttribute(h, 15);
}