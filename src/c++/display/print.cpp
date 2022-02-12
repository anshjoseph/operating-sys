
int PRINT_COUNT = 0;
void print_adv(char *str, uint8_t color,int next_line=0){
    
    int index = 0;
    uint16_t *terminal_buffer = (uint16_t*)0xb8000;
    uint32_t vga_index=0;

    if(next_line == 1){
        PRINT_COUNT += 1;
        vga_index = 80 * (PRINT_COUNT);
    } 
    while(str[index]){
        terminal_buffer[vga_index] = (unsigned short)str[index]|(unsigned short)color << 8;
        index++;
        vga_index++;
    }
}

void print(char* str,uint8_t color=0x07,int next_line=1){
    if(PRINT_COUNT == 0){
        PRINT_COUNT ++;
        print_adv(str,color,0);
    }
    else{
        print_adv(str,color,next_line);
    }
    
    
}

void cout(char* str)
{
    static uint16_t *terminal_buffer = (uint16_t*)0xb8000;
    static int x=0,y=0;
    for(int i=0; str[i] != '\0'; ++i)
    {   
        switch(str[i])
            {

                case '\n':
                    y++;
                    x=0;
                    break;

                default:
                    terminal_buffer[80*x+y] = (terminal_buffer[80*x+y] & 0xFF00)|str[i];
                    x++;
                    break;
            }


    if(x>=80)
        {
            y++;
            x=0;
        }
    if(y>=25)
        {   
            for(y=0;y<25;y++)
            {
                for(x=0;x<80;x++)
                {
                    terminal_buffer[80*x+y] = (terminal_buffer[80*x+y] & 0xFF00)|' ';
                }
            }
            x=0;
            y=0;
        }
    }
}