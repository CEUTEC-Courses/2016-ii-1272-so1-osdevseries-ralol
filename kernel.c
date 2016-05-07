void putChar(int col, int line, char chr,int color);
void putStr(int col, int line, char *msj,int color);
int sizeOfString(char *str);

int main() {
 
    putInMemory(0xB000, 0x8140, 'H');
    putInMemory(0xB000, 0x8141, 0x2);
    putInMemory(0xB000, 0x8142, 'e');
    putInMemory(0xB000, 0x8143, 0x7);
    putInMemory(0xB000, 0x8144, 'l');
    putInMemory(0xB000, 0x8145, 0x7);
    putInMemory(0xB000, 0x8146, 'l');
    putInMemory(0xB000, 0x8147, 0x7);
    putInMemory(0xB000, 0x8148, 'o');
    putInMemory(0xB000, 0x8149, 0x7);
    putInMemory(0xB000, 0x814A, ' ');
    putInMemory(0xB000, 0x814B, 0x7);
    putInMemory(0xB000, 0x814C, 'W');
    putInMemory(0xB000, 0x814D, 0x7);
    putInMemory(0xB000, 0x814E, 'o');
    putInMemory(0xB000, 0x814F, 0x7);
    putInMemory(0xB000, 0x8150, 'r');
    putInMemory(0xB000, 0x8151, 0x7);
    putInMemory(0xB000, 0x8152, 'l');
    putInMemory(0xB000, 0x8153, 0x7);
    putInMemory(0xB000, 0x8154, 'd');
    putInMemory(0xB000, 0x8155, 0x7);
    putInMemory(0xB000, 0x8156, '!');
    putInMemory(0xB000, 0x8157, 0x7);

    putChar(40,12,'H',0xf1);
    putChar(41,12,'E',0xf1);
    putChar(42,12,'L',0xf1);
    putChar(43,12,'L',0xf1);
    putChar(44,12,'O',0xf1);
    putChar(45,12,' ',0xf1);
    putChar(46,12,'W',0xf1);
    putChar(47,12,'O',0xf1);
    putChar(48,12,'R',0xf1);
    putChar(49,12,'L',0xf1);
    putChar(50,12,'D',0xf1);


    putStr(60,24,"Hello Mundo",0xf4);

	while(1) {
		/*loops infinitly*/
	};
}

void putChar(int col, int line, char chr, int color)
{
	int strtAddress = 0x8000 + (80 * line - (80 - col ))*2;

	putInMemory(0xB000, strtAddress,chr);
	putInMemory(0xB000, strtAddress + 1,color);
}

int sizeOfString(char *str)
{
	char c = str[0];
	int cont = 0;
	while( c != '\0')
	{
		cont++;
		c = str[cont];
	}

	return cont;
}


void putStr(int col, int line, char* msj,int color)
{
	int currentCol = col;
	int i;
	
	for (i = 0; i < sizeOfString(msj); i++)
     		{
          		putChar(currentCol,line, msj[i],color);
			currentCol += 1;
     		}

}
