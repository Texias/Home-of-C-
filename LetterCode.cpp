#include"LetterCode.h"
bool LetterCode::char_is_OK()
{
    return (str<='z'&&str>='a')||(str==' ')||(str<='Z'&&str>='A');
}
void LetterCode::build_map(char *direction)
{
    input.clear();
    input.open(direction);
    if(!input)
    {
        cerr<<"Can not open the file !";
    }
    string strs;
    char pre_str = '!';
    single_Num = 0.0;
    double_Num = 0.0;
    while(input>>str)
    {

        if(char_is_OK())
        {
            ++single_Num;
            if(char_map.count(str))
                ++char_map[str];
            else
                char_map[str] =1.0;
            if(pre_str!='!')
            {
                ++double_Num;
                strs.push_back(pre_str);
                strs.push_back(str);
                if(string_map.count(strs))
                    ++string_map[strs];
                else
                    string_map[strs] = 1.0;
                strs.clear();
            }
            pre_str = str;
        }
    }
    input.close();
}
void single_possibility(LetterCode& A ,map<double ,char>& single_map)
{
    if(A.char_map.empty())
        cerr<<"the char_map is empty !";
    for(map<char ,double>::iterator iter = A.char_map.begin();iter != A.char_map.end();++iter)
        single_map.insert(make_pair(iter->second/A.single_Num,iter->first));
}
void double_possibility(LetterCode& A ,map<double ,string>& double_map)
{
    if(A.string_map.empty())
        cerr<<"the string_map is empty !";
    for(map<string ,double>::iterator iter = A.string_map.begin();iter!=A.string_map.end();++iter)
        double_map.insert(make_pair(iter->second/A.double_Num,iter->first));
}
double Average(map<double ,char>& single_map,char* direction)
{
    if(single_map.empty())
        cerr<<"the single map is empty !";
    double H = 0.0;
    ofstream output(direction);
    for(map<double ,char>::iterator iter = single_map.begin();iter!=single_map.end();++iter)
    {
        H += iter->first*log(1.0/iter->first)/log(2.0);
        output<<iter->second<<'\t'<<iter->first<<endl;
    }

    output<<'H'<<'\t'<<H<<endl;
    return H;
}
double Average(map<double ,string>& string_map,char* direction)
{
    if(string_map.empty())
        cerr<<"the string map is empty !";
    double H = 0.0;
    ofstream output(direction);
    for(map<double ,string>::iterator iter = string_map.begin();iter!=string_map.end();++iter)
    {
        H += iter->first*log(1.0/iter->first)/log(2.0);
        output<<iter->second<<'\t'<<iter->first<<endl;
    }
    output<<'H'<<'\t'<<H<<endl;
    return H;
}
double minus_of_two_data(double A,double B)
{
    return (A-B>0.0)?(A-B):(B-A);
}
void Fei_Nuo(map<double ,char>::iterator start,map<double ,char>::iterator ends,map<char,string>& Fei_Nuo_map)
{
    map<double ,char>::iterator iter = start;
    if(++iter==ends)
        return;
    double Total_num = 0.0;
    for(iter = start;iter != ends;++iter)
        Total_num += iter->first;
    double Min = 1;
    double Num = 0.0;
    while(--iter!=start)
    {
        Num += iter->first;
        double temp = minus_of_two_data(Num,Total_num-Num);
        if(temp<Min)
            Min = temp;
        else
        {
            ++iter;
            break;
        }
    }
    if(iter==start)
    {
        ++iter;
    }
    map<double ,char>::iterator pt_map = start;
    while(pt_map != iter)
        Fei_Nuo_map[(pt_map++)->second].push_back('1');
    while(pt_map != ends)
        Fei_Nuo_map[(pt_map++)->second].push_back('0');
    Fei_Nuo(start,iter,Fei_Nuo_map);
    Fei_Nuo(iter,ends,Fei_Nuo_map);
}
void Fei_Nuo_map(map<double ,char>& single_map,map<char,string>& fei_Nuo_map)
{
    if(!single_map.empty())
    {
        map<double ,char>::iterator start = single_map.begin();
        map<double ,char>::iterator ends = single_map.end();
        Fei_Nuo(start,ends,fei_Nuo_map);
    }
}
double Effectience_of_Fei_Nuo(double H,LetterCode& A,map<char,string>& Fei_Nuo_map)
{
    double Average_length = 0.0;
    for(map<char,string>::iterator iter = Fei_Nuo_map.begin();iter != Fei_Nuo_map.end();++iter)
        Average_length += A.char_map[iter->first]/A.single_Num*iter->second.size();
    return H/Average_length;
}
void Out_put_Fei_nuo_map(char* direction,double effectience,map<char,string>& Fei_Nuo_map)
{
	ofstream output(direction);
	for(map<char ,string>::iterator iter = Fei_Nuo_map.begin();iter != Fei_Nuo_map.end();++iter)
	{
		output<<iter->first<<'\t'<<iter->second<<endl;
	}
	output<<"The effectience is :    "<<effectience;
}
void Code_in_Fei_Nuo(char* in,char* out,map<char, string>& Fei_Nuo_map)
{
    ifstream input(in);
    if(!input)
        cerr<<"can not open the file !";
    ofstream output(out);
    char str;
    while(input>>str)
    {
        if((str<='z'&&str>='a')||(str==' ')||(str<='Z'&&str>='A'))
        {
            output<<Fei_Nuo_map[str];
        }
    }
}
void Encode_in_Fei_Nuo(char* in,char* out,map<char, string>& Fei_Nuo_map)
{
    ifstream input(in);
    if(!input)
        cerr<<"can not open the file !";
    ofstream output(out);
    char str;string strs;
    while(input>>str)
    {

        strs.push_back(str);
        for(map<char, string>::iterator iter = Fei_Nuo_map.begin();iter != Fei_Nuo_map.end();++iter)
        {
            if(strs==iter->second)
            {
                output<<iter->first;
                strs.clear();
                break;
            }
        }
    }

}
