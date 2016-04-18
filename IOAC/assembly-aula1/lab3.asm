	.data
str1:	.asciiz "Resultado: "

	.text
	.globl main

main:

	addi $t0, $zero, 100 

	#Imprimir str1
	li $v0, 4
	la $a0, str1
	syscall
	
	#Imprimir o int
	li $v0, 1
	move $a0, $t0
	syscall
	

