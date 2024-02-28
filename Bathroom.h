#ifndef BATHROOM__H
#define BATHROOM_H
#include "IRoom.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Pressure.h"

class Bathroom: public IRoom
{
public:
    void createRoom()
    {
        int n = 2;
        fstream f;
        s = "Bathroom1.txt";
        f.open(s, ios::in);
        while (f)
        {
            f.close();
            s[8] = '0' + n;
            n++;
            f.open(s, ios::in);
        }
        f.close();
        f.open(s, ios::app);
        f.close();
    }
    void readRoom()
    {
        ifstream f;
        double t, h, p;
        f.open(s);
        cout << endl << "Datele din fisierul " << s << endl;
        for (int i = 1; i <= update * 2; i++)
        {
            f >> t >> h >> p;
            cout << "Temperatura" << i << ": " << t << " grade Celsius" << endl;
            cout << "Umiditatea" << i << ": " << h << "%" << endl;
            cout << "Presiunea" << i << ": " << p << " hPa" << endl;
        }
        f.close();
    }
    void updateRoom()
    {
        sensor.push_back(new Temperature());
        sensor.push_back(new Humidity());
        sensor.push_back(new Pressure());
        sensor.push_back(new Temperature());
        sensor.push_back(new Humidity());
        sensor.push_back(new Pressure());
        fstream f;
        f.open(s, ios::app);
        f << fixed << setprecision(2);
        for (int i = 0; i < 6; i++)
        {
            if (i == 3)
            {
                system("pause");
                f << endl << sensor[update * 6 + i]->readSensor() << ' ';
            }
            else
                f << sensor[update * 6 + i]->readSensor() << ' ';
        }
        f << endl;
        update++;
        system("pause");
        f.close();
    }
    void deleteRoom()
    {
        int r = remove(s.c_str());
        if (!r)
            cout << endl << "Fisierul " << s << " a fost sters." << endl;
    }

private:
	vector <ISensor*> sensor;
	string s;
	int update = 0;



};


#endif
