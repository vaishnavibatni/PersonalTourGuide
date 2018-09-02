#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm> 
#include <string.h>
#include<sstream>
#include<vector>
using namespace std;
vector<int> extractNums( string str){
    std::vector<int> numbers(10);
    char * pch;
 	 printf ("Splitting string \"%s\" into tokens:\n",str.c_str());
	char * abc=(char *)str.c_str();
 	 pch = strtok (abc," place(),.-");
	int i=0;
 	 while (pch != NULL)
  {
    printf ("%s\n",pch);
    numbers[i++]=atoi(pch);
    pch = strtok (NULL, " place(),.-");
  }
    return numbers;
}
int main()
{
	int budget;
		int age;
	int xcoord;
	int ycoord;
	int interest;
	int timelimit;
	int mode_of_transport;
	string name;

	cout << "\nHey! What's your name? ";
	cin >> name;
	cout << "\nHi " << name << "! How old are you? ";
	cin >> age;
	cout << "\nWe'd like to know the x-coordinate and y-coordinate of the place from where you want to begin your trip. Enter x-coordinate first: ";
	cin >> xcoord;
	cout << "\nNow enter the y-coordinate: ";
	cin >> ycoord;
	cout << "\nWhat kind of tourism are you interested in? Enter 1 for adventurous tourism. Or enter 2 for religious tourism. Or enter 3 if you haven't thought about it: ";
	cin >> interest;
	cout << "\nGreat! What's your budget? Enter amount in dollars";
	cin >> budget;
	cout << "\nHow many hours do you want to spend on this trip? ";
	cin >> timelimit;
	cout << "\nDo you have a preferred mode of transport? Enter any number we don't care...";
		cin >> mode_of_transport;
	


	string input = "\n#const budget = " + to_string(budget) + ".\n#const age = " + to_string(age) + ".\n#const xcoord = " + to_string(xcoord) + ".\n#const ycoord = " + to_string(ycoord) + ".\n#const interest = " + to_string(interest) +".\n#const timelimit = " + to_string(timelimit)+".";

	cout << "\n\nString to write in file -> "<<input;

	ofstream file1;
	file1.open("input.lp");
	file1 << input;
	file1.close();
	system("clingo newFinal input.lp > abc.txt");
	ifstream file ( "abc.txt" );
	string value;
	int i=0;
	while ( file.good() )
	{
     	     getline ( file, value );
	     const char * value1= value.c_str();
		if((strstr(value1,"place"))!=NULL){
   	     		cout<<"\n" <<i<<" "<< value<<"\n"; break;
		}
		i++; 
	}
	cout<<"\n"<<value<<"\n";
	vector<int> values =extractNums(value);
	std::sort (values.begin(), values.end());
		int j=1;
	int g;
	ifstream file2 ( "csvFile.csv" );
	for(int i=0;i<10;i++){
		cout<<values[i]<<"\t";	
		
		g=1;
		while ( file2.good() && g!=0)
		{
			string value;
     	     		getline ( file2, value );
			if(values[i]==j){
   	     			cout<<"\n"<< value<<"\n";
				g=0;
			}
			j++; 
		}

	}
	
	return 0;
}
