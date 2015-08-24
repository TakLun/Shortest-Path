#include<string>
#include <iostream>

using namespace std;


int shortestRoute(int, int, int p[0][11]);

int main(){

	//Creates the array for distances
	//initialized with "infinity"
	int distance[11][11];
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			distance[i][j] = 1000000;
		}
	}

	int path [11][11];
		for (int i = 0; i < 11; i++){
			for (int j = 0; j < 11; j++){
				path[i][j] = 0;
		}
	}

	//set all distance
	//Albany
	distance[0][5] = 130; distance[0][6] = 140; distance[0][9] = 100;

	//Allentown
	distance[1][8] = 65; distance[1][6] = 70;

	//Binghamton
	distance[2][6] = 180; distance[2][8] = 60; distance[2][9] = 70;

	//Buffalo
	distance[3][7] = 60; distance[3][10] = 100;

	//Kingston
	distance[4][5] = 160; distance[4][10] = 180; distance[4][9] = 65;

	//Montreal 
	distance[5][0] = 130; distance[5][4] = 160;

	//NYC
	distance[6][0] = 140; distance[6][1] = 70; distance[6][8] = 100; distance[6][2] = 180;

	//Rochester
	distance[7][3] = 60; distance[7][9] = 70;

	//Scranton
	distance[8][1] = 65; distance[8][2] = 60; distance[8][6] = 100;
	
	//Syracuse
	distance[9][0] = 100; distance[9][2] = 70; distance[9][4] = 65; distance[9][7] = 70;

	//Toronto
	distance[10][3] = 100; distance[10][4] = 180;
	
	//Find shortest path
	for (int i = 0; i < 11; i++){
		for(int j = 0; j < 11; j++){
			for(int k = 0; k < 11; k++){
				if(distance[j][k] > distance[j][i] + distance[i][k]){
					distance[j][k] = distance[j][i] + distance[i][k];
					path[j][k] = i;
				}
			}
		}
	}
	//Set up key
	cout << "Albany = 0" << endl;
	cout << "Allentown = 1" << endl;
	cout << "Binghamton = 2" << endl;
	cout << "Buffalo = 3" << endl;
	cout << "Kingston = 4" << endl;
	cout << "Montreal = 5" << endl;
	cout << "New York City = 6" << endl;
	cout << "Rochester = 7" << endl;
	cout << "Scranton = 8" << endl;
	cout << "Syracuse = 9" << endl;
	cout << "Toronto = 10" << endl;

	//Print out the route accoding to corresponding number.
	cout << endl << "Shortest Route is from ";
	shortestRoute(6,10,path);
	cout << endl;

}

//Fuction that Prints the shortest path.
int shortestRoute(int i, int j, int p[0][11]) {
	if(p[i][j] != 0) {
		shortestRoute(i, p[i][j], p);
		cout << " - " << p[i][j];
		shortestRoute(p[i][j], j, p);
	}
	else {
		return 0;
	}
}
