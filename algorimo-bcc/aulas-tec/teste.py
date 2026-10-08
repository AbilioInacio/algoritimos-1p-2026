# 1. Ler a quantidade de conjuntos
n = int(input("Digite a quantidade de conjuntos (N): "))

# Criar uma lista para armazenar todos os conjuntos digitados
todos_os_conjuntos = []

# 2. Ler os elementos de cada conjunto usando o loop
for i in range(n):
    # O usuário deve digitar os elementos separados por espaço (Ex: 1 2 3)
    entrada = input(f"Digite os elementos do conjunto {i + 1} separados por espaço: ")
    
    # split() separa o texto pelos espaços e set() transforma em um conjunto
    conjunto = set(entrada.split())
    # Adiciona o conjunto na nossa lista
    todos_os_conjuntos.append(conjunto)

# 3. Realizar a interseção de todos eles
# O asterisco (*) serve para desempacotar a lista dentro da função intersection
intersecao_final = set.intersection(*todos_os_conjuntos)

# 4. Mostrar o resultado
print("\n--- Resultado da Interseção ---")
if intersecao_final:
    # Transforma de volta em lista ordenada para ficar bonito visualmente
    resultado_formatado = sorted(list(intersecao_final))
    print("Elementos que aparecem em TODOS os conjuntos:", resultado_formatado)
else:
    print("A interseção é vazia (não há elementos em comum entre todos).")
