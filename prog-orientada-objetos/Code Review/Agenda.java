import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class Agenda {
    private final List<Consulta> consultas = new ArrayList<>();

    // Encapsulamento da lista de consultas
    public List<Consulta> getConsultas() {
        return Collections.unmodifiableList(consultas);
    }

    // Método privado centralizado para reaproveitamento da lógica de busca usando Iterator
    private Consulta buscarConsultaAgendadaPorPacienteEHorario(Paciente paciente, String horario) {
        if (paciente == null || horario == null) return null;
        
        Iterator<Consulta> iterator = consultas.iterator();
        while (iterator.hasNext()) {
            Consulta c = iterator.next();
            if (c.getPaciente().getId() == paciente.getId() 
                && c.getHorario().equals(horario) 
                && c.isAgendada()) {
                return c;
            }
        }
        return null;
    }

    // Validação de conflito de horário para médicos utilizando Iterator
    private boolean existeConflitoMedico(Medico medico, String horario) {
        if (medico == null || horario == null) return false;

        Iterator<Consulta> iterator = consultas.iterator();
        while (iterator.hasNext()) {
            Consulta c = iterator.next();
            if (c.getMedico().getId() == medico.getId() 
                && c.getHorario().equals(horario) 
                && c.isAgendada()) {
                return true;
            }
        }
        return false;
    }

    public boolean agendarConsulta(Paciente paciente, Medico medico, String horario) {
        // Guard Clauses
        if (paciente == null || paciente.getNome() == null || paciente.getNome().isEmpty()) {
            System.out.println("Erro ao agendar: Paciente inválido.");
            return false;
        }
        if (medico == null || medico.getNome() == null || medico.getNome().isEmpty()) {
            System.out.println("Erro ao agendar: Médico inválido.");
            return false;
        }
        if (horario == null || horario.trim().isEmpty()) {
            System.out.println("Erro ao agendar: Horário inválido.");
            return false;
        }

        // Validação de conflitos de horário
        if (buscarConsultaAgendadaPorPacienteEHorario(paciente, horario) != null) {
            System.out.println("Erro ao agendar: Paciente já possui consulta neste horário.");
            return false;
        }
        if (existeConflitoMedico(medico, horario)) {
            System.out.println("Erro ao agendar: Médico já possui atendimento neste horário.");
            return false;
        }

        consultas.add(new Consulta(paciente, medico, horario));
        System.out.println("Consulta agendada com sucesso!");
        return true;
    }

    public Consulta buscarConsulta(Paciente paciente, String horario) {
        return buscarConsultaAgendadaPorPacienteEHorario(paciente, horario);
    }

    public boolean cancelarConsulta(Paciente paciente, String horario) {
        Consulta consulta = buscarConsultaAgendadaPorPacienteEHorario(paciente, horario);
        if (consulta == null) {
            System.out.println("Erro ao cancelar: Consulta agendada não encontrada.");
            return false;
        }

        consulta.setSituacao(Consulta.Situacao.CANCELADA);
        System.out.println("Consulta cancelada com sucesso!");
        return true;
    }

    public boolean remarcarConsulta(Paciente paciente, String horarioAtual, String novoHorario) {
        if (novoHorario == null || novoHorario.trim().isEmpty()) {
            System.out.println("Erro ao remarcar: Novo horário é inválido.");
            return false;
        }

        Consulta consulta = buscarConsultaAgendadaPorPacienteEHorario(paciente, horarioAtual);
        if (consulta == null) {
            System.out.println("Erro ao remarcar: Consulta de origem não foi encontrada.");
            return false;
        }

        // Verificar se o novo horário conflita para o paciente
        if (buscarConsultaAgendadaPorPacienteEHorario(paciente, novoHorario) != null) {
            System.out.println("Erro ao remarcar: Paciente já possui consulta no novo horário.");
            return false;
        }

        // Verificar se o novo horário conflita para o médico
        if (existeConflitoMedico(consulta.getMedico(), novoHorario)) {
            System.out.println("Erro ao remarcar: Médico já possui consulta no novo horário.");
            return false;
        }

        consulta.setHorario(novoHorario);
        System.out.println("Consulta remarcada com sucesso para " + novoHorario);
        return true;
    }

    // Listagem percorrida via Iterator
    public void listarConsultasPorMedico(Medico medico) {
        if (medico == null) {
            System.out.println("Médico inválido para listagem.");
            return;
        }

        System.out.println("--- Agenda do Dr(a). " + medico.getNome() + " ---");
        boolean encontrou = false;
        
        Iterator<Consulta> iterator = consultas.iterator();
        while (iterator.hasNext()) {
            Consulta c = iterator.next();
            if (c.getMedico().getId() == medico.getId()) {
                System.out.println(c.getPaciente().getNome() + " - " + c.getHorario() + " - " + c.getSituacao());
                encontrou = true;
            }
        }
        
        if (!encontrou) {
            System.out.println("Nenhuma consulta registrada para este médico.");
        }
    }
}
