//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>
#include <valarray>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;



// ECE244 Student: you may want to add the prototype of
// helper functions you write here

void maxShapes(stringstream &userInput);//
void create(stringstream &userInput);
void move(stringstream &userInput);
void rotate(stringstream &userInput);
void drawing(stringstream &userInput);
void deleting(stringstream &userInput);
bool validShapeName(string validName); 
bool existingShapeName(string nameOfShape);//
bool validType(string validType);//
bool invalidAngle(int angle);//
bool invalidFoundShape(string nameOfShape);//
bool invalidArgument(stringstream &userInput);//

int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        if(command==keyWordsList[1]){
                maxShapes(lineStream);
        }
        else if(command==keyWordsList[2]){
            create(lineStream);
        }
        else if(command==keyWordsList[3]){
                move(lineStream);
        }
        else if(command==keyWordsList[4]){
            rotate(lineStream);
        }
        else if(command==keyWordsList[5]){
            drawing(lineStream);
        }
        else if(command==keyWordsList[6]){
            deleting(lineStream);
        }
        else{
            cout << "Error: invalid command" << endl;;
        }
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}


void maxShapes(stringstream &userInput){
    userInput >> max_shapes; 
    
    if(invalidArgument(userInput)==true){
        return;
    }
    //checks for too many arguments 
    if(userInput.eof()== false){
        cout << "Error: too many arguments"<<endl;
        return; 
    }
    
    for(int i=0; i<shapeCount;i++){
        delete shapesArray[i];
        shapesArray[i]=NULL;
    }
    delete [] shapesArray;
    shapesArray=nullptr;
    shapeCount=0; 
 
    
    
    shapesArray = new Shape*[max_shapes];
    for(int j=0;j< max_shapes;j++){
        shapesArray[j]=NULL; 
    } 
    
    cout <<"New database: max shapes is "<< max_shapes <<endl; 
}

bool validShapeName(string validName){
    for(int i=0; i<7; i++){
        if(validName==keyWordsList[i]){
            return false;
           
        }
    }
    for(int i=0;i<4;i++){
        if(validName==shapeTypesList[i]){
            return false;
        }
    }
    return true; 
}

bool existingShapeName(string nameOfShape){
    for(int i=0; i<=max_shapes; i++){
        if(shapesArray[i]!=NULL && nameOfShape == shapesArray[i]->getName()){
            return true;   
        }
    }
    return false; 
}

bool validType(string validType){
    for(int i=0; i<=4; i++){
        if(validType==shapeTypesList[i]){
            return true;   
        }
    }
    return false;
}


bool invalidAngle(int angle){
    if(angle>=0 && angle<=360){
        return false;    
    }
    return true; 
}

bool invalidFoundShape(string nameOfShape){
    for(int i=0; i<max_shapes; i++){
        if(shapesArray[i]!= NULL && nameOfShape == shapesArray[i]->getName()){
            return true; 
        }
    }
    return false;
}



bool invalidArgument(stringstream &userInput){
    if(userInput.fail() && userInput.eof()==true){
            cout << "Error: too few arguments"<<endl; 
            return true;
        }else if(userInput.fail()==true){
            cout <<"Error: invalid argument" <<endl; 
            return true;
        }
        else{
            return false;
        }
    }


void create(stringstream &userInput){
    string shapeName; 
    string shapeType;
    int xLocation;
    int yLocation; 
    int xSize;
    int ySize;
    
    userInput >> shapeName;

    //------------------------------------error checking for the shapeName 
    if(validShapeName(shapeName)==false){
        cout << "Error: invalid shape name" <<endl;
        return;     
    }
    if(existingShapeName(shapeName)==true){
        cout << "Error: shape " << shapeName << " exists" << endl; 
        return; 
    }

    
    //-----------------------------------error checking for the shape type
    userInput >> shapeType;
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(validType(shapeType)==false){
       cout <<"Error: invalid shape type" <<endl;
       return;
    }
    
    //------------------------------------error checking for x and y location 
    userInput >> xLocation; 
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(xLocation<0){
        cout <<"Error: invalid value"<<endl;
       return; 
    }
    
    userInput >> yLocation;
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(yLocation<0){
         cout <<"Error: invalid value"<<endl;
        return;
    }

    
    //-------------------------------------error checking for x and y size
    userInput >> xSize;
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(xSize<0){
         cout <<"Error: invalid value"<<endl;
        return;
    }
    
    userInput >> ySize; 
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(ySize<0){
         cout <<"Error: invalid value"<<endl;
        return; 
    }
    
    if(shapeType=="circle"){
        if(xSize!=ySize){
             cout <<"Error: invalid value"<<endl;
            return;
        }
    }
    
    
    //-----------------------------------------------error checking if shape array is full 
    
    //checks for too many arguments 
    if(userInput.eof()== false){
        cout << "Error: too many arguments"<<endl;
        return; 
    }
    
    
    if(shapeCount >= max_shapes){
        cout <<"Error: shape array is full" << endl;
        return;
    }
    
    
    
    shapesArray[shapeCount] = new Shape(shapeName, shapeType, xLocation, xSize, yLocation, ySize);
    
    cout << "Created " << shapeName <<": "<<shapeType<<" "<<xLocation<<" "<<yLocation<<" "<<xSize<<" "<<ySize<<endl;
    shapeCount++;
}

void move(stringstream &userInput){
    int previousLocation; 
    int xLocation,yLocation,xSize; 
    string shapeName; 
    
    //--------------------------------checks if shape Name exists 
    userInput >> shapeName;
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(invalidFoundShape(shapeName)== true){
      for(int i=0; i<max_shapes; i++){
        if(shapesArray[i]!= NULL && shapeName == shapesArray[i]->getName()){
            previousLocation=i; 
        }
    }  
    }else if(invalidFoundShape(shapeName)==false){
        cout << "Error: shape "<< shapeName<<" not found" <<endl;
        return;    
    }

    
    //------------------------------------error checking for x and y location 
    userInput >> xLocation; 
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(xLocation<0){
        cout <<"Error: invalid value"<<endl;
       return; 
    }
    
    userInput >> yLocation;
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(yLocation<0){
         cout <<"Error: invalid value"<<endl;
        return;
    } 
    //checks for too many arguments 
    if(userInput.eof()== false){
        cout << "Error: too many arguments"<<endl;
        return; 
    }
    
    shapesArray[previousLocation]->setXlocation(xLocation);
    shapesArray[previousLocation]->setYlocation(yLocation);
    
    cout << "Moved " << shapeName <<" to "<< xLocation << " " << yLocation << endl; 
    
}

void rotate(stringstream &userInput){
    string shapeName;
    int angle;
    int previousLocation; 
    
    //--------------------------------checks if shape Name exists 
    userInput >> shapeName; 
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if(invalidFoundShape(shapeName)== true){
      for(int i=0; i<max_shapes; i++){
        if(shapesArray[i]!= NULL && shapeName == shapesArray[i]->getName()){
            previousLocation=i; 
        }
    }  
    }else if(invalidFoundShape(shapeName)==false){
        cout << "Error: shape "<<shapeName<<" not found" <<endl;
        return;    
    }
    //----------------------------------read in the angle and check if valid
    
    userInput >> angle; 
    if(invalidAngle(angle)!=false){
          cout <<"Error: invalid value"<<endl;
         return; 
    }
    
    if(invalidArgument(userInput)==true){
        return;
    }
    //checks for too many arguments 
    if(userInput.eof()== false){
        cout << "Error: too many arguments"<<endl;
        return; 
    }
    
    
    shapesArray[previousLocation]->setRotate(angle);
    cout <<"Rotated "<< shapeName <<" by "<< angle << " degrees" <<endl;
    
}

void drawing(stringstream &userInput){
    string shapeName; 
    int location;
    
    
    userInput >> shapeName; 
    
    
    
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if((shapeName!="all") && (invalidFoundShape(shapeName)==false)){
        cout << "Error: shape "<< shapeName<<" not found" <<endl;
        return;
    }
    //checks for too many arguments 
    if(userInput.eof()== false){
        cout << "Error: too many arguments"<<endl;
        return; 
    }

    
    if(shapeName == "all"){
       cout << "Drew all shapes" << endl; 
        for(int i=0; i<max_shapes; i++){
            if(shapesArray[i]!=NULL){
                shapesArray[i]->draw();
            }
        }
    }
    else{
    
    if(invalidFoundShape(shapeName)== true){
      for(int i=0; i<max_shapes; i++){
        if(shapesArray[i]!= NULL && shapeName == shapesArray[i]->getName()){
            location=i; 
            cout << "Drew ";
            shapesArray[location]->draw();
        } 
        
    }  
    }else if(invalidFoundShape(shapeName)==false){
        cout << "Error: shape "<< shapeName<<" not found" <<endl;
        return;    
    }
    }
    return;
    
    
}

void deleting (stringstream &userInput){
    string shapeName;
    int location; 
    
    userInput >> shapeName;
    
     
    if(invalidArgument(userInput)==true){
        return;
    }
    
    if((shapeName!="all") && (invalidFoundShape(shapeName)==false)){
        cout << "Error: shape "<< shapeName<<" not found" <<endl;
        return;
    }
    //checks for too many arguments 
    if(userInput.eof()== false){
        cout << "Error: too many arguments"<<endl;
        return; 
    }

    if(shapeName == "all"){
        cout << "Deleted: all shapes" <<endl;
        for(int i=0; i<max_shapes; i++){
            if(shapesArray[i]!=NULL){
                delete shapesArray[i];
                shapesArray[i]=NULL;
            }
        }
        return; 
    }
    else{
    
    if(invalidFoundShape(shapeName)== true){
      for(int i=0; i<max_shapes; i++){
        if(shapesArray[i]!= NULL && shapeName == shapesArray[i]->getName()){
            location=i; 
            delete shapesArray[i];
            shapesArray[location]=NULL;
            cout << "Deleted shape " << shapeName <<endl;
        } 
        
    }
      return; 
    }else{
        cout << "Error: shape "<< shapeName<<" not found" <<endl;
        return;    
    }
    }
    
}
