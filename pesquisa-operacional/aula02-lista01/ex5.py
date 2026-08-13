import gurobipy as gp
from gurobipy import GRB

# Criar o objeto do modelo
m = gp.Model('Industria-racao')

# Adicionar variáveis de decisão
osso = m.addVar(name='osso')
soja = m.addVar(name='soja')
peixe = m.addVar(name='peixe')

proteina = m.addConstr(0.2*osso + 0.5*soja + 0.4*peixe >= 0.3, name='min-proteina')
calcio = m.addConstr(0.6*osso + 0.4*soja + 0.4*peixe >= 0.5, name='min-calcio')
mincusto = m.addConstr(osso + soja + peixe == 1, name='mincusto')

m.setObjective(0.56*osso + 0.81*soja + 0.46*peixe, GRB.MINIMIZE)

m.write('industria-racao.lp')
m.optimize()

for v in m.getVars():
    print(v.varName, "=", v.x)

print('Obj:', m.objVal)