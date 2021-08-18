#include <iostream>
using namespace std;

class AbstracEmployee
{
      virtual void AskforPromotion()=0;
};

class Employee: AbstracEmployee
{
private:
    string Name;
    string Company;
    int Age;

public:
    void setName(string name) { Name = name; }
    string getName() { return Name; }

    void setCompany(string company) { Company = company; }
    string getCompany() { return Company; }

    void setAge(int age)
    {
        if (age > 18)
            Age = age;
    }
    int getAge() { return Age; }

    void Introduce()
    {
        cout << "\nName - " << Name;
        cout << "\nCompany - " << Company;
        cout << "\nAge - " << Age;
    }

    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
        cout<<"\n***The data is updated !***";
    }
    void AskforPromotion()
    {
        if(Age<18) cout<<"\nSorry, No promotion for you !";
        else cout<<"\nYes, you are promoted !";
    }

    virtual void Work()
    {
       cout<<"\n"<< Name <<" is checking the email, reading a book,...";
    }


};

class Developer : public Employee
{
public:
    string ProLanguage;
    Developer(string name, string company, int age, string language) : Employee(name, company, age)
    {
        ProLanguage = language;
    }
    void Fixbug()
    {
        cout<<"\n"<< getName() <<" fix bug by using "<< ProLanguage;
    }
    void Work()
    {
       cout<<"\n"<<getName()<<" is working with "<<ProLanguage;
    }
};

class Marketer: public Employee
{
    public:
    string CampaignMarketing;

    Marketer(string name, string company, int age, string campaign) : Employee(name, company, age)
    {
        CampaignMarketing=campaign;
    }

    void CreatCampaign()
    {
        cout<<"\n"<<getName() <<" is preparing for the "<< CampaignMarketing;
    }

    void Work()
    {
       cout<<"\n"<<getName()<<" is preparing for the "<<CampaignMarketing;
    }
};

int main()
{
    Developer d=Developer("Dang Gia Thinh","Techcompany",19,"C++");
    Marketer m=Marketer("Johnny","Techcompany",25,"Black Friday");
    
    Employee *e1= &d;
    Employee *e2= &m;

    e1->Work();
    e2->Work();
    

    return 0;
}