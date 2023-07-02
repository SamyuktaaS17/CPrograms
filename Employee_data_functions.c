
#include <stdio.h>
#include<time.h>

struct DateOfBirth{
    	int Date;
    	int Month;
    	int Year;
	};
    
struct Address{
    	int Door_no;
    	char Street[20];
    	char Area[20];
    	char City[20];
    	int Pincode;
	};

struct Allowance{
    	int DA;
    	int HRA;
    	int MA;
	};

struct Deduction{
    	int PF;
    	int IT;
	};
    
struct employee{
	int Emp_Id;
	char Emp_Name[20];
	struct DateOfBirth DOB;
	int age;
	struct Address add;
	char Dept[20];
	int Basic_Salary;
	struct Allowance all;
	struct Deduction ddn;
	int Gross_Salary;
	int Net_Salary;
};

struct employee database();

int main()
{
    struct employee e1[5];
    int age(int ,int ,int );
    void allowance(int ,int * ,int * ,int * );
    void gross_salary(int ,int  ,int *);
    void deduction(int ,int *,int *);
    int net_salary(int ,int ,int );
    //void payslip(struct , int ,int *);
    int id,ps=0;
    
    
    for(int i=0;i<5;i++)
	{
	    //intialisation
	    int years=0;
        e1[i].all.HRA=0,e1[i].all.MA=0,e1[i].all.DA=0;
        e1[i].ddn.PF=0,e1[i].ddn.IT=0;
        e1[i].Gross_Salary=0,e1[i].Net_Salary=0;
    
	    printf("\nEnter details of employee %d \n",i+1);
	    e1[i] = database();
	
	
	    years=age(e1[i].DOB.Date,e1[i].DOB.Month,e1[i].DOB.Year);
	    printf("\nAge is %d \n",years);
	
	    allowance(e1[i].Basic_Salary,&e1[i].all.DA,&e1[i].all.HRA,&e1[i].all.MA);
	    int allowances=e1[i].all.HRA+e1[i].all.DA+e1[i].all.MA;
	    printf("\nda: %d, hra: %d, ma: %d \n",e1->all.DA,e1->all.HRA,e1->all.MA);
	
	    gross_salary(e1[i].Basic_Salary,allowances,&e1[i].Gross_Salary);
	    printf("\nGross salary: %d \n",e1[i].Gross_Salary);
	
	    deduction(e1[i].Basic_Salary,&e1[i].ddn.PF,&e1[i].ddn.IT);
	    printf("\nPF: %d, Income Tax: %d \n",e1[i].ddn.PF,e1[i].ddn.IT);
    	int ded=e1[i].ddn.PF+e1[i].ddn.IT;
	
	    e1[i].Net_Salary=net_salary(e1[i].Basic_Salary,allowances,ded);
	    printf("\nNet Salary= %d \n",e1[i].Net_Salary);
	   
	    
	}
	
	

	printf("\nEnter Emp_Id to be searched: \n");
	scanf("%d",&id);
	payslip(e1,id, &ps);
	printf("The payslip of id %d is: %d \n",id,ps);
	max_dept(e1);
	
	return 0;
}


//employee details
struct employee database()
{
	struct employee e;
	printf("Enter Emp_ID: \n");
	scanf("%d",&e.Emp_Id);
	printf("Enter Emp_Name: \n");
	scanf("%s",e.Emp_Name);
	printf("Enter DOB DD: \n");
	scanf("%d",&e.DOB.Date);
	printf("Enter DOB MM: \n");
	scanf("%d",&e.DOB.Month);
	printf("Enter DOB YYYY: \n");
	scanf("%d",&e.DOB.Year);
	printf("Enter address details: \n");
	printf("Street: \n");
	scanf("%s",e.add.Street);
	printf("Door_No: \n");
	scanf("%d",&e.add.Door_no);
	printf("Area: \n");
	scanf("%s",e.add.Area);
	printf("City: \n");
	scanf("%s",e.add.City);
	printf("Pincode: \n");
	scanf("%d",&e.add.Pincode);
	printf("Enter Dept: \n");
	scanf("%s",e.Dept);
	printf("Enter Basic Salary: ");
	scanf("%d",&e.Basic_Salary);
	
    return e;
}

//age calculation
age(int d,int m,int y)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    tm.tm_mon=tm.tm_mon+1;
    tm.tm_year=tm.tm_year+1900;
    if(d>tm.tm_mday)
    {
        tm.tm_mon=tm.tm_mon-1;
    }
    if(m>tm.tm_mon)
    {
         tm.tm_year= tm.tm_year-1;
    }
    return(tm.tm_year-y);
}

//allowances
allowance(int bs,int *da,int *hra, int *ma)
{
    *da=0.42*bs;
    *hra=0.1*bs;
    *ma=0.15*bs;
}

//gross salary
gross_salary(int bs,int allowances,int *gs)
{
    *gs=bs+allowances;
}

//deductions
deduction(int bs, int *pf, int * it)
{
    *pf=0.12*bs;
    *it=0.2*bs;
}

//net salary
int net_salary(int bs,int all,int ded)
{
    int net_sal;
    net_sal=bs+all-ded;
    return net_sal;
}

//finding payslip of required employee
void payslip(struct employee e[5], int id, int *ps )
{
    for(int i=0;i<5;i++)
    {
        if(e[i].Emp_Id==id)
        {
            *ps= e[i].Net_Salary;
        }
    }
}

//finding department with max salary
void max_dept(struct employee e[5])
{
    int max=0;
    int id=0;
    for(int i=0;i<5;i++)
    {
        if(e[i].Net_Salary>max)
        {
            max=e[i].Net_Salary;
            id=i;
        }
    }
    printf("\nDept with highest salary is %s\n",e[id].Dept);
}