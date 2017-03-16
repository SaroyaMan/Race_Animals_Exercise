#include <iostream>
#include <cstring>
#ifndef fileparser
#define fileparser
#define SIZE 100
using namespace std;

class FileParser
{
	FILE* fp;
	int rows;
	int columns;
	char** map;
	public:
		FileParser();
		int getRows() {return rows;}
		int getColumns() {return columns;}
		char** getMap() {return map;}
		void printMap();
};
#endif
