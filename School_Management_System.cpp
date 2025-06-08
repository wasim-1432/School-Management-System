#include<iostream>
#include<fstream>
#include<time.h>
#include <iomanip>
#include<string.h>
using namespace std;
class School_Management
{
    private:
        string name,fName,Mname,dOb,admissionNo,_class,searchName;
        fstream file,file1;
        float mark1,mark2,mark3,mark4,mark5,mark6;
        int y;
    public:
        void New_Admission();
        void View_All_Students_Details();
        void Search_Student_Via_Class();
        void Search_Student_Via_Name();
        void View_Result_Of_Specific_Students_via_Name();
        void Add_Students_MArks();
}obj;
int main()
{
    char choice;
    cout<<"Press 1 for checking your result\n";
    cout<<"Press 2 for All Students Details\n";
    cout<<"Press 3 for checking any class students details\n";
    cout<<"Press 4 for check specific student's details\n";
    cin>>choice;
    switch(choice)
    {
        case 'A':
            obj.New_Admission();
            break;
        case '1':
            obj.View_Result_Of_Specific_Students_via_Name();
            break;
        case '2':
            obj.View_All_Students_Details();
            break;
        case '3':
            obj.Search_Student_Via_Class();
            break;
        case '4':
            obj.Search_Student_Via_Name();
            break;
        case 'R':
            obj.Add_Students_MArks();
            break;
        default:
            cout<<"Invalid Selection... Please Trya Again.";
    }
    cout<<endl;
    return 0;
}
void School_Management::New_Admission()
{
    cin.ignore();
    cout<<"------------------------------------------Admission Section----------------------------------------------------------\n";
    cout<<"Enter Student's Name :: ";
    getline(cin,name);
    cout<<"Enter Father's Name :: ";
    getline(cin,fName);
    cout<<"Enter Mother's Name :: ";
    getline(cin,Mname);
    cout<<"Enter Student's Date Of Birth :: ";
    getline(cin,dOb);
    cout<<"Enter Student's Class :: ";
    getline(cin,_class);
    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    admissionNo = "";
    srand(time(0));
    for(int i = 0; i < 10; i++) {
        int index = rand() % chars.size(); 
        admissionNo += chars[index];          
    }
    file.open("saveData4.txt",ios :: out | ios :: app);
    file<<name<<","<<fName<<","<<Mname<<","<<dOb<<","<<_class<<","<<admissionNo<<endl;
    cout<<"-------------------------------------------------Admission Ho Gya.--------------------------------------------------------------------\n";
    cout<<"Your Admission Number :: "<<admissionNo;
    file.close();
}
void School_Management::View_All_Students_Details()
{
    cin.ignore();
    file.open("saveData4.txt",ios :: in);
    cout<<"----------------------------------------------------------------------Student's Details---------------------------------------------------------------------------\n";
    cout<<left<<setw(25)<<"Student's Name"<<setw(25)<<"Father's Name"<<setw(25)<<"Mother's name"<<setw(25)<<"Date Of Birth"<<setw(20)<<"Class"<<setw(25)<<"Addmission Number"<<endl;
    while(getline(file,name,',') && getline(file,fName,',') && getline(file,Mname,',') && getline(file,dOb,',') && getline(file,_class,',') && getline(file,admissionNo))
    {
        cout<<left<<setw(25)<<name<<setw(25)<<fName<<setw(25)<<Mname<<setw(25)<<dOb<<setw(20)<<_class<<setw(25)<<admissionNo<<endl;
    }
    cout<<"-----------------------------------------------------------------------The End------------------------------------------------------------------------------------\n";
    file.close();
}
void School_Management::Search_Student_Via_Class()
{
    cin.ignore();
    file.open("saveData4.txt",ios :: in);
    string searchClass;
    cout<<"Enter The Class Number(1-9) :: ";
    getline(cin,searchClass);
    cout<<"--------------------------------------------------------------------Student's Details----------------------------------------------------------------------------\n";
    cout<<left<<setw(25)<<"Student's Name"<<setw(25)<<"Father's Name"<<setw(25)<<"Mother's name"<<setw(25)<<"Date Of Birth"<<setw(20)<<"Class"<<setw(25)<<"Addmission Number"<<endl;
    while(getline(file,name,',') && getline(file,fName,',') && getline(file,Mname,',') && getline(file,dOb,',') && getline(file,_class,',') && getline(file,admissionNo))
    {
        if(searchClass==_class)
        {
            cout<<left<<setw(25)<<name<<setw(25)<<fName<<setw(25)<<Mname<<setw(25)<<dOb<<setw(20)<<_class<<setw(25)<<admissionNo<<endl;
        }
    }
    file.close();
}
void School_Management::Search_Student_Via_Name()
{
    cin.ignore();
    file.open("saveData4.txt",ios :: in);
    cout<<"Enter Student's Name :: ";
    getline(cin,searchName);
    cout<<"--------------------------------------------------------------------Student's Details----------------------------------------------------------------------------\n";
    cout<<left<<setw(25)<<"Student's Name"<<setw(25)<<"Father's Name"<<setw(25)<<"Mother's name"<<setw(25)<<"Date Of Birth"<<setw(20)<<"Class"<<setw(25)<<"Addmission Number"<<endl;
    while(getline(file,name,',') && getline(file,fName,',') && getline(file,Mname,',') && getline(file,dOb,',') && getline(file,_class,',') && getline(file,admissionNo))
    {
        if(name==searchName)
        {
            cout<<left<<setw(25)<<name<<setw(25)<<fName<<setw(25)<<Mname<<setw(25)<<dOb<<setw(20)<<_class<<setw(25)<<admissionNo<<endl;
        }
    }
    file.close();
}
void School_Management::Add_Students_MArks()
{
    do
    {
        cin.ignore();
        cout<<"--------------------------------------------------------Add Student's Marks-------------------------------------------------------------------\n";
        file1.open("saveData5.txt",ios :: out | ios :: app);
        cout<<"Enter Student's Name :: ";
        getline(cin,name);
        cout<<"Enter Physics Mark   :: ";
        cin>>mark1;
        cout<<"Enter Chemistry Mark :: ";
        cin>>mark2;
        cout<<"Enter Math Mark      :: ";
        cin>>mark3;
        cout<<"Enter English Mark   :: ";
        cin>>mark4;
        cout<<"Enter Hindi Mark     :: ";
        cin>>mark5;
        cout<<"Enter Urdu Mark      :: ";
        cin>>mark6;
        file1<<name<<","<<mark1<<","<<mark2<<","<<mark3<<","<<mark4<<","<<mark5<<","<<mark6<<endl;
        cout<<"-----------------------------------------------------Marks Add Ho Gya...!----------------------------------------------------------------------\n";
        cout<<"Add new Student's Marks (Y/N) :: ";
        cin>>y;
    } while (y==1);
}
void School_Management::View_Result_Of_Specific_Students_via_Name()
{
    cin.ignore();
    file1.open("saveData5.txt", ios::in);
    if (!file1)
    {
        cout << "File could not be opened.\n";
        return;
    }
    cout << "Enter Student's Name :: ";
    getline(cin, searchName);
    cout << "--------------------------------------------------------------------Student's Result----------------------------------------------------------------------------\n";
    cout << left << setw(25) << "Name"
         << setw(25) << "Physics Marks"
         << setw(25) << "Chemistry Marks"
         << setw(25) << "Math Marks"
         << setw(25) << "English Marks"
         << setw(25) << "Hindi Marks"
         << setw(25) << "Urdu Marks" << endl;
    bool found = false;
    while (
        getline(file1, name, ',') &&
        file1 >> mark1 && file1.get() &&
        file1 >> mark2 && file1.get() &&
        file1 >> mark3 && file1.get() &&
        file1 >> mark4 && file1.get() &&
        file1 >> mark5 && file1.get() &&
        file1 >> mark6)
    {
        file1.get();
        if (name == searchName)
        {
            found = true;
            cout << left << setw(25) << name
                 << setw(25) << mark1
                 << setw(25) << mark2
                 << setw(25) << mark3
                 << setw(25) << mark4
                 << setw(25) << mark5
                 << setw(25) << mark6 << endl;
        }
    }
    if (!found)
    {
        cout << "No record found for student: " << searchName << endl;
    }
    file1.close();
}