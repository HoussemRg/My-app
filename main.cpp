#include <iostream>
#include <string>

using namespace std;

class Employee{
protected:
    string nom;
    string numMatricule;
public:
    Employee(string name="",string num="0");
    string getNom()const;
    string getNumMatricule()const;
    virtual double calculSalaire()=0;


};


Employee::Employee(string name,string num):nom(name),numMatricule(num){}
string Employee::getNom()const{
    return this->nom;
}
string Employee::getNumMatricule()const{
    return this->numMatricule;
}

bool operator<(Employee& e1,Employee& e2){
    return ((e1.calculSalaire())<(e2.calculSalaire()));
}


ostream& operator<<(ostream& flux,Employee& e){
    flux<<"Nom : "<<e.getNom()<<endl;
    flux<<"Matricule : "<<e.getNumMatricule()<<endl;
    flux<<"salaire : "<<e.calculSalaire()<<endl;
    return flux;
}



class Enseignant:public virtual Employee{
protected:
    string specialite;
    double chargeHoraire;
public:
    Enseignant(string no,string num, string spec,double n=10);
    void setChargeHoraire(double n);
    string getSpecialite()const;
    double getHoraire()const;
    double calculSalaire();



};

Enseignant::Enseignant(string no,string num, string spec,double n):Employee(no,num),specialite(spec),chargeHoraire(n){}
void Enseignant::setChargeHoraire(double n){
    this->chargeHoraire=n;
}
string Enseignant::getSpecialite()const{
    return this->specialite;
}
double Enseignant::getHoraire()const{
    return this->chargeHoraire;
}
double Enseignant::calculSalaire(){
    return ((this->chargeHoraire)*4*25);
}

class Administratif:public virtual Employee{
protected :
    int nbAnne;
public :
    Administratif(string nom="",string num="",int nb=0);
    int getNbAnneAncienne();
    void incrementerAnne();

};
Administratif::Administratif(string nom,string num,int nb):Employee(nom,num),nbAnne(nb){}
int Administratif::getNbAnneAncienne(){
    return this->nbAnne;
}
void Administratif::incrementerAnne(){
    this->nbAnne++;
}

class Directeur: public Administratif{
public:
    Directeur(string n,string num,int nb=0);
    double calculSalaire();


};
Directeur::Directeur(string n,string num,int nb):Employee(n,num),Administratif(n,num,nb){}
double Directeur::calculSalaire(){
    return (1000+(30*this->nbAnne));
}
class ChefDepartement:public Enseignant,public Administratif{
public:
    ChefDepartement(string no,string num, string spec,double n,int nb);
    double calculSalaire();

};

ChefDepartement::ChefDepartement(string no,string num, string spec,double n,int nb):Employee(no,num),Enseignant(no,num,spec,n),Administratif(no,num,nb){}
double ChefDepartement::calculSalaire(){
    return ((this->chargeHoraire)*4*25+200);
}

class Fonctionnaire: public Administratif{
public:
    Fonctionnaire(string n,string num,int nb=10);
    double calculSalaire();


};
Fonctionnaire::Fonctionnaire(string n,string num,int nb):Employee(n,num),Administratif(n,num,nb){}
double Fonctionnaire::calculSalaire(){
    return (500+(30*this->nbAnne));
}


class Centre{
private:
    string nomCentre;
    Employee** tab;
    int nbEmployee;
public:
    Centre(string n);
    string getNom();
    int getNombreEmployee();
    void ajouterEmployee(Employee* E);
    double calculSalaireTotal();
    friend ostream& operator<<(ostream& flux,Centre& C);
};
Centre::Centre(string n):nomCentre(n),nbEmployee(0){
    this->tab=new Employee* [100];
    for(int i=0;i<100;i++){
        this->tab[i]=NULL;
    }
}
string Centre::getNom(){
    return this->nomCentre;
}
int Centre::getNombreEmployee()
{
    return this->nbEmployee;
}
void Centre::ajouterEmployee(Employee* E){
    for(int i=0;i<100;i++){
        if(this->tab[i]==NULL){
            this->tab[i]=E;
            this->nbEmployee++;
            break;
        }
    }
}

double Centre::calculSalaireTotal(){
    double s=0;
    for(int i=0;i<this->nbEmployee;i++){
       if(this->tab[i]!=NULL){
          s+=this->tab[i]->calculSalaire();
       }
    }
    return s;
}

ostream& operator<<(ostream& flux,Centre& C){
    flux<<"Nom du Centre : "<<C.getNom()<<endl;
    for(int i=0;i<C.getNombreEmployee();i++ ){
        flux<<(*C.tab[i]);
    }
    flux<<"Salaire Total : "<<C.calculSalaireTotal()<<endl;
    return flux;
}

int main()
{
    Enseignant E("Achraf","1288","Telecom",10);
    Directeur D("Houssem","1563",20);
    ChefDepartement Ch("Seif","1485","Mecanique",15,3);
    Fonctionnaire F("Ayoub","1354",36);
    Centre C("Notre Centre ");
    C.ajouterEmployee(&D);
    C.ajouterEmployee(&E);
    C.ajouterEmployee(&Ch);
    C.ajouterEmployee(&F);
    cout<<C;




    return 0;
}
