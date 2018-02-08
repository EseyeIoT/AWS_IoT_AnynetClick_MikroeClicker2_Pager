// This project uses Mikro Electronica CLICKER2 and is designed for use with
// their Mikro Pro C compiler and libraries
// CLICK modules used :
// OLED B or W Click utilising an SSD1306 controller
// Anynet 2G Click.  Cellular AWS gateway / client

#include "Oled_M.h"

/* font for OLED */
const unsigned char font[] = { // compact 5x8 font
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5F,0x00,0x00,0x00,0x07,0x00,0x07,0x00, //  'sp,!,"
    0x14,0x7F,0x14,0x7F,0x14, // #
    0x24,0x2A,0x7F,0x2A,0x12,0x23,0x13,0x08,0x64,0x62,0x36,0x49,0x56,0x20,0x50, //  '$,%,&
    0x00,0x08,0x07,0x03,0x00,0x00,0x1C,0x22,0x41,0x00,0x00,0x41,0x22,0x1C,0x00, //  '',(,)
    0x2A,0x1C,0x7F,0x1C,0x2A,0x08,0x08,0x3E,0x08,0x08,0x00,0x00,0x70,0x30,0x00, //  '*,+,,
    0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x60,0x60,0x00,0x20,0x10,0x08,0x04,0x02, //  '-,.,/
    0x3E,0x51,0x49,0x45,0x3E,0x00,0x42,0x7F,0x40,0x00,0x72,0x49,0x49,0x49,0x46, //  '0,1,2
    0x21,0x41,0x49,0x4D,0x33,0x18,0x14,0x12,0x7F,0x10,0x27,0x45,0x45,0x45,0x39, //  '3,4,5
    0x3C,0x4A,0x49,0x49,0x31,0x41,0x21,0x11,0x09,0x07,0x36,0x49,0x49,0x49,0x36, //  '6,7,8
    0x46,0x49,0x49,0x29,0x1E,0x00,0x00,0x14,0x00,0x00,0x00,0x40,0x34,0x00,0x00, //  '9,:,;
    0x00,0x08,0x14,0x22,0x41,0x14,0x14,0x14,0x14,0x14,0x00,0x41,0x22,0x14,0x08, //  '<,=,>
    0x02,0x01,0x59,0x09,0x06,0x3E,0x41,0x5D,0x59,0x4E,                          //  '?,@
    0x7C,0x12,0x11,0x12,0x7C,                                                   //  'A
    0x7F,0x49,0x49,0x49,0x36,0x3E,0x41,0x41,0x41,0x22,0x7F,0x41,0x41,0x41,0x3E, //  'B,C,D
    0x7F,0x49,0x49,0x49,0x41,0x7F,0x09,0x09,0x09,0x01,0x3E,0x41,0x41,0x51,0x73, //  'E,F,G
    0x7F,0x08,0x08,0x08,0x7F,0x00,0x41,0x7F,0x41,0x00,0x20,0x40,0x41,0x3F,0x01, //  'H,I,J
    0x7F,0x08,0x14,0x22,0x41,0x7F,0x40,0x40,0x40,0x40,0x7F,0x02,0x1C,0x02,0x7F, //  'K,L,M
    0x7F,0x04,0x08,0x10,0x7F,0x3E,0x41,0x41,0x41,0x3E,0x7F,0x09,0x09,0x09,0x06, //  'N,O,P
    0x3E,0x41,0x51,0x21,0x5E,0x7F,0x09,0x19,0x29,0x46,0x26,0x49,0x49,0x49,0x32, //  'Q,R,S
    0x03,0x01,0x7F,0x01,0x03,0x3F,0x40,0x40,0x40,0x3F,0x1F,0x20,0x40,0x20,0x1F, //  'T,U,V
    0x3F,0x40,0x38,0x40,0x3F,0x63,0x14,0x08,0x14,0x63,0x03,0x04,0x78,0x04,0x03, //  'W,X,Y
    0x61,0x59,0x49,0x4D,0x43,                                                   //  'Z
    0x00,0x7F,0x41,0x41,0x41,0x02,0x04,0x08,0x10,0x20,                          //  '[,\'
    0x00,0x41,0x41,0x41,0x7F,0x04,0x02,0x01,0x02,0x04,0x40,0x40,0x40,0x40,0x40, //  '],^,_
    0x00,0x03,0x07,0x08,0x00,0x20,0x54,0x54,0x38,0x40,0x7F,0x28,0x44,0x44,0x38, //  '`,a,b
    0x38,0x44,0x44,0x44,0x28,0x38,0x44,0x44,0x28,0x7F,0x38,0x54,0x54,0x54,0x18, //  'c,d,e
    0x00,0x08,0x7E,0x09,0x02,0x0C,0x52,0x52,0x4A,0x3C,0x7F,0x08,0x04,0x04,0x78, //  'f,g,h
    0x00,0x44,0x7D,0x40,0x00,0x20,0x40,0x40,0x3D,0x00,0x7F,0x10,0x28,0x44,0x00, //  'i,j,k
    0x00,0x41,0x7F,0x40,0x00,0x7C,0x04,0x78,0x04,0x78,0x7C,0x08,0x04,0x04,0x78, //  'l,m,n
    0x38,0x44,0x44,0x44,0x38,0x7C,0x18,0x24,0x24,0x18,0x18,0x24,0x24,0x18,0x7C, //  'o,p,q
    0x7C,0x08,0x04,0x04,0x08,0x48,0x54,0x54,0x54,0x24,0x04,0x04,0x3F,0x44,0x24, //  'r,s,t
    0x3C,0x40,0x40,0x20,0x7C,0x1C,0x20,0x40,0x20,0x1C,0x3C,0x40,0x30,0x40,0x3C, //  'u,v,w
    0x44,0x28,0x10,0x28,0x44,0x4C,0x50,0x50,0x50,0x3C,0x44,0x64,0x54,0x4C,0x44, //  'x,y,z
    0x00,0x08,0x36,0x41,0x00,0x00,0x00,0x77,0x00,0x00,0x00,0x41,0x36,0x08,0x00, //  '{,|,}
    0x02,0x01,0x02,0x04,0x02                                                    //  '~
};

char aws_message[255], temp_buff[64], data_rcvd = 0, *msgptr, *msgend, cmd_text[200];
unsigned char _x, _y, _sx=1, _sy=1; // scaling factors

int msg_length = 0, idx = 0, len;
unsigned int count = 0;

sbit OLED_RST at LATD0_bit;
sbit OLED_CS at LATD1_bit;
sbit OLED_DC at RG0_bit;

/* initialise hardware */
static void MCU_Init() {
  TRISD0_bit = 0;
  TRISD1_bit = 0;
  TRISG0_bit = 0;

  SPI1_Init();
  Delay_ms(500);

  /* init aws uart */
  UART2_Init(9600);
  delay_ms(200);
}

/* wait for response from aws */
void waitForAwsResponse(char *aws_response, int attempts) {
  char output[255];

  LATD4_bit = 0;
  while(1)   {
    if (UART2_Data_Ready() == 1) {          // if data is received
      UART2_Read_Text(output, aws_response, attempts);    // reads text until response is matched
      break;
    }
  }
}

//Send command to OLED m display
void OLED_M_command(unsigned char temp) {
  OLED_CS=0;
  OLED_DC=0;
  SPI1_Write(temp);
  OLED_CS=1;
}

//Send data to OLED m display
void OLED_M_data(unsigned char temp) {
  OLED_CS=0;
  OLED_DC=1;
  SPI1_Write(temp);
  OLED_CS=1;
}

// intialise OLED
void OLED_M_Init() {
  OLED_RST=0;
  Delay_ms(1000);
  OLED_RST=1;
  Delay_ms(1000);
  OLED_M_command(SSD1306_DISPLAYOFF);             //0xAE  Set OLED Display Off
  OLED_M_command(SSD1306_SETDISPLAYCLOCKDIV);     //0xD5  Set Display Clock Divide Ratio/Oscillator Frequency
  OLED_M_command(0x80);
  OLED_M_command(SSD1306_SETMULTIPLEX);           //0xA8  Set Multiplex Ratio
  OLED_M_command(0x27);
  OLED_M_command(SSD1306_SETSEGMENTREMAP);
  OLED_M_command(SSD1306_COMSCANDEC);
  OLED_M_command(SSD1306_SETDISPLAYOFFSET);       //0xD3  Set Display Offset
  OLED_M_command(0x00);
  OLED_M_command(SSD1306_CHARGEPUMP);             //0x8D  Set Charge Pump
  OLED_M_command(0x14);
  OLED_M_command(SSD1306_SETSTARTLINE);           //0x40  Set Display Start Line
  OLED_M_command(SSD1306_SETCOMPINS);             //0xDA  Set COM Pins Hardware Configuration
  OLED_M_command(0x12);
  OLED_M_command(SSD1306_SETCONTRAST);            //0x81   Set Contrast Control
  OLED_M_command(0xAF);
  OLED_M_command(SSD1306_SETPRECHARGE);           //0xD9   Set Pre-Charge Period
  OLED_M_command(0x25);
  OLED_M_command(SSD1306_SETVCOMDETECT);          //0xDB   Set VCOMH Deselect Level
  OLED_M_command(0x20);
  OLED_M_command(SSD1306_DISPLAYALLON_RESUME);    //0xA4   Set Entire Display On/Off
  OLED_M_command(SSD1306_NORMALDISPLAY);          //0xA6   Set Normal/Inverse Display
  OLED_M_command(SSD1306_DISPLAYON);
}

void OLED_SetRow(unsigned char add) {
    add = 0xB0 | add;
    OLED_M_command(add);
}

void OLED_SetColumn(unsigned char add) {
    add += 32;
    OLED_M_command((SSD1306_SETHIGHCOLUMN | (add >> 4))); // SET_HIGH_COLUMN
    OLED_M_command((0x0f & add));        // SET LOW_COLUMN
}

void OLED_SetScale(unsigned char sx, unsigned char sy) {
    _sx = sx; _sy = sy;
}

void OLED_Clear(void) {
    unsigned char i,j;
    for(i=0; i<5; i++) { // 5*8=40 pixel rows (actually 39)
        OLED_SetRow(i);
        OLED_SetColumn(0);
        for(j=0; j<96; j++)  OLED_M_data(0);
    }
    _x = 0; _y = 0;
    OLED_SetRow(0);
    OLED_SetColumn(0);
}

/*  scalable horizontally and vertically */
void OLED_Putchar(char ch) {
    unsigned char i, j, k, byte;
    const unsigned char *f = &font[(ch-' ')*5];
    const unsigned char mask[]={1, 3, 7, 0xf };

    for(i=0; i<6; i++) {
        unsigned long word = 0;
        byte = *f++ << 1;
        if (i==5) byte = 0;
        for(j=0; j<8; j++) { // expand byte to word
            word <<= _sy;
            if (byte & 0x80) word |= mask[_sy-1];
            byte <<= 1;
        }
        for(j=0; j<_sy; j++) { // exp vert
            OLED_SetRow(_y+j) ;
            OLED_SetColumn(_x+i*_sx);
            for(k=0; k<_sx; k++) { // exp horiz
                OLED_M_data(word);
            }
            word >>= 8;
        }
    }

    _x+= 6 * _sx;
    if (_x >= SSD1306_LCDWIDTH) { // wrap x
        _x = 0; OLED_SetColumn(0);
        _y += _sy;
        if (_y >= 5-_sy) { // wrap y
            _y = 0;
        }
        OLED_SetRow(_y);
    }
}

/* Write a string to the OLED */
void OLED_Puts(char x, char y, char *s) {
    _y = y; _x = x;
    OLED_SetRow(_y);
    OLED_SetColumn(_x);
    while(*s) {
        OLED_Putchar(*s++);
        _x++;
    }
}

/* Set up the connection to AWS */
void setupAws(void) {
  /* turn off echo */
  UART2_Write_Text("ATE0\r\n");
  waitForAwsResponse("OK", 255);

  /* start afresh - closes */
  sprintf(cmd_text, "AT+AWSSUBCLOSE=0\r\n");
  UART2_Write_text(cmd_text);
  waitForAwsResponse("0,", 255);

  // OPEN an SSL encryped AWS IoT connection and subscribe to the data
  sprintf(cmd_text, "AT+AWSSUBOPEN=0,\"msgout\"\r\n");
  UART2_Write_text(cmd_text);
  waitForAwsResponse("0,0", 255);
}

void main() {
  /* init hw */
  MCU_Init();
  Delay_ms(500);
  OLED_M_Init();
  Delay_ms(500);

  /* initial message */
  OLED_Clear();
  OLED_Puts(0, 0, "Eseye Pager");
  OLED_Puts(0, 1, "Demo V: 0.1");
  OLED_Puts(0, 2, "Setting up AWS");

  setupAws();

  OLED_Clear();
  OLED_Puts(0, 0, "Message:");

  /* main loop*/
  while(1) {
    memset(aws_message, 0, sizeof(aws_message));
    memset(temp_buff, 0, sizeof(temp_buff));
    // WAIT for AWS subscribed data to start arriving
    // +AWS:0,<length>\r\n<data>
    while(1) {
      if (UART2_Data_Ready() == 1) {          // if data is received
        UART2_Read_Text(temp_buff, "+AWS:0,", 255);    // reads text until aws_response is found
        break;
      }
    }

    // so next is message length -- read data to \r\n so we have the complete length
    while(1) {
      if (UART2_Data_Ready() == 1) {          // if data is received
        UART2_Read_Text(temp_buff, "\r\n", 255);    // reads text until aws_response is found
        break;
      }
    }
    
    // convert data length
    msg_length = atoi(temp_buff);
    
    // now receive the message data
    data_rcvd = 0;
    idx = 0;
    while(data_rcvd < msg_length) {
      if (UART2_Data_Ready() == 1) {
        aws_message[idx++] = UART2_Read();
        data_rcvd += 1;
      }
    }

    /* process json or raw */
    // JSON format {"message":"<message text>"}
    // RAW format <message text>
    msgptr = strstr(aws_message, "message");
    if(msgptr != 0) {
      msgptr += 11;
      msgend = strchr(msgptr, '"');
      if(msgend != 0) {
        *msgend = 0;
      }
    } else {
      // not json
      msgptr = aws_message;
    }

    /* display message on the OLED */
    OLED_Puts(0, 3, "              ");
    OLED_Puts(0, 3, msgptr);
  }
}
