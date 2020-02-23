#include "volimage.h"

bool isNumber(std::string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 


int main(int argc, char* argv[])
{
    using namespace std;

    if (argc<2)
    {
        cout<<"usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]"<<endl;
        cout<<"usage: volimage: error: too few arguments"<<endl;
        return 1; 
    } 

    string filename = "../Files/brain_mri_raws/"+string(argv[1])+".data";
    ifstream in(filename);
    if (!in)
    {
        cout<<"Enter a valid imageBase"<<endl;
        return false; 
    }

    VolImage data;
    data.readImages(string(argv[1]));
    

    if (argc>6)
    {
        cout<<"usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]"<<endl;
        cout<<"usage: volimage: error: too many arguments"<<endl;
        return 1;
    }

    if (argc>2)
    {
        if (string(argv[2])!="-d" && string(argv[2])!="-x")
        {
            cout<<"usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]"<<endl;
            cout<<"usage: volimage: error: no valid "<<string(argv[2])<<" option"<<endl;
            return 1;
        }
        if (!isNumber(string(argv[3])))
        {
            cout<<"usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]"<<endl;
            cout<<"usage: volimage: error: "<<string(argv[3])<<" is not a valid argument"<<endl;
            return 1;
        }
        if (argc==6 && !isNumber(string(argv[4])))
        {
            cout<<"usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]"<<endl;
            cout<<"usage: volimage: error: "<<string(argv[4])<<" is not a valid argument"<<endl;
            return 1;
        }
        else{
            if (string(argv[2])=="-d")
            {
                if (argc<6)
                {
                    cout<<"usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]"<<endl;
                    cout<<"usage: volimage: error: too few arguments for -d"<<endl;
                    return 0;
                }              
                data.diffmap(stoi(string((argv[3]))),stoi(string((argv[4]))),argv[5]);
                return 0;
            }
            else if(string(argv[2])=="-x")
            {
                if (argc>5)
                {
                    cout<<"usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]"<<endl;
                    cout<<"usage: volimage: error: too many arguments for -x"<<endl;
                    return 0;
                } 
                data.extract(stoi(string(argv[3])),string(argv[4]));
                return 0;
            }            
        }
    }
    return 0;
}