public class Barbeiro {
    private int id; 
    public Cliente proximo;
    private Cliente atual;
    public Barbeiro(int a){
        this.id=a;
    }

    public Cliente proximoCliente() { 
    
    }
    // Seleciona o próximo cliente (dentro desta chamada o
    // barbeiro pode dormir esperando um cliente).
    public void corteTerminado(Cliente c) {  }
    // O barbeiro acorda o cliente que está na sua cadeira
    // e espera que ele saia da barbearia
    // (tome cuidado para acordar o cliente certo).
}