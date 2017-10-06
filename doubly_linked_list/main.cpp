//
//  main.cpp
//  doubly_linked_list
//
//  Created by 村上候助 on 2017/10/05.
//  Copyright © 2017 村上候助. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>




using namespace std;

struct Node{
    int key;
    Node *prev, *next;
};

Node *nil;

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil -> next = nil;
    nil -> prev = nil;
}

void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

Node* listSearch(int key){
    Node *cur = nil->next;
    while( cur != nil && cur-> key != key){
        cur = cur->next;
    }
    return cur;
}

void deleteNode(Node *t){
    t->prev->next = t->next;
    t->next->prev = t-> prev;
    free(t);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void printNodes(){
    Node *cur = nil->next;
    int ct = 0;
    while( cur != nil ){
        if(ct) cout << " ";
        cout << cur->key;
        cur = cur-> next;
        ct ++;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    init();
    int i, n, key;
    char action[20];
    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        scanf("%s", action);
        if(action[0] == 'i'){
            scanf("%d", &key);
            insert(key);
        }
        else if(action[0] == 'd'){
            if(strlen(action) > 6){
                if(action[6] == 'F'){
                    deleteFirst();
                }
                else if (action[6] == 'L'){
                    deleteLast();
                }
            }
            else{
                scanf("%d", &key);
                Node *t = listSearch(key);
                deleteNode(t);
            }
        }
    }
    printNodes();
    
    //    std::cout << "Hello, World!\n";
    return 0;
}

