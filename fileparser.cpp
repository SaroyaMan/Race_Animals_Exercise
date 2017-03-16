#include "fileparser.h"


FileParser::FileParser()
{
	int i=0,j=0;
	rows=0, columns=0;
	fp = fopen("map.txt", "r");
	if (fp == 0)
	{
		cerr<<"The file has not been found.\n";
		exit(1);				//exception
	}
	fscanf(fp, "%d", &rows);	
	char c;
	while (c != ',') 	
		c = fgetc(fp);		

	fscanf(fp, "%d", &columns);
	map = new char*[rows+1];
	for (i=0; i<rows+1; i++)
	{
		map[i] = new char[columns+1];
		map[i][columns] = '\0';
	}
	for (i=0; i<columns; i++) map[rows][i] = '\0';
	fgetc(fp);	fgetc(fp);
	i=0;
	while (!feof(fp))
	{
		fscanf(fp, "%c", &map[i][j]);
		c = fgetc(fp);
		if (c == '\n')
		{
			i++;
			j=0;
		} 
		else j++;
	}
	fclose(fp);
}

void FileParser::printMap()
{
	int i=0, j=0;
	for (i=0; i<rows; i++)
	{
		for (j=0; j<columns; j++)
			cout<<map[i][j]<<"   ";
		cout<<endl;	
	}
}

