//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below



#include "GroupList.h"

GroupList::GroupList(){
    head=nullptr;
}

GroupList::~GroupList(){
    GroupNode* ptr;
    while(head!=nullptr){
        ptr=head; 
        head=ptr->getNext();
        ptr->~GroupNode();
        delete ptr; 
    }
    
}

GroupNode* GroupList::getHead() const{
    return head; 
}

void GroupList::setHead(GroupNode* ptr){
    head=ptr; 
}

void GroupList::insert(GroupNode* s){
    if(head==nullptr){
        head=s;
        s->setNext(nullptr);
        return;
        
    }else{
        GroupNode* tptr = head; 
        while(tptr!=nullptr){
            if(tptr->getNext()==nullptr){
                tptr->setNext(s);
                s->setNext(nullptr);
                return;
            }
            tptr=tptr->getNext();  
    }
        
        }
    
}

GroupNode* GroupList::remove(string name){
    if(head==NULL) return nullptr;
    GroupNode* tptr=head;
    GroupNode* pptr=NULL;
    while(tptr!=NULL){
        if(tptr->getName()==name)break;
        pptr=tptr;
        tptr=tptr->getNext();
    }
    if(tptr==NULL) return nullptr; 
    if(tptr==head){
        head=head->getNext();
        //delete tptr;
        return tptr;   
    }
    pptr->setNext(tptr->getNext());
    return tptr; 
}


void GroupList::print() const{
    GroupNode* printer = head;
    while(printer!=nullptr){
        printer->print();
        printer = printer->getNext();
    }    
    
}
