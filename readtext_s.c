#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

#define MAX_LEGTH 1000
using namespace std;
//set globle value
//count_number means the value of the ciphertext 
int count_number=0;
string *output = new string[MAX_LEGTH];
string ciphertext_data[MAX_LEGTH][2];
string map[16][16];
int output_l = 0;
int map_l = 0;
int plain_l = 0;
int key_l = 0;

int size(int arr1[])
{   
    int size;
    size = sizeof(arr1)/sizeof(arr1[0]);
    return size;
}
void ReadDataWBW()
{
    ifstream fin("data.txt");
    string s;
    int i = 0;
    while (fin >> s) {
        if (s.size() == 2 ){
                output[i] = s;
                ciphertext_data[i][0]=output[0];
                ciphertext_data[i][1]=output[1];
                i++;
        }
    }
    count_number = i;
    delete [] output;
}

void ReadMap() {
    ifstream fi("map.txt");             // read file
    string m;
    int t = 0;
    int n = 0;
    long x;
    // put all value in to 2d array
    while (fi >> m) {                   // input data to string m
        if(n<16) {
            map[t][n] = m;
            n++;
        }
        else {
            t++;
            map[t][0] = m;
            n=1;    
        }                      
    }
    map_l = t;                          // store length of 2d array
    // do the printing job, DELETE AFTER THIS PART IS DONE
    for(int r = 0; r<=t; r++) {
        for(int r1=0;r1<16;r1++) {
        }
    }
}

void GetplainText(){ 
    return;
}

// find the corresponding asscii
char findASCII(int dec_num) {
    char ascii = (char)dec_num;         // convert decimal number to ascii
    return ascii;
}

// check if the asscii is printable
int CheckPrintable(int dec_num) {
    if(dec_num >= 0 & dec_num <=31) {return 0;} // check if the decimal number is in [0,31]
    else {return 1;}   
}

void SearchTable(){
    int* ph = new int[16];
    int* kl = new int[16];
    int* pl = new int[16];
    int* kh = new int[16];
    vector<int> possiblekey;
    vector<int> possiblekey_tmp;
    vector<int> abosultkey;
    //a is the ph kl counter
    //b is the pl kh counter
    int a = 0;
    int b = 0;
    //for (int i=0;i<count_number;i+=8){
    for (int i=0;i<1;i+=8){
        for (int p = 0;  p<16; p++){
            for (int k = 0;  p<16; k++) {
                if (map[p][k]==ciphertext_data[i][0]){
                    // here we got the map ph k by ch and save them
                    ph[a] = p;
                    kl[a] = k;
                    a++;
                   
                }
                if (map[p][k]==ciphertext_data[i][1]){
                    pl[b] = p;
                    kh[b] = k;
                    b++;
                }
            }
        }
         cout << possiblekey_tmp[i]<<"Test1 here"<< endl;

        //now we get all the combination of ph kl pl kh
        //here we need to check the whether phpl is printable
        for (int phi=0; phi < size(ph) ; phi++){
            for (int pli=0; pli < size(pl) ; pli++){
                if (CheckPrintable(ph[phi]*16+pl[pli])==1){
                            possiblekey_tmp.push_back(kh[phi]*16+kl[pli]);                            
                } 
            }
        }
        //here is the test for print all the possiblekey_tmp of the first ciphertext
        for (int i = 0 ; i< possiblekey_tmp.size();i++){
            cout << possiblekey_tmp[i]<<"Test1 here"<< endl;
        }
    }
    delete [] ph;
    delete [] pl;
    delete [] kl;
    delete [] kh;
}
        //now we get all the possiblekey of the n ciphertext element

                    
int main(){
    ReadDataWBW();
    //for(int n=0;n<count_number;n++){
    //    cout << "higher bit:" << output[n][0] << "\t lower bit" << output[n][1] << endl;
    //}
   // delete [] map;
   ReadMap();
   SearchTable();
   return 0;
}

