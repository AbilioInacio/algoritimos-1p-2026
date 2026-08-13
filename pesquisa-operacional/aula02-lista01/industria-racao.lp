\ Model Industria-racao
\ LP format - for model browsing. Use MPS format to capture full model detail.
Minimize
  0.56 osso + 0.81 soja + 0.46 peixe
Subject To
 min-proteina: 0.2 osso + 0.5 soja + 0.4 peixe >= 0.3
 min-calcio: 0.6 osso + 0.4 soja + 0.4 peixe >= 0.5
 mincusto: osso + soja + peixe = 1
Bounds
End
