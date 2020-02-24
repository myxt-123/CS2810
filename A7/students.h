class Student {
public:
	int id;
	int marks[5];
	int skill;
	int rank;
};

class list {
public:
	int total;
	vector<Student> students;
};

class table {
public:
	vector<list> table;
	unordered_map<int, Student> id;

	void insert(int id, int m1, int m2, int m3, int m4, int m5, int skill);
	int find(int id1, int id2);
	int count(int id);
	void print();
}