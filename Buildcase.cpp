#include <bits/stdc++.h>
using namespace std;

string randomPos (int r, int c){
	srand(time(NULL));
	int x = rand() % (r - 1 - 0 + 1) + 0;
	int y = rand() % (c - 1 - 0 + 1) + 0;
	stringstream ss;
	ss << "(" << x << ',' << y << ")";
	return ss.str();
}

int main(){
	for (int id = 202; id <= 1202 ; id++){
	srand(time(NULL));
	set<string> pos;
	char direct[4] = {'U', 'L', 'R', 'D'};
	int map_num_rows = rand() % (30 - 20 + 1) + 20;
	int map_num_cols = rand() % (30 - 20 + 1) + 20;
	int max_obj = rand () % (40 - 30 + 1) + 30;
	int num_walls = rand () % (15 - 1 + 1) + 1;
	int num_fake_walls = rand () % (10 - 1 + 1) + 1;
	int num_step = rand () % (100 - 50 + 1) + 50;
	/*
		SHERLOCK
	*/
	int len_rule_sherlock = rand () % (10 - 5 + 1) + 5;
	string sherlock_rule;
	for (int i = 0 ; i < len_rule_sherlock; i++){
		int random = rand() % (1000 - 0 + 1);
		sherlock_rule += direct[random % 4];
	}
	string sherlock_pos;
	string tmp_shlk = randomPos(map_num_rows, map_num_cols);
	while (pos.find(tmp_shlk) != pos.end())
		tmp_shlk = randomPos(map_num_rows, map_num_cols);
	sherlock_pos = tmp_shlk;
	int sherlock_init_hp = rand() % (510 - -10 + 1) - 10;
	int sherlock_init_exp = rand() % (910 - -10 + 1) - 10;
	pos.insert(sherlock_pos);
	/*
		WATSON
	*/
	int len_rule_watson = rand() % (10 - 5 + 1) + 5;
	string watson_rule;
	for (int i = 0 ; i < len_rule_watson; i++){
		int random = rand() % (1000 - 0 + 1);
		watson_rule += direct[random % 4];
	}
	string watson_pos ;
	string tmp_wat = randomPos(map_num_rows, map_num_cols);
	while (pos.find(tmp_wat) != pos.end())
		tmp_wat = randomPos(map_num_rows, map_num_cols);
	watson_pos = tmp_wat;
	int watson_init_hp = rand() % (510 - -10 + 1) - 10;
	int watson_init_exp = rand() % (910 - -10 + 1) - 10;
	pos.insert(watson_pos);
	/*
		CRIMINAL
	*/
	string tmp_pos = randomPos(map_num_rows, map_num_cols);
	while (pos.find(tmp_pos) != pos.end())
		tmp_pos = randomPos(map_num_rows, map_num_cols);
	string criminal_pos = tmp_pos;
	pos.insert(criminal_pos);

	set<string> arr_walls;
	while (num_walls > 0){
		string tmp = randomPos(map_num_rows, map_num_cols);
		if (pos.find(tmp) == pos.end()){
			arr_walls.insert(tmp);
			pos.insert(tmp);
			num_walls --;
		}
	}
	string set_pos_wall = "[";
	for (auto x : arr_walls)
		set_pos_wall += (x + ';');
	set_pos_wall[(int)set_pos_wall.size() - 1] = ']';

	set<string> arr_fwalls;
	while (num_fake_walls > 0){
		string tmp = randomPos(map_num_rows, map_num_cols);
		if (pos.find(tmp) == pos.end()){
			arr_fwalls.insert(tmp);
			pos.insert(tmp);
			num_fake_walls --;
		}
	}
	string set_pos_fwall = "[";
	for (auto x : arr_fwalls)
		set_pos_fwall += (x + ';');
	set_pos_fwall[(int)set_pos_fwall.size() - 1] = ']';

	string path = "F:\\VSCode\\nghia_case\\input\\input" + to_string(id) + ".txt"; 
	fstream file(path, ios::out);
	file << "MAP_NUM_ROWS=" << map_num_rows << endl;
	file << "MAP_NUM_COLS=" << map_num_cols << endl;
	file << "MAX_NUM_MOVING_OBJECTS=" << max_obj << endl;
	file << "ARRAY_WALLS=" << set_pos_wall << endl;
	file << "ARRAY_FAKE_WALLS=" << set_pos_fwall << endl;
	file << "SHERLOCK_MOVING_RULE=" << sherlock_rule << endl;
	file << "SHERLOCK_INIT_POS=" << sherlock_pos << endl;
	file << "SHERLOCK_INIT_HP=" << sherlock_init_hp << endl;
	file << "SHERLOCK_INIT_EXP=" << sherlock_init_exp << endl;
	file << "WATSON_MOVING_RULE=" << watson_rule << endl;
	file << "WATSON_INIT_POS=" << watson_pos << endl;
	file << "WATSON_INIT_HP=" << watson_init_hp << endl;
	file << "WATSON_INIT_EXP=" << watson_init_exp << endl;
	file << "CRIMINAL_INIT_POS=" << criminal_pos << endl;
	file << "NUM_STEPS=" << num_step << endl;
}

}