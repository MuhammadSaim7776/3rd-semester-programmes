INCLUDE C:\Irvine\Irvine32.inc
INCLUDELIB C:\Irvine\Irvine32.lib
.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD
.data
char BYTE ?
val1 BYTE ?
val2 BYTE ?
result BYTE ?
menu BYTE "Enter the operation u want to perform",0dh,0ah,0dh,0ah,
	"1. ADD",0dh,0ah,
	"2. Subtract",0dh,0ah,
	"3. Multiply",0dh,0ah,
	"Choice> ",0
str1 BYTE "Enter the first number ",0
str2 BYTE "Enter the second number ",0
str3 BYTE "The result is ",0

.code
main PROC
mov edx,offset menu
call writestring
call readint
mov char,al
cmp char,1
je sum
sum:
call clrscr
mov edx,str1
call writestring
call readint
mov val1,al
mov edx,str2
call writestring
call readint
mov val2,al
INVOKE ExitProcess, 0
main ENDP
end main