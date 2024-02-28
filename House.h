#ifndef HOUSE_H
#define HOUSE_H
#include "Living.h"
#include "Bedroom.h"
#include "Bathroom.h"
#include "Kitchen.h"

class House
{
public:
    void addRoom(IRoom* r)
    {
        r->createRoom();
        rooms.push_back(r);
    }
    void removeRoom(int n)
    {
        rooms[n]->deleteRoom();
        rooms.erase(rooms.begin() + n);
    }
    void collectRoomData()
    {
        for (int i = 0; i < rooms.size(); i++)
            rooms[i]->updateRoom();
    }
    void viewRoomData()
    {
        for (int i = 0; i < rooms.size(); i++)
            rooms[i]->readRoom();
    }

private:
    vector <IRoom*> rooms;
};

#endif
