// *** Begin ***
// This is a sample program segment for COMP102 Lab Exercise 11
// Program:	Final Grade Report
// author:	
// version: 1.0 (2009-11-24)
/*	*** Programming as a Problem Solving Process ***
Problem Statement:
The program will output a final grade report for the department's internal use.
The final grade report shall list all students according to the descending order of their overall grades.
(Discussion point)	Try to summarize the problem in one sentence or a short paragraph
It must cover all requirements

Problem Analysis: (Discussion point)
Output:		

Input:		

Assumptions:
all input data are valid

*** Initial Algorithm ***
1. Read the student records from a plain text file into an array of appropriate structure.
2. Sort the student records in descending order according to the final grade.
3. Print the sorted list of student records to the screen.
4. Search student record based on user input until "0" is entered.

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maxNameLen = 30;
const int maxIDLen = 9;
const int maxStudent = 20;
const int maxLab = 3;
char calculateOverallGrade(int lab1, int lab2, int lab3, double midtermScore, double finalScore);
struct studentRecordType {
	// TODO #1: Study the student records in the provided plain text file (download here) and design an appropriate structure.
	// Each student record consists of student name (max length of 50 characters), student id (e.g. 061234567),
	// three lab scores (0..2), one mid-term exam grade (0..100) and one final exam grade (0..100).
	// insert your codes below
 char studentName[maxNameLen];/////
 char id[maxIDLen]; ///////
 int lab1,lab2,lab3;
 double mid,final;

	// insert your codes above
	char finalGrade;
};

int populateStudentRecords(studentRecordType studentList[]) {
	ifstream fin;
	char ch;
	int studentCount = 0;
	fin.open("students.txt");

	// TODO #2: Complete this function to read and store

	fin.getline(studentList[studentCount].studentName,maxNameLen+1, ';');

	while(!fin.eof()) {

		// all student records into an array of the structure designed in TODO #1
		// You will need to use fin.getline() to read in the student name, refer to notes on strings
		// insert your codes below
	//cout<<"fasdf  ";
fin.getline(studentList[studentCount].id,10,' ');
		//fin.getline(studentList[studentCount].id,5,' ');
		//studentList[studentCount].id[5]='\0';
		//cout<<" afsdf"<<endl;
	//	fin>>studentList[studentCount].id;
		fin>>studentList[studentCount].lab1;
		
		fin>>studentList[studentCount].lab2;
		
		fin>>studentList[studentCount].lab3;
		
		fin>>studentList[studentCount].mid;
		
		fin>>studentList[studentCount].final;
		// insert your codes above
		fin.get(ch); // read the return character into a dummy variable
		studentList[studentCount].finalGrade = calculateOverallGrade( studentList[studentCount].lab1,studentList[studentCount].lab2,studentList[studentCount].lab3,studentList[studentCount].mid,studentList[studentCount].final );
		studentCount++;
		fin.getline(studentList[studentCount].studentName,30, ';');
		//studentList[studentCount].studentName[30]='\0';/////???
		//fin.get(ch);cout<<ch<<endl;
	}

	fin.close();
	return studentCount;
}

void bubbleSort(studentRecordType studentList[], int size)
{
	studentRecordType temp;

	for (int outer = size - 1; outer > 0; outer--)
	{
		for (int inner = 0; inner < outer; inner++)
		{
			if (strcmp(studentList[inner].studentName, studentList[inner + 1].studentName) > 0)
			{
				temp = studentList[inner];
				studentList[inner] = studentList[inner + 1];
				studentList[inner + 1] = temp;
			}
		}
	}
}

int binarySearch(studentRecordType studentList[], char value[], int left, int right)
{
	// TODO #3: Complete the function binarySearch().
	// You may use the non-recursive version of binary search as explained in lecture.
	// Optional take-home exercise: you are encouraged to complete the recursive version
	// below by filling in: (i) the branching condition and
	// (ii) parameters in calling function binarySearch() in the recursive branches.

	// Recursive version - begin //
	if ( left>right )
		return -1;

	int center = (left + right) / 2;

	if (strcmp(studentList[center].studentName, value) > 0)
			return binarySearch(studentList, value, left,center-1);
	else if (strcmp(studentList[center].studentName, value) < 0)
		// TODO #3
		return binarySearch(studentList, value, center+1,right);
	else
		return center;
	// Recursive version - end //

	// you can write your non-recursive version here: 

}


char calculateOverallGrade(int lab1, int lab2, int lab3, double midtermScore, double finalScore){
	double OverallScore				= 0;
	char Grade						= ' ';

	// This is not the actual weighting used in COMP102
	// Overall = 0.3*mid-term + 0.4*final + sum(lab)*5
	OverallScore =	0.3*midtermScore + 0.4*finalScore + (lab1+lab2+lab3)*5;

	//	Translate the OverallScore to a letter Grade and display the result on screen
	switch(int(OverallScore)/10){
		case 10:
		case 9: Grade = 'A';
			break;
		case 8: Grade = 'B';
			break;
		case 7: Grade = 'C';
			break;
		case 6: Grade = 'D';
			break;
		default: Grade = 'F';
	};
	return Grade;
}

void main() {
	// TODO #4: Complete the function main() to print the matched student record to screen
	studentRecordType studentRecord[maxStudent];
	int numStudentRecords = 0;
	int index = 0;
	char input[maxNameLen] = "";

	numStudentRecords = populateStudentRecords(studentRecord);

	bubbleSort(studentRecord, numStudentRecords);

	// Print sorted list of student record to screen
	cout << "Grade Student # Name" << endl;
	for (int i=0; i<numStudentRecords; i++) {
		cout << studentRecord[i].finalGrade <<
			"     " << studentRecord[i].id <<
			" " << 	 studentRecord[i].studentName<< endl;;
	}

	cout << "Please enter name of student (or 0 to end): ";
	cin.getline(input,maxNameLen);
	while (strcmp(input,"0") !=0) {
		cout << "Searching for: " << input << endl << endl;
		index = binarySearch(studentRecord, input, 0, numStudentRecords);
		if (index > -1) {
			cout << "Grade Student # Name" << endl;
			cout << studentRecord[index].finalGrade <<
				"     " << studentRecord[index].id <<
				" " << 	 studentRecord[index].studentName << endl << endl;
		} else {
			cout << "Student not found!" << endl << endl;
		}
		cout << "Please enter name of student (or 0 to end): ";
		cin.getline(input,maxNameLen);
	};
	

	//char as[5]={'a','a','a','a','a'};
	//cout<<as<<endl;
}
// *** end ***
