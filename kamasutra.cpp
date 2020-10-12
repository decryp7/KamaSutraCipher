//============================================================================
// Name        : kamasutra.cpp
// Author      : Teo Kok Yong S8370639B
// Version     :
// Copyright   : Your copyright notice
// Description : kamasutra
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <getopt.h>
using namespace std;

void GenerateKeyFile(const char * path);
void Encrypt(const char * keyFilePath, const char * plainFilePath, const char * cipherFilePath);
void Decrypt(const char * keyFilePath, const char * cipherFilePath, const char * plainFilePath);
char * ReadFile(const char * path);

void Encrypt(const char * keyFilePath, const char * plainFilePath, const char * cipherFilePath){
	char * keyFile = ReadFile(keyFilePath);
	char * plainFile = ReadFile(plainFilePath);
	int plainFileCharCount = strlen(plainFile);
	
	string key(keyFile);
	
	for(int i=0;i < plainFileCharCount;i++){
		char targetChar = plainFile[i];
		int pos = key.find(targetChar);

		if(pos > -1){
			if(pos%2 == 1){
				//odd number, get the previous
				//cout << "plainText " << plainFile[i]<<endl;
				plainFile[i] = keyFile[pos-1];
				//cout << "key " << keyFile[pos-1] << endl;
			}else{
				//even, get next
				//cout << "plainText " << plainFile[i]<<endl;
				plainFile[i] = keyFile[pos+1];
				//cout << "key " << keyFile[pos+1] << endl;
 			}
		}
	}
	
	ofstream cipherFileOut(cipherFilePath);
	cipherFileOut.write(plainFile, strlen(plainFile));
	cipherFileOut.close();
}

void Decrypt(const char * keyFilePath, const char * cipherFilePath, const char * plainFilePath){
	//encrypting the ciphertext again will give u back the plainfile
	Encrypt(keyFilePath, cipherFilePath, plainFilePath);
}

void GenerateKeyFile(const char * path){
	char randomAlphabets[26];
	srand(time(0));
	for(int i = 0; i < 26; i++){
		char randomAlphabet('a' + rand()%26);
		string g(randomAlphabets);
		while(g.find(randomAlphabet) != string::npos){
			randomAlphabet = 'a' +rand()%26;
		}
		randomAlphabets[i] = randomAlphabet;
	}
	ofstream outfile(path);
	outfile.write(randomAlphabets, 26) ;
	outfile.close();
}

char * ReadFile(const char * path){
	string line;
	string content;
	char * buffer;
	
	ifstream infile(path);
	if(infile.is_open()){
		/*infile.seekg(0, ios::end);
		int length = infile.tellg();
		infile.seekg(0, ios::beg);
		
		buffer = new char[length];
		
		infile.read(buffer, length);
		
		return buffer;*/
		while (!infile.eof()){
			char ch = infile.get();
			content += ch;
		}
		
		buffer  = new char[content.length()];
		
		strcpy(buffer, content.c_str());
		
		return buffer;
		
	}else{
		cout << "Unable to open " << path; 
	}
	
	/*
	if(infile.is_open()){
		while(!infile.eof()){
			//getline(infile, line);
			//content += line;
			infile.read(buffer, 1024);
			cout << buffer;
		}
		
		//char * textArray = new char[content.length()-1];
		//strcpy(textArray, content.c_str());
		//cout << textArray;
		//return textArray;
	}else{
		cout << "Unable to open " << path; 
	}*/
	
	return NULL;
}

int main(int argc, char *argv[]) {
	int c;
	
	while(1){
		static struct option long_options[5] = {
				{"key", required_argument , 0, 'k'},
				{"encrypt", required_argument, 0, 'e'},
				{"decrypt", required_argument, 0, 'd'},
				{"help", required_argument, 0, 'h'},
				{0,0,0,0}
		};
	
	
	c = getopt_long(argc,argv, "k:e:d:h", long_options, 0);
	
	if(c == -1)
		break;
	
	switch(c){
		case 'k':
			GenerateKeyFile(optarg);
			break;
		case 'e':
			Encrypt(optarg, argv[optind], argv[optind+1]);
			break;
		case 'd':
			Decrypt(optarg, argv[optind], argv[optind+1]);
			break;
	
	}
	}
	return 0;
}





