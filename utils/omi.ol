inicia_tsc	grafo_enunciado
inicia_tsa_main
abrir_ambito_ppal_main
buscar	declarar_main	main_v1
insertar_tsa_main	main_v1	1	1	1	3	2		
abrir_clase	AA
buscar	declarar_miembro_instancia	AA	AA_a1
insertar_tsc	AA	AA_a1	8	1	1	3	2		
buscar	declarar_miembro_instancia	AA	AA_sa1
insertar_tsc	AA	AA_sa1	7	1	1	1	1		
buscar	declarar_miembro_clase	A	A_a2
insertar_tsc	AA	AA_a2	7	1	1	3	1		
buscar	declarar_miembro_instancia	AA	AA_mA1@1
abrir_ambito_tsc	AA	AA_mA1@1	5	3	3	2
buscar	declarar_id_local_metodo	AA	mA1@1_pmA1
insertar_tsc	AA	mA1@1_pmA1	2	1	1	3	2		
buscar	id_no_cualificado	a1	AA
buscar	id_no_cualificado	v1	AA
buscar	id_no_cualificado	pmA1	AA
cerrar_ambito_tsc	AA
cerrar_clase	AA
abrir_clase_hereda	BB	AA
buscar	declarar_miembro_instancia	BB	BB_b1
insertar_tsc	BB	BB_b1	8	1	1	3	2	
buscar	declarar_miembro_instancia	BB	BB_aa1
insertar_tsc	BB	BB_aa1	8	0	1	3	2
buscar	declarar_miembro_instancia	BB	BB_mB1@1
abrir_ambito_tsc	BB	BB_mB1@1	5	1	3	2
buscar	declarar_id_local_metodo	BB	mB1@1_pmB1
insertar_tsc	BB	mB1@1_pmB1	2	1	1	3	2	
buscar	id_cualificado_instancia	aa1	a1	BB
buscar	id_cualificado_instancia	aa1	sa1	BB
cerrar_ambito_tsc	BB
cerrar_clase	BB
buscar	declarar_main	main_a
insertar_tsa_main	main_a		1	0	1	3	2			
buscar	id_no_cualificado	a	main
buscar	id_no_cualificado	v1	main
buscar	id_no_cualificado	v1	main
buscar	id_cualificado_instancia	a	mA1@1	main
buscar	id_no_cualificado	v1	main
buscar	id_cualificado_instancia	a	a1	main
buscar	id_no_cualificado	x	main
buscar	id_cualificado_clase	AA	a1	main
buscar	id_cualificado_clase	AA	sa1	main
buscar	id_no_cualificado	a	main
cerrar_tsa_main
cerrar_tsc
