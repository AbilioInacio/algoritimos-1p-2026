public class Consulta {
    public Paciente paciente;
    public Medico medico;
    public String horario;
    public String situacao = "Agendada";

    public Consulta(Paciente paciente, Medico medico, String horario) {
        this.paciente = paciente;
        this.medico = medico;
        this.horario = horario;
    }
}
