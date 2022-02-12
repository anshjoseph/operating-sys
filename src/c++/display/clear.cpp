
void clear(){
    int index = 0;
    uint16_t *terminal_buffer = (uint16_t*)0xb8000;
    while(index < 80 * 25 * 2){
        terminal_buffer[index] = ' ';
        index += 1;
    }
}