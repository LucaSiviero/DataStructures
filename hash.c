//Good evenning everybody. Now we are going to build a hashTable structure.
//We'll implement searching, deletion and adding functions.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 20     //size of the table

struct Cell {
    int key;
    int value;
};

struct Cell* hashArray[SIZE];   //THE ACTUAL TABLE OMG
struct Cell* fessitem;      //a very strange item...
struct Cell* item;          //a very normal one

/*Modulus is at the base of hashing.
We place the elements with an index calculated this way: Key % SIZE, which is a number between 0 and 19.
then what we do is... write the method hashcode, which will give us the index.*/

int hashCode(int key){
    int hashCode = key%SIZE;    //A number between 0 and 19.
    return hashCode;
}

struct Cell* search(int key){       //We know the key           LAST FUNCTION WROTE
    int index = hashCode(key);      //So we get the index
    
    while(hashArray[index] != NULL){    //usual loop    
        if(hashArray[index]->key == key) {      //If it's actually who we're looking for
            printf("%d found!\n", hashArray[index]->key);
            return hashArray[index];    
        }
        ++index;            
        index %= SIZE;
    }
    return NULL;        //If we didn't find our element..
}

void insert(int key, int value){        //FIRST ONE     complexity: O(n)
    struct Cell* item = (struct Cell*) malloc(sizeof(struct Cell)); //This is the object we store in the array. It's casted to pointer because we're passing it by reference
    item->key = key;
    item->value = value;

    int index = hashCode(key);      //the position in the array
    while(hashArray[index] != NULL && hashArray[index]->key != -1){ //Until i find an empty or deleted cell (deleted cells have key=-1)
        ++index;        //Next cell

        index %= SIZE;  //This is done because if we get to index 19, we're going to get a ++19, which is 20. But 20 in terms of x modulus 20 means 0, so we do modulus again
    }

    hashArray[index] = item;       //At the end of the upper loop, we're going to place the item at the first empty cell.
    //if we are at the first iteration of the function, the table is going to be empty, so we're occuping the first cell, BEST CASE SCENARIO, O(1).
    
}

int removeCell(struct Cell* item) {
    fessitem = (struct Cell*) malloc(sizeof(struct Cell));    
    fessitem->key = -1;
    fessitem->value = -1;
    int key = item->key;        //This is the key of the object...
    int index = hashCode(key);      //This is the index of the element, SOOOOO
    while(hashArray[index]!=NULL){  //go through the table, until a null object is found
       
        if(hashArray[index]->key == key){   //If the element we're looping through has the same key we were looking for (E' POP ISS OOO)
            struct Cell* temp = hashArray[index];   //We temporary move it,
            hashArray[index] = fessitem;              //And we free it.
            printf("%d removed\n",temp->key);
            return temp->key;
            
        }
        ++index;
        index %= SIZE;
    }
    return 76;
}

int main (){    //WORST MAIN EVER
    
    insert(25, 1000);
    struct Cell* cella = search(25);
    removeCell(cella);
    return 0;
}