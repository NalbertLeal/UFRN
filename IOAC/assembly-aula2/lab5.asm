	.data
str1: .asciiz "Resultado: "

	.text	
	.globl main
	
main:		li $t5, 10
		li $s0, 20
		jal comecou
		j fim
	
comecou:
		addi $t5, $t5,1
		addi $t5, $t5,1
		addi $t5, $t5,1
		addi $t5, $t5,1
		addi $t5, $t5,1
		jr $ra
	
fim:
		li $v0, 4
		la $a0, str1
		syscall

		
		li $v0, 1
		move $a0, $t5
		syscall
					
		li $v0, 10
		syscall
		
		
		