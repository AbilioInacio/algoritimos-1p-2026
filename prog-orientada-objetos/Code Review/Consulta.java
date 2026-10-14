public class Consulta {
    public enum Situacao {
        AGENDADA,
        CANCELADA,
        FINALIZADA
    }

    private Paciente paciente;
    private Medico medico;
    private String horario;
    private Situacao situacao;

    public Consulta(Paciente paciente, Medico medico, String horario) {
        if (paciente == null) {
            throw new IllegalArgumentException("Paciente não pode ser nulo.");
        }
        if (medico == null) {
            throw new IllegalArgumentException("Médico não pode ser nulo.");
        }
        if (horario == null || horario.trim().isEmpty()) {
            throw new IllegalArgumentException("Horário não pode ser nulo ou vazio.");
        }
        this.paciente = paciente;
        this.medico = medico;
        this.horario = horario.trim();
        this.situacao = Situacao.AGENDADA;
    }

    public Paciente getPaciente() {
        return paciente;
    }

    public Medico getMedico() {
        return medico;
    }

    public String getHorario() {
        return horario;
    }

    public void setHorario(String horario) {
        if (horario == null || horario.trim().isEmpty()) {
            throw new IllegalArgumentException("Horário não pode ser nulo ou vazio.");
        }
        this.horario = horario.trim();
    }

    public Situacao getSituacao() {
        return situacao;
    }

    public void setSituacao(Situacao situacao) {
        if (situacao == null) {
            throw new IllegalArgumentException("Situação não pode ser nula.");
        }
        this.situacao = situacao;
    }

    public boolean isAgendada() {
        return this.situacao == Situacao.AGENDADA;
    }

    @Override
    public String toString() {
        return paciente.getNome() + " - " + medico.getNome() + " - " + horario + " - " + situacao;
    }
}
