typedef struct Quadruplet Quadruplet;
struct Quadruplet {
				 char*opr;
				 char* op1;
				 char* op2;
				 char* res;};
				 
typedef struct QuadList QuadList;

 struct QuadList
  {
  	Quadruplet val;
  	QuadList *svt;
  };

void quadAppend();
void insertQuad (char*,char*,char*,char*);
void afficherQuad();
