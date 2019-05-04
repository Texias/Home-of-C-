#ifndef LETTERCODE_H_INCLUDED
#define LETTERCODE_H_INCLUDED
#include<map>
#include<cmath>
#include<string>
#include<fstream>
#include<iostream>
#include<iterator>
using namespace std;

class LetterCode
{
	/**
	*str : A charactor used to read the input file 
	*single_Num : To store the total number of the single word
	*double_Num : To store the total number of the double word
	*input : The input data file direction
	*char_map : The single possibility
	*string_map : The double possibility
	**/
public:
    char str;
    double single_Num;
    double double_Num;
    ifstream input;
    map<char ,double> char_map;  
    map<string ,double> string_map; 
	
    bool char_is_OK();/**To diaglose if the str is Ok for the requirements**/
	
    void build_map(char *direction);/**To build the char_map and the string_map**/
	
};
void single_possibility(LetterCode& A ,map<double ,char>& single_map);/**possibility of single word and blank**/

void double_possibility(LetterCode& A ,map<double ,string>& string_map);/**possibility if double continous word**/

double Average(map<double ,char>& single_map,char* direction);/**average of possibility group**/

double Average(map<double ,string>& string_map,char* direction);/**average of possibility group**/

double minus_of_two_data(double &A,double &B); /**the distance of two double numbers**/

void Fei_Nuo(map<double ,char>::iterator start,map<double ,char>::iterator ends,map<char,string>& Fei_Nuo_map);

void Fei_Nuo_map(map<double ,char>& single_map,map<char ,string >& fei_Nuo_map); /**Fei_Nuo code of English letter**/

double Effectience_of_Fei_Nuo(double H,LetterCode& A,map<char,string>& Fei_Nuo_map);

void Out_put_Fei_nuo_map(char* direction,double effectience,map<char,string>& Fei_Nuo_map);/**output fei_Nuo_map and its effectience**/

void Code_in_Fei_Nuo(char* ,char* ,map<char, string>& Fei_Nuo_map);/**code of input**/

void Encode_in_Fei_Nuo(char* ,char* ,map<char, string>& Fei_Nuo_map);/**encode of input**/

#endif // LETTERCODE_H_INCLUDED
