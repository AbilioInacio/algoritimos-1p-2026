public class Main {
    public static void main(String[] args) {
        Agenda agenda = new Agenda();

        // Instanciação com dados válidos
        Paciente ana = new Paciente(1, "Ana");
        Paciente mesmaAna = new Paciente(1, "Ana");
        Medico drJoao = new Medico(10, "João");

        System.out.println("--- Testes de Agendamento ---");
        // Tentativa de agendamento com horário inválido (deve falhar)
        try {
            agenda.agendarConsulta(ana, drJoao, "");
        } catch (Exception e) {
            System.out.println("Exceção esperada capturada: " + e.getMessage());
        }

        // Agendamento válido
        agenda.agendarConsulta(ana, drJoao, "14:00");

        // Tentativa de agendar a mesma pessoa no mesmo horário (deve falhar)
        agenda.agendarConsulta(mesmaAna, drJoao, "14:00");

        System.out.println("\n--- Testes de Remarcação ---");
        // Remarcar para um horário inválido (deve falhar)
        agenda.remarcarConsulta(ana, "14:00", "");

        // Remarcar com sucesso
        agenda.remarcarConsulta(ana, "14:00", "15:00");

        System.out.println("\n--- Testes de Cancelamento ---");
        // Cancelar consulta existente
        agenda.cancelarConsulta(mesmaAna, "15:00");

        System.out.println("\n--- Relatório Final do Médico ---");
        // Listagem que preserva histórico
        agenda.listarConsultasPorMedico(drJoao);
    }
}
