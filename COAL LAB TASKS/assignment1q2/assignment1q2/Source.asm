INCLUDE c:\Irvine\Irvine32.inc
INCLUDELIB c:\Irvine\Irvine32.lib
.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO dwExitCode:dword
.data
String byte 20 DUP(?)
StringSize  DWORD ?
Msg1  byte  "Enter a string : "  ,0
Msg2 byte "Reversed string is : ",0
.code
main PROC
call clrscr
mov dh,15 ;x coordinate
mov dl,26 ;y coordinate
call gotoxy
mov edx , OFFSET Msg1
call WriteString
mov edx, OFFSET String
mov ecx, SIZEOF String
call ReadString
mov StringSize, eax
mov ecx,StringSize
mov esi,OFFSET String
L1: 
	mov eax,[esi]    ; get character
    push eax         ; push on stack
    inc  esi
loop L1
    mov  ecx,StringSize
    mov  esi,OFFSET String
L2: 
	pop  eax           ; get character
    mov  [esi],al      ; store in string
    inc  esi
loop L2
mov dl,26 ;y coordinate
mov dh,16 ;x coordinate
call gotoxy
mov edx,offset Msg2
call WriteString
mov EDX ,OFFSET String
call WriteString
INVOKE ExitProcess,0
main ENDP
end main