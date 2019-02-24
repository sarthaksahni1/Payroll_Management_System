#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<process.h>

class employee

{

 int empno;
 char name[30];
 char dep[30];
 char address[70];
 char contactno[20];
 public:
 void input();
 void output();
 void readfile();
 void writefile();
 void insertfile();
 void modfile();
 void deletefile();
 void searchfile();

};

void employee::input()

{

 cout<<"\n Enter Employee Number";
 cin>>empno;
 cout<<"\nEnter Employee Name";
 gets(name);
 cout<<"\nEnter Employee Department";
 gets(dep);
 cout<<"\nEnter Employee Address";
 gets(address);
 cout<<"\nEnter Employee Contact Number";
 gets(contactno);

}

void employee::output()

{

 cout<<"\n Employee Number"<<empno;
 cout<<"\n Employee Name"<<name;
 cout<<"\n Employee department"<<dep;
 cout<<"\n Employee designation"<<dep;
 cout<<"\n Employee Address"<<address;
 cout<<"\n Employee Contact Number"<<contactno;

}

void employee::readfile()

{

 employee e;
 ifstream infile("employee.dat",ios::binary);
 if(!infile)
 cout<<"File doesn't exist";
 else
 {
  while(infile.read((char*)&e,sizeof(e)))
  e.output();
  infile.close();
 }

}

void employee::writefile()

{

 ofstream onfile("employee.dat",ios::binary);
 employee e[10];
 int n,i;
 cout<<"\n Enter total number of employees";
 cin>>n;
 cout<<"\n[Enter all employee information one after other]";
 for(i=0;i<n;i++)
 {
  e[i].input();
  onfile.write((char*)&e[i],sizeof(e[i]));
 }
 onfile.close();

}

void employee::insertfile()

{

 int f=0;
 employee e1,e2;
 ofstream onfile("temp.dat",ios::binary);
 ifstream infile("employee.dat",ios::binary);
 if(!infile)
 cout<<"File doesnot exist";
 else
 {
  cout<<"enter new employee information";
  e1.input();
  while(infile.read((char*)&e2,sizeof(e2)))
 {
 if(e1.empno<e2.empno)
 {
  onfile.write((char*)&e1,sizeof(e1));
  f=1;
  break;
 }
 else
 onfile.write((char*)&e2,sizeof(e2));
 }
 if(f==1)
 {
  onfile.write((char*)&e2,sizeof(e2));
  while(infile.read((char*)&e2,sizeof(e2)))
 {
 onfile.write((char*)&e2,sizeof(e2));
 }
 }
 else
 {
  onfile.write((char*)&e1,sizeof(e1));
  onfile.close();
  infile.close();
  remove("employee.dat");
  rename("temp.dat","employee.dat");
 }
 }
}

void employee::modfile()

{

 int f=0;
 ifstream infile("employee.dat",ios::binary);
 ofstream onfile("temp.dat",ios::binary);
 employee e1,e2;
 if(!infile)
 cout<<"file doesnot exist";
 else
 {
  e1.input();
  while(infile.read((char*)&e2,sizeof(e2)))
  {
   if(e1.empno==e2.empno)
   {
    onfile.write((char*)&e2,sizeof(e2));
   }
   if(f==0)
   cout<<"\n Employee number not exist";
   else
   {
    infile.close();
    onfile.close();
    remove("employee.dat");
	 rename("temp.dat","employee.dat");
   }
  }
}
}

void employee::deletefile()

{

 int rno,f=0;
 employee e;
 ifstream infile("employee.dat",ios::binary);
 ofstream onfile("temp.dat",ios::binary);
 if(!infile)
 cout<<"file doesnot exist";
 else
 {
  cout<<"enter employee number";
  cin>>rno;
  while(infile.read((char*)&e,sizeof(e)))
  {
	if(e.empno!=rno)
	onfile.write((char*)&e,sizeof(e));
	else
	f=1;
  }
 infile.close();
 onfile.close();
 if(f==0)
 cout<<"Employee with the given information";
 else
 {
  cout<<"\n\n File Deleted\t\t";
  remove("employee.dat");
  rename("temp.dat","employee.dat");
  }
 }
}


void employee::searchfile()

{

 int rn,f=0;
 employee e;
 ifstream infile("employee.dat",ios::binary);
 if(!infile)
 cout<<"file doesnot exist";
 else
 {
  cout<<"\n Enter employee number";
  cin>>rn;
  while(infile.read((char*)&e,sizeof(e)&&(f==0)))
  {
  if(e.empno==rn)
  {
	e.output();
	f=1;
  }
 }
}
 if(f==0)
 cout<<"\n Employee with the information doenot exist";
 infile.close();
}

class salary

{

  int empno;
  char name[30];
  char des[30];
  char dep[40];
  long int bp,hra,da,np,perks;

  public:
  void calculate();
  void input();
  void output();
  void readfile();
  void writefile();
  void insertfile();
  void modfile();
  void deletefile();
  void searchfile();

};

void salary::input()

{

	cout<<"\nEnter Employee Number:";
	cin>>empno;
	cout<<"\nEnter Employee Name:";
	gets(name);
	cout<<"\nEnter Department:";
	gets(dep);
	cout<<"\nEnter Designation:";
	gets(des);
	cout<<"\nEnter Employees Basic Pay:";
	cin>>bp;
	cout<<endl;
	calculate();

}

void salary::output()

{

	cout<<"\n\nEmployee Number:";
	cout<<empno;
	cout<<"\nEmployee Name:"<<name;
	cout<<"\nEmployee Department:"<<dep;
	cout<<"\nEmployee Designation:"<<des;
	cout<<"\nEmployee Basic Pay:"<<bp;
	cout<<"\nEmployee House Rental Allowance:"<<hra;
	cout<<"\nEmployee Domestic Allowance:"<<da;
	cout<<"\nEmployee Net Pay:"<<np;
	if(bp>40000)
	{
	  cout<<"\nPerks:Home Furnish Allowance,Chauffer,Fuel,Telephone,Electricity:"<<perks;
	}
	if((bp<40000)&&(bp>30000))
	{
	  cout<<"\nPerks:Chauffer,Fuel,Telephone,Electricity:"<<perks;
	}
	if((bp<30000)&&(bp>20000))
	{
	  cout<<"\nPerks:Fuel,Telephone,Electricity:"<<perks;
	}
	if((bp<20000)&&(bp>10000))
	{
	  cout<<"\nPerks:Telephone,Electricity:"<<perks;
	}
	if(bp<10000)
	{
	  cout<<"\nPerks:Telephone:"<<perks;
	}

}

void salary::calculate()

{

	perks=0;
	float chauffer=5000;
	float fuel=3000;
	float tele=100;
	float elec=5000;
	float hfa=5000;

	if((bp>=40000))
	{
	  hra=0.30*bp;
	  da=0.40*bp;
	  perks=hfa+chauffer+fuel+tele+elec;
	}
	if((bp<40000)&&(bp>=30000))
	{
	  hra=0.25*bp;
	  da=0.35*bp;
	  perks=chauffer+fuel+tele+elec;
	}
	if((bp<30000)&&(bp>=20000))
	{
	  hra=0.20*bp;
	  da=0.30*bp;
	  perks=fuel+tele+elec;
	}
	if((bp<20000)&&(bp>=10000))
	{
	  hra=0.15*bp;
	  da=0.25*bp;
	  perks=tele+elec;
	}
	if((bp<10000))
	{
	  hra=0.10*bp;
	  da=0.20*bp;
	  perks=tele;
	}

np=hra+da+bp+perks;

}

void salary::readfile()

{

  salary s;

  ifstream infile("salary.dat",ios::binary);
  if(!infile)
  cout<<"File Doesnot Exist";
  else
  {
  while(infile.read((char*)&s,sizeof(s)))
  {
  s.output();
  infile.close();
  }}

}

void salary::writefile()

{

  ofstream onfile("salary.dat",ios::binary);
  salary s[10];
  int n,i;
  cout<<"\nEnter Total Number Of Employees:";
  cin>>n;
  cout<<"\n[Enter all Employee Information One After Other:]\n";
  for(i=0;i<n;i++)
  {
  s[i].input();
  onfile.write((char*)&s[i],sizeof(s[i]));
  }
  onfile.close();

}

void salary::insertfile()

{

  int f=0;
  salary s1,s2;
  ofstream onfile("temp.dat",ios::binary);
  ifstream infile("salary.dat",ios::binary);
  if(!infile)
  cout<<"File Does Not Exist";
  else
  {
  cout<<"Enter New Employee Information:\n";
  s1.input();
  while(infile.read((char*)&s2,sizeof(s2)))
	 {
	 if(s1.empno<s2.empno)
	 {
	 onfile.write((char*)&s1,sizeof(s1));
	 f=1;
	 break;
	 }
	 else
	 onfile.write((char*)&s2,sizeof(s2));
	 }
  if(f==1)
  {
  onfile.write((char*)&s2,sizeof(s2));
  while(infile.read((char*)&s2,sizeof(s2)));
	{
	onfile.write((char*)&s2,sizeof(s2));
	}
  }
  else
  onfile.write((char*)&s1,sizeof(s1));
  onfile.close();
  infile.close();
  remove("salary.dat");
  rename("temp.dat","salary.dat");
  }

}

void salary::modfile()

{
  int f=0;
  ifstream infile("salary.dat",ios::binary);
  ofstream onfile("temp.dat",ios::binary);
  salary s1,s2;
  if(!infile)
  cout<<"File Does Not Exist";
  else
  {
  s1.input();
  while(infile.read((char*)&s2,sizeof(s2)))
	{
	if(s1.empno==s2.empno)
	 {
	 onfile.write((char*)&s1,sizeof(s1));
	 f=1;
	 }
	}
	onfile.write((char*)&s2,sizeof(s2));

	if(f==0)
	cout<<"\nEmployee Number Doesnot Exist";
	else
	{
	infile.close();
	onfile.close();
	remove("salary.dat");
	rename("temp.dat","salary.dat");
	}
}

}
void salary::deletefile()

{

	int rno,f=0;
	salary s;
	ifstream infile("salary.dat",ios::binary);
	ofstream onfile("temp.dat",ios::binary);
	if(!infile)
	cout<<"\nFile Does Not Exist.";
	else
	{
	cout<<"\nEnter Employee Number:";
	cin>>rno;
	while(infile.read((char*)&s,sizeof(s)))
	 {
	 if(s.empno!=rno)
	 onfile.write((char*)&s,sizeof(s));
	 else
	 f=1;
	 }
	infile.close();
	onfile.close();
	if(f==0)
	cout<<"\nEmployee With The Given Information Does Not Exist.";
	else
	{
	cout<<"\n\nFile Deleted.\t\t";
	remove("salary.dat");
	rename("temp.dat","salary.dat");
	}
	}

}

void salary::searchfile()

{

  int rn,f=0;
  salary s;
  ifstream infile("salary.dat",ios::binary);
  if(!infile)
  cout<<"File Does Not Exist";
  else
  {
  cout<<"\nEnter any Employee Number:";
  cin>>rn;
  while(infile.read((char*)&s,sizeof(s))&&(f==0))
	{
	if(s.empno==rn)
	{
	s.output();
	f=1;
	}
	}
  if(f==0)
  cout<<"\nEmployee With Given Information Does Not Exist.";
  infile.close();
  }

}

void wel_screen()

{

	cout<<"\n\n";
	cout<<"\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	cout<<"\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	cout<<"\t\t++                               ++\n";
	cout<<"\t\t++                               ++\n";
	cout<<"\t\t++     PAYROLL                   ++\n";
	cout<<"\t\t++     MANAGEMENT                ++\n";
	cout<<"\t\t++     SYSTEM                    ++\n";
	cout<<"\t\t++                               ++\n";
	cout<<"\t\t++                               ++\n";
	cout<<"\t\t++    DEVELOPED BY:-             ++\n";
	cout<<"\t\t++    SARTHAK SAHNI              ++\n";
	cout<<"\t\t++          &                    ++\n";
	cout<<"\t\t++    MOHIT MAKHIJA              ++\n";
	cout<<"\t\t++        XII-B                  ++\n";
	cout<<"\t\t++                               ++\n";
	cout<<"\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	cout<<"\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

}

void main()

 {
 employee e;
 salary s;
 int choice;
 char ch;
 int w;
 wel_screen();
 getche();

 do
 {
 clrscr();
 l1:cout<<"\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	 cout<<"\t\t++                               ++\n";
	 cout<<"\t\t++\t 1.EMPLOYEE INFORMATION      ++\n";
	 cout<<"\t\t++\t 2.PAYROLL INFORMATION       ++\n";
	 cout<<"\t\t++\t 3.EXIT                      ++\n";
	 cout<<"\t\t++                               ++\n";
	 cout<<"\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	 cout<<"\n\n\t\tENTER YOUR CHOICE:";
	 cin>>choice;
 clrscr();
 switch(choice)
 {
  case 1:
  do
  {
  l2:clrscr();
  cout<<"\n\t\t+-+-+-+-+-+-+-+-+EMPLOYEE INFORMATION+-+-+-+-+-+-+-+-+-\n\t\t";
  cout<<"\n\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
  cout<<"\t\t++                                                     ++\n";
  cout<<"\t\t++                                                     ++\n";
  cout<<"\t\t++   1.Write Payroll Information.                      ++\n";
  cout<<"\t\t++   2.Read Payroll Information.                       ++\n";
  cout<<"\t\t++   3.Search Payroll Information.                     ++\n";
  cout<<"\t\t++   4.Modify Payroll Information.                     ++\n";
  cout<<"\t\t++   5.Delete Payroll Information.                     ++\n";
  cout<<"\t\t++   6.Insert Payroll Information.                     ++\n";
  cout<<"\t\t++   7.Exit.                                           ++\n";
  cout<<"\t\t++                                                     ++\n";
  cout<<"\t\t++                                                     ++\n";
  cout<<"\n\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
  cout<<"\n\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
  cout<<"\n\n\t\tEnter Your Choice:";
  cin>>(w);
  clrscr();
  switch(w)
  {
  case 1:e.writefile();
  break;
  case 2:e.readfile();
  getche();
  break;
  case 3:e.searchfile();
  getche();
  break;
  case 4:e.modfile();
  break;
  case 5:e.deletefile();
  getche();
  break;
  case 6:e.insertfile();
  break;
  case 7:goto l1;
  default:cout<<"Wrong Input!!";
  getche();
  goto l2;
  }
 }while(w!=7);
 case 2:
 do
 {
 l3:clrscr();
  cout<<"\n\t\t+-+-+-+-+-+-+-+-+PAYROLL INFORMATION+-+-+-+-+-+-+-+-+-+	\n\t\t";
  cout<<"\n\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
  cout<<"\t\t++                                                     ++\n";
  cout<<"\t\t++                                                     ++\n";
  cout<<"\t\t++   1.Write Payroll Information.                      ++\n";
  cout<<"\t\t++   2.Read Payroll Information.                       ++\n";
  cout<<"\t\t++   3.Search Payroll Information.                     ++\n";
  cout<<"\t\t++   4.Modify Payroll Information.                     ++\n";
  cout<<"\t\t++   5.Delete Payroll Information.                     ++\n";
  cout<<"\t\t++   6.Insert Payroll Information.                     ++\n";
  cout<<"\t\t++   7.Exit.                                           ++\n";
  cout<<"\t\t++                                                     ++\n";
  cout<<"\t\t++                                                     ++\n";
  cout<<"\n\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
  cout<<"\n\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
  cout<<"\n\n\t\tEnter Your Choice:";
  cin>>(w);
  clrscr();
  switch(w)
  {
  case 1:s.writefile();
  break;
  case 2:s.readfile();
  getche();
  break;
  case 3:s.searchfile();
  getche();
  break;
  case 4:s.modfile();
  break;
  case 5:s.deletefile();
  getche();
  break;
  case 6:s.insertfile();
  break;
  case 7:goto l1;
  default:cout<<"Wrong Input!!";
  getche();
  goto l1;
  }
 }
 while(w!=7);
 {
  case 3:
  cout<<"\n\n\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
  cout<<"\t\t+                                 +\n";
  cout<<"\t\t+          THANK YOU..!!          +\n";
  cout<<"\t\t+                                 +\n";
  cout<<"\n\n\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

  exit(0);

  }
 cout<<"\n\n\t\t Do You Want To Continue Or Not[y/n]?";
 cin>>ch;
 }
} while(ch=='Y'||ch=='y');
}

