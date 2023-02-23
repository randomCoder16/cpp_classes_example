#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "functions.h"
using std::string;
using std::cout;
#define WIN32
// TOOK DAMAGE BUT DID NOT REVIVE
#define TOOKDAMAGE
#define REVIVED 0

class Player {
	int health;
	int bullets;

public:
	// Constructor
	Player(int x, int y) {
		health = x;
		bullets = y;
	}

	// Setters
	void Shoot() {
		bullets -= 1;
	}

	void TakeDamage() {
		health -= 5;
	}

	void ReviveHealth(int x) {
		health += x;
		// Health can not exceed 100 (maximum)
		// if revided to more than 100, subtract all the other health and set health back to maximum
		if (health > 100) {
			health = 100;
		}
		else {
			health = health;
		}
	}

	// Getters
	int CurrentHealth() {
		return health;
	}
};

void gameOne() {
	clock_t start, end;
	start = clock();
	double execution_time;
#ifdef TOOKDAMAGE
	Player player1 = Player(100, 50);
	player1.Shoot();
	// take damage five times
	for (int i = 0; i <= 5; ++i) {
		player1.TakeDamage();
	}

	// IF revived
#if REVIVED == 1
	player1.ReviveHealth(20);
	cout << "Current health: " << player1.CurrentHealth() << std::endl;
#else
	cout << "Current health: " << player1.CurrentHealth() << std::endl;
#endif

	// ENDIF revived
#else
	Player player1 = Player(100, 50);
	player1.Shoot();
	player1.TakeDamage();
	cout << "Current health: " << player1.CurrentHealth() << std::endl;
#endif // 

	player1.ReviveHealth(20);

	end = clock();
	execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
	string ttl = "Took " + std::to_string(execution_time) + " seconds!";
	cout << ttl << std::endl;
}