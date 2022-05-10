#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"


// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------
struct VCipher::CipherCheshire{
	string keyword;
};

//Default constructor
VCipher::VCipher(){
	smile = new CipherCheshire;
	smile->keyword = "a";
}

//constructor initialize the object with some input key.
VCipher::VCipher(string keyword){
	smile = new CipherCheshire;
	for(unsigned int i = 0; i<keyword.size(); i++){
		if(keyword[i] == ' '){
			cout << "Error: not a valid Vigenere key word" << endl;
			exit(EXIT_FAILURE);
		}
	}
	smile->keyword = keyword;
	
}

//destructor
VCipher::~VCipher(){
	
	delete smile;
}



string VCipher::encrypt(string raw){
	cout << "Encrypting...";
	string retStr;
	string plain_text = "abcdefghijklmnopqrstuvwxyz";
	unsigned int i;
	unsigned int j=0;
	for(i = 0; i<raw.size(); i++){
		if(raw[i] == ' '){
			retStr.push_back(raw[i]);
		}else if (islower(raw[i])){
			
			string copy = "abcdefghijklmnopqrstuvwxyz";
			rotate_string(copy, find_pos(plain_text,raw[i]));
			unsigned int foundkey = smile->keyword[j % smile->keyword.size()];
			retStr += copy[find_pos(plain_text, foundkey)];
			j++;
		}else if (isupper(raw[i])){
			raw[i] = LOWER_CASE(raw[i]);
			string copy = "abcdefghijklmnopqrstuvwxyz";
			rotate_string(copy, find_pos(plain_text,raw[i]));
			unsigned int foundkey = smile->keyword[j % smile->keyword.size()];
			retStr += UPPER_CASE(copy[find_pos(plain_text, foundkey)]);
			j++;
		}
	}
	
	cout << "Done" << endl;
	
	return retStr;
}

string VCipher::decrypt(string enc){
	cout << "Decrypting...";
	string retStr;
	string plain_text = "abcdefghijklmnopqrstuvwxyz";
	unsigned int i;
	unsigned int j=0;
	for(i = 0; i<enc.size(); i++){
		if(enc[i] == ' '){
			retStr.push_back(enc[i]);
		}else if (islower(enc[i])){
			
			string copy = "abcdefghijklmnopqrstuvwxyz";
			unsigned int foundkey = smile->keyword[j % smile->keyword.size()];
			rotate_string(copy, find_pos(plain_text,foundkey));
			retStr += plain_text[find_pos(copy, enc[i])];
			j++;
		}else if (isupper(enc[i])){
			enc[i] = LOWER_CASE(enc[i]);
			string copy = "abcdefghijklmnopqrstuvwxyz";
			unsigned int foundkey = smile->keyword[j % smile->keyword.size()];
			rotate_string(copy, find_pos(plain_text,foundkey));
			retStr += UPPER_CASE(plain_text[find_pos(copy,enc[i])]);
			j++;
		}
	}
	
	cout << "Done" << endl;
	
	return retStr;
}

