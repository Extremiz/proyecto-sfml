#ifndef CONTROLFILE_H
#define CONTROLFILE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace sf;
using namespace std;
struct input{
	int points;
	string name;
};
class controlfile{
public:
	controlfile();
	bool entreeneltop(int p);
	void editlist(string a,int b);
	int max_point();
	string get_name(int x);
	int get_point(int x);

private:
	char a[50];
	vector<input>v;
	input aux;
	input auxi;
};
#endif
