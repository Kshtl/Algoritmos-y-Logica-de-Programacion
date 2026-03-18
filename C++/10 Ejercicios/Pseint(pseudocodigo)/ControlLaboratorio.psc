Algoritmo ControlLaboratorio
	Definir minutosTarde, faltas Como Entero
	Definir credencial, perteneceCurso Como Lógico
	Definir estado, motivo, prioridad Como Cadena
	Escribir 'Minutos de atraso:'
	Leer minutosTarde
	Escribir 'Numero de faltas:'
	Leer faltas
	Escribir 'Tiene credencial? (Verdadero/Falso):'
	Leer credencial
	Escribir 'Pertenece al curso? (Verdadero/Falso):'
	Leer perteneceCurso
	// Evaluación de condiciones
	Si  NO credencial Entonces
		estado <- 'NO INGRESA'
		motivo <- 'No trae credencial'
		prioridad <- 'ALTA'
	SiNo
		Si  NO perteneceCurso Entonces
			estado <- 'NO INGRESA'
			motivo <- 'No pertenece al curso'
			prioridad <- 'ALTA'
		SiNo
			Si faltas>=5 Entonces
				estado <- 'NO INGRESA'
				motivo <- 'Tiene 5 o más faltas'
				prioridad <- 'ALTA'
			SiNo
				Si minutosTarde>10 Entonces
					estado <- 'NO INGRESA'
					motivo <- 'Llega con más de 10 minutos tarde'
					prioridad <- 'MEDIA'
				SiNo
					Si faltas>=3 Entonces
						estado <- 'INGRESA CON ADVERTENCIA'
						motivo <- 'Tiene 3 o más faltas'
						prioridad <- 'MEDIA'
					SiNo
						Si minutosTarde>=0 Y minutosTarde<=10 Entonces
							Si minutosTarde>0 Entonces
								estado <- 'INGRESA CON ADVERTENCIA'
								motivo <- 'Llega entre 0 y 10 minutos tarde'
								prioridad <- 'BAJA'
							SiNo
								estado <- 'INGRESA SIN PROBLEMA'
								motivo <- 'Llega puntual'
								prioridad <- 'BAJA'
							FinSi
						FinSi
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
	Escribir 'Estado: ', estado
	Escribir 'Motivo: ', motivo
	Escribir 'Prioridad: ', prioridad
FinAlgoritmo
