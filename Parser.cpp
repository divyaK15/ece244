//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itself must be allocated
GroupList* gList;
//GroupNode* poolGroup;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
void shape(stringstream &userInput);
void group(stringstream &userInput);
void draw(stringstream &userInput);
void move(stringstream &userInput);
void deleteing(stringstream &userInput);
bool validShapeName(string validName);
bool existingName(string name);
bool shapeNameFound(string nameOfShape);
bool groupNameFound(string groupName);

int main() {
    // Create the groups list
    gList = new GroupList();
    
    // Create the pool group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup);
    
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
        if(command==keyWordsList[0]){
                shape(lineStream);
        }
        else if(command==keyWordsList[1]){
            group(lineStream);
        }
        else if(command==keyWordsList[2]){
            move(lineStream);
        }
        else if(command==keyWordsList[3]){
                deleteing(lineStream);
        }
        else if(command==keyWordsList[4]){
            draw(lineStream);
        }

        else{
            cout << "error: invalid command" << endl;;
        }
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

void shape (stringstream &userInput){

   
    string shapeName; 
    string shapeType;
    int xLocation;
    int yLocation; 
    int xSize;
    int ySize;
    
    userInput >> shapeName;


    //------------------------------------error checking for the shapeName 
    if(validShapeName(shapeName)==false){
        cout << "error: invalid name" <<endl;
        return;     
    }
    if(existingName(shapeName)==true){
        cout << "error: name " << shapeName << " exists" << endl; 
        return; 
    }
    
    if(groupNameFound(shapeName)==true){
        cout <<"error: name " << shapeName <<" exists" <<endl;
        return;
    }

    userInput >> shapeType;
    userInput >> xLocation; 
    userInput >> yLocation;
    userInput >> xSize;
    userInput >> ySize;

    ShapeNode* newShape = new ShapeNode();
    newShape->setShape(new Shape (shapeName,shapeType,xLocation,yLocation,xSize,ySize));
    gList->getHead()->getShapeList()->insert(newShape);
    newShape->setNext(nullptr);
    cout << shapeName << ": " << shapeType << " "<< xLocation << " " << yLocation <<" "<< xSize << " " << ySize << endl; 
    
    
}

   

void group(stringstream &userInput){
    string groupName; 
    
    userInput >> groupName; 
    
    if(validShapeName(groupName)==false){
        cout << "error: invalid name" <<endl;
        return;     
    }
    
    if(existingName(groupName)==true){
        cout <<"error: name " <<groupName <<" exists" <<endl;
        return;
    }
    
    if(groupNameFound(groupName)==true){
        cout << "error: name "<<groupName<<" exists"<<endl;
    }
    else{ 
        GroupNode* newGroup = new GroupNode(groupName);
        gList->insert(newGroup);
        cout << groupName << ": group" <<endl; 
    }
    
    
}

void move(stringstream &userInput){
    string shapeName;
    string shapeType;
    int xLocation;
    int yLocation; 
    int xSize;
    int ySize;
    string toGroup;
    
    userInput >> shapeName; 
    userInput >> toGroup; 
    

    
    if(existingName(shapeName)==false){
        cout << "shape " << shapeName << " not found" << endl; 
        return;
    }
    
    if(groupNameFound(toGroup)==false){
        cout <<"error: group "<<toGroup <<" not found"<<endl;
        return; 
    }
     
    GroupNode* ok = gList->getHead();
    while(ok!=nullptr){
        if( (ok->getShapeList()->find(shapeName))!=nullptr){
            break;
        }
        ok = ok->getNext();
    }


    
    GroupNode* tptr = gList->getHead();
    while(tptr!=nullptr){
        if((tptr->getName())==toGroup){ 
            break;
        }
       tptr=tptr->getNext();
    }

    
    
    ShapeNode* pointing = ok->getShapeList()->remove(shapeName);
    tptr->getShapeList()->insert(pointing);
    pointing->setNext(nullptr);
    cout << "moved " << shapeName << " to " << toGroup << endl;

    
}

void deleteing(stringstream &userInput){
    
    string whatToDelete; 
    userInput >> whatToDelete; 
    
    
    if(validShapeName(whatToDelete)==false){
        cout << "error: invalid name" << endl;
        return; 
    }
    
    GroupNode* tptr = gList->getHead();
    
    if(groupNameFound(whatToDelete)==true){
        GroupNode* tptr = gList->getHead();
            while(tptr!=nullptr){
            if((tptr->getName())==whatToDelete){
                gList->remove(whatToDelete);
                break; 
             }
              tptr=tptr->getNext();
    }  
    ShapeNode* list = tptr->getShapeList()->getHead();
    gList->getHead()->getShapeList()->insert(list);
    tptr->getShapeList()->setHead(nullptr);
    gList->remove(whatToDelete);
    delete tptr;
    cout << whatToDelete <<": deleted" << endl; 
    return;    
    }
    
    

    if(existingName(whatToDelete)==true){
        GroupNode* ok = gList->getHead();
        while(ok!=nullptr){
        if( (ok->getShapeList()->find(whatToDelete))!=nullptr){
            break;
        }
        ok = ok->getNext();
    }
        
        GroupNode* naming = ok;
        ShapeNode* cool = naming->getShapeList()->getHead();
        while(naming!=nullptr){
            while(cool!=nullptr){
                if(cool->getShape()->getName()==whatToDelete){
                    naming->getShapeList()->remove(whatToDelete);
                    break;
                }
                cool=cool->getNext();
                
            }
            naming=naming->getNext();
            
        }
        delete cool; 
        cout << whatToDelete << ": deleted" <<endl;
     
        
    }
    else if(existingName(whatToDelete)==false){
        cout << "error: shape "<< whatToDelete <<"not found" <<endl; 
        return;
    }


}

void draw(stringstream &userInput){
    
    cout << "drawing:" << endl; 
    gList->print();
    
}

bool validShapeName(string validName){ 
        for(int i=0; i<6; i++){
        if(validName==keyWordsList[i]){
            return false; 
           
        }
    }
    for(int i=0;i<3;i++){
        if(validName==shapeTypesList[i]){
            return false;
        }
    }
    return true; 
}

bool existingName(string validName){
    GroupNode* tptr = gList->getHead();
    while(tptr!=nullptr){
        if( (tptr->getShapeList()->find(validName))!=nullptr){
            return true;
        }
        tptr = tptr->getNext();
    }
    return false;
   
}

bool shapeNameFound(string nameOfShape){
    int location; 
    GroupNode* tptr = gList->getHead();
    while(tptr!=nullptr){
        if((tptr->getShapeList()->find(nameOfShape))!=nullptr){
            return false; 
        }
        tptr=tptr->getNext();
    }
    return false; 
}

bool groupNameFound(string groupName){
    GroupNode* tptr = gList->getHead();
    while(tptr!=nullptr){
        if((tptr->getName())==groupName){ 
            return true;
        }
       tptr=tptr->getNext();
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
