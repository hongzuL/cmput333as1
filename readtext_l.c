#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const int length = 10000000;
int output_l = 0;
int map_l = 0;
int plain_l = 0;
int key_l = 0;
string map[16][16];
vector<int> possible_key;

// Read from data.txt, and form an array
void ReadDataWBW(string *output)
{
    ifstream fin("data.txt");           // read file
    string s;
    int i = 0;
    // put all data in to array
    while (fin >> s) {                  // input data to string s
        if (s.size() == 2 ){
                output[i] = s;
                i++;
        }
    }
    output_l = i;                       // store the length of array
    // doing printing job, DELETE AFTER THIS PART IS DONE
    for(int n=0;n<i;n++){
    }
}

// Read from from map.txt, and form an 2d array
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

// return a 
void possibleKey(vector<int> arrayA, vector<int> arrayB) {
    int l=0;
    for(int a=0;a<arrayA.size();a++) {
        for(int b=0;b<arrayB.size();b++){
            if(arrayA[a]==arrayB[b]){
                if(inOrout(arrayA[a], possible_key)==1){
                    possible_key[l] = arrayA[a];
                    l++;
                }                
            }
        }    
    }
}

// check if the elements in this vector already
int inOrnot(int element, vector<int> arrayv){
    int flag = 1;
    if(arrayv.size()==0) {continue;}
    else {
        for(int p=0;p<arrayv.size();p++){
            if(arrayv[p] == element) {
                flag = 0;
            }
        }
    }
    return flag;
}

int main(){
    string *output= new string[length];
    ReadDataWBW(output);
    ReadMap();
    delete [] output;
    return 0;
}
