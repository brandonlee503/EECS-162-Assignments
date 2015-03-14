/********************************************************************* 
 ** Program Filename: 4assignment.cpp
 ** Author: Brandon Lee
 ** Date: 5/21/14
 ** Description: Assignment 4
 ** Input: N/A
 ** Output: A colorful graph on GRADS
 *********************************************************************/ 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <bitset>

using namespace std;

int main(){

	ifstream inlol;
	ofstream outlol;

	inlol.open("heat_input.dat", ios::app); //inputfilename and iosapp to append the file
	if(inlol.fail()){ //Check if file was opened successfully
		cout << "Input file opening failed..." << endl;
		exit(1);
	}
	outlol.open("heat_bin.dat"); //outfilename
	if(outlol.fail()){ //Check if file was opened successfully
		cout << "Output file opening failed..."  << endl;
		exit(1);
	}

	//Defining our variables and stuff
	// s_heat is specific heat, p is density, c is thermal connectivity , deltat is delta t
	float temp = 0, s_heat = 58.4, p = 0.321, c = 0.12, deltat = 0.000335;
	float oldtemp[30]={};
	float newtemp[30]={};
	oldtemp[29]=100;
	float dx=1;
	//Weird variables?:
	int i;
	int b;
	oldtemp[29]=100;

	cout << "\tWriting Paramaters into heat_input.dat file..." << endl;
	inlol >> temp >> s_heat >> p >> c >> deltat >> oldtemp[30] >> newtemp[30] >> dx; //Writing parameters into .dat file
	cout << "\tDone writing parameters! Now outputting results: " << endl;			
	
	//Acutal Calculations
	for(int i=0; i<=50; i++){
		cout << "Time: " << i << endl;
		for(b=1; b<29; b++){
			newtemp[b]=((s_heat*deltat)/((c*p)*(pow(dx,2))))*(oldtemp[b+1]-2*oldtemp[b]+oldtemp[b-1])+oldtemp[b];
			cout << newtemp[b] << " ";
			//Converts to binary
			outlol.write((char*)&newtemp[b], sizeof(float));
			//Old method, but still kind of works too :)
			/*
			char* bits = reinterpret_cast <char*> (&newtemp[b]);
			for(size_t j=0; j<sizeof newtemp[b]; ++j)
					outlol << bitset<8>(bits[j]); //Prints floats as binary onto heat_bin.dat file
			outlol << '\n';
			*/
		}

		for(b=0; b<29; b++){
			oldtemp[b]=newtemp[b];
		}
		cout << endl << endl;
	}

	inlol.close();
	outlol.close();

	return 0;
}