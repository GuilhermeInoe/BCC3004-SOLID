
//EXEMPLO RUIM:
class printCarro{
    private:
        int ano;
        float precoFipe;
        char[50] marca;
        char[50] modelo;

    public:
        void printCarro(marca, modelo, ano, precoFipe);
        void calcularIPVA(ano, precoFipe);             
};

//EXEMPLO CORRIGIDO:
class console{                                 
    private:                                          
        int ano;
        float precoFipe;
        char[50] marca;
        char[50] modelo;

    public:
        class printCarro{
            printCarro(marca, modelo, ano, precoFipe){
                //bloco de codigo
            }
        };

        class calcularIPVA{
            calcularIPVA(ano, precoFipe){
                //bloco de codigo
            }
        };
};