Ele foi totalmente desenvolvido e testado na máquina virtal (fedora), espero que esteja compilando certinho.

Posteriormente existiram algumas modificações:
Primeiro eu retirei os printf restantes, livrando o programa de lixo visual. Arrumei a máscara (tanto int quanto long) no code, tirando a 0x7f e colocando 0x7ff. Portanto exclui a máscara fixa de 0x80 que estava ali para o programa funcionar em certos casos (já que agora ela se provou inútil). Por último solucionei o problema do padding da estrutura.

