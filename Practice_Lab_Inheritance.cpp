/*Q1 - Hotel Rooms:
In a Hotel there are two types of rooms Simple Hotel room and Apartment room. Apartment are expensive as compared to Simple rooms. 
Define a class HotelRoom which has two int members for storing the number of bathrooms and bedrooms. 
Define a constructor which initializes these members. 
Also define a function named get_price , which calculates the prices using this formuls: 50 * (# of bedrooms) + 100 * (# of bathrooms) 

Define another class called Apartment which inherits from HotelRoom. Define a relevant constructor for it. 
This class also has a get_price function which calculate the price using the above formula plus 100. 

Write a main() which takes int n as input and creates a vector of type HotelRoom* of size n. Then takes n lines of input. 
Each line contains the type of room, number of bed rooms and number of bathrooms. 
You have to create an object based on the type of room and add it into the array. 
After taking the input, loop through all the rooms and calculate the total price(profit) of all the rooms and print it. */

#include<iostream>
#include<vectors>
#include<cstring>
using namespace std;

class HotelRoom{
    public:
    int bathroom_num, bedroom_num;
    HotelRoom(){
        bathroom_num = 0; bedroom_num = 0;
    }
    HotelRoom(int bathrooms, int bedrooms){
        bathroom_num = bathrooms; bedroom_num = bedrooms;
    }
    virtual int get_price(){
        int price = 100*bathroom_num + 50*bedroom_num;
        return price;
    }
};

class Apartment : public HotelRoom{
    public:
    Apartment(int bathrooms, int bedrooms) : HotelRoom(bathrooms, bedrooms) {};
    int get_price(){
        int price = HotelRoom::get_price() + 100;
        return price;
    }
};

int main(){
    int n; cin >> n;
    vector<HotelRoom*> Room;
    for(int i = 0; i < n; i++){
        string type; int bedrooms; int bathrooms;
        cin >> type >> bedrooms >> bathrooms;
        if(type == "standard") Room.push_back(new HotelRoom(bathrooms, bedrooms));
        else if (type == "apartment") Room.push_back(new Apartment(bathrooms, bedrooms));
    }
    int total_price = 0;
    for(int i = 0; i < n; i++){
        total_price += Room[i]->get_price();
    }
    cout << total_price;
}


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------
Q2
