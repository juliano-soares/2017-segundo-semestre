///Trabalho 3: Sistema Bancário – Listas encadeadas
///Criar um programa em C para controle clientes e movimentações bancárias destes clientes. O sistema deve atender aos seguintes
///requisitos:
/// Deve ser possível cadastrar clientes: incluir clientes, excluir clientes e listar todos os clientes.OK
/// Deve ser possível cadastrar agências: incluir agências, excluir agências e listar todas as agências.OK
/// Deve ser possível cadastrar contas de clientes em agências: incluir contas, excluir contas e listas todas as contas.
/// Deve ser possível cadastrar transações/movimentações bancárias de clientes em agências bancárias: incluir transação, excluir
///transação e listas todas as transações.
/// Restrições:
///o Um cliente não pode ter mais de uma conta na mesma agência (mas pode ter contas em agências diferentes);OK
///o Uma conta só pode ser criada para um cliente que exista na lista de clientes, e em uma agência que exista na lista de
///agências.
///o Os tipos de transações/movimentações permitidas são: verificar saldo, efetuar saque, efetuar transferência e efetuar
///pagamento. Obviamente algumas destas transações só podem ser efetuadas se houver saldo suficiente (incluindo o
///limite, quando existente). Estas transações devem ser válidas (efetuadas por um cliente existente, de contas
///existentes, em agências existentes).
///o Saques diários de uma conta não podem exceder o valor de 1000 reais.
///o Transferências diárias de uma conta não podem exceder o valor de 3000 reais.
///o Pagamentos diários de uma conta não podem exceder o valor de 5000 reais.
/// Sobre cada cliente, guardar: CPF, nome e telefone. Para excluir um cliente, informe o seu CPF (se houver contas e
///transações bancárias deste cliente, avisar o usuário e removê-las também).OK
/// Sobre cada agência, guardar: código da agência, nome, endereço e nome do gerente. Para excluir uma agência, informe o seu
///código (se houver contas e transações bancárias desta agência, avisar o usuário e removê-las também).OK
/// Sobre as contas, guardar: número da conta, cliente da conta, agência da conta, data de criação da conta, saldo e valor de
///limite permitido. Não é permitido guardar dados duplicados dos clientes ou das agências na lista de contas; deve-se guardar a
///referência aos clientes e às agências de uma das seguintes formas: ou armazenando-se na lista de contas apenas os
///respectivos códigos (de cliente e de agência) ou via apontadores para aquelas listas. Para excluir uma conta, informe o
///código da conta (se houver transações bancárias desta conta, avisar o usuário e removê-las também).
/// Sobre as transações/movimentações bancárias, guardar: código da transação, número da conta que efetivou a transação, tipo
///da transação (verificar saldo, efetuar saque, efetuar transferência ou efetuar pagamento), data da transação, e a agência onde
///feita a transação. Uma transação pode ser efetuada em qualquer agência bancária (não necessariamente na agência bancária
///daquela conta). Assuma que as transações não são feitas via internet nem em caixas eletrônicos. Para excluir uma transação,
///informe o seu código.
/// Devem ser gerados os seguintes relatórios de consulta:
///o R1: listar o nome dos clientes e o nome da agência em que estes possuem conta
///o R2: listar as agências que ainda não possuem nenhuma conta aberta
///o R3: listar todos os saques efetuados em certo mês informado pelo usuário
///o R4: listar o saldo das contas que não estão no negativo
///o R5: listar todas as contas de certo cliente informado pelo usuário
///o R6: listar todas as transferências bancárias efetuadas numa certa agência informada pelo usuário
///o R7: listar todas as transações bancárias realizadas por certo cliente informado pelo usuário
///o R8: listar todos os pagamentos realizados
///o R9: listar o nome dos clientes que não realizaram nenhuma transação bancária
///o R10: listar o nome dos clientes que têm o maior saldo em conta em cada agência.
