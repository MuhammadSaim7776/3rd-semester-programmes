INCLUDE c:\Irvine\Irvine32.inc
INCLUDELIB c:\Irvine\Irvine32.lib
.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO dwExitCode:dword
.data
menu BYTE "WELCOME TO MY CALCULATOR",0dh,0ah,0dh,0ah,
    "Enter operator",0dh,0ah,0dh,0ah,
	"1. Addition (+)",0dh,0ah,
	"2. Subtraction (-)",0dh,0ah,
	"3. Multiplication (*)",0dh,0ah,
	"4. Division (/)",0dh,0ah,
	"Choice> ",0

choice BYTE ?
val1 DWORD ?
val2 DWORD ?
msg1 BYTE "Enter first number",0ah,0dh,0
msg2 BYTE "Enter second number",0ah,0dh,0
sm BYTE "The sum of given numbers is  ",0
sb BYTE "The subtraction of given numbers is  ",0
Ml BYTE "The multiplication of two numbers is ",0
dv BYTE "The division of two numbers is ",0
et BYTE "THANKS FOR USING MY APP",0
ab BYTE "Press 1 if you want to perform another operation and 0 for exit ",0ah,0dh,0
er BYTE "overflow!!!!!. plz try with number in range of 0 to 65535 ",0ah,0dh,0
.code
main proc
strt:
	call clrscr
	mov edx,OFFSET menu
	call WriteString
	call Readchar
	mov choice,al
	call clrscr
	mov edx, OFFSET msg1
	call WriteString
	call ReadDec
	mov val2,eax
	mov edx, OFFSET msg2
	call WriteString
	call ReadDec
	mov val1,eax
	cmp choice,'+'
	je sum
	cmp choice,'-'
	je subt
	cmp choice,'*'
	je mult
	cmp choice,'/'
	je divs	
sum:
	push val2
	push val1
	call AddTwo
	mov edx,OFFSET sm
	call WriteString
	call WriteInt
	jmp srt
subt:
	push val2
	push val1
	call SubTwo
	mov edx,OFFSET sb
	call WriteString
	call WriteInt
	jmp srt
mult:
	push val2
	push val1
	call MulTwo
	mov edx,OFFSET Ml
	call WriteString
	call WriteInt
	jmp srt
divs:
	push val2
	push val1
	call DivTwo
	mov edx,OFFSET dv
	call WriteString
	call WriteInt
	jmp srt
srt:
	mov edx, OFFSET ab
	call crlf
	call writestring
	call readint
	cmp eax,1
	je strt
	jmp ext
error:
	mov edx, OFFSET er
	call writestring
	jmp strt
AddTwo Proc
	push ebp
	mov ebp,esp
	mov eax,0
	mov eax,[ebp+12]
	add eax,[ebp+8]
	pop ebp
	ret
AddTwo ENDP
SubTwo Proc
	push ebp
	mov ebp,esp
	mov eax,0
	mov eax,[esp+12]
	sub eax,[esp+8]
	pop ebp
	ret
SubTwo ENDP
MulTwo Proc
	push ebp
	mov ebp,esp
	mov eax,[esp+12]
	mov ecx,[esp+8]
	mul ecx
	pop ebp
	ret
MulTwo ENDP
DivTwo Proc
	push ebp
	mov ebp,esp
	mov edx,0
	mov eax,[esp+12]
	mov ecx,[esp+8]
	div ecx
	pop ebp
	ret
DivTwo ENDP
ext Proc
	call clrscr
	mov DH,5
	mov DL,45
	call gotoxy
	mov edx, OFFSET et
	call WriteString
ext ENDP
INVOKE ExitProcess,0
main ENDP
end main

