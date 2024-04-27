//EXEMPLO RUIM:
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

//EXEMPLO CORRIGIDO:

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