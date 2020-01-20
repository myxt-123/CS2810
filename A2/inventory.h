class InventoryItem
{
public:
	int id;
	float price;
	string manufacturer;
	string type;

	static InventoryItem list[1000];


	InventoryItem();										//used to initialize the static array
	InventoryItem(int i, float p, string m, string t);		//for initializing the elements
	~InventoryItem();										//destructor for the elements
	int getID();
	float getPrice();
	string getManufacturer();
	string getType();
};

InventoryItem InventoryItem::list[1000];					//declaration of the static variable

class Pen
{
public:
	int id;
	float width;
	string colour;
	string style;

	static Pen list[1000];

	Pen();													//used to initialize the static array
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

	Pencil();												//used to initialize the static array
	Pencil(int i, float w, string h, string s);
	~Pencil();
	int getID();
	float getWidth();
	string getHardness();
	string getSize();
};

Pencil Pencil::list[1000];