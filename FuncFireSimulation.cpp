#include "FuncFireSimulation.h"

using namespace std;

/*	This is simply only a bit of information
of me the creator.
*/
void Creator(){
	cout << endl;
	cout << endl;
	cout << "+--------------------------------------------------------------+" << endl;
	cout << "|								|" << endl;
	cout << "|		Computer Science and Engineering		|" << endl;
	cout << "|								|" << endl;
	cout << "|		CSCE 2100 - Computer Science  			|" << endl;
	cout << "|								|" << endl;
	cout << "|	Marco Aguilera  ma0882  MarcoAguilera@my.unt.edu	|" << endl;
	cout << "|								|" << endl;
	cout << "+--------------------------------------------------------------+" << endl;
	cout << endl;
	cout << endl;
}

void Intro(){
	cout << "Introduction to Simulation..." << endl;
}

void EnterForestSquare(){

	/* Following are variables for Forest Matrix */
	fstream fin;	//to allow access to files
	char firstfilename[30]; //to allow the filename to be typed in.
	string woodsrow;	//testing to get simply the first line in the file.
	string num; 	//testing to get the number by itself
	//string woodspoint; 	//used for testing inside the pushbacks

	/*Following are variables for Weather File */
	fstream zin;//allows acces to weather file.
	char secondfilename[30];
	string NumDay_WindDirection;
	string SecondWindDirectionDay; //secind direction that was used to the first one
	string FirstWindDirection;
	string SubStringNumAccess; // using stoi afor the day count
	string DaysBurningFireTree; //days the tree bruns for.
	int BurningNumDay; //the int that takes the substring value
	int DayCount;
	int DayCount_2;
	int DayChange;
	int FirstDay = 0;

	/* Opening the Forest Matrix */
	vector<vector<string> >forest; //open the file as string, but made thing complicated.
	vector<vector<int> >forestINT; // made a mirror of the first one in integers
	cout << "Enter Forest Simulation Type Please: " << endl;
	cin.getline(firstfilename,30);
	fin.open(firstfilename);
		if(fin.fail())
		{
			cout<<"File does not exist"<<endl;
			exit(1);
		}
	/* Opening the Weather Information */
	cout << "Enter The File Describing The Weather Please: " << endl;
	cin.getline(secondfilename,30);
	zin.open(secondfilename);
		if(zin.fail())
		{
			cout<<"File does not exist"<<endl;
			exit(1);
		}
/*The Following Portion reads the files*/
getline(zin, FirstWindDirection);
 //attempted eof but didnt work
if('N'||'S'||'E'||'W'||'R' == FirstWindDirection[6])
{
cout <<"The wind is blowing " << FirstWindDirection[6] << endl;
//Having Issues Reading The Number Of Days It Takes
//For A Tree To Turn To 'B'-(Burnt)
//Count for Days
string lines;
getline(fin, num);// object that reads in the first line after F:2 // F:3
DaysBurningFireTree = num.substr(2);
BurningNumDay = stoi(DaysBurningFireTree);

while(getline(fin,lines))
{
	stringstream ss(lines);
	string temp;
	vector<string> woods;
	vector<int> woodsINT; // mirror image of the matrix that will represent each value as a number
	while(getline(ss, temp, ','))
	{
		woods.push_back(temp);
		if(temp == " " || temp == "T") //excludes these characters inside of the matrix
		{
		woodsINT.push_back(0); // assigns the not F to 0
		}
		if(temp == "F")
		{
			woodsINT.push_back(1); // this assisgn the F to number 1 and will increment later
		}
	}
forest.push_back(woods);
forestINT.push_back(woodsINT);
}

cout << "Current Day: " << FirstDay << endl; // Day 0 will always stay the same
	for(int i = 0; i < forest.size(); ++i)
	{
		for(int j = 0; j < forest[i].size(); ++j)
		{
			cout << forest[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
	zin.close(); // close the file to start form day 1

zin.open(secondfilename);
getline(zin,FirstWindDirection);
/*Making the sixth Character the Direction*/
char test = FirstWindDirection[6];

/*Changing the Fourth Char of the string
	into a string using stoi with c++ 11*/
SubStringNumAccess = FirstWindDirection.substr(4);
DayChange = stoi(SubStringNumAccess);
DayCount = (DayChange);
if(0 == DayCount)
{
	//Incrementing to start at Day One
	DayCount = (DayCount + 1);
}

bool checkBurningEnding = false; // changes when everything is a B
bool checkNumofIterationOfString = false; // this will take care of the iterations that are taken to complete the simulation
while(!zin.eof() && checkBurningEnding == false)
{
	getline(zin,SecondWindDirectionDay); // this will take the wind direction and later see which one is the last one.
	if(DayCount != 1)
	{
	cout <<"The wind is blowing " << test << endl; // opens up the switch statement
	}
	if(SecondWindDirectionDay == "") // here we check if the next line is empty
	{
		while(checkBurningEnding == false && checkNumofIterationOfString == false)
		{
			switch(test)
			{
				/*
				Both Switch statements are the same and the dirst one is in charge of the
				last day or in other words the last wind direction.
				This one will also complete the count and output how many day it took
				for the fire to burn out.
				*/
				case 'N':	{

					cout << "Inside North" << endl;
					cout << "Current Day: " << DayCount << endl;

					for(int i = 0; i < forest.size(); i++)
					{
						for(int j = 0; j < forest[i].size(); j++)
						{
							int TempISize = forest.size();
							int TempJSize = forest[i].size();
							int tempi = i;
							int tempj = j;

							if(forest[i][j] == "F" && forestINT[i][j] >=1)
							{
								forestINT[i][j] += 1;
								if(tempi-1 >= 0 && tempj-1 >= 0)
								{
									if(forest[i-1][j-1] != " ")
									{
										forest[i-1][j-1] = "F";
									}
								}
								if(tempi-1 >= 0 )
								{
									if(forest[i-1][j] != " ")
									{
								forest[i-1][j] = "F";
									}
								}
								if(tempi-1 >= 0 && tempj+1 < TempJSize)
								{
									if(forest[i-1][j+1] != " ")
									{
										forest[i-1][j+1] = "F";
									}
								}
							}
						}
					}

					for(int i = 0; i < forest.size(); i++)
					{
						for(int j = 0; j < forest[i].size(); j++)
						{
							if(forest[i][j] == "F" && forestINT[i][j] == 0)
							{
								forestINT[i][j] = 1;
							}
							if(forestINT[i][j] > BurningNumDay)
							{
								forest[i][j] = "B";
							}
							cout << forest[i][j];
						}
						cout << endl;
					}
					cout << endl;

					bool temp = false;

					for(int i = 0; i < forest.size(); i++)
					{
					for(int j = 0; j < forest[i].size(); j++)
					{
						if(forest[i][j] == "F")
						{
							temp = true;
						}
					}

					}

					if(temp == false)
					{
					checkBurningEnding = true;
					}
							break;
						}
				case 'S':	{

						cout << "Inside South" << endl;
						cout << "Current Day: " << DayCount << endl;
						for(int i = 0; i < forest.size(); i++)
						{
							for(int j = 0; j < forest[i].size(); j++)
							{
								int TempISize = forest.size();
								int TempJSize = forest[i].size();
								int tempi = i;
								int tempj = j;
								if(forest[i][j] == "F" && forestINT[i][j] >= 1)
								{
									forestINT[i][j] += 1;
									if(tempi+1 < TempISize && tempj-1 >= 0)
									{
										if(forest[i+1][j-1] != " ")
										{
										forest[i+1][j-1] = "F";
										}
									}
									if(tempi+1 < TempISize)
									{
										if(forest[i+1][j] != " ")
										{
										forest[i+1][j] = "F";
										}
									}
									if(tempi+1 < TempISize && tempj+1 < TempJSize)
									{
										if(forest[i+1][j+1] != " ")
										{
										forest[i+1][j+1] = "F";
										}
									}
								}
							}
						}

						for(int i = 0; i < forest.size(); i++)
						{
							for(int j = 0; j < forest[i].size(); j++)
							{
								if(forest[i][j] == "F" && forestINT[i][j] == 0)
								{
									forestINT[i][j] = 1;
								}
								if(forestINT[i][j] > BurningNumDay)
								{
									forest[i][j] = "B";
								}
								cout << forest[i][j];
							}
							cout << endl;
						}
						cout << endl;

					bool temp = false;

					for(int i = 0; i < forest.size(); i++)
					{
						for(int j = 0; j < forest[i].size(); j++)
						{
							if(forest[i][j] == "F")
							{
								temp = true;
							}
						}

					}

					if(temp == false)
					{
						checkBurningEnding = true;
					}
							break;
			}
				case 'E':	{

					cout << "Inside East" << endl;
					cout << "Current Day: " << DayCount << endl;
					for(int i = 0; i < forest.size(); i++)
					{
						for(int j = 0; j < forest[i].size(); j++)
						{
							int TempISize = forest.size();
							int TempJSize = forest[i].size();
							int tempi = i;
							int tempj = j;

							if(forest[i][j] == "F" && forestINT[i][j] >= 1)
							{
								forestINT[i][j] += 1;
								if(tempj+1 < TempJSize && tempi-1 >= 0)
								{
									if(forest[i-1][j+1] != " ")
									{
									forest[i-1][j+1] = "F";
									}
								}
								if(tempj+1 < TempJSize)
								{
									if(forest[i][j+1] != " ")
									{
									forest[i][j+1] = "F";
									}
								}
								if(tempi+1 < TempISize && tempj+1 < TempJSize)
								{
									if(forest[i+1][j+1] != " ")
									{
									forest[i+1][j+1] = "F";
									}
								}
							}

						}
					}
					for(int i = 0; i < forest.size(); ++i)
					{
						for(int j = 0; j < forest[i].size(); ++j)
						{
							if(forest[i][j] == "F" && forestINT[i][j] == 0)
							{
								forestINT[i][j] = 1;
							}
							if(forestINT[i][j] > BurningNumDay)
							{
								forest[i][j] = "B";
							}
							cout << forest[i][j];
						}
					cout << endl;
				}
				cout << endl;

				bool temp = false;

				for(int i = 0; i < forest.size(); i++)
				{
					for(int j = 0; j < forest[i].size(); j++)
					{
						if(forest[i][j] == "F")
						{
							temp = true;
						}
					}

				}

				if(temp == false)
				{
					checkBurningEnding = true;
				}
							break;
			}
				case 'W': {

						cout << "Inside West" << endl;
						cout << "Current Day: " << DayCount << endl;
						for(int i = 0; i < forest.size(); i++)
						{
							for(int j = 0; j < forest[i].size(); j++)
							{
								int TempISize = forest.size();
								int TempJSize = forest[i].size();
								int tempi = i;
								int tempj = j;

								if(forest[i][j] == "F" && forestINT[i][j] >= 1)
								{
									forestINT[i][j] += 1;
									if(tempi+1 < TempISize && tempj-1 >= 0)
									{
										if(forest[i+1][j-1] != " ")
										{
										forest[i+1][j-1] = "F";
										}
									}
									if(tempj-1 >= 0)
									{
										if(forest[i][j-1] != " ")
										{
										forest[i][j-1] = "F";
										}
									}
									if(tempi-1 >= 0 && tempj-1 >= 0)
									{
										if(forest[i-1][j-1] != " ")
										{
										forest[i-1][j-1] = "F";
										}
									}
								}

							}
						}
						for(int i = 0; i < forest.size(); ++i)
						{
							for(int j = 0; j < forest[i].size(); ++j)
							{
								if(forest[i][j] == "F" && forestINT[i][j] == 0)
								{
									forestINT[i][j] = 1;
								}
								if(forestINT[i][j] > BurningNumDay)
								{
									forest[i][j] = "B";
								}
								cout << forest[i][j];
							}
						cout << endl;
					}
					cout << endl;

					bool temp = false;

					for(int i = 0; i < forest.size(); i++)
					{
						for(int j = 0; j < forest[i].size(); j++)
						{
							if(forest[i][j] == "F")
							{
								temp = true;
							}
						}

					}

					if(temp == false)
					{
						checkBurningEnding = true;
					}
							break;
			}
				case 'R':	{
					cout << "Inside Rain" << endl;
					cout << "Current Day: " << DayCount << endl;
					for(int i = 0; i < forest.size(); ++i)
					{
						for(int j = 0; j < forest[i].size(); ++j)
						{
						cout << forest[i][j];
						}
					cout << endl;
					}
				cout << endl;
					break;
			}
			}
			++DayCount; //counter for the days of each time the next trees are affected.
		}
		if(checkNumofIterationOfString == false) //this boolean will set a condition for the daycount
		{
		cout << "Fire Lasted " << DayCount - 1 << " days !!" << endl;
		}
		checkNumofIterationOfString = true;
	}
	else{
	SubStringNumAccess = SecondWindDirectionDay.substr(4); //makes the day into an integer since it is inside of a string
	DayChange = stoi(SubStringNumAccess); // use c++ 11 because of stoi
	DayCount_2 = (DayChange);
	}
	bool firstrun = false;
while(DayCount != DayCount_2 && checkNumofIterationOfString == false)
{
	switch(test)
	{
		case 'N':	{

			cout << "Inside North" << endl;
			cout << "Current Day: " << DayCount << endl;

			for(int i = 0; i < forest.size(); i++)
			{
				for(int j = 0; j < forest[i].size(); j++)
				{
					int TempISize = forest.size();
					int TempJSize = forest[i].size();
					int tempi = i;
					int tempj = j;

					if(forest[i][j] == "F" && forestINT[i][j] >=1)
					{
						forestINT[i][j] += 1;
						if(tempi-1 >= 0 && tempj-1 >= 0)
						{
							if(forest[i-1][j-1] != " ")
							{
								forest[i-1][j-1] = "F";
							}
						}
						if(tempi-1 >= 0 )
						{
							if(forest[i-1][j] != " ")
							{
						forest[i-1][j] = "F";
							}
						}
						if(tempi-1 >= 0 && tempj+1 < TempJSize)
						{
							if(forest[i-1][j+1] != " ")
							{
								forest[i-1][j+1] = "F";
							}
						}
					}
				}
			}

			for(int i = 0; i < forest.size(); i++)
			{
				for(int j = 0; j < forest[i].size(); j++)
				{
					if(forest[i][j] == "F" && forestINT[i][j] == 0)
					{
						forestINT[i][j] = 1;
					}
					if(forestINT[i][j] > BurningNumDay)
					{
						forest[i][j] = "B";
					}
					cout << forest[i][j];
				}
				cout << endl;
			}
			cout << endl;

			bool temp = false;

			for(int i = 0; i < forest.size(); i++)
			{
			for(int j = 0; j < forest[i].size(); j++)
			{
				if(forest[i][j] == "F")
				{
					temp = true;
				}
			}

			}

			if(temp == false)
			{
			checkBurningEnding = true;
			}
					break;
				}
		case 'S':	{

				cout << "Inside South" << endl;
				cout << "Current Day: " << DayCount << endl;
				for(int i = 0; i < forest.size(); i++)
				{
					for(int j = 0; j < forest[i].size(); j++)
					{
						int TempISize = forest.size();
						int TempJSize = forest[i].size();
						int tempi = i;
						int tempj = j;
						if(forest[i][j] == "F" && forestINT[i][j] >= 1)
						{
							forestINT[i][j] +=1;
							if(tempi+1 < TempISize && tempj-1 >= 0)
							{
								if(forest[i+1][j-1] != " ")
								{
								forest[i+1][j-1] = "F";
								}
							}
							if(tempi+1 < TempISize)
							{
								if(forest[i+1][j] != " ")
								{
								forest[i+1][j] = "F";
								}
							}
							if(tempi+1 < TempISize && tempj+1 < TempJSize)
							{
								if(forest[i+1][j+1] != " ")
								{
								forest[i+1][j+1] = "F";
								}
							}
						}
					}
				}

				for(int i = 0; i < forest.size(); i++)
				{
					for(int j = 0; j < forest[i].size(); j++)
					{
						if(forest[i][j] == "F" && forestINT[i][j] == 0)
						{
							forestINT[i][j] = 1;
						}
						if(forestINT[i][j] > BurningNumDay)
						{
							forest[i][j] = "B";
						}
						cout << forest[i][j];
					}
					cout << endl;
				}
				cout << endl;

			bool temp = false;

			for(int i = 0; i < forest.size(); i++)
			{
				for(int j = 0; j < forest[i].size(); j++)
				{
					if(forest[i][j] == "F")
					{
						temp = true;
					}
				}

			}

			if(temp == false)
			{
				checkBurningEnding = true;
			}
					break;
	}
		case 'E':	{

			cout << "Inside East" << endl;
			cout << "Current Day: " << DayCount << endl;
			for(int i = 0; i < forest.size(); i++)
			{
				for(int j = 0; j < forest[i].size(); j++)
				{
					int TempISize = forest.size();
					int TempJSize = forest[i].size();
					int tempi = i;
					int tempj = j;

					if(forest[i][j] == "F" && forestINT[i][j] >= 1)
					{
						forestINT[i][j] += 1;
						if(tempj+1 < TempJSize && tempi-1 >= 0)
						{
							if(forest[i-1][j+1] != " ")
							{
							forest[i-1][j+1] = "F";
							}
						}
						if(tempj+1 < TempJSize)
						{
							if(forest[i][j+1] != " ")
							{
							forest[i][j+1] = "F";
							}
						}
						if(tempi+1 < TempISize && tempj+1 < TempJSize)
						{
							if(forest[i+1][j+1] != " ")
							{
							forest[i+1][j+1] = "F";
							}
						}
					}

				}
			}
			for(int i = 0; i < forest.size(); ++i)
			{
				for(int j = 0; j < forest[i].size(); ++j)
				{
					if(forest[i][j] == "F" && forestINT[i][j] == 0)
					{
						forestINT[i][j] = 1;
					}
					if(forestINT[i][j] > BurningNumDay)
					{
						forest[i][j] = "B";
					}
					cout << forest[i][j];
				}
			cout << endl;
		}
		cout << endl;

		bool temp = false;

		for(int i = 0; i < forest.size(); i++)
		{
			for(int j = 0; j < forest[i].size(); j++)
			{
				if(forest[i][j] == "F")
				{
					temp = true;
				}
			}

		}

		if(temp == false)
		{
			checkBurningEnding = true;
		}
					break;
	}
		case 'W': {

				cout << "Inside West" << endl;
				cout << "Current Day: " << DayCount << endl;
				for(int i = 0; i < forest.size(); i++)
				{
					for(int j = 0; j < forest[i].size(); j++)
					{
						int TempISize = forest.size();
						int TempJSize = forest[i].size();
						int tempi = i;
						int tempj = j;

						if(forest[i][j] == "F" && forestINT[i][j] >= 1)
						{
							forestINT[i][j] += 1;
							if(tempi+1 < TempISize && tempj-1 >= 0)
							{
								if(forest[i+1][j-1] != " ")
								{
								forest[i+1][j-1] = "F";
								}
							}
							if(tempj-1 >= 0)
							{
								if(forest[i][j-1] != " ")
								{
								forest[i][j-1] = "F";
								}
							}
							if(tempi-1 >= 0 && tempj-1 >= 0)
							{
								if(forest[i-1][j-1] != " ")
								{
								forest[i-1][j-1] = "F";
								}
							}
						}

					}
				}
				for(int i = 0; i < forest.size(); ++i)
				{
					for(int j = 0; j < forest[i].size(); ++j)
					{
						if(forest[i][j] == "F" && forestINT[i][j] == 0)
						{
							forestINT[i][j] = 1;
						}
						if(forestINT[i][j] > BurningNumDay)
						{
							forest[i][j] = "B";
						}
						cout << forest[i][j];
					}
				cout << endl;
			}
			cout << endl;

			bool temp = false;

			for(int i = 0; i < forest.size(); i++)
			{
				for(int j = 0; j < forest[i].size(); j++)
				{
					if(forest[i][j] == "F")
					{
						temp = true;
					}
				}

			}

			if(temp == false)
			{
				checkBurningEnding = true;
			}
					break;
	}
		case 'R':	{
			cout << "Inside Rain" << endl;
			cout << "Current Day: " << DayCount << endl;
			for(int i = 0; i < forest.size(); ++i)
			{
				for(int j = 0; j < forest[i].size(); ++j)
				{
				cout << forest[i][j];
				}
			cout << endl;
			}
		cout << endl;
			break;
	}
	}
	++DayCount;
}
if(SecondWindDirectionDay == "")
{}
else{
	test = SecondWindDirectionDay[6];
}
}
}//end
