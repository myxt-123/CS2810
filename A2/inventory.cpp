#include <iostream>
#include <string>

using namespace std;

class InventoryItem
{
public:
	int id;
	float price;
	string manufacturer;
	string type;

	static InventoryItem list[1000];

	InventoryItem(){
		for(int ii = 0; ii < 1000; ++ii){
			list[ii].id = 0;
			list[ii].price = 0;
			list[ii].manufacturer = '\0';
			list[ii].type = '\0';
		}
	};

	InventoryItem(int i, float p, string m, string t)
	{
		id = i;
		price = p;
		manufacturer = m;
		type = t;
	};
	~InventoryItem();
	int getID();
	float getPrice();
	string getManufacturer();
	string getType();
};

InventoryItem InventoryItem::list[1000];

class Pen
{
public:
	int id;
	float width;
	string colour;
	string style;

	static Pen list[1000];

	Pen(int i, float w, string c, string s);
	~Pen();
	int getID();
	float getWidth();
	string getColour();
	string getStyle();
};

Pen Pen::list[1000];

class Pencil
{
public:
	int id;
	float width;
	string hardness;
	string size;

	static Pencil list[1000]; 

	Pencil(int i, float w, string h, string s);
	~Pencil();
	int getID();
	float getWidth();
	string getHardness();
	string getSize();
};

Pencil Pencil::list[1000];

int main()
{

}

