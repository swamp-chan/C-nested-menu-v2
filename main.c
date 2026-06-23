
#include<stdio.h>

#define author "AUTHOR_NAME";

typedef void (*program_function)();

typedef enum{
  back,
  sub_menu,
  program,
  quit,
}itemtype;

typedef struct Menu_{
  int id;
  char *title;
  itemtype type;
  union{
    program_function pfunction;
    struct Menu_ *submenu;
  }action; 
}Menu;

//the main functions 
void pre_menu();
void pre_function();
void post_function();
void print_menu(Menu *m);
void execute_function(program_function function_to_execute);
void menu_loop(Menu *m);

int main(void){
  printf("Hello World!");
  return 0;
}
