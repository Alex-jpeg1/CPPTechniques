    #include<bits/stdc++.h>
    #include <memory>
    #include <unordered_map>

    using namespace std;

    class PomFructifer
    {
        public:
            PomFructifer() = default;
            PomFructifer(string speciePom, string perioadaRecoltare, int productieAnuala)
            {
                //Munceste
            }
            bool operator==(PomFructifer other)
            {
                return _speciePom == other._speciePom;
            }
            friend istream& operator>>(istream& in, PomFructifer& pom)
            {
                cin>>pom._speciePom>>pom._perioadaRecoltare>>pom._productieAnuala;
                return in;
            }
            friend ostream& operator<<(ostream& out, const PomFructifer& pom)
            {
                cout<<pom._speciePom<<" "<<pom._perioadaRecoltare<<" "<<pom._productieAnuala;
                return out;
            }
            [[nodiscard]] string GetSpecie() const 
            {
                return _speciePom;
            }
        private:
            string _speciePom;
            string _perioadaRecoltare;
            int _productieAnuala;
    };
    class Samantoase:public virtual PomFructifer{};
    class Samburoase:public virtual PomFructifer{};
    class Nucifere:public virtual PomFructifer{};

    class Mar:public Samantoase{public: Mar() = default;};
    class Par:public Samantoase{public: Par() = default;};
    class Gutui:public Samantoase{};

    class Prun:public Samburoase{};
    class Cais:public Samburoase{};
    class Piersic:public Samburoase{};
    class Cires:public Samburoase{};
    class Visin:public Samburoase{};

    class Nuc:public Nucifere{};

    class Livada
    {
        public:
            Livada():
            _NumarPomi(9)
            {}
            Livada(int NumarPomi):
            _NumarPomi{NumarPomi}
            {}
            template<typename Pom>
            void CreeazaPomi(int numarPomi)
            {
                unique_ptr<PomFructifer> pomiIntermediar = make_unique<Pom>();
                _Pomi.emplace_back(pomiIntermediar);
            }
        private:
            int _NumarPomi;
            vector<unique_ptr<PomFructifer>> _Pomi;
    };

    ostream& operator<<(ostream& out, const vector<PomFructifer> v)
    {
        for(auto x:v)
        {
            out<<x<<" ";
        }
        return out;
    }
    void test()
    {
        PomFructifer* firstElement = new PomFructifer[3];

        for(PomFructifer* currentPom = firstElement; currentPom < firstElement + 3; currentPom++)
        {
            cin>>*currentPom;
        }

        unordered_map<string, vector<PomFructifer>>aranjati;

        for(PomFructifer* currentPom = firstElement; currentPom < firstElement + 3; currentPom++)
        {
            aranjati[currentPom->GetSpecie()].push_back(*currentPom);
        }

        for(auto x: aranjati)
        {
            cout<<x.second;
            cout<<'\n';
        }

        delete[] firstElement;
    }

    void DoWork()
    {
        Livada livada;
        
        livada.template CreeazaPomi<Mar>(100);
        livada.template CreeazaPomi<Par>(50);
    }

    int main()
    {
        //test();
        DoWork();
    }