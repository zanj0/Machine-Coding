/*
Question Link: https://workat.tech/machine-coding/practice/snake-and-ladder-problem-zgtac9lxwntg
Sample Solution Link: https://workat.tech/machine-coding/article/how-to-design-snake-and-ladder-machine-coding-ehskk9c40x2w
*/
#include <bits/stdc++.h>
using namespace std;
class Player {
private:
	string name;
	int id;
public:
	Player() {

	}
	Player(string name) {
		id = rand() % 100;
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}
};
class Dice {
private:
	int id;
	int maxMove;
public:
	Dice() {

	}
	Dice(int id, int maxMove) {
		this->id = id;
		this->maxMove = maxMove;
	}
	int getVal() {
		return (rand() % maxMove) + 1;
	}
};
class SnakeAndLadder {
	map <string, int> positionsOfPlayer;
	map <int, int> moveTo;
	vector <Player> players;
	Dice dice;
public:
	SnakeAndLadder() {

	}

	SnakeAndLadder(vector <Player> players, vector < pair <int, int> >& snakesAndLadders) {
		dice = Dice(1, 6);
		this->players = players;
		for (auto& player : players) {
			positionsOfPlayer[player.getName()] = 0;
		}
		for (auto& it : snakesAndLadders) {
			moveTo[it.first] = it.second;
		}
	}
	int getPositionAfterMove(int currentPosition, int increment) {
		int finalPosition = currentPosition + increment;
		if (finalPosition > 100) return currentPosition;
		while (moveTo.count(finalPosition)) {
			finalPosition = moveTo[finalPosition];
		}
		return finalPosition;
	}
	void play() {
		bool gameFinished = false;
		while (!gameFinished) {
			for (int i = 0; i < players.size() && !gameFinished; i++) {
				int diceValue = dice.getVal();
				string playerName = players[i].getName();
				int nextPosition = getPositionAfterMove(positionsOfPlayer[playerName], diceValue);
				cout << playerName << " rolled a " << diceValue << " and moved from " << positionsOfPlayer[playerName] << " to " << nextPosition << endl << endl;
				if (nextPosition == 100) {
					cout << playerName << " has won the game!"  << endl;
					gameFinished = true;
					break;
				}

				positionsOfPlayer[playerName] = nextPosition;
			}
		}
	}
};
void solve() {
	srand(time(NULL));
	int n;
	cin >> n;
	vector < pair <int, int> > positions;
	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		positions.push_back({x, y});
	}
	cin >> n;
	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		positions.push_back({x, y});
	}
	int playerCnt;
	cin >> playerCnt;
	vector <Player> players(playerCnt);
	for (int i = 0; i < playerCnt; i++) {
		string name;
		cin >> name;
		players[i] = Player(name);
	}
	SnakeAndLadder snakesAndLadder(players, positions);
	snakesAndLadder.play();

}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
}