
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define author "Author_name"

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
	return;
	
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


// ====== LABWORK 2 =========== //

void lab2_q1(){
	struct std {
		int id;
		char name[50];
		int grade;	
	} students[10];
	
	printf("Enter the following details: \n");
	int i;
	for(i = 0; i< 10; i++){
		
		printf("\nEnter id: ");
		scanf("%d",&students[i].id);
		
		printf("Enter name: ");
		scanf("%s",students[i].name);
		
		printf("Enter grade: ");
		scanf("%d",&students[i].grade);
		
	}
	printf("\n\nPrinting the details: \n");
	for(i = 0; i<10; i++){
		printf("%d. %s of grade %d\n", students[i].id, students[i].name, students[i].grade);
	}
}

void lab2_q2(){
	struct e{
		char name[20];
		char desig[20];
		int sal;
	}emp[3];
	int i, n=3;
	for(i = 0; i<n; i++){
		printf("\n\nEnter employee name: ");
		scanf("%s",emp[i].name);
		printf("Enter designation: ");
		scanf("%s",emp[i].desig);
		printf("Enter salary: ");
		scanf("%d",&emp[i].sal);
	}
	
	char nam[20], found_index = -1;
	printf("\nEnter the name of the employee to search: ");
	scanf("%s",nam);
	for(i = 0; i<n; i++){
		if(strcmp(emp[i].name, nam) == 0){
			found_index = i;
		}
	}
	if(found_index != -1){
		printf("\nEmployee found: \n%s of designation %s", emp[found_index].name, emp[found_index].desig);
	}
	else{
		printf("\nEmployee not found");
	}
}

void lab2_q3(){
	struct employee{
		char ename[100];
		char eaddress[100];
	};
	struct salarydetails{
		char pos[100];
		float salary;
		struct employee detail;
	}payinfo[5];
	int i, n = 5;
	for(i = 0; i<n; i++){
		printf("\nenter name: ");
		scanf("%s", payinfo[i].detail.ename);
		printf("enter address: ");
		scanf("%s", payinfo[i].detail.eaddress);
		printf("enter position: ");
		scanf("%s", payinfo[i].pos);
		printf("enter salary: ");
		scanf("%f",&payinfo[i].salary);
	}
	
	printf("\nPrinting data that was inputted: \n");
	for(i = 0; i<n; i++){
		printf("%s of pos %s with salary %.2f living in %s\n", payinfo[i].detail.ename, payinfo[i].pos, payinfo[i].salary, payinfo[i].detail.eaddress);
	}
}

void lab2_q4(){
	struct student{
		int id;
		char name[60];
		char add[60];
	}st[3];
	int i,j, n = 3;
	for(i = 0; i<n; i++){
		printf("\nEnter name: ");
		scanf("%s",st[i].name);
		printf("Enter id: ");
		scanf("%d",&st[i].id);
		printf("Enter address: ");
		scanf("%s",st[i].add);
	}
	struct student temp;
	for(i = 0; i<n; i++){
		for(j = i+1; j<n; j++){
			if(strcmp(st[i].name,st[j].name)>0);
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
		}
	}
	printf("\nIn sorted format: \n");
	for(i = 0; i<n; i++){
		printf("%d. %s living in \n", st[i].id, st[i].name, st[i].add);
	}
}

void lab2_q5(){
	typedef struct {
		int id;
		char name[60];
		char subj[60];
	}teacher;
	teacher t[5];
	int i, n = 5;
	for(i = 0; i<n; i++){
		printf("\nEnter name: ");
		scanf("%s",t[i].name);
		printf("Enter subject: ");
		scanf("%s", t[i].subj);
		printf("Enter id: ");
		scanf("%d",&t[i].id);
	}
	printf("\nOutputting the entered data: \n");
	for(i = 0; i<n; i++){
		printf("%d. %s teaching %s\n", t[i].id, t[i].name, t[i].subj);
	}
}

void lab2_q6(){
	struct distance{
		int km;
		int m;
	}a,b,c;
	printf("Enter distance 1: ");
	scanf("%d%d", &a.km, &a.m);
	printf("Enter distance 2: ");
	scanf("%d%d", &b.km, &b.m);
	c.km = a.km + b.km + (a.m + b.m)/1000;
	c.m = (a.m + b.m)%1000;
	printf("the sum of the distances = %dkm and %dm",c.km,c.m);
}

void lab2_q7(){
	union student{
		int id;
		char name[60];
		int grade;
	}sname, sid, sgrade;
	printf("Enter name: ");
	scanf("%s",sname.name);
	printf("Enter grade: ");
	scanf("%d",&sgrade.grade);
	printf("Enter id: ");
	scanf("%d", &sid.id);
	printf("\n%d. %s of grade %d", sid.id, sname.name, sgrade.grade);
}


// ====== LABWORK 3 =========== //

void lab3_q1(){
	int a, b;
	int *pa, *pb;
	pa = &a;
	pb = &b;
	printf("Enter any two numbers: ");
	scanf("%d%d",pa,pb);
	int sum, diff, mul;
	float div;
	sum = *pa + *pb;
	mul = *pa * *pb;
	diff = *pa - *pb;
	div = (float)*pa / *pb;
	printf("sum = %d\ndifference = %d\nmultiplication = %d\ndivision = %.3f",sum,diff,mul,div);
	
}

void lab3_q2(){
	int a, *pa;
	pa = &a;
	printf("Enter a number: ");
	scanf("%d",pa);
	if(*pa%2 == 0){
		printf("even");
	}
	else{
		printf("odd");
	}
}

void lab3_q3(){
	int i,n, *pn, sum;
	pn = &n;
	float avg;
	printf("Enter the nth number: ");
	scanf("%d",pn);
	sum = 0;
	for(i = 1; i<=*pn; i++){
		sum += i;
	}
	avg = (float)sum / *pn;
	printf("sum = %d and avg = %.3f", sum, avg);
}

void lab3_q4(){
	int n = 10;
	int arr[n], *parr, i;
	parr = arr;
	printf("Enter elements of the array:\n");
	for(i = 0; i<n; i++){
		scanf("%d", (parr+i));
	}
	printf("the elements of array are: ");
	for(i = 0; i<n; i++){
		printf("%d ",*(parr+i));
	}
}

void lab3_q5(){
	int n = 10;
	int arr[n], *parr, max, min, i;
	parr = arr;
	printf("Enter the elements of the array:\n");
	for(i = 0; i<n; i++){
		scanf("%d", (parr+i));
	}
	max = *parr;
	min = *parr;
	for(i = 1; i<n; i++){
		if(max<*(parr+i))
			max = *(parr+i);
		if(min>*(parr+i))
			min = *(parr+i);
	}
	printf("max = %d and min = %d", max, min);
}

void lab3_q6_byref(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void lab3_q6_byvalue(int a, int b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("\nafter swapping from value:\nn1=%d and n2=%d",a,b);
}

void lab3_q6(){
	int n1,n2;
	printf("Enter two numbers(n1 and n2): ");
	scanf("%d%d",&n1,&n2);
	lab3_q6_byref(&n1,&n2);
	printf("after swapping from reference:\nn1=%d and n2=%d",n1,n2);
	lab3_q6_byvalue(n1, n2);
}

void lab3_q7(){
	int n = 10;
	int arr[n], *parr, i, j, temp;
	parr = arr;
	printf("Enter elements of array: ");
	 for(i = 0; i<n; i++){
	 	scanf("%d",(parr+i));
	 }
	 for(i = 0; i<n; i++){
	 	for(j = i+1; j<n; j++){
	 		if(*(parr+i)<*(parr+j)){
	 			temp = *(parr+i);
	 			*(parr+i) = *(parr+j);
	 			*(parr+j) = temp;
			 }
		 }
	 }
	 printf("The array sorted is: ");
	 for(i = 0;i<n;i++){
	 	printf("%d ",*(parr+i));
	 }
}

void lab3_q8(){
	int n, *pn, i;
	pn = &n;
	printf("Enter number: ");
	scanf("%d",pn);
	for(i = 1; i<=10; i++){
		printf("%d\t*\t%d\t=\t%d\n",*pn,i,*pn*i);
	}
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

Menu labwork2[] = {
	{1, "Array of structure 10 students", program, {.pfunction = lab2_q1}},
	{2, "Array of 20 employees", program, {.pfunction = lab2_q2}},
	{3, "Nested array of payinfo", program, {.pfunction = lab2_q3}},
	{4, "Sorting struct based on name", program, {.pfunction = lab2_q4}},
	{5, "Using typedef", program, {.pfunction = lab2_q5}},
	{6, "Sum of km and m", program, {.pfunction = lab2_q6}},
	{7, "Student using union", program, {.pfunction = lab2_q7}},
	{0, "BACK", back, {.pfunction = NULL}}
};

Menu labwork3[] = {
	{1, "Basic pointer arithemetic calc", program, {.pfunction = lab3_q1}},
	{2, "Even or odd with pointer", program, {.pfunction = lab3_q2}},
	{3, "Sum and avg of n numbers", program, {.pfunction = lab3_q3}},
	{4, "Input and print array using pointer", program, {.pfunction = lab3_q4}},
	{5, "Max and min in array using pointer", program, {.pfunction = lab3_q5}},
	{6, "Swapping by reference and value", program, {.pfunction = lab3_q6}},
	{7, "Sort arrays using pointers", program, {.pfunction = lab3_q7}},
	{8, "Multiplication table", program, {.pfunction = lab3_q8}},
	{0, "BACK", back, {.pfunction = NULL}},
};

Menu Main_Menu[] = {
	{1, "Labwork 1", sub_menu, {.submenu = labwork1}},
	{2, "Labwork 2", sub_menu, {.submenu = labwork2}},
	{3, "Labwork 3", sub_menu, {.submenu = labwork3}},
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
      int temp;
      printf("\nEnter \"YES\" if you understand: ");
      scanf("%d",&temp);
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


