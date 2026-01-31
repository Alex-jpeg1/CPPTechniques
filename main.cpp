#include<bits/stdc++.h>

using namespace std;

void test();

class secretar;

template<typename Derived>
class Scoala
{
   public:
      void Practica()
      {
         static_cast<Derived*>(this)->Activitate();
      }
   private:
      vector<secretar> Secretariat;
};

class ScoalaGimnaziala: public Scoala<ScoalaGimnaziala>
{
   public:
      void Activitate()
      {
         cout<<"Practic activitate";
      }
   private:
};

class Liceu: public Scoala<Liceu>
{
   public:
      void Activitate()
      {
         cout<<"Practica activitate";
      }
   private:
};

class ScoalaSpeciala: public Scoala<ScoalaSpeciala>
{
   public:
      void Activitate()
      {
         cout<<"Scoala Speciala";
      }
   private:
};
class secretar
{
   public:
      secretar() = default;
      secretar(string nume, string numeInstitutie, int vechime, int numarClase);
      secretar(const secretar&);
      friend ostream& operator<<(ostream&, const secretar&);
      friend istream& operator>>(istream&, secretar&);

      bool operator>(const secretar&) const ;

   private:
      string nume;
      string numeInstitutie;
      int vechime;
      int numarClase;
};

secretar::secretar(string nume, string numeInstitutie, int vechime, int numarClase)
   :nume{nume},
   numeInstitutie{numeInstitutie},
   vechime{vechime},
   numarClase{numarClase}
{

}

secretar::secretar(const secretar& other)
{
   this->nume = other.nume;
   this->numeInstitutie = other.numeInstitutie;
   this->vechime = other.vechime;
   this->numarClase = other.numarClase; 
}

ostream& operator<<(ostream& os, const secretar& obj)
{
   os<<obj.nume<<" "<<obj.numeInstitutie<<" "<<obj.vechime<<" "<<obj.numarClase;
   return os;
}

istream& operator>>(istream& is, secretar& obj)
{
   is>>obj.nume>>obj.numeInstitutie>>obj.vechime>>obj.numarClase;
   return is;
}

bool secretar::operator>(const secretar& other) const 
{
   if(this->numarClase > other.numarClase)   
   {
      return true;
   }
   return false;
}

ostream& operator<<(ostream& os, vector<secretar> v)
{
   for(auto x: v)
   {
      cout<<x<<" ";
   }
   return os;
}

void test()
{
   int numarTotal;
   cin>>numarTotal;
   vector<secretar> v;
   for(int i= 0; i<numarTotal; i++)
   {
      secretar val;
      cin>>val;
      v.emplace_back(val);
   }
   sort(v.begin(),v.end(), greater<const secretar>());
   cout<<v;
}



int main()
{
   Liceu liceu;
   liceu.Practica();
}