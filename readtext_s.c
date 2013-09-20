#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

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

// check if the elements in this vector already
int inOrnot(int element, vector<int> arrayv){
    int flag = 1;
    if((int)arrayv.size()==0) {return flag;}
    else {
        for(int p=0;p<(int)arrayv.size();p++){
            if(arrayv[p] == element) {
                flag = 0;
            }
        }
    }
    return flag;
}
// check if the key is satified for the quesiton
// 0 means yes 1 means no;
int Key_satis(int dec_num){
    if (dec_num > 47 & dec_num < 58){
        return 0;    
    }
    if (dec_num > 64 & dec_num < 91){
        return 0;
    }
    if (dec_num >96 & dec_num < 123){
        return 0;
    }
    return 1;
}
// Read the Data from the data.txt file 
void ReadDataWBW()
{
    ifstream fin("data.txt");
    string s;
    int i = 0;
    while (fin >> s) {
        if (s.size() == 2 ){
                output[i] = s;
                ciphertext_data[i][0]=output[i][0];
                ciphertext_data[i][1]=output[i][1];
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

    // put all value in to 2d array
    while (fi >> m) {                   // input data to string m
        if(n<16) {
            map[t][n] = m[2];
            n++;
        }
        else {
            t++;
            map[t][0] = m[2];
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
    //int* ph = new int[16];
    //int* kl = new int[16];
    //int* pl = new int[16];
    //int* kh = new int[16];
    vector<int> ph;
    vector<int> kl;
    vector<int> pl;
    vector<int> kh;
    vector<int> possiblekey;
    vector<int> possiblekey_tmp;
    vector<int> abosultkey;
    //for (int i=0;i<count_number;i+=8){
    for (int i=0;i<count_number;i+=8){
        for (int p = 0;  p<16; p++){
            for (int k = 0;  k<16; k++) {
                if (map[p][k]==ciphertext_data[i][0]){
                    ph.push_back(p);
                    kl.push_back(k);
                }
                if (map[p][k]==ciphertext_data[i][1]){
                    pl.push_back(p);
                    kh.push_back(k);
                }
            }
        }
        //now we get all the combination of ph kl pl kh
        //here we need to check the whether phpl is printable
        //cout << "size(ph)"<< ph.size()<< endl;
        for (int phi=0; phi < (int)ph.size() ; phi++){
            for (int pli=0; pli < (int)pl.size() ; pli++){
                if (CheckPrintable(ph[phi]*16+pl[pli])==1){
                    int Doc_Num = 0;
                    Doc_Num = kh[pli]*16+kl[phi];
                    if (Key_satis(Doc_Num)==0){
                        if (i>7){
                            if (inOrnot(Doc_Num,possiblekey)==0 & inOrnot(Doc_Num,possiblekey_tmp)==1){
                                possiblekey_tmp.push_back(Doc_Num);
                                cout << "test here" << possiblekey_tmp.size()<<endl;
                            }
                        }
                        else{
                            if(inOrnot(Doc_Num,possiblekey_tmp)==1){
                                possiblekey_tmp.push_back(Doc_Num);
                            }
                        }
                    }
                } 
            }
        }
        if ((int)possiblekey.size()==0){
            possiblekey = possiblekey_tmp;
            possiblekey_tmp.clear();
            cout << possiblekey.size() <<endl;
        }
        else{
            possiblekey.clear();
            possiblekey = possiblekey_tmp;
            possiblekey_tmp.clear();
        }
        ph.clear();
        pl.clear();
        kl.clear();
        kh.clear();
        //here is the test for print all the possiblekey_tmp of the first cipherteit
       // int size = possiblekey_tmp.size();
    }
    for (int counter = 0 ; counter< (int)possiblekey.size();counter++){
            cout << "PoosibiltK===: "<< findASCII(possiblekey[counter]) << endl;
    }

}
        //now we get all the possiblekey of the n ciphertext element

                    
int main(){
   ReadDataWBW();  
   ReadMap();
   SearchTable();
   return 0;
}

