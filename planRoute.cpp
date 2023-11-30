// <zianren> 
// <wpinto> 
// <034,014> 
// <Date Submitted>

//------------------------------------------------------
// AUTOGRADER INFO -- IGNORE BUT DO NOT REMOVE 
// test_cases: true
// feedback('all')
// 35b24e49-2842-4603-8ba7-0f656200c2d1
//------------------------------------------------------

// Add your code here!




#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <functional>
#include <string>

using namespace std;
 //Function to fix data corruption
    void fix_string(string &Planet_name){
        int index_XX = Planet_name.find("XX");
        int index_ = Planet_name.find("_");

        //erases XX from string
        if (index_XX != string::npos) {
            Planet_name.erase(index_XX,2);
        }
        //replace _ with space
        if (index_ != string::npos) {
            Planet_name.replace(index_, 1," ");
        }
    }    

    //


int main(){
    struct Planet {
        int Planet_row;
        int Planet_column;
        string Planet_symbol;
        int Planet_ID;
    };
    Planet default_planet = {0,0,"a",0};
    struct Planet_names {
        int Planet_ID;
        string Planet_name;
    };
   
    //Prompt user for filename (tested, working)
    string Location;
    string Name;

    cout << "Enter Locations Filename: ";
    cin >> Location;
    cout << "Enter Names Filename: ";
    cin >> Name;
    //

    //Read in location and names files
    ifstream Locations_file (Location);
    ifstream Name_file (Name);
    if (! Locations_file.is_open() || !Name_file.is_open()){
        cout << "Input file could not be opened";
        cout << "" << endl;
        return 1;
    }
    //


    //testcase cout every vector in Planet and Planet_names

    

    //Reading in data from the files
    int Range_row;
    int Range_column;
    int Start_row;
    int Start_column;
    int End_row;
    int End_column;

    int Planet_row;
    int Planet_column;
    string Planet_symbol;
    int Planet_ID;

    Locations_file >> Range_row >> Range_column;
    Locations_file >> Start_row >> Start_column;
    Locations_file >> End_row >> End_column;
    vector <Planet> Planet_vector;
    Planet planet;

    //cout << Range_row << " " << Range_column;

    while (Locations_file >> planet.Planet_row >> planet.Planet_column >> planet.Planet_symbol >> planet.Planet_ID ) {
        Planet_vector.push_back(planet);
    }
    //tested by test case

    Planet_names planet_name;
    vector <Planet_names> Planet_names_vector;
    while (Name_file >> planet_name.Planet_ID >> planet_name.Planet_name){
        Planet_names_vector.push_back(planet_name);
    }
    //tested by test case

    // test case to print out the vectors of planets and planet names


    //for(size_t i = 0; i<Planet_vector.size();++i){
    //    cout << Planet_vector.at(i).Planet_row << " " << Planet_vector.at(i).Planet_column << " " << Planet_vector.at(i).Planet_symbol << " " << Planet_vector.at(i).Planet_ID <<endl;
    //}

    //for(size_t i = 0; i<Planet_names_vector.size();++i){
    //    cout << Planet_names_vector.at(i).Planet_ID << " " << Planet_names_vector.at(i).Planet_name <<endl;
    //}

    //check each planet in file to see if out of range
    for(size_t i = 0;i<Planet_vector.size();++i){
        if(Planet_vector.at(i).Planet_row > Range_row || Planet_vector.at(i).Planet_column > Range_column || Planet_vector.at(i).Planet_row < 1 || Planet_vector.at(i).Planet_column < 1 ){
            cout << Planet_vector.at(i).Planet_ID << " " << "out of range - ignoring"<<endl;
            //erase that planet from planet_vector - look to recent lab for example
            Planet_vector.erase(Planet_vector.begin()+ i);
            --i;

        }   
    }
            

    







}