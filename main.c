
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define author "AUTHOR_NAME"

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

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


//==== LABWORK 1 ==== //
void lab1_q1(){
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

void lab1_q2(){
	int a,b,c;
	printf("Enter 3 numbers: ");
	scanf("%d %d %d", &a, &b, &c);
  if(a > b && a > c){
      printf("%d is the greatest", a);
  }
  else if(b > c && b > a){
      printf("%d is the greates", b);
  }
  else{
      printf("%d is the greatest", c); 
  }
}

void lab1_q3_prime_composite(int n){
  if(n<=1){ printf ("composite"); return;}
  for(int i = 2; i*i<=n; i++){
    if(n%i == 0){
      printf("composite");
      return;
    }
  }
  printf("prime");
}

void lab1_q3(){
  int a;
  printf("Enter number: ");
  scanf("%d", &a);
  lab1_q3_prime_composite(a);
}

void lab1_q4(){
  int i, sum=0;
  for(i = 1; i<=200; i++){
    sum += i;
  }
  printf("The sum of series = %d",sum);
}

int lab1_q5_sum(int a, int b){
  return a+b;
}

void lab1_q5(){
  int a,b;
  printf("Enter any two numbers: ");
  scanf("%d %d", &a, &b);
  printf("the sum = %d",lab1_q5_sum(a,b));
}

void lab1_q6(){
	int n,i, sum =0;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: \n");
	for(i = 0; i<n; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("The elements are: \n");
	for(i = 0; i<n; i++){
		printf("%d ",arr [i]);
	}
	printf("\nThe sum is: %d", sum);
}

void lab1_q7_matrix_sum(int a[][5], int b[][5], int r, int c){
	int i,j,sum[r][5];
	for(i = 0; i<r; i++){
		for(j = 0; j<c; j++){
			sum[i][j] = a[i][j]+b[i][j];
		} 
	}
	for(i = 0; i<r; i++){
		for(j = 0; j<c; j++){
			printf("%d  ",sum[i][j]);
		}
		printf("\n");
	}
	
}

void lab1_q7(){
	int i,j,r,c;
	printf("enter row and columns: ");
	scanf("%d %d", &r, &c);
	int a[r][5], b[r][5];
	
	printf("Matrix A: \n");
	for(i = 0; i<r; i++){
		for(j = 0; j<c; j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nMatric B: \n");
		for(i = 0; i<r; i++){
			for(j = 0; j<c; j++){
				scanf("%d",&b[i][j]);
		}
	}
	lab1_q7_matrix_sum(a, b, r, c);
}

void lab1_q8_sort(char strings[][120], int n){
  int i,j;
  char temp[120];
  for(i = 0; i<n; i++){
    for(j = i+1; j<n; j++ ){
      if(strcmp(strings[i], strings[j])>0){
        strcpy(temp,strings[i]);
        strcpy(strings[i],strings[j]);
        strcpy(strings[j],temp);
      }
    }
  }
}

void lab1_q8(){
  int i,n;
  printf("Enter number of strings: ");
  scanf("%d", &n);
  char string[n][120];
  for(i = 0; i<n; i++){
      scanf("%s",string[i]);
  }
  lab1_q8_sort(string, n);
  printf("\nAfter sorting: \n");
  for(i = 0; i<n; i++){
      printf("%s\n",string[i]);
  }

}

int lab1_q9_factorial(int n){
	if(n == 0){ return 1;}
	if(n>1){
		return n*lab1_q9_factorial(n-1);
	}
	return n;
	
}

void lab1_q9(){
	int n;
	printf("Enter Number: ");
	scanf("%d",&n);
	printf("factorial of the number = %d", lab1_q9_factorial(n));
}




// ======= MENU DECLARATION =============== //
Menu labwork1[] = {
	{1, "Even or odd using function", program, {.pfunction = lab1_q1}},
	{2, "Greatest Among Three Numbers", program, {.pfunction = lab1_q2}},
  {3, "Prime or Composite", program, {.pfunction = lab1_q3}},
  {4, "Sum of series", program, {.pfunction = lab1_q4}},
  {5, "Sum of two numbers", program, {.pfunction = lab1_q5}},
  {6, "Basic Array Operations", program, {.pfunction = lab1_q6}},
  {7, "Sum of matrix", program, {.pfunction = lab1_q7}},
  {8, "sorting strings", program, {.pfunction = lab1_q8}},
  {9, "Factorial with recursion", program, {.pfunction = lab1_q9}},
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
	system(CLEAR_COMMAND);
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
		if(selected_obj != NULL){
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
	system(CLEAR_COMMAND);
	printf("Author name: %s\n",author);
}
void execute_function(program_function function_to_execute){
	pre_function();
	function_to_execute();
	post_function();
}
void post_function(){
  while(getchar() != '\n');
  getchar();
}


