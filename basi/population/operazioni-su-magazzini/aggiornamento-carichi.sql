UPDATE carico
inner join pagamento on carico.ts = pagamento.tsCarico and carico.magazzino = pagamento.magazzino
SET saldato=1 
