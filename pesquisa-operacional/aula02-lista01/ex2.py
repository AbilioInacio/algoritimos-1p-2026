import gurobipy as gp
from gurobipy import GRB

# Criar o objeto do modelo
m = gp.Model('Fazenda')

# Adicionar variáveis de decisão
x = m.addVar(name='x')
y = m.addVar(name='y')

mins = m.addConstr(x >= 2, name='mins')
minc = m.addConstr(y >= 1, name='minc')
maxplant = m.addConstr(x + y <= 7, name='maxplant')

m.setObjective(5*x + 3*y, GRB.MAXIMIZE)

m.write('Fazenda.lp')
m.optimize()

for v in m.getVars():
    print(v.varName, "=", v.x)

print('Obj:', m.objVal)