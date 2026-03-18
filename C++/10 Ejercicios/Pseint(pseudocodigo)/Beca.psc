Proceso Becas
	
    Definir promedio, asistencia, ingresos Como Real
    Definir materiasPerdidas Como Entero
    Definir participaProyecto Como Entero
	
    Definir tipoAyuda, razonAcademica, razonEconomica, observacion Como Cadena
	
    Escribir "Ingrese promedio:"
    Leer promedio
	
    Escribir "Ingrese porcentaje de asistencia:"
    Leer asistencia
	
    Escribir "Ingrese numero de materias perdidas:"
    Leer materiasPerdidas
	
    Escribir "Ingrese ingresos familiares:"
    Leer ingresos
	
    Escribir "Participa en proyectos? (1=Si, 0=No):"
    Leer participaProyecto
	
    // Evaluacion academica principal
    Si promedio < 7 Entonces
        tipoAyuda <- "SIN BENEFICIO"
        razonAcademica <- "Promedio menor a 7"
		
    Sino
        Si asistencia < 80 Entonces
            tipoAyuda <- "SIN BENEFICIO"
            razonAcademica <- "Asistencia menor al 80%"
			
        Sino
            Si promedio >= 9 Y asistencia >= 90 Y materiasPerdidas = 0 Entonces
                tipoAyuda <- "BECA COMPLETA"
                razonAcademica <- "Alto rendimiento academico"
				
            Sino
                Si promedio >= 8 Y promedio < 9 Y asistencia >= 85 Entonces
                    tipoAyuda <- "BECA PARCIAL"
                    razonAcademica <- "Buen rendimiento academico"
					
                Sino
                    tipoAyuda <- "AYUDA DE MATERIALES"
                    razonAcademica <- "Cumple condiciones basicas"
                FinSi
				
                // Restriccion por materias perdidas
                Si materiasPerdidas > 1 Entonces
                    Si tipoAyuda = "BECA COMPLETA" Entonces
                        tipoAyuda <- "BECA PARCIAL"
                    FinSi
                FinSi
				
            FinSi
        FinSi
    FinSi
	
    // Evaluacion economica
    Si participaProyecto = 1 Y ingresos < 500 Entonces
		
        razonEconomica <- "Ingresos bajos y participa en proyectos"
		
        Si tipoAyuda = "AYUDA DE MATERIALES" Entonces
            tipoAyuda <- "BECA PARCIAL"
        Sino
            Si tipoAyuda = "BECA PARCIAL" Y materiasPerdidas = 0 Entonces
                tipoAyuda <- "BECA COMPLETA"
            FinSi
        FinSi
		
    Sino
        razonEconomica <- "No cumple condiciones economicas especiales"
    FinSi
	
    observacion <- "Evaluacion final realizada"
	
    Escribir "Tipo de ayuda: ", tipoAyuda
    Escribir "Razon academica: ", razonAcademica
    Escribir "Razon economica: ", razonEconomica
    Escribir "Observacion: ", observacion
	
FinProceso