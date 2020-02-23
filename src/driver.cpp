#include "volimage.h"


int main(int argc, char* argv[])
{

    using namespace std;

    string filename = "../Files/brain_mri_raws/MRI.data";

    ifstream in(filename);
    if (!in)
    {
        cout<<"Error"<<endl;
        return false; 
    }

    if (argc<2)
    {
        cout<<"Please enter valid arguments" <<endl;
        return 1;
    } 

    for(int i = 0; i < argc; i++)
    {
        cout<<argv[i] <<endl;
    }

    VolImage data;
    data.readImages("MRI");
    data.diffmap(2,3,"test");
    data.extract(0,"extract");

    return 0;
}