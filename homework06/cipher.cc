#include "cipher.h"

/* Cheshire smile implementation.
   It only contains the cipher alphabet
 */
struct Cipher::CipherCheshire {
    string cipher_alpha;
};

/* This function checks the cipher alphabet
   to make sure it's valid
 */
bool is_valid_alpha(string alpha);


// -------------------------------------------------------
// Cipher implementation
/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
Cipher::Cipher()
{
    // TODO: Implement this default constructor 
    smile = new CipherCheshire;
    smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
}

/* This constructor initiates the object with a
   input cipher key
 */
Cipher::Cipher(string cipher_alpha)
{
    // TODO: Implement this constructor
    smile = new CipherCheshire;
    if (is_valid_alpha(cipher_alpha)){
       smile->cipher_alpha = cipher_alpha;
       }
    else{
        cout << "Invalid cipher alphabet/key: " << cipher_alpha << endl;
	exit(EXIT_FAILURE);
	}
}

/* Destructor
 */
Cipher::~Cipher()
{
    // TODO: Implement this constructor
    // for clean up smile
    delete smile;
}

/* This member function encrypts the input text 
   using the intialized cipher key
 */
string Cipher::encrypt(string raw)
{
    cout << "Encrypting...";
    string retStr;
    // TODO: Finish this function
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


/* This member function decrypts the input text 
   using the intialized cipher key
 */
string Cipher::decrypt(string enc)
{
    string retStr;
    cout << "Decrypting...";
    // TODO: Finish this function
    
    string plain_alpha = "abcdefghijklmnopqrstuvwxyz";
    for(unsigned int i = 0; i<enc.size(); i++){
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
// -------------------------------------------------------


//  Helper functions 
/* Find the character c's position in the cipher alphabet/key
 */
unsigned int find_pos(string alpha, char c)
{
    unsigned int pos = 0;

    // TODO: You will likely need this function. Finish it.
    for(pos = 0; pos< alpha.size(); pos++){
	    
	if(alpha[pos] == LOWER_CASE(c))
            return pos;
    }
    return pos;
}

/* Make sure the cipher alphabet is valid - 
   a) it must contain every letter in the alphabet 
   b) it must contain only one of each letter 
   c) it must be all lower case letters 
   ALL of the above conditions must be met for the text to be a valid
   cipher alphabet.
 */
bool is_valid_alpha(string alpha)
{
    bool is_valid = true;
    if(alpha.size() != ALPHABET_SIZE) {
        is_valid = false; 
    } else {
        unsigned int letter_exists[ALPHABET_SIZE];
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            letter_exists[i] = 0;
        }
        for(unsigned int i = 0; i < alpha.size(); i++) {
            char c = alpha[i];
            if(!((c >= 'a') && (c <= 'z'))) {
                is_valid = false;
            } else {
                letter_exists[(c - 'a')]++;
            }
        }
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            if(letter_exists[i] != 1) {
                is_valid = false;
            }
        }
    }

    return is_valid;
}
