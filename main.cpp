#include"LetterCode.h"
using namespace std;
int main(int argc,char** argv)
{
    /*
    *argv[1]:the path of article downloaded on the Internet
    *argv[2]:the path of article coded with Fei_Nuo excel
    *argv[3]:the path of article encoded with Fei_Nuo excel
    *argv[4]:the path of single possibility and its average
    *argv[5]:the path of double possibility and its average
	*argv[6]:the path of Fei_nuo_map file
    */
    if(argc != 7)
    {
        cerr<<"Input error !"<<endl;
        return -1;
    }
	
    LetterCode the_Goal;                       //LetterCode module
    the_Goal.build_map(argv[1]);               //Comeplete the module
	
    map<double ,char> single_map;              //Single and string excel
    map<double ,string> string_map;
    single_possibility(the_Goal ,single_map);  //Comeplete the single and string excel 
    double_possibility(the_Goal ,string_map);  //according to the module
    double H_single = Average(single_map,argv[4]);//Compute the average of single and string excel
    double H_string = Average(string_map,argv[5]);
	
    map<char,string> fei_Nuo_map;         // Fei_Nuo excel
    Fei_Nuo_map(single_map,fei_Nuo_map);  //Comeplete the Fei_Nuo excel
    double effectience = Effectience_of_Fei_Nuo(H_single,the_Goal,fei_Nuo_map);//The effectience of Fei_Nuo excel
    Out_put_Fei_nuo_map(argv[6],effectience,fei_Nuo_map); //Output the Fei_Nuo excel and its effectience
	Code_in_Fei_Nuo(argv[1],argv[2] ,fei_Nuo_map);    //Code in Fei_Nuo excel
    Encode_in_Fei_Nuo(argv[2] ,argv[3] ,fei_Nuo_map); // Encode in Fei_Nuo excel
}
