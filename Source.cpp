#include <iostream>
#include <time.h>
using namespace std;

int maze1[20][50];			//0 - Duvar			1 - Boþluk		2 - Bonus1			3-Bonus2		4 - Araba

int carPosX = 1;
int carPosY = 0;

void createRandomMaze();
void createBonuses();
void drawMaze();

void moveManually();
void moveAutomatically();


int main() {
	srand(time(NULL));

	createRandomMaze();
	createBonuses();

	maze1[carPosX][carPosY] = 4;

	int choice;
	cout << "press 1 to manual" << endl;
	cout << "press 2 to automatic" << endl;
	cin >> choice;

	if (choice == 1) {
		moveManually();
	}
	else if (choice == 2) {
		moveAutomatically();
	}
	else {
		cout << "error" << endl;
	}


	system("pause");
	return 0;
}

void createRandomMaze() {
	maze1[1][0] = 1;
	maze1[18][49] = 1;
	for (int i = 1; i < 19; i++) {
		maze1[i][1] = 1;
	}
	for (int j = 1; j < 49; j++) {
		maze1[18][j] = 1;
	}

	for (int i = 1; i < 19; i++) {
		for (int j = 1; j < 49; j++) {
			if (maze1[i][j] == 0) {
				int chance = rand() % 3;
				if (chance == 0) {
					maze1[i][j] = 1;
				}
			}
		}
	}
}

void drawMaze() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			int val;
			val = maze1[i][j];

			switch (val)
			{
			case 0:
				cout << "|";
				break;
			case 1:
				cout << " ";
				break;
			case 2:
				cout << "a";
				break;
			case 3:
				cout << "b";
				break;
			case 4:
				cout << "+";
				break;
			default:

				break;
			}

		}
		cout << endl;
	}

}

void createBonuses() {
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 50; j++) {
			if (i == 1 && j == 0) {
				continue;
			}
			if (i == 18 && j == 49) {
				continue;
			}
			if (maze1[i][j] == 1) {
				int createOrNot = rand() % 20;
				if (createOrNot == 0) {
					int whichBonus;
					whichBonus = rand() % 2;
					if (whichBonus == 0) {
						maze1[i][j] = 2;
					}
					else {
						maze1[i][j] = 3;
					}
					//tam þu an sümeyyenin beyni yandý..
				}
				else {
					maze1[i][j] = 1;
				}
			}
		}
	}
}

void moveManually() {
	while (1) {
		system("cls");
		drawMaze();

		cout << "up - w , down - s , left - a , right - d" << endl;
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'w':
			if (maze1[carPosX - 1][carPosY] != 0) {
				maze1[carPosX][carPosY] = 1;
				carPosX = carPosX - 1;
				carPosY = carPosY;
				maze1[carPosX][carPosY] = 4;
			}
			break;
		case 's':
			if (maze1[carPosX+1][carPosY] != 0) {
				maze1[carPosX][carPosY] = 1;
				carPosX = carPosX + 1;
				carPosY = carPosY;
				maze1[carPosX][carPosY] = 4;
		}
			break;
		case 'a':
			if (maze1[carPosX][carPosY-1] != 0) {
				maze1[carPosX][carPosY] = 1;
				carPosX = carPosX;
				carPosY = carPosY-1;
				maze1[carPosX][carPosY] = 4;
			}
			break;
		case 'd':
			if (maze1[carPosX][carPosY+1] != 0) {
				maze1[carPosX][carPosY] = 1;
				carPosX = carPosX ;
				carPosY = carPosY+1;
				maze1[carPosX][carPosY] = 4;
			}
			break;
		}
	}
}

void moveAutomatically() {
	while (1) {
		system("cls");
		drawMaze();
		
		int yon = rand() % 4;

		switch (yon) 
		{
		case 0:
			if (maze1[carPosX - 1][carPosY] != 0) {
				maze1[carPosX][carPosY] = 1;
				carPosX = carPosX - 1;
				carPosY = carPosY;
				maze1[carPosX][carPosY] = 4;
			}
			break;
		case 1:
			if (maze1[carPosX +1][carPosY] != 0) {
				maze1[carPosX][carPosY] = 1;
				carPosX = carPosX +1;
				carPosY = carPosY;
				maze1[carPosX][carPosY] = 4;
			}
			break;
		case 2:
			if (maze1[carPosX ][carPosY+1] != 0) {
				maze1[carPosX][carPosY] = 1;
				carPosX = carPosX;
				carPosY = carPosY+1;
				maze1[carPosX][carPosY] = 4;
			}
			break;
		case 3:
			if (maze1[carPosX ][carPosY-1] != 0) {
				maze1[carPosX][carPosY] = 1;
				carPosX = carPosX;
				carPosY = carPosY-1;
				maze1[carPosX][carPosY] = 4;
			}
			break;

		}
	}
}
