#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"


// -------------------------------------------------------
// Caesar Cipher implementation
/* CCheshire csmile implementation.
 * it contains the rot
 */

  //Caesar Cipher implenmentation.
  struct CCipher::CipherCheshire{
  	  string cipher_alpha;
	  int rot;
  };

  void rotate_string(string& in_str, int rot);
  
  //Default constructor.
  CCipher::CCipher(){
  	smile = new CipherCheshire;
	smile->rot = 0;
	smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
	
  }
 //initial the object with a rotated string.
  CCipher::CCipher(int offset){
	if(offset < 0){
	    cout << "Error: Caesar cipher is less than 0" << endl;
	    exit(EXIT_FAILURE);
	}else{
  	smile = new CipherCheshire;
	smile->rot = offset;
	smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";	
	rotate_string(smile->cipher_alpha, smile->rot);
	}
	
  }

  //Destructor.
  CCipher::~CCipher(){
      delete smile;
  }

// -------------------------------------------------------
string CCipher::encrypt(string raw)
{
	cout << "Encrypting...";
	string retStr;
	string plain_alpha = "abcdefghijklmnopqrstuvwxyz";
	for(unsigned int i = 0; i<raw.size(); i++){
		if(raw[i] == ' '){
		    retStr.push_back(raw[i]);
		}else{
		    unsigned int pos = find_pos(plain_alpha, raw[i]);
		    if(isupper(raw[i])){
		       char in_cipher = smile->cipher_alpha[pos];
		       retStr.push_back(UPPER_CASE(in_cipher));
		    }else{
		       retStr.push_back(smile->cipher_alpha[pos]);
		    }
		}
	}

	cout << "Done" << endl;
	
	return retStr;


}

string CCipher::decrypt(string enc){
	cout << "Decrypting...";
	string retStr;

	string plain_alpha = "abcdefghijklmnopqrstuvwxyz";
	for(unsigned int i = 0; i< enc.size(); i++){
		if(enc[i] == ' '){
		    retStr.push_back(enc[i]);
		}else{
		    unsigned int pos = find_pos(smile->cipher_alpha, enc[i]);
		    if(isupper(enc[i])){
		       char in_plain = plain_alpha[pos];
		       retStr.push_back(UPPER_CASE(in_plain));
		    }else{
		       retStr.push_back(plain_alpha[pos]);
		    }
		}
	}

	cout << "Done" << endl;

	return retStr;
	
}
// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{
    // TODO: You will likely need this function. Implement it.
    if(rot < 0){
       cout << "Not valid shift/offset/rotation value: " << rot << endl;
       exit(EXIT_FAILURE);
    }else{
        rot = rot % 26;
 	reverse(in_str.begin(),in_str.begin()+rot);
	reverse(in_str.begin()+rot,in_str.end());	
	reverse(in_str.begin(),in_str.end());
    }
}
