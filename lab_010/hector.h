#ifndef HECTOR_H
#define HECTOR_H

using namespace std;

//
// the class interface
//
class Hector
{
public:
	static const int SENTINEL = -1;

	Hector();
	~Hector();

	int linny(int value);
	int doubles(int value);
	int cheney(int value);		

	void print();

private:
        //
        // used by the chained version of collision handling
        //
	struct Node {
		int   key;
		Node *next;
	};

	static const int TSIZE = 17;
	static const int VAL   = 10;

	Node *cheneyTable[TSIZE];	
	int   linnyTable[TSIZE];
	int   doublesTable[TSIZE];
		
};
#endif	/* HECTOR_H */
