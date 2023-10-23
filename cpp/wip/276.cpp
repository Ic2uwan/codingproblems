#include <iostream>
#include <vector>
using namespace std;

class boss {
public:
	int num;
	int x;
	int y;
	int s;
	int t;
	bool alive = true;
	boss(int x, int y, int s, int t, int i);
	void move();
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int , int>> bombMap;
	vector<bool> deleteList;
	vector<boss> vBoss;
	for (int i = 0; i < k; i++) {
		int x, y, s, t;
		cin >> x >> y >> s >> t;
		vBoss.push_back(boss(x, y, s, t, i));
	}
	
	bool allDead = false;
	while (!allDead) {
		bool stillAlive = false;
		for (int i = 0; i < k; i++) {
			if (vBoss[i].alive == true)
				stillAlive = true;
		}
		if (!stillAlive) 
			allDead = true;

		for (int i = 0; i < k; i++) {
			if (vBoss[i].alive) {
				bool flag = false;
				for (int j = 0; j < bombMap.size(); j++)
					if (bombMap[j].first == vBoss[i].x && bombMap[j].second == vBoss[i].y) {
						flag = true;
					}
				if (!flag) {
					bombMap.push_back({ vBoss[i].x, vBoss[i].y });
					cout << i << ' ' << vBoss[i].x << ' ' << vBoss[i].y << " pushed\n";
					deleteList.push_back(false);
				}
				vBoss[i].move();
				if (vBoss[i].x < 0 || vBoss[i].y < 0 || vBoss[i].x >= n || vBoss[i].y >= m) {
					vBoss[i].alive = false;
				}
			}
		}
		
		for (int i = 0; i < bombMap.size(); i++) {
			for (int j = 0; j < vBoss.size(); j++){
				if (bombMap[i].first == vBoss[j].x && bombMap[i].second == vBoss[j].y && vBoss[j].alive == true) {
					vBoss[j].alive = false;
					cout << i << ' ' << vBoss[j].x << ' ' << vBoss[j].y << " blew\n";
					deleteList[i] = true;
				}
			}
		}

		for (int i = deleteList.size() - 1; i >= 0; i--)
			if (deleteList[i] == true) {
				bombMap.erase(bombMap.begin() + i);
				deleteList.erase(deleteList.begin() + i);
			}
	}

	cout << bombMap.size();
	return 0;
}

boss::boss(int x, int y, int s, int t, int i) {
	this->x = x;
	this->y = y;
	this->s = s;
	this->t = t;
	this->num = i;
}

void boss::move() {
	this->x += this->s;
	this->y += this->t;
}