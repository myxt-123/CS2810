class BTech{
public:

	RollNumber r;
	string hostel;
	Faculty facad;
	Faculty BTPGuide;
	float cgpa;
	void changeHostel(string);
	string getHostel(){return hostel;}
	Faculty getFacad(){return facad;}
	Faculty getBTPGuide(){return BTPGuide;}
	void setBTPGuide(Faculty);
};

void BTech::changeHostel(string newHostel){
	hostel = newHostel;
}

void BTech::setBTPGuide(Faculty guide){
	BTPGuide = guide;
}



