public class Paciente {
    private int id;
    private String nome;

    public Paciente(int id, String nome) {
        if (id <= 0) {
            throw new IllegalArgumentException("ID do paciente deve ser maior que zero.");
        }
        if (nome == null || nome.trim().isEmpty()) {
            throw new IllegalArgumentException("Nome do paciente não pode ser nulo ou vazio.");
        }
        this.id = id;
        this.nome = nome.trim();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        if (id <= 0) {
            throw new IllegalArgumentException("ID do paciente deve ser maior que zero.");
        }
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if (nome == null || nome.trim().isEmpty()) {
            throw new IllegalArgumentException("Nome do paciente não pode ser nulo ou vazio.");
        }
        this.nome = nome.trim();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Paciente paciente = (Paciente) o;
        return id == paciente.id;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
}
