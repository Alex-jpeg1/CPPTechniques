#include<bits/stdc++.h>
#include <memory>

using namespace std;

class Proba
{
    public:
        Proba() = default;
        Proba(string nume, string locDesfasurare, string tipulProbei, string barem)
            :
            _nume{nume},
            _locDesfasurare{locDesfasurare},
            _tipulProbei{tipulProbei},
            _barem{barem}
        {}

        bool operator!=(const Proba& other)
        {
            if(_tipulProbei != other._tipulProbei)
                return true;

            return false;
        }

        friend ostream& operator<<(ostream& os, const Proba& proba)
        {
            os<<proba._nume<<" "<<proba._locDesfasurare<<" "<<proba._tipulProbei<<" "<<proba._barem;
            return os;
        } 
        friend istream& operator>>(istream& is, Proba& proba)
        {
            is>>proba._nume>>proba._locDesfasurare>>proba._tipulProbei>>proba._barem;
            return is;
        }
        virtual void SimuleazaParticipare()
        {
            cout<<"A fost apelata functia pentru proba usor";
        }
        virtual ~Proba() = default;
    private:
        string _nume;
        string _locDesfasurare;
        string _tipulProbei;
        string _barem;
};
class ProbaSportiva: public Proba
{
    public:
        ProbaSportiva() = default;
        void SimuleazaParticipare() override
        {
            cout<<"A fost facuta proba pentru sport";
        }
    private:

};
class ProbaLingvistica:public Proba
{
    public:
        ProbaLingvistica() = default;
        void SimuleazaParticipare() override
        {
            cout<<"A fost facuta proba lingvistica";
        }
    private:
};
class ProbaMuzicala:public Proba
{
    public:
        ProbaMuzicala() = default;
        void SimuleazaParticipare() override
        {
            cout<<"A fost facuta proba muzicala";
        }
    private:
};

class Candidat
{
    public:
        void Paticipa()
        {
            cout<<"Particip";
        }
    private:
        vector<shared_ptr<Proba>>_ProbeleParticipant;
};

template<typename Type>
class Comisie
{
    public:
        Comisie() = default;
        void DoWork()
        {
            //Verifica care candidati se afla in normele baremului
        }
    private:
        vector<Candidat> Candidati;
};

void test()
{
    Comisie<ProbaSportiva> ComisieSport;
    Comisie<ProbaLingvistica> ComisieLingvistica1,ComisieLingvistica2, ComisieLingvistica3;
    Comisie<ProbaMuzicala> ComisieMuzica;
}

int main()
{
    test();
}