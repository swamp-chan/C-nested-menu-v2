

#include<stdio.h>
#include<stdlib.h>

#define author "AUTHOR_NAME"

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
void display_menu(Menu *m);
void execute_function(program_function function_to_execute);
Menu *select_menu(Menu *m, int id);
void menu_loop(Menu *m);

//functions of lab1
void lab1_evenodd(){
	printf("Enter number: ");
	int n;
	scanf("%d",&n);
	if(n%2 == 0){
		printf("Even number");
	}
	else{
		printf("Odd number");
	}
	
}

void lab1_great(){
	int a,b,c;
	printf("Enter 3 numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	if(a>b){
		if(a>c){
			printf("%d", a);
		}
	}
	else{
		if(b>c){
			printf("%d", b);
		}
		else{
			printf("%d",c);
		}
	}
}

//labwork 1
Menu labwork1[] = {
	{1, "Even or odd using function", program, {.pfunction = lab1_evenodd}},
	{2, "Greatest Among Three Numbers", program, {.pfunction = lab1_great}},
	{0, "BACK", back, {.pfunction = NULL}}
};

Menu Main_Menu[] = {
	{1, "Labwork 1", sub_menu, {.submenu = labwork1}},
	{2, "Labwork 2", sub_menu, {.submenu = NULL}},
	{0, "QUIT", quit, {.submenu = NULL}}
};




int main(void){
  menu_loop(Main_Menu);
  return 0;
}


void pre_menu(){
	system("clear");
	printf("Pick any option to display: \n\n");
}

void display_menu(Menu *menu_to_display){
	int i;
	for(i = 0; menu_to_display[i].id != 0; i++ ){
		printf("%d. %s\n",menu_to_display[i].id, menu_to_display[i].title);
    if(menu_to_display[i+1].id == 0){
      printf("%d. %s\n",menu_to_display[i+1].id, menu_to_display[i+1].title);
    }
	}
}

Menu *select_menu(Menu *selected_menu, int opt){
	int i;
	for(i = 0; selected_menu[i].id != 0; i++){
		if(selected_menu[i].id == opt){
			return &selected_menu[i];
		}
		if(selected_menu[i+1].id == 0){
			return &selected_menu[i+1];
		}
	}
	return NULL;
}


void menu_loop(Menu *current_menu){
	int option;
  Menu *selected_obj;
	do{
		pre_menu();
		display_menu(current_menu);
		scanf("%d", &option);

		selected_obj = select_menu(current_menu, option);
		//printf("THE TYPE OF SELECTED OBJ: %d", selected_obj->type);
		//getchar();
		if(selected_obj){
			switch(selected_obj->type){
				case quit:
					exit(0);
					break;
				case sub_menu:
					menu_loop(selected_obj->action.submenu);
					break;
				case program:
					execute_function(selected_obj->action.pfunction);
					break;
				case back:
					return;
					break;
			}
		}
		else{
			printf("ENTER VALID OPTION");
      getchar();
		}
	}while(1);
	
}

void pre_function(){
	system("clear");
	printf("Author name: %s\n",author);
}
void execute_function(program_function function_to_execute){
	pre_function();
	function_to_execute();
	post_function();
}
void post_function(){
	getchar();
}

