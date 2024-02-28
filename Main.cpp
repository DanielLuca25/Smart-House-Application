#include <iostream>
#include "House.h"
using namespace std;
int main()
{
    House h;
    Living l1;
    Bathroom ba1, ba2;
    Bedroom be1, be2;
    Kitchen k1;
    h.addRoom(&l1);
    h.addRoom(&ba1);
    h.addRoom(&ba2);
    h.addRoom(&be1);
    h.addRoom(&be2);
    h.addRoom(&k1);
    ba1.updateRoom();
    ba1.updateRoom();
    be1.updateRoom();
    h.collectRoomData();
    system("cls");
    h.viewRoomData();
    h.removeRoom(2);
    h.removeRoom(3);
}
