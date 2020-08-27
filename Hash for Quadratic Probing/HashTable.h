#ifndef _HASHTABLE_
#define _HASHTABLE_

#include "HashUtils.h"

// Do not modify the public interface of this class.
// Otherwise, your code will not compile!
template <class T>
class HashTable {
    struct Entry {
        std::string Key;             // the key of the entry
        T Value;   // the value of the entry
        bool Deleted;        // flag indicating whether this entry is deleted
        bool Active;         // flag indicating whether this item is currently used

        Entry() : Key(), Value(), Deleted(false), Active(false) {}
    };

    struct Bucket {
        Entry entries[3];
    };

    int _capacity; // INDICATES THE SIZE OF THE TABLE
    int _size; // INDICATES THE NUMBER OF ITEMS IN THE TABLE

    Bucket* _table; // HASH TABLE
    void add(std::string key, const T& value);
    double total ;
    // You can define private methods and variables

public:
    // TODO: IMPLEMENT THESE FUNCTIONS.
    // CONSTRUCTORS, ASSIGNMENT OPERATOR, AND THE DESTRUCTOR
    HashTable();
    HashTable(const HashTable<T>& rhs);
    HashTable<T>& operator=(const HashTable<T>& rhs);
    ~HashTable();
    
    // TODO: IMPLEMENT THIS FUNCTION.
    // INSERT THE ENTRY IN THE HASH TABLE WITH THE GIVEN KEY & VALUE
    // IF THE GIVEN KEY ALREADY EXISTS, THE NEW VALUE OVERWRITES
    // THE ALREADY EXISTING ONE. 
    // IF LOAD FACTOR OF THE TABLE IS BIGGER THAN 0.5,
    // RESIZE THE TABLE WITH THE NEXT PRIME NUMBER.
    void Insert(std::string key, const T& value);

    // TODO: IMPLEMENT THIS FUNCTION.
    // DELETE THE ENTRY WITH THE GIVEN KEY FROM THE TABLE
    // IF THE GIVEN KEY DOES NOT EXIST IN THE TABLE, JUST RETURN FROM THE FUNCTION
    // HINT: YOU SHOULD UPDATE ACTIVE & DELETED FIELDS OF THE DELETED ENTRY.
    void Delete(std::string key);

    // TODO: IMPLEMENT THIS FUNCTION.
    // IT SHOULD RETURN THE VALUE THAT CORRESPONDS TO THE GIVEN KEY.
    // IF THE KEY DOES NOT EXIST, THIS FUNCTION MUST RETURN T()
    T Get(std::string key) const;

    // TODO: IMPLEMENT THIS FUNCTION.
    // AFTER THIS FUNCTION IS EXECUTED THE TABLE CAPACITY MUST BE
    // EQUAL TO newCapacity AND ALL THE EXISTING ITEMS MUST BE REHASHED
    // ACCORDING TO THIS NEW CAPACITY.
    // WHEN CHANGING THE SIZE, YOU MUST REHASH ALL OF THE ENTRIES FROM 0TH ENTRY TO LAST ENTRY
    void Resize(int newCapacity);
    
    // TODO: IMPLEMENT THIS FUNCTION.
    // RETURNS THE AVERAGE NUMBER OF PROBES FOR SUCCESSFUL SEARCH
    double getAvgSuccessfulProbe();
    
    // TODO: IMPLEMENT THIS FUNCTION.
    // RETURNS THE AVERAGE NUMBER OF PROBES FOR UNSUCCESSFUL SEARCH
    double getAvgUnsuccessfulProbe();

    // THE IMPLEMENTATION OF THESE FUNCTIONS ARE GIVEN TO YOU
    // DO NOT MODIFY!
    int Capacity() const;
    int Size() const;
};



template <class T>
HashTable<T>::HashTable() {
    _size = 0;
    _capacity = 0;
    _table = NULL;
    total = 0;
// TODO: CONSTRUCTOR

}

template <class T>
HashTable<T>::HashTable(const HashTable<T>& rhs) { 
    _size = rhs._size;
    _capacity = rhs._capacity;
    _table = new Bucket[_capacity];
    for(unsigned int i=0;i<_capacity;i++){
        for(int j=0;j<3;j++){
            _table[i].entries[j] = (rhs._table)[i].entries[j];
        }
    }
    
// TODO: COPY CONSTRUCTOR

}

template <class T>
HashTable<T>& HashTable<T>::operator=(const HashTable<T>& rhs) {
    _size = rhs._size;
    _capacity = rhs._capacity;
    delete [] _table;
    _table = new Bucket[_capacity];
    for(unsigned int i=0;i<_capacity;i++){
        for(int j=0;j<3;j++){
            _table[i].entries[j] = (rhs._table)[i].entries[j];
        }
    }
// TODO: OPERATOR=

}

template <class T>
HashTable<T>::~HashTable() {
    delete [] _table ;
// TODO: DESTRUCTOR

}
template <class T>
void HashTable<T>::add(std::string key, const T& value) {
    int key1 = Hash(key);
    bool success = false;
    for(int i=0;!success;i++){
            if(!(_table[(key1+(i*i))%_capacity].entries[0].Active)){
                _table[(key1+(i*i))%_capacity].entries[0].Key = key;
                _table[(key1+(i*i))%_capacity].entries[0].Value = value;
                _table[(key1+(i*i))%_capacity].entries[0].Active = true;
                _table[(key1+(i*i))%_capacity].entries[0].Deleted = false;
                total += (i+1);
                success = true;
                _size++;
                return;
            }
            else if(_table[(key1+(i*i))%_capacity].entries[0].Key == key){
                _table[(key1+(i*i))%_capacity].entries[0].Key = key;
                _table[(key1+(i*i))%_capacity].entries[0].Value = value;
                _table[(key1+(i*i))%_capacity].entries[0].Active = true;
                _table[(key1+(i*i))%_capacity].entries[0].Deleted = false;
                success = true;
                
                return;
            }
            else if(!(_table[(key1+(i*i))%_capacity].entries[1].Active)){
                _table[(key1+(i*i))%_capacity].entries[1].Key = key;
                _table[(key1+(i*i))%_capacity].entries[1].Value = value;
                _table[(key1+(i*i))%_capacity].entries[1].Active = true;
                _table[(key1+(i*i))%_capacity].entries[1].Deleted = false;
                total += (i+1);
                success = true;
                 _size++;
                return ;
            }
            else if(_table[(key1+(i*i))%_capacity].entries[1].Key == key){
                _table[(key1+(i*i))%_capacity].entries[1].Key = key;
                _table[(key1+(i*i))%_capacity].entries[1].Value = value;
                _table[(key1+(i*i))%_capacity].entries[1].Active = true;
                _table[(key1+(i*i))%_capacity].entries[1].Deleted = false;
                success = true;
                 
                return;
            }
            
            else if(!(_table[(key1+(i*i))%_capacity].entries[2].Active)){
                _table[(key1+(i*i))%_capacity].entries[2].Key = key;
                _table[(key1+(i*i))%_capacity].entries[2].Value = value;
                _table[(key1+(i*i))%_capacity].entries[2].Active = true;
                _table[(key1+(i*i))%_capacity].entries[2].Deleted = false;
                total += (i+1);
                success = true;
                 _size++;
                return ;
            }
            else if(_table[(key1+(i*i))%_capacity].entries[2].Key == key){
                _table[(key1+(i*i))%_capacity].entries[2].Key = key;
                _table[(key1+(i*i))%_capacity].entries[2].Value = value;
                _table[(key1+(i*i))%_capacity].entries[2].Active = true;
                _table[(key1+(i*i))%_capacity].entries[2].Deleted = false;
                success = true;
              
                return;
            }
        }
    
    
}
template <class T>
void HashTable<T>::Insert(std::string key, const T& value) {
    
    int key1 = Hash(key);
    if(_capacity == 0){
        _capacity = NextCapacity(_capacity);
        _table = new Bucket [_capacity];
        
    }
    
    if(((float)_size / (3*_capacity)) > 0.5){
        
        Resize(NextCapacity(_capacity));
        add(key,value);
        
    }
    
    else {
        add(key,value);
        
    }
    
// TODO: IMPLEMENT THIS FUNCTION.
// INSERT THE ENTRY IN THE HASH TABLE WITH THE GIVEN KEY & VALUE
// IF THE GIVEN KEY ALREADY EXISTS, THE NEW VALUE OVERWRITES
// THE ALREADY EXISTING ONE. IF LOAD FACTOR OF THE TABLE IS BIGGER THAN 0.5,
// RESIZE THE TABLE WITH THE NEXT PRIME NUMBER.

}

template <class T>
void HashTable<T>::Delete(std::string key) {
    int key1 = Hash(key);
    for(int i=0;1;i++){
        for(int j=0;j<3;j++){
            if(_table[(key1+(i*i))%_capacity].entries[j].Active == false){
                if(_table[(key1+(i*i))%_capacity].entries[j].Deleted == false){
                return;
            }}
            else if(_table[(key1+(i*i))%_capacity].entries[j].Key == key){
                _table[(key1+(i*i))%_capacity].entries[j].Deleted = true;
                _table[(key1+(i*i))%_capacity].entries[j].Active = false;
                _size--;
                total -= (i+1);
                
                
            }
        }
    }
// TODO: IMPLEMENT THIS FUNCTION.
// DELETE THE ENTRY WITH THE GIVEN KEY FROM THE TABLE
// IF THE GIVEN KEY DOES NOT EXIST IN THE TABLE, JUST RETURN FROM THE FUNCTION
// HINT: YOU SHOULD UPDATE ACTIVE & DELETED FIELDS OF THE DELETED ENTRY.

}

template <class T>
T HashTable<T>::Get(std::string key) const {
    int key1 = Hash(key);
    for(int i=0;1;i++){
        for(int j=0;j<3;j++){
            if(_table[(key1+(i*i))%_capacity].entries[j].Active == false){
                if(_table[(key1+(i*i))%_capacity].entries[j].Deleted == false){
                return T();
            }}
            else if(_table[(key1+(i*i))%_capacity].entries[j].Key == key){
                
                return _table[(key1+(i*i))%_capacity].entries[j].Value;
            }
        }
    }
// TODO: IMPLEMENT THIS FUNCTION.
// IT SHOULD RETURN THE VALUE THAT CORRESPONDS TO THE GIVEN KEY.
// IF THE KEY DOES NOT EXIST, THIS FUNCTION MUST RETURN T()

}

template <class T>
void HashTable<T>::Resize(int newCapacity) {
    
    unsigned int counter = 0;
    Entry *temp;
    temp = new Entry [_size];
    for(unsigned int i = 0; i<_capacity ; i++){
        for(int j = 0; j < 3 ; j++){
            if(_table[i].entries[j].Active){
                temp[counter].Key = _table[i].entries[j].Key ;
                temp[counter].Value = _table[i].entries[j].Value ;
                temp[counter].Active = true;
                temp[counter].Deleted = false;
                counter++;
            }
        }
    }
    delete [] _table ;
    _table = new Bucket[newCapacity];
    for(unsigned int i=0;i<counter;i++){
        add(temp[i].Key,temp[i].Value);
    }
    delete [] temp;
    _capacity = newCapacity;
    _size = counter;
// TODO: IMPLEMENT THIS FUNCTION. AFTER THIS FUNCTION IS EXECUTED
// THE TABLE CAPACITY MUST BE EQUAL TO newCapacity AND ALL THE
// EXISTING ITEMS MUST BE REHASHED ACCORDING TO THIS NEW CAPACITY.
// WHEN CHANGING THE SIZE, YOU MUST REHASH ALL OF THE ENTRIES FROM 0TH ENTRY TO LAST ENTRY

}


template <class T>
double HashTable<T>::getAvgSuccessfulProbe() {
    
    return total/_size;
// TODO: IMPLEMENT THIS FUNCTION.
// RETURNS THE AVERAGE NUMBER OF PROBES FOR SUCCESSFUL SEARCH

}

template <class T>
double HashTable<T>::getAvgUnsuccessfulProbe() {
    double unsuc = 0;
    int c = 1;
    bool suc=false;
    int k;
    for(int i=0;i<_capacity;i++){
        for(k=i,c=1;;k++,c++){
        for(int j=0;j<3;j++){
            if(!(_table[(k % _capacity)].entries[j].Active)){
                unsuc += c ;
                suc = true;
                break;
            }
        }
        if(suc){
            suc = false;
            break;
        }
    }}

    return unsuc/_capacity;
// TODO: IMPLEMENT THIS FUNCTION.
// RETURNS THE AVERAGE NUMBER OF PROBES FOR UNSUCCESSFUL SEARCH

}

template <class T>
int HashTable<T>::Capacity() const {
    return _capacity;
}

template <class T>
int HashTable<T>::Size() const {
    return _size;
}

#endif
