public class Medico {
    private int id;
    private String nome;

    public Medico(int id, String nome) {
        if (id <= 0) {
            throw new IllegalArgumentException("ID do médico deve ser maior que zero.");
        }
        if (nome == null || nome.trim().isEmpty()) {
            throw new IllegalArgumentException("Nome do médico não pode ser nulo ou vazio.");
        }
        this.id = id;
        this.nome = nome.trim();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        if (id <= 0) {
            throw new IllegalArgumentException("ID do médico deve ser maior que zero.");
        }
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if (nome == null || nome.trim().isEmpty()) {
            throw new IllegalArgumentException("Nome do médico não pode ser nulo ou vazio.");
        }
        this.nome = nome.trim();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Medico medico = (Medico) o;
        return id == medico.id;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
}
