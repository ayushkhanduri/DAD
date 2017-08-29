#include"stdlib.h"

struct state{
  bool found;
  int position;
  state(){
    found = false;
    position = -1;
  }
};
