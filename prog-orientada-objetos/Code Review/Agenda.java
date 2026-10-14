import java.util.ArrayList;

public class Agenda {
    public ArrayList<Consulta> consultas = new ArrayList<>();

    public void agendar(Paciente paciente, Medico medico, String horario) {
        if (paciente != null) {
            if (medico != null) {
                if (horario != null) {
                    boolean existe = false;
                    for (Consulta c : consultas) {
                        if (c.paciente == paciente && c.horario.equals(horario)) {
                            existe = true;
                        }
                    }
                    if (!existe) {
                        consultas.add(new Consulta(paciente, medico, horario));
                        System.out.println("Consulta cadastrada.");
                    } else {
                        System.out.println("Horário já utilizado.");
                    }
                } else {
                    System.out.println("Horário inválido.");
                }
            } else {
                System.out.println("Médico inválido.");
            }
        } else {
            System.out.println("Paciente inválido.");
        }
    }

    public Consulta buscar(Paciente paciente, String horario) {
        Consulta encontrada = null;
        for (Consulta c : consultas) {
            if (c.paciente.id == paciente.id && c.horario.equals(horario)) {
                encontrada = c;
            }
        }
        return encontrada;
    }

    public void cancelar(Paciente paciente, String horario) {
        for (Consulta c : consultas) {
            if (c.paciente.id == paciente.id && c.horario.equals(horario)) {
                c.situacao = "Cancelada";
            }
        }
    }

    public void remarcar(Paciente paciente, String horarioAtual, String novoHorario) {
        for (Consulta c : consultas) {
            if (c.paciente.id == paciente.id && c.horario.equals(horarioAtual)) {
                c.horario = novoHorario;
                c.situacao = "Agendada";
            }
        }
    }

    public void removerCanceladas() {
        for (Consulta c : consultas) {
            if (c.situacao.equals("Cancelada")) {
                consultas.remove(c);
            }
        }
    }

    public void listarDoMedico(Medico medico) {
        for (Consulta c : consultas) {
            if (c.medico.id == medico.id) {
                System.out.println(c.paciente.nome + " - " + c.horario + " - " + c.situacao);
                if (c.horario.equals("")) {
                    c.horario = "08:00";
                }
            }
        }
    }
}
