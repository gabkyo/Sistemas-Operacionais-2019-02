public class Cliente{
    private int id;
    public Cliente(int a){
        this.id=a;
    }
    // Operação chamada pelos clientes:
    public boolean cortaCabelo(Cliente c) {
        return true;
    }
    // Se a barbearia não estiver lotada, espera que o corte
    // seja feito e retorna TRUE.
    // Se a barbearia estiver lotada, retorna FALSE.
}