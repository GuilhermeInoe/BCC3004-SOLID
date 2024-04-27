# BCC3004-SOLID
Atividade sobre princípios SOLID de Engenhraria de software. </br>
  Princípios Escolhidos: </br>
<p>    - Princípio da Segregação da Interface </br></p>
<p>    - Princípio da responsabilidade única </br></p>
<p>    - Substituição de Liskov </br></p>
<p>    - Demeter</br></p>

</br>
</br>
</br>
<h2>  Principio da Segregação da Interface </h2>
<h3>Este princípio diz que interfaces específicas são melhores do que interfaces gerais</h3>
<h4>Exemplo ruim:</h4>
<p>Neste caso, ao efetuar um pagamento em um cartão, a classe implementa a função processarPagamentoPix(), mesmo não sendo utilizada</p>

```
class DebitarPagamento{
    void processarPagamentoCartao() 

    void processarPagamentoPix()
};
```

<h4>Exemplo corrigido:</h4>
<p>Neste caso, as interfaces foram separadas, onde cada uma delas executa uma funcionalidade própria</p>

```
class pagamentoCartao{          
      void processarPagamentoCartao()
    };
  
    class pagamentoPix{
      void processarPagamentoCredito()
    };
};
```
</br>
</br>
</br>
<h2>  Princípio da responsabilidade única </h2>
<h3>Este princípio diz que toda classe deve ter apenas uma responsabilidade</h3>
<h4>Exemplo ruim:</h4>
<p>Neste exemplo, a mesma classe é responsável por duas atividades: imprimir veiculo e calcular o ipva</p>

```
class printCarro{
    private:
        int ano;
        float precoFipe;
        char[50] marca;
        char[50] modelo;

    public:
        void printCarro(marca, modelo, ano, precoFipe) 
        void calcularIPVA(ano, precoFipe)             
};
```

<h4>Exemplo corrigido:</h4>
<p>Neste caso, temos classes separadas, que se preocupam somente com uma única função</p>

```
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
```

<h2>  Substituição de Liskov </h2>
<h3>O Princípio de Substituição de Liskov diz que objetos podem ser substituídos por seus subtipos sem que isso afete a execução correta do programa</h3>
<h4>Exemplo ruim:</h4>
<p>Neste exemplo, para calcular a área do quadrado, o código ignora o valor da altura, assim, um objeto da classe quadrado não pode ser substituído por um objeto da classe figura, sem afetar o funcionamento do programa</p>

```

using System;

namespace LSP_Violacao
{
    class Program
    {
        private static Retangulo getNovoRetangulo()
        {
            //um factory
            return new Quadrado();
        }

        static void Main(string[] args)
        {
            //vamos criar um novo retangulo
             Retangulo r = Program.getNovoRetangulo();

            //definindo a largura e altura do retangulo   
             r.setLargura(5);
             r.setAltura(10);
            // o usuário sabe que r é um retângulo
            // e assume que ele pode definir largura e altura
           // como para a classe base(Retangulo)

            Console.WriteLine(r.getArea());
            Console.ReadKey();
           // O valor retornado é 100 e não 50 como era esperado
        }
    }
}

```

<h4>Exemplo corrigido:</h4>
<p>Alterando o método estático getNovoRetangulo(); podemos garantir o funcionamento correto do programa </p>

```

using System;

namespace LSP_Correcao
{
    class Program
    {
        
        private static Retangulo getNovoRetangulo()
        {
        //um factory
        return new Retangulo();
        }

        static void Main(string[] args)
        {
            //vamos criar um novo retangulo
             Retangulo r = Program.getNovoRetangulo();

            //definindo a largura e altura do retangulo   
             r.setLargura(5);
             r.setAltura(10);
            // o usuário sabe que r é um retângulo
            // e assume que ele pode definir largura e altura
           // como para a classe base(Retangulo)

            Console.WriteLine(r.getArea());
            Console.ReadKey();
           // O valor retornado é 100 e não 50 como era esperado
        }
    }
}
```

<h2>  Demeter </h2>
<h3>Este princípio diz que devemos evitar longas cadeias de chamadas de métodos</h3>
<h4>Exemplo ruim:</h4>
<p>Neste exemplo, estamos violando a lei de demeter ao acessar o item do pedido através do cliente</p>

```
class item{
    private:
        float preco;

    public:
        montarItem(){
            //bloco de código
        }
}

class pedido{
    private:
        int quantidade;

    public:
        getItem(){
            return item;
        }
}

class cliente{
    private:
        char[50] nome;

    public:
        getPedido() {
            return pedido;
        }
        
}

int main(){
    char Pedido = cliente.getPedido()->getItem()->montarItem();
}

```

<h4>Exemplo corrigido:</h4>
<p>Neste caso, temos uma chamada única, que evita outras chamadas</p>

```
class item{
    private:
        float preco;

    public:
        montarItem(){
            //bloco de código
        }
}

class pedido{
    private:
        int quantidade;

    public:
        getItem(){
            return item;
        }
}

class cliente{
    private:
        char[50] nome;

    public:
        getItem() {
            return cliente.getPedido()->getItem();
        }
        
}

int main(){
    string clienteItem= cliente->getItem();
}

```
