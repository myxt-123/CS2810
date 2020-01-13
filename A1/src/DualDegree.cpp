class DualDegree{
public:

	RollNumber r;
	string hostel;
	Faculty facad;
	Faculty DDPGuide;
	Faculty TASupervisor;
	float cgpa;
	void changeHostel(string);
	string getHostel(){return hostel;}
	Faculty getFacad(){return facad;}
	Faculty getDDPGuide(){return DDPGuide;}
	Faculty getTASupervisor(){return TASupervisor;}
	void setDDPGuide(Faculty);
	void setTASupervisor(Faculty);
}

void DualDegree::changeHostel(string newHostel){
	hostel = newHostel;
}

void DualDegree::setDDPGuide(Faculty guide){
	DDPGuide = guide;
}

void DualDegree::setTASupervisor(Faculty TA){
	TASupervisor = TA;
}