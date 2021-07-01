#define MAXSTACK  100

int top;
uint8_t entry[MAXSTACK];
   

void Push (uint8_t e);
void Pop ();
void TraverseStack( void (*ptf)(uint8_t));