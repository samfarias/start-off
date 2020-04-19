/*
Author: Sammuel Farias
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Lab 6C: this program enchipers somethign using a cypher 
with the user assigned shift 
*/

#include<iostream>

#include<string>

using namespace std;

//Function prototypes.

string encryptCaesar(string plainText, int rShift);

string encryptVigenere(string plainText, string keyword);

string decryptCaesar(string cipherText, int rShift);

string decryptVigenere(string ciphertext, string keyword);

//definition of the function encryptCaesar()

//performs Caesar cipher encryption

//it takes a string and magnitude of the right shift.

string encryptCaesar(string plainText, int rShift)

{

       char ch;

       int i;

       //replace each letter in the plaintext with a letter

       //rShift number of positions down the alphabet.

       for (i = 0; plainText[i] != '\0'; ++i)

       {

              ch = plainText[i];

              //check the character is lowercase

              if (ch >= 'a' && ch <= 'z')

              {

                     ch = ch + rShift;

                     if (ch > 'z')

                     {

                           ch = ch - 'z' + 'a' - 1;

                     }

                     plainText[i] = ch;

              }

              //check the character is uppercase

              else if (ch >= 'A' && ch <= 'Z')

              {

                     ch = ch + rShift;

                     if (ch > 'Z')

                     {

                           ch = ch - 'Z' + 'A' - 1;

                     }

                     plainText[i] = ch;

              }

       }

       //return the new plain text

       //that is cipher text

       return plainText;

}

//definition of the function decryptCaesar()

//performs Caesar cipher decryption

//it takes a cipherText and magnitude of the right shift.

string decryptCaesar(string cipherText, int rShift)

{

       int i;

       char ch;

       //replace each letter in the plaintext with a letter

       //rShift number of positions up the alphabet.

       for (i = 0; cipherText[i] != '\0'; ++i)

       {

              ch = cipherText[i];

              //check the character is lowercase

              if (ch >= 'a' && ch <= 'z')

              {

                     ch = ch - rShift;

                     if (ch < 'a')

                     {

                           ch = ch + 'z' - 'a' + 1;

                     }

                     cipherText[i] = ch;

              }

              //notice whether we're working with an uppercase

              else if (ch >= 'A' && ch <= 'Z')

              {

                     ch = ch - rShift;

                     if (ch < 'A')

                     {

                           ch = ch + 'Z' - 'A' + 1;

                     }

                     cipherText[i] = ch;

              }

       }

       //return the cyphed text

       return cipherText;

}



string encryptVigenere(string plainText, string keyword)

{

       int i, j;

       string cipher = "";

       char p;

       //conevert the keyword into uppercase

       for (int k = 0; k < keyword.length(); k++)

       {

              if (islower(keyword[k]))

              {

                     keyword[k] = keyword[k] - 32;

              }

       }

       int len = plainText.length() / keyword.length();

       //make the keyword upto length of plainText

       for (i = 0; i < len; i++)

       {

              keyword += keyword;

       }            

       j = 0;

       //each letter of plaintext shifted by

       //sequence is determined by a keyword,

       //in which each letter corresponds to specific shift

       for (i = 0; i<plainText.length(); i++)

       {

              //check the character is lowercase or uppercase

              if ((plainText[i] >= 'a' && plainText[i] <= 'z') ||

                     (plainText[i] >= 'A' && plainText[i] <= 'Z'))

              {

                     //Shift the character number of positions up the alphabet.

                     if (plainText[i] >= 'a' && plainText[i] <= 'z')

                           p=(plainText[i] - 'a' + (keyword[j] - 'A')) % 26 + 'a';

                     else

                           p=(plainText[i] - 'A' + (keyword[j] - 'A')) % 26 + 'A';

                     cipher = cipher + p;

                     j++;

              }

              else

                     cipher = cipher + plainText[i];

       }

       //return the encrypted text

       return cipher;

}

//definition of the function decryptVigenere()

//performs Vigenere cipher decryption

//it takes a string and a keyword.

string decryptVigenere(string ciphertext, string keyword)

{

       int i, j;

       string plain = "";

       char p;

       //conevert the keyword into uppercase

       for (int k = 0; k < keyword.length(); k++)

       {

              if (islower(keyword[k]))

              {

                     keyword[k] = keyword[k] - 32;

              }

       }     

       int len = ciphertext.length() / keyword.length();     

       //make the keyword upto length of plainText

       for (i = 0; i < len; i++)

       {

              keyword += keyword;

       }            

       j = 0;

       //each letter of plaintext shifted by

       //sequence is determined by a keyword,

       //in which each letter corresponds to specific shift

       for (i = 0; i<ciphertext.length(); i++)

       {

              //check the character is lowercase or uppercase

              if ((ciphertext[i] >= 'a' && ciphertext[i] <= 'z') ||

                     (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z'))

              {

                     //Shift the character number of positions down the alphabet.

                     if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')

                     {

                           p=(ciphertext[i] - 'a' - (keyword[j] - 'A')) % 26 + 'a';

                     }

                     else

                     {

                           p = (ciphertext[i] - 'A' - (keyword[j] - 'A')) % 26 + 'A';

                     }

                     plain = plain + p;

                     j++;

              }

              else

                     plain = plain + ciphertext[i];

       }

       //return the decrypted text

       return plain;

}

//definition of main function

int main()

{

       //declare the variable

       string plainText, keyword;

       int rShift;

       //read plain text and shift number

       cout << "Enter Plain Text: ";

       getline(cin, plainText);

       cout << "\n= Caesar =\n";

       cout << "\nEnter Shift\t: ";

       cin >> rShift;

       //call the funtion encryptCaesar() and print the value

       string cipher = encryptCaesar(plainText, rShift);

       cout << "\nCiphertext\t: " << cipher << "\n";

       //call the funtion decryptCaesar() and print the value

       plainText = decryptCaesar(cipher, rShift);

       cout << "\nDecrypted\t: " << plainText;

       cout << endl;

       cout << "\n= Vigenere =\n";

       //read the keyword

       cout << "\nEnter Keyword\t: ";

       cin >> keyword;

       //call the funtion encryptVigenere() and print the value

       string cipher_text = encryptVigenere(plainText, keyword);

       cout << "\nCiphertext\t: " << cipher_text << "\n";

       //call the funtion decryptVigenere() and print the value

       cout << "\nDecrypted\t: " << decryptVigenere(cipher_text, keyword) << endl;

       return 0;

}


/*
Author: Sammuel Farias
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Lab 6C: this program enchipers somethign using a cypher 
with the user assigned shift 


#include <iostream> #include <string>
using namespace std;
string encryptVigenere(string str, string key);
int main() 
{    string str;     
    cout << “Plaintext: ";     
    getline(cin, str);     
    string key;     
    cout << "Enter keyword: ";     
    cin >> key;     
    cout << "Ciphertext     : " << encryptVigenere(str, key) << endl;    
}

string encryptVigenere(string str, string keyword) {    
  string ans = "";    
  char ch;    
  int iter=0, key;    
  for(int i = 0; i < str.length(); ++i) 
  {        
  ch = str[i];        
  if(ch >= 'A' && ch <= 'Z') {            
    key = keyword[iter] - 'a';            
    iter = (iter+1)%keyword.length();            
    ch = 'A' + (ch-'A'+key+26)%26;
  }        
  if(ch >= 'a' && ch <= 'z') {            
      key = keyword[iter] - 'a';            
      iter = (iter+1)%keyword.length();            
      ch = 'a' + (ch-'a'+key+26)%26;        
    }        
    ans += ch;    
  }    
  return ans; 
}
*/