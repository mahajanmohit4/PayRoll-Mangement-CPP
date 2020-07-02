#include <iostream>
#include <string.h>

using namespace std;
 string Emp_Name;
class Employee
{
protected:

    int Join_Year;
    int Emp_age;
    int Emp_id;

public:

    void Accept()
    {
         cout<<"\n------------------------------------------------"<<endl;
        cout<<"Enter Employee ID          : ";
        cin>>Emp_id;
        cout<<"Enter Employee name        : ";
        cin.ignore();
        getline(cin,Emp_Name);
        cout<<"Enter Employee age         : ";
        cin>>Emp_age;
        cout<<"Enter Employee join Year   : ";
        cin>>Join_Year;
         cout<<"\n------------------------------------------------"<<endl;

    }
    void Display_Emp_detail()
    {
        cout<<"\n------------------------------------------------"<<endl;
        cout<<"          Employee information "<<endl;
        cout<<"\n------------------------------------------------"<<endl;

        cout<<"Employee ID          : "<<Emp_id<<endl;
        cout<<"Employee name        : "<<Emp_Name<<endl;
        cout<<"Employee age         : "<<Emp_age<<endl;
        cout<<"Employee join Year   : "<<Join_Year<<endl;

        cout<<"\n------------------------------------------------"<<endl;

    }
};

class Admin : public Employee
{
protected:
    double Emp_Basic_Salary;
    int Emp_OT_Hour;
    float Emp_OT;
    float Emp_Overtime_Pay , Emp_Tax_Rate;
    float Emp_Gross_Pay , Emp_Net_Pay;
    float Emp_Annual_Pay;
    float Emp_travel_cut;
    int   Total_Exp;
    int Emp_leave;
    int km;
    char Emp_Pay_Grade;
    float Payment_with_leave,Leave;


public:
    void Accept1()
    {
        //Accept();
         cout<<"\n------------------------------------------------"<<endl;
        cout<<"Enter Monthly salary       : ";
        cin>>Emp_Basic_Salary;

        cout<<"Enter Over Time in hours   : ";
        cin>>Emp_OT_Hour;

        cout<<"Enter Absenties            : ";
        cin>>Emp_leave;

        cout<<"KMs Travel                 : ";
        cin>>km;

         cout<<"\n------------------------------------------------"<<endl;
    }
    void Overtime_Pay();
    void Tax_Rate();
    void Pay_Grade();
    void travelallownces();
    void Emp_Payment();
    void Emp_Yearly_Payment();
	void Emp_Experience_Count();
	void Emp_Retire_Year();
	void Emp_Leave_Pay();


};

void Admin :: Overtime_Pay()
{
    Emp_OT = Emp_Basic_Salary * .01;
    Emp_Overtime_Pay = Emp_OT_Hour * Emp_OT;

}


void Admin :: Tax_Rate()
{
    if(Emp_Basic_Salary < 10000)
    {
        Emp_Tax_Rate = Emp_Basic_Salary * .05;  // .05 means 5%

    }
    if(Emp_Basic_Salary >= 10000 && Emp_Basic_Salary <= 20000)
    {
        Emp_Tax_Rate = Emp_Basic_Salary * .10;  // .10 means 10%

    }
    else if(Emp_Basic_Salary >= 20000 && Emp_Basic_Salary <=30000)
    {
        Emp_Tax_Rate = Emp_Basic_Salary * .15;

    }
    else if(Emp_Basic_Salary >= 30000 && Emp_Basic_Salary <= 40000)
    {
        Emp_Tax_Rate = Emp_Basic_Salary * .20;

    }
    else if(Emp_Basic_Salary >= 40000 && Emp_Basic_Salary <= 50000)
    {
        Emp_Tax_Rate = Emp_Basic_Salary * .25;

    }
    else if(Emp_Basic_Salary > 50000)
    {
        Emp_Tax_Rate = Emp_Basic_Salary * .30;

    }
}

void Admin :: travelallownces()
{
    if(km>=1 && km<=4)
    {
        Emp_travel_cut = 500;
    }
    else if(km>=5 && km<=15)
    {
        Emp_travel_cut = 1000;
    }

    else if(km>=16 && km<=20)
    {
        Emp_travel_cut = 1500;
    }
    else if(km>20)
    {
        Emp_travel_cut = 2000;

    }
    else
    {
        Emp_travel_cut = 0;

    }


}
void Admin :: Pay_Grade()
{
	if(Emp_Basic_Salary <= 10000)
    {
        Emp_Pay_Grade = 'F';

    }
    else if(Emp_Basic_Salary >= 10001 && Emp_Basic_Salary <= 20000)
    {
    	Emp_Pay_Grade = 'E';
    }
    else if(Emp_Basic_Salary >= 20001 && Emp_Basic_Salary <=30000)
    {
            Emp_Pay_Grade = 'D';

    }
    else if(Emp_Basic_Salary >= 30001 && Emp_Basic_Salary <= 40000)
    {
            Emp_Pay_Grade = 'C';
    }
    else if(Emp_Basic_Salary >= 40001 && Emp_Basic_Salary <= 50000)
    {
    	Emp_Pay_Grade = 'B';
    }
    else
    {
    	Emp_Pay_Grade = 'A';
    }
}
void Admin :: Emp_Payment()
{
    Emp_Gross_Pay = Emp_Basic_Salary + Emp_Overtime_Pay - Payment_with_leave - Emp_travel_cut;
    Emp_Net_Pay = Emp_Gross_Pay - Emp_Tax_Rate ;

}


void Admin :: Emp_Yearly_Payment()
{
	Emp_Annual_Pay = 12 * Emp_Basic_Salary;
     cout<<"\n------------------------------------------------"<<endl;
	cout<<"Annual Income              : "<<"Rs. "<<Emp_Annual_Pay<<endl;
	 cout<<"\n------------------------------------------------"<<endl;
}


 void Admin::Emp_Experience_Count()
 {

	Total_Exp = 2020 - Join_Year;
     cout<<"\n------------------------------------------------"<<endl;
	cout<<"Total work experience      : "<<Total_Exp<<" years"<<endl;
	 cout<<"\n------------------------------------------------"<<endl;
 }

void Admin :: Emp_Retire_Year()
{

	 	if(Emp_age<60)
		{
            int Remaining_year=60-Emp_age;
             cout<<"\n------------------------------------------------"<<endl;
            cout<<"Employee remaining year    : "<<Remaining_year<<" Years"<<endl;
             cout<<"\n------------------------------------------------"<<endl;
		}
		else
		{
			cout<<endl<<" Employee retired    : "<<endl;
		}

}

void Admin :: Emp_Leave_Pay()
{

     Leave = Emp_Basic_Salary * .01;

       Payment_with_leave =  Emp_leave * Leave;

}


class PayRoll : public Admin
{
public:
    void Payment()
    {
        cout<<"\n-----------------------------------------------"<<endl;
        cout<<"Employee ID          : "<<Emp_id<<endl;
        cout<<"Employee name        : "<<Emp_Name<<endl;
        cout <<"Employee Pay Grade   : " <<Emp_Pay_Grade << endl;
        cout<<"Overtime Money is    : "<<"Rs. "<<Emp_Overtime_Pay<<endl;
        cout<<"Absents Salary cut   : "<<"Rs. "<< Payment_with_leave<<endl;
        cout<<"Withholding Tax      : "<<"Rs. "<<Emp_Tax_Rate<<endl;
        cout<<"Travel Cut           : "<<"Rs. "<<Emp_travel_cut<<endl;
        cout<<"Gross Payment        : "<<"Rs. "<<Emp_Gross_Pay<<endl;   //Without Tex Payment
        cout<<"Net Payment          : "<<"Rs. "<<Emp_Net_Pay<<endl;
         cout<<"\n------------------------------------------------"<<endl;

    }
};

int main()
{
    while(1)
    {


     PayRoll emp;
    int n;

    cout<<"\n\n1. Enter the employee details    : "<<endl;
    cout<<"2. Enter details from admin      : "<<endl;
    cout<<"3. View the employee detials     : "<<endl;
    cout<<"4. view employee Pay slip        : "<<endl;
    cout<<"5. The employee yearly payment   : "<<endl;
    cout<<"6. Experiance in this company    : "<<endl;
    cout<<"7. The employee Job in hand      : "<<endl;
    cout<<"8. Exit "<<endl<<endl;


    cout<<"Enter choice : ";
    cin>>n;

    switch(n)
    {
    case 1:
        {
             emp.Accept();
             break;
        }
    case 2:
        {
             emp.Accept1();
    emp.Overtime_Pay();

    emp.Emp_Leave_Pay();

    emp.Pay_Grade();

    emp.Tax_Rate();

    emp.travelallownces();

    emp.Emp_Payment();
    break;

        }
    case 3:
        {
             cout<<"\n-----------------------------------------------"<<endl;
                emp.Display_Emp_detail();
                break;
        }
    case 4:
        {
            emp.Payment();
            break;
        }
    case 5:
        {
            emp.Emp_Yearly_Payment();
            break;
        }
    case 6:
        {
            emp.Emp_Experience_Count();
            break;
        }
    case 7:
        {
            emp.Emp_Retire_Year();
            break;
        }
    case 8:
        {
            return 0;
        }
    }

    }




    return 0;
}
