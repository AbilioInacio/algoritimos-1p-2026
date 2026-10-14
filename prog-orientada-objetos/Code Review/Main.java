public class Main {
    public static void main(String[] args) {
        Agenda agenda = new Agenda();

        Paciente ana = new Paciente(1, "");
        Paciente mesmaAna = new Paciente(1, "Ana");

        Medico drJoao = new Medico(10, "João");

        agenda.agendar(ana, drJoao, "");
        agenda.agendar(ana, drJoao, "14:00");
        agenda.agendar(mesmaAna, drJoao, "14:00");

        agenda.consultas.add(
            new Consulta(mesmaAna, drJoao, "14:00")
        );

        agenda.remarcar(ana, "14:00", "");
        agenda.cancelar(mesmaAna, "14:00");

        Consulta c = agenda.buscar(ana, "14:00");
        if (c != null) {
            c.situacao = "FINALIZADA";
        }

        agenda.removerCanceladas();
        agenda.listarDoMedico(drJoao);
    }
}
