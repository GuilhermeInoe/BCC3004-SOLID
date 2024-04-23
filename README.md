# BCC3004-SOLID
Atividade sobre princípios SOLID de Engenhraria de software.
  Princípios Escolhidos: - Princípio da Segregação da Interface
                         - Princípio da responsabilidade única
                         - 
                         - 


<h2>  Principio da Segregação da Interface </h2>
<h3>Este princípio diz que interfaces específicas são melhores do que interfaces gerais</h3>
<h4>Exemplo ruim:</h4>
<p>class DebitarPagamento{
    void processarPagamentoCartao() //Neste caso, ao efetuar um pagamento em um cartão, a classe implementa a função processarPagamentoPix(), mesmo não sendo utilizada 

    void processarPagamentoPix()
};</p>

<h4>Exemplo corrigido:</h4>
<p>class pagamentoCartao{          //Neste caso, as interfaces foram separadas, onde cada uma delas executa uma funcionalidade própria
      void processarPagamentoCartao()
    };
  
    class pagamentoPix{
      void processarPagamentoCredito()
    };
};</p>

<h2>  Princípio da responsabilidade única </h2>
<h3>Este princípio diz que toda classe deve ter apenas uma responsabilidade</h3>
<h4>Exemplo ruim:</h4>
<p>class printCarro{
    private:
        int ano;
        float precoFipe;
        char[50] marca;
        char[50] modelo;

    public:
        void printCarro(marca, modelo, ano, precoFipe) //Neste exemplo, a mesma classe é responsável por duas
        void calcularIPVA(ano, precoFipe)              //atividades: imprimir veiculo e calcular o ipva
};</p>

<h4>Exemplo corrigido:</h4>
<p>namespace console{                                 //Neste caso, temos classes separadas, que se preocupam somente com 
    private:                                          //uma única função
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
};</p>
