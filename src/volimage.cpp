#include "volimage.h"

//Default constructor
VolImage::VolImage():width(0),height(0){};

//Default destructor
VolImage::~VolImage(){
    std::cout<<"Clearing dynamically located memory"<<std::endl;
    for (size_t i = 0; i < slices.size(); i++)
    {        
        for (size_t j = 0; j < height; j++)
        {
            delete[] slices.at(i)[j];/* code */
        }
        delete[] slices.at(i);
    }
    
};


// populate the object with images in stack and
//set member variables define in .cpp 
bool VolImage::readImages(std::string baseName){

    using namespace std;

    // ======================================================= GET HEADER DATA ================================================================================

    string filename = "../Files/brain_mri_raws/"+baseName+".data";
    string headerLine;
    string heightInHeader;
    string widthInHeader;
    string numberOfImagesString;

    ifstream headerReader(filename);
    if (!headerReader)
    {
        cout<<"Incorrect base name"<<endl;
        return false; 
    }
    
    getline(headerReader,headerLine);
    istringstream token(headerLine);

    getline(token,widthInHeader,' ');
    getline(token,heightInHeader,' ');
    getline(token,numberOfImagesString,' ');

    height=stoi(heightInHeader);
    width=stoi(widthInHeader);
    int numberofImages=stoi(numberOfImagesString);

    // cout<<"width "<<width<<endl;
    // cout<<"height "<<height<<endl;
    // cout<<"images "<<numberofImages<<endl;


    // =========================================================================================================================================================

    int j = 0;
    unsigned char value;
    char buf[sizeof(unsigned char)];

    cout<<"Reading raw file"<<endl;

    for (size_t i = 0; i < numberofImages ; i++)
    {
        filename = "../Files/brain_mri_raws/"+baseName + to_string(i)+".raw";
        unsigned char **rowPtr;
        rowPtr=new unsigned char *[height];

        ifstream fileStream(filename, ios::binary);
        for (size_t y = 0; y < height; y++)
        {

            unsigned char * row;
            row = new unsigned char [width];

            for (size_t x = 0; x < width; x++)
            {           
                fileStream.read(buf,sizeof(buf));
                memcpy(&value, buf, sizeof(value));
                row[x]=value;
                j++;        
                   
            }
            rowPtr[y]=row;
        }
        slices.push_back(rowPtr);   
    }
    // cout << endl << "Total count: " << j << endl<<endl; 
};


void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix){
    using namespace std;
    ofstream binaryFile ("../bin/"+output_prefix+".raw", ios::out | ios::binary);

    if(!binaryFile)
    {
        cout<<"Failed to generate output file, check that bin file exists."<<endl;
    }

        cout<<"Creating difference map"<<endl;
    
    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
        {
            unsigned char newChar = (unsigned char)(abs((float)slices.at(sliceI)[y][x] - (float)slices.at(sliceJ)[y][x])/2);
            binaryFile.write ((char*)&newChar, sizeof (newChar));
        }
        
    }
    binaryFile.close();
};

void VolImage::extract(int sliceId, std::string output_prefix){
    using namespace std;
    ofstream binaryFile ("../bin/"+output_prefix+".raw", ios::out | ios::binary);

    if(!binaryFile)
    {
        cout<<"Failed to generate output file, check that bin file exists."<<endl;
    }

    cout<<"Extracting raw file"<<endl;

    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
        {
            binaryFile.write ((char*)&slices.at(sliceId)[y][x], sizeof (unsigned char));
        }
    }
    binaryFile.close();
}

void VolImage::slice(int row,std::string output_prefix){
    using namespace std;
    ofstream binaryFile ("../bin/"+output_prefix+".raw", ios::out | ios::binary);

    if(!binaryFile)
    {
        cout<<"Failed to generate output file, check that bin file exists."<<endl;
    }

    cout<<"Extracting top row from each slice"<<endl;

    for (size_t y = 0; y < slices.size(); y++)
    {
        for (size_t x = 0; x < width; x++)
        {
            binaryFile.write ((char*)&slices.at(y)[row][x], sizeof (unsigned char));
        }
    }
    binaryFile.close();
}

 int VolImage::volImageSize(void){
    using namespace std;    
    int bytes=sizeof(unsigned char [width])*height*slices.size();
    bytes+=sizeof(unsigned char *)*height*slices.size();
    bytes+=sizeof(unsigned char *[height])*slices.size();
    bytes+=sizeof(char **)*slices.size();
    return bytes;
 };
