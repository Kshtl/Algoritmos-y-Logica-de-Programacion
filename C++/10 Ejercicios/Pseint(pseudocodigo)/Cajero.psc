Algoritmo Cajero
	Definir saldo, deposito, retiro Como Real
	Definir opcion Como Cadena
	Definir b20, b10, b5, b1 Como Entero
	Definir e20, e10, e5, e1 Como Entero
	Definir totalCajero, resto, totalRestante Como Entero
	saldo <- 0
	b20 <- 10
	b10 <- 10
	b5 <- 10
	b1 <- 10
	Repetir
		Escribir 'Menu'
		Escribir '1 - Ver saldo'
		Escribir '2 - Depositar'
		Escribir '3 - Retirar'
		Escribir '4 - Salir'
		Leer opcion
		Según opcion Hacer
			'1':
				Escribir 'Saldo: ', saldo
				Si saldo=0 Entonces
					Escribir 'Ingrese deposito:'
					Leer saldo
				FinSi
			'2':
				Escribir 'Monto a depositar:'
				Leer deposito
				Si deposito>0 Entonces
					saldo <- saldo+deposito
				SiNo
					Escribir 'Error'
				FinSi
			'3':
				Escribir 'Monto a retirar:'
				Leer retiro
				Si retiro<=0 Entonces
					Escribir 'Error: monto invalido'
				SiNo
					Si retiro>saldo Entonces
						Escribir 'Error: saldo insuficiente'
					SiNo
						totalCajero <- b20*20+b10*10+b5*5+b1
						Si retiro>totalCajero Entonces
							Escribir 'Error: sin efectivo'
						SiNo
							resto <- retiro
							// Billetes de 20
							e20 <- resto/20
							Si e20>b20 Entonces
								e20 <- b20
							FinSi
							resto <- resto-e20*20
							// Billetes de 10
							e10 <- resto/10
							Si e10>b10 Entonces
								e10 <- b10
							FinSi
							resto <- resto-e10*10
							// Billetes de 5
							e5 <- resto/5
							Si e5>b5 Entonces
								e5 <- b5
							FinSi
							resto <- resto-e5*5
							// Billetes de 1
							e1 <- resto
							Si e1>b1 Entonces
								e1 <- b1
							FinSi
							resto <- resto-e1
							Si resto<>0 Entonces
								Escribir 'No se puede entregar exacto'
							SiNo
								b20 <- b20-e20
								b10 <- b10-e10
								b5 <- b5-e5
								b1 <- b1-e1
								saldo <- saldo-retiro
								Escribir 'Billetes:'
								Escribir '20: ', e20
								Escribir '10: ', e10
								Escribir '5: ', e5
								Escribir '1: ', e1
								Escribir 'Saldo: ', saldo
								totalRestante <- b20*20+b10*10+b5*5+b1
								Escribir 'Cajero: ', totalRestante
							FinSi
						FinSi
					FinSi
				FinSi
			'4':
				Escribir 'Saliendo'
			De Otro Modo:
				Escribir 'Opcion invalida'
		FinSegún
	Hasta Que opcion='4'
	Escribir 'Saldo final: ', saldo
FinAlgoritmo
