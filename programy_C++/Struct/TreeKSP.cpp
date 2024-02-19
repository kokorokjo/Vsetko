class intervalovy_strom 
{
    class vrchol 
    {
        int hodnota;
        int zaciatok, koniec; 
        vrchol *lavy, *pravy; 
    public:

       
        vrchol(int zac, int kon) : zaciatok(zac), koniec(kon) 
        {
            hodnota = 0;

            
            if(koniec - zaciatok > 1)  
            {
                int stred = (zaciatok + koniec)/2;
                lavy = new vrchol(zaciatok, stred);
                pravy = new vrchol(stred, koniec);
            }
            else 
            {
                lavy = pravy = NULL;
            }
        }

        void zmen(int i, int h)
        {
            if(zaciatok == i && koniec == i+1) 
            {
                hodnota = h;
                return;
            }
            int stred = (zaciatok + koniec)/2;

            
            if(i < stred) lavy -> zmen(i, h);  
            else pravy->zmen(i, h);         

            
            hodnota = lavy->hodnota + pravy->hodnota; 
        }

        int sucet(int l, int r)
        {
            if(l >= koniec || r <= zaciatok) return 0;
            if(l <= zaciatok && r >= koniec) return hodnota;
            return lavy->sucet(l, r) + pravy->sucet(l, r);  
        }

        ~vrchol() 
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
        while(n < velkost) n *= 2; 
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