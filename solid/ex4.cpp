//EXEMPLO RUIM:
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

//EXEMPLO CORRIGIDO:
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
