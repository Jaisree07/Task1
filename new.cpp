#include <iostream> 
#include <fstream>
using namespace std;

//initialization
void init(ifstream &infile1){
    
    if(infile1.is_open())
    {
        infile1.seekg(0,ios::end);
        cout<<"File1 opened\n";
        if(infile1.tellg()==0)
        {
           // cout<<file1.tellg();
            cout<<"File1 is empty"<<endl;
            infile1.close();
            exit(0);
        } 
        else{
            cout<<"Data is present"<<endl;
             infile1.seekg(0,ios::beg);
        }  
    }
    else
    {
        cout<<"File1 does not exist"<<endl;
        exit(0);
    }
}

void process(ifstream &file1,fstream &file2){
    string line;
    ifstream checkfile2("file2.csv");
    if(!file2.is_open())
    {
        cout<<"File2 is not found"<<endl;
        cout<<"File2 is created"<<endl;
        file2.open("file2.csv", ios::out);
        while(getline(file1,line))
            file2<<line<<endl;
        cout<<"File2 is copied"<<endl;
        file2.close();
    }
    else{
        //fstream file2("file2.csv", ios::in | ios::out);
        file2.seekg(ios::end);
        if (checkfile2.tellg() == 0) {
            cout << "File2 is empty" << endl;
            checkfile2.close();
            file2.open("file2.csv",ios::out);
            file2.seekp(0, ios::beg);
            file1.clear();
            file1.seekg(0, ios::beg);
            while (getline(file1, line))
                file2 << line << endl;
            cout << "File2 is copied" << endl;
    }
    else{
        cout<<"File2 has data"<<endl;
        cout<<"Clear the data"<<endl;
        checkfile2.close();
        file2.open("file2.csv",ios::in|ios::trunc);
        cout<<"File2 is cleared"<<endl;
    }
}
    // if(file2.is_open())
    // {
    //    // cout<<"File2 already exists\n";
       
    //     file2.seekg(0,ios::end);
    //     if(file2.tellg()==0){
    //           cout<<"File2 is empty"<<endl; //in this case copy 1 to 2
    //         while(getline(file1,line))
    //         file2<<line<<endl;
    //     cout<<"File2 is copied"<<endl;
    //     }  
    //     else{
    //         ifstream secfile("file2.csv",ios::trunc);
    //         // check
    //        //if(secfile.tellg() == 0){
    //             cout << "File data cleared"; 
    //        // }
    //     }
    // }
    // else{
    //     cout<<"File2 is not found"<<endl;
    //     cout<<"File2 is created"<<endl;
    //     fstream file2("file2.csv", ios::out);
    //     while(getline(file1,line))
    //         file2<<line<<endl;
    //     cout<<"File2 copied"<<endl;
    // }

    file1.close();
    file2.close();
}

int main() { 
    // string file1="file1.csv";
    // string file2="file2.csv";
    // ifstream file1("file1.csv");

    // Initialization
    ifstream file1("file1.csv");
    init(file1);
    // if(file1.is_open())
    // {
    //     file1.seekg(0,ios::end);
    //     cout<<"File1 opened\n";
    //     if(file1.tellg()==0)
    //     {
    //        // cout<<file1.tellg();
    //         cout<<"File1 is empty"<<endl;
    //         file1.close();
    //         exit(0);
    //     } 
    //     else{
    //         cout<<"Data is present"<<endl;
    //          file1.seekg(0,ios::beg);
    //     }  
    // }
    // else
    // {
    //     cout<<"File1 does not exist"<<endl;
    //     //exit(0);
    // }
    
    // Processs

    fstream file2("file2.csv",ios::out);
    process(file1,file2);
    // string line;
    // if(file2.is_open())
    // {
    //    // cout<<"File2 already exists\n";
    //     file2.seekg(0,ios::end);
    //     if(file2.tellg()==0){
    //           cout<<"File2 is empty"<<endl; //in this case copy 1 to 2
    //         while(getline(file1,line))
    //         file2<<line<<endl;
    //     cout<<"File2 is copied"<<endl;
    //     }  
    // }
    // else{
    //     cout<<"File2 is not found"<<endl;
    //     ofstream file2("file2.csv");
    //     cout<<"File2 is created"<<endl;
    //     while(getline(file1,line))
    //         file2<<line<<endl;
    //     cout<<"File2 is copied"<<endl;
    // }

    //truncate
    
    //trunc(file2);
}