class intervalovy_strom //vonkajsia trieda reprezentujuca cely strom
{
    class vrchol //trieda, ktorej instancie reprezentuju vrcholy
    {
        int hodnota;
        int zaciatok, koniec; //zaciatok a koniec mojho intervalu
        vrchol *lavy, *pravy; //smerniky na synov

    public:

        //konstruktor. Vytvori vrchol zodpovedajuci intervalu [zac, kon) 
        //aj s celym podstromom
        vrchol(int zac, int kon) : zaciatok(zac), koniec(kon) 
        {
            hodnota = 0;

            //ak este nie som list, vyrobim aj svojich synov s podstromami
            if(koniec - zaciatok > 1)  
            {
                int stred = (zaciatok + koniec)/2;
                lavy = new vrchol(zaciatok, stred);
                pravy = new vrchol(stred, koniec);
            }
            else //ak som list, tak nemam synov
            {
                lavy = pravy = NULL;
            }
        }

        void zmen(int i, int h)
        {
            if(zaciatok == i && koniec == i+1) //ak som i-ty list, zmenim si hodnotu
            {
                hodnota = h;
                return;
            }
            int stred = (zaciatok + koniec)/2;

            //ak je i-ty list v lavom podstrome, delegujem poziadavku lavemu synovi
            if(i < stred) lavy -> zmen(i, h);  
            else pravy->zmen(i, h);            //ak je v pravom, tak pravemu synovi

            //pri vynarani z rekurzie sa aktualizujem
            hodnota = lavy->hodnota + pravy->hodnota; 
        }

        int sucet(int l, int r)
        {
            if(l >= koniec || r <= zaciatok) return 0;
            if(l <= zaciatok && r >= koniec) return hodnota;
            return lavy->sucet(l, r) + pravy->sucet(l, r);  //delegovanie na synov
        }

        ~vrchol() //destruktor
        {
            if(lavy != NULL) delete lavy;
            if(pravy != NULL) delete pravy;
        }
    };

    vrchol *koren;

public:
    intervalovy_strom(int velkost)
    {
        int n = 1;
        while(n < velkost) n *= 2; //najdeme najblizsiu vacsiu mocninu dvojky
        koren = new vrchol(0, n);
    }
    //   intervalovy_strom(int velkost)
    // {
    //     koren = new vrchol(0, velkost);
    // }

    void zmen(int i, int h)
    {
        koren->zmen(i, h);
    }

    int sucet(int l, int r)
    {
        return koren->sucet(l, r);
    }

    ~intervalovy_strom()
    {
        delete koren;
    }
};

int main(){

    


}