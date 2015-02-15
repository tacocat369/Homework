#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>
#include "lib/setint.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	map<string,SetInt*> index;
	if (argc < 3){
		cout << "Insufficient command line arguements" << endl;
		return 1;
	}
	ifstream infile(argv[1]);
	int page = 1;
	string word;
	infile >> word;
	SetInt* temp;
	int x;
	while (!infile.fail()){
		if (word == "<pagebreak>"){
			page++;
		}
		else{
			bool punct = false;
			bool hyphen = false;
			if (ispunct(word[0])){
				word = word.substr(1, word.length()-1);
			}
			if (ispunct(word[word.length()-1])){
				word = word.substr(0, word.length()-2);
			}
			x = word.length();
			for (int i=0; i<x; i++){
				if (ispunct(word[i]) && word[i] != '-'){
					punct = true;
				}
				word[i] = tolower(word[i]);
			}
			if (!punct){
				int startpt = 0;
				x = word.length();
				int size2;
				for (int i=0; i<x; i++){
					if (word[i] == '-'){
						hyphen = true;
						string word2 = word.substr(startpt, i-startpt);
						size2 = word2.length();
						if (size2 > 1){
							startpt = i + 1;
							if (!index.count(word2)){
								temp = new SetInt();
								temp->insert(page);
								index[word2] = temp;
							}
							else{
								index[word2]->insert(page);
							}
						}
					}
					else if (hyphen && i == x-1){
						string word2 = word.substr(startpt, i-startpt+1);
						size2 = word2.length();
						if (size2 > 1){
							if (!index.count(word2)){
								temp = new SetInt();
								temp->insert(page);
								index[word2] = temp;
							}
							else{
								index[word2]->insert(page);
							}
						}
					}
				}
				if (!hyphen && x > 1){
					if (!index.count(word)){
						temp = new SetInt();
						temp->insert(page);
						index[word] = temp;
					}
					else{
						index[word]->insert(page);
					}
				}
			}
		}
		infile >> word;
	}
	ofstream outfile;
	outfile.open(argv[2]);
	for (int i=3; i<argc; i++){
		string str(argv[i]);
		x = str.length();
		for (int i=0; i<x; i++){
			str[i] = tolower(str[i]);
		}
		if (index.count(str)){
			int const* temp = index[str]->first();
			while (temp != NULL){
				outfile << *temp << " ";
				temp = index[str]->next();
			}
			outfile << endl;
		}
		else{
			outfile << "None" << endl;
		}
	}
	outfile.close();
	map<string,SetInt*>::iterator it;
	for(it = index.begin(); it != index.end(); ++it){
		delete it->second;
	}
	return 0;
}
