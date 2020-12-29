//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below


//#include "Shape.h"
//#include "ShapeNode.h"
#include "ShapeList.h"


ShapeList::ShapeList(){
    head=nullptr;
}

ShapeList::~ShapeList(){
    ShapeNode* ptr; 
    while(head != nullptr){
        ptr=head; 
        head = ptr->getNext();
        ptr->~ShapeNode();
        delete ptr; 
    }
}

ShapeNode* ShapeList::getHead() const{
    return head; 
}

void ShapeList::setHead(ShapeNode* ptr){
    head=ptr; 
}

ShapeNode* ShapeList::find(string name) const{
    
    ShapeNode* tptr = head;
    while(tptr!=nullptr){
        if(tptr->getShape()->getName()==name){
            return tptr;
        }
        tptr=tptr->getNext();
    }
    return nullptr;
  }


void ShapeList::insert(ShapeNode* s){
    if(head==nullptr){
        head=s;
        //s->setNext(nullptr);
    }else{
        ShapeNode* tptr = head; 
        while(tptr!=nullptr){
            if(tptr->getNext()==nullptr){
                tptr->setNext(s);
               //s->setNext(nullptr);
                return;
            }
            tptr=tptr->getNext();  
    }
        
        }
}
    

ShapeNode* ShapeList::remove(string name){
    if(head==NULL){
        return nullptr; 
    }
    ShapeNode* tptr = head;
    ShapeNode* pptr = NULL;
    while(tptr!=NULL){
        if(tptr->getShape()->getName()==name){
            break;
        }
        pptr=tptr;
        tptr=tptr->getNext();
    }
    if (tptr==NULL){
        return nullptr; 
    }
    if(tptr==head){
        head=head->getNext();
        return tptr;
    }
    pptr->setNext(tptr->getNext());
    return tptr;
    
}

void ShapeList::print() const{
    ShapeNode* test = head; 
    while (test!=nullptr){
        test->print();
        test = test->getNext();
    }
    
}